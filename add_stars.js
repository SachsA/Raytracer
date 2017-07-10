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

var map = require(`./${process.argv[2]}`);
var obj = map.geometry;

const gry='\x1b[1;30m'
const red='\x1b[0;31m'
const grn='\x1b[0;32m'
const yel='\x1b[0;33m'
const blu='\x1b[0;34m'
const pnk='\x1b[0;35m'
const cyn='\x1b[0;36m'
const wht='\x1b[0;37m'
const nrm='\x1b[m'

Array.prototype.checkExist = function (b) {
	if (b instanceof Array)
	{
		if (this[0] == b[0] && this[1] == b[1] && this[2] == b[2])
			return true
		else
			return false
	}
	else
		return false
};

function pos_exists(array, pos)
{
	for (var i = 12; i < array.length; ++i)
	{
		if (array[i].pos.checkExist(pos))
			return false
	}
}

function getRand (min = -5000, max = 5000) {
	return Math.round(Math.random() * (max - min) + min);
};

var nw;
for (var i = 0; i < 3000; ++i)
{
	var color = getRand(150, 255);
	nw = {"type":"sphere", "radius":5, "pos":[getRand(-400), getRand(), getRand()], "color":[color, color, color], "refraction":1}
	while (pos_exists(obj, nw.pos))
	{
		nw = {"type":"sphere", "radius":5, "pos":[getRand(-400), getRand(), getRand()], "color":[color, color, color], "refraction":1}
	}
	obj[obj.length] = nw;
}

map.geometry = obj;
console.log(JSON.stringify(map));
