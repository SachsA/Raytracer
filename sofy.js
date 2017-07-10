#!/usr/bin/node
/*
** sofy.js for raytracer in /rendu/Infographie/raytracer
**
** Made by Thomas Lombard
** Login   <lombar_e@epitech.net>
**
** Started on  Sun Jun 25 12:08:46 2017 Thomas Lombard
** Last update Sat May 27 19:55:16 2017 Kellian CIPIERRE
*/

fs = require('fs');
const path = require('path');
const readline = require('readline');
const tty = require('tty');

try {
	var config = require('./src/parser/config.js');
	var glob = require('./src/parser/globals.js');
	var get = require('./src/parser/getters.js');
} catch (e) {
	console.error(e.code);
	process.exit(1);
}
const gry='\x1b[1;30m'
const red='\x1b[31m'
const grn='\x1b[32m'
const yel='\x1b[33m'
const blu='\x1b[34m'
const pnk='\x1b[35m'
const cyn='\x1b[36m'
const wht='\x1b[37m'
const nrm='\x1b[m'

var formats = {json:true, ply:true}

if (process.argv.length < 3) {
	help(); process.exit(0);
}

const support = ["", "sphere", "plan", "cone", "cylindre", "triangle"];
var argv = {help:false, live:true, file:null, out:null, redirect:false}
var json;

parse_opt(process.argv);

if (argv.help != false) {
	if (argv.help == true)
		help()
	else if (argv.help)
		help(argv.help)
	process.exit(0);
}
else if (argv.file.slice(-5) == ".json" && formats.json) {
	try {
		var obj = require('./' + argv.file);
	} catch (e) {
		console.error(`JSON PARSER: ${argv.file}`);
		console.error(e.message);
		process.exit(2);
	} finally {
		json = valid_map(obj);
		delete obj;
		if (argv.live)
			print_stats(json);
		else
			program_output(argv, json);
	}
} else {
	console.error(`${red}Cannot parse ${argv.file}${nrm}`);
	process.exit(2);
}

function parse_opt(o)
{
	for (var i = 2; i < o.length; ++i) {
		switch (o[i]) {
			case "--live":
			case "-l":
				if (o[i + 1] !== undefined && argv.out == null) {
					++i;
					if (o[i] == "yes")
						argv.live = true;
					else if (o[i] == "no")
						argv.live = false;
					else
						help(), process.exit(1);
				}
				else
					help(), process.exit(1);
			break;
			case "--help":
			case "-h":
				if (o[i + 1] !== undefined && glob.help[o[i + 1]] !== undefined)
					argv.help = o[++i];
				else
					argv.help = true;
			break;
			case "--file":
			case "-f":
				argv.redirect = true;
				++i
				if (o[i] !== undefined && o[i].slice(0, 1) != '-' &&
				    o[i].slice(-5) != ".json") {
					argv.out = o[i];
				}
				else
				{
					--i;
					argv.out = null;
				}
			break;
			default:
				try {
					fs.accessSync(o[i], 'r');
				} catch (e) {
					help(); process.exit(1);
				} finally {
					argv.file = o[i];
				};
		}
	}
	if (argv.redirect == true)
		argv.live = false;
	if (argv.out == null && argv.redirect == true && argv.file != null)
		argv.out = path.parse(argv.file).name + '.rt';
}

function valid_map(obj)
{
	var ret = new Object();
	var idx = 0;

	if (obj.name === undefined)
		console.error("La scène doit avoir un nom"), process.exit(2);
	else if (typeof obj.name != "string")
		console.error("Le nom de la scène doit être une chaîne"), process.exit(2);
	ret.name = obj.name;

	ret.geometry = new Array();
	for (var i in obj.geometry) {
		var o = obj.geometry[i];
		var add = new Object();

//	**************************************************************************** Type getter
		if (o.type === undefined || typeof o.type != 'string') {
			console.error("Quel est le type de l'objet"); continue;
		}
		if ((add.type = support.indexOf(o.type)) < 0) {
			console.error(`${red}Le type d'objet ${o.type} est inconnu${nrm}`); continue
		};
//	**************************************************************************** Radius coord check
		if (add.type == 1 || add.type == 4)
		{
			if (o.radius !== undefined) {
				if (isNaN((add.radius = get.float(o.radius))))
					continue;
			} else {
				console.error(`${red}Le rayon doit être un nombre${nrm}`); continue;
			}
		}
		else
			add.radius = 0;
//	**************************************************************************** Angle check
		if (add.type == 3) {
			if (o.angle !== undefined) {
				if (isNaN((add.deg = get.float(o.angle))))
					continue;
			} else {
				console.error(`${red}L'angle doit être un nombre${nrm}`); continue;
			}
		}
		else
			add.deg = 0;
//	**************************************************************************** Position coord check
		if ((add.reflexion = get.float(o.reflexion)) === null ||
//	**************************************************************************** Rotation check
		    (add.pos = get.coord(o.pos)) === null ||
//	**************************************************************************** Rotation check
		    (add.rot = get.coord(o.rot)) === null ||
//	**************************************************************************** Maximum coord check
		    (add.max = get.coord(o.max)) === null ||
//	**************************************************************************** Minimum coord check
		    (add.min = get.coord(o.min)) === null ||
//	**************************************************************************** Color check
		    (add.color = get.color(o.color)) === null)
			continue;
//	**************************************************************************** Textures check
		if (o.refraction === undefined)
			add.refraction = 100;
		else if ((add.refraction = get.float(o.refraction)) === null)
			continue;
		add.texture = get.texture(o.texture);
		ret.geometry[idx] = add;
		++idx;
	}
	idx = 0;
	ret.light = new Array();
	for (var i in obj.lights) {
		var o = obj.lights[i];
		var add = new Object();
		if ((add.pos = get.coord(o.pos)) == null)
			continue;
		if ((add.color = get.color(o.color)) == null)
			continue;
		ret.light[idx] = add;
		++idx;
	}
	ret.camera = obj.camera;
	if (obj.camera === undefined) {
		ret.camera = {pos:[-2000, 0, 0], dir:[0, 0, 0]};
	}
	else {
		ret.camera.pos = get.coord(ret.camera.pos);
		ret.camera.dir = get.coord(ret.camera.dir);
	}


	return (ret);
}

function print_stats(obj)
{
	console.log(`Nom de la scene      : ${grn}${obj.name}${nrm}`);
	console.log("\nElements de la scène :");
	for (var i = 0; obj.geometry[i] !== undefined; ++i) {
		console.log(`\tForme n°[${i}]    : ${grn}${support[obj.geometry[i].type]}${nrm}`);
		console.log(`\tRadius               : ${cyn}${obj.geometry[i].radius}${nrm}`);
		console.log(`\tAngle (°)            : ${cyn}${obj.geometry[i].deg}${nrm}`);
		console.log(`\tIndice de réflexion  : ${yel}${obj.geometry[i].reflexion}${nrm}`);
		console.log(`\tIndice de réfraction : ${yel}${obj.geometry[i].refraction}${nrm}`);
		console.log(`\tPosition (xyz)       : ${yel}${obj.geometry[i].pos}${nrm}`);
		console.log(`\tRotation (xyz)       : ${yel}${obj.geometry[i].rot}${nrm}`);
		console.log(`\tLimites max (xyz)    : ${yel}${obj.geometry[i].max}${nrm}`);
		console.log(`\tLimites min (xyz)    : ${yel}${obj.geometry[i].min}${nrm}`);
		console.log(`\tCouleur              : ${grn}${obj.geometry[i].color}${nrm}`);
		console.log(`\tTexture              : ${grn}${obj.geometry[i].texture}${nrm}`);
		console.log("");
	}
	for (var i = 0; obj.light[i] !== undefined; ++i) {
		console.log(`Lumière n°${i} :`);
		console.log(`\tPosition          : ${grn}${obj.light[i].pos}${nrm}`);
		console.log(`\tCouleur           : ${grn}${obj.light[i].color}${nrm}`);
		console.log("");
	}
	console.log("Camera : ");
	console.log(`\tPosition       : ${grn}${obj.camera.pos}${nrm}`);
	console.log(`\tDirection      : ${grn}${obj.camera.dir}${nrm}`);
}

function	get_buffer(obj)
{
	var		size;
	var		ret;
	var		offset = 4 + 20 + 512;
	var		obj_size;
	var		light_size;

	size = get.buffer_hdr();
	size += obj.geometry.length * get.buffer_obj();
	size += obj.light.length * get.buffer_lights();
	ret = new Buffer(size);
	// Sécurité
	ret.fill(0);
	// Set un magic number => permet de savoir avec quoi et comment sont compilés les données
	ret.writeUInt32LE(config.magic, 0);
	// Version du compileur
	ret.write(config.tag, 4, 20);
	// Nom de la scene
	ret.write(obj.name, 24, 511);
	offset = ret.writeInt32LE(obj.geometry.length, offset);
	offset = ret.writeInt32LE(obj.light.length, offset);
	for (var i in obj.geometry)
	{
		var o = obj.geometry[i];
		offset = ret.writeInt32LE(o.type - 1, offset);
		offset = ret.writeFloatLE(o.radius, offset);
		offset = ret.writeFloatLE(o.deg, offset);
		offset = ret.writeFloatLE(o.reflexion, offset);
		offset = ret.writeFloatLE(o.refraction, offset);
		offset = ret.writeFloatLE(o.pos[0], offset);
		offset = ret.writeFloatLE(o.pos[1], offset);
		offset = ret.writeFloatLE(o.pos[2], offset);
		offset = ret.writeFloatLE(o.rot[0], offset);
		offset = ret.writeFloatLE(o.rot[1], offset);
		offset = ret.writeFloatLE(o.rot[2], offset);
		offset = ret.writeFloatLE(o.max[0], offset);
		offset = ret.writeFloatLE(o.max[1], offset);
		offset = ret.writeFloatLE(o.max[2], offset);
		offset = ret.writeFloatLE(o.min[0], offset);
		offset = ret.writeFloatLE(o.min[1], offset);
		offset = ret.writeFloatLE(o.min[2], offset);
		offset = ret.writeUInt8(o.color[0], offset);
		offset = ret.writeUInt8(o.color[1], offset);
		offset = ret.writeUInt8(o.color[2], offset);
		offset = ret.writeUInt8(o.color[3], offset);
		if (o.texture) {
			offset = ret.writeUInt8(1, offset);
			ret.write(o.texture, offset, 1024);
			offset += 1024;
		} else
			offset = ret.writeUInt8(0, offset);
	}
	for (var i in obj.light)
	{
		var o = obj.light[i];
		offset = ret.writeFloatLE(o.pos[0], offset);
		offset = ret.writeFloatLE(o.pos[1], offset);
		offset = ret.writeFloatLE(o.pos[2], offset);
		offset = ret.writeUInt8(o.color[0], offset);
		offset = ret.writeUInt8(o.color[1], offset);
		offset = ret.writeUInt8(o.color[2], offset);
		offset = ret.writeUInt8(o.color[3], offset);
	}
	offset = ret.writeFloatLE(obj.camera.pos[0], offset);
	offset = ret.writeFloatLE(obj.camera.pos[1], offset);
	offset = ret.writeFloatLE(obj.camera.pos[2], offset);
	offset = ret.writeFloatLE(obj.camera.dir[0], offset);
	offset = ret.writeFloatLE(obj.camera.dir[1], offset);
	offset = ret.writeFloatLE(obj.camera.dir[2], offset);
	return (ret);
}

function program_output(opts, obj)
{
	if (opts.out != null && opts.redirect == true) {
		fs.writeFile(opts.out, get_buffer(obj), function(err) {
		    if(err) {
		        return console.log(err);
		    }
		})
	}
	else if (opts.live == false)
		process.stdout.write(get_buffer(obj));
	else
		print_stats(obj);
}

function help(type)
{
	color = false;
	if (type === undefined || type =="full")
		glob.help['']();
	if (type !== undefined && glob.help[type] !== undefined)
	{
		console.log("\n------------------------------------------------\n");
		glob.help[type]();
	}
	console.log("\n------------------------------------------------\n");
}
