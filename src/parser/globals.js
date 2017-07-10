/*
** globals.js for raytracer1 in /Infographie/raytracer1/parser
**
** Made by Thomas Lombard
** Login   <lombar_e@epitech.net>
**
** Started on  Mon Feb 20 11:20:13 2017 Thomas Lombard
** Last update Sun May 14 01:24:40 2017 Thomas Lombard
*/

const gry='\x1b[1;30m'
const red='\x1b[0;31m'
const grn='\x1b[0;32m'
const yel='\x1b[0;33m'
const blu='\x1b[0;34m'
const pnk='\x1b[0;35m'
const cyn='\x1b[0;36m'
const wht='\x1b[0;37m'
const nrm='\x1b[m'

/*
**     ${yel}"config":{
**	    ${yel}cluster${nrm}:${yel}false${nrm},
**	    ${yel}threads${nrm}:${yel}true${nrm},
**	    ${yel}aliasing${nrm}:${yel}4${nrm},
**    ${yel}},${nrm}
*/

function json(language)
{
	console.log(`
Syntaxe des fichiers JSON :

Les options peuvent être les suivantes et s'appliquent sur tout les objets avec ou sans effet :

     radius: <Float | Integer> (Requis pour certaines formes)
     angle: <Float | Integer> (Requis pour certaines formes)
     reflexion:  [0]	   -> Coeficient de réflexion
     refraction: [0]	   -> Coeficient de réflexion
     pos:	 [0, 0, 0] -> <Float[3] | Integer[3]>
     rot:	 [0, 0, 0] -> <Float[3] | Integer[3]>
     max:	 [0, 0, 0] -> <Float[3] | Integer[3]>
     min:	 [0, 0, 0] -> <Float[3] | Integer[3]>
     color:	 [0, 0, 0] -> <Integer[3] 0 -> 255>

Voici un fichier d'exemple :
{
    ${grn}"name"${nrm}: ${grn}"example_map"${nrm},
    ${grn}geometry${nrm}: [
	${grn}{${grn}"type"${yel}:"cylindre", ${grn}"radius"${yel}:30${grn}}${nrm},
	${yel}{${grn}"type"${yel}:"sphere", ${grn}"radius"${yel}:30}${nrm},
	${yel}{${grn}"type"${yel}:"cone", ${grn}"angle"${yel}:40, "rot":[20, 160, 0], "min":[10, 300, 100]}${nrm},
	${yel}{${grn}"type"${yel}:"plan", "pos":[0, 0, -300]}${nrm},
    ],
    ${yel}lights${nrm}: [ ${yel}{${grn}color${yel}: [255, 0, 0], ${grn}pos${yel}: [0, 0, 0], ${yel}rot${yel}: [0, 0, 0]}${nrm} ],
}`);
}

function ply()
{
	console.log(`
Les fichiers ply sont des fichiers de sortie de blender. Vous pouvez obtenir des scnènes avancées pour le rt via Blender`);
}

function int()
{
	console.log(`
Int est un type de donnée. C'est forcément un nombre entier compris entre -2147483648 et 2147483647 (0xFFFFFFFF)`);
}

function float()
{
	console.log(`
Float est un type de donnée. C'est un nombre qui peut être ddécimal`);
}

function vector()
{
	console.log(`
Vector est un format de donnée. Il définit un vecteur par 3 points. Ces derniers peuvent être de type int ou float.
	Ils sont constitués de 3 coordonnées : x y et z respectivement.`)
}

function color()
{
	console.log(`
Une couleur est une série de composantes définissant la valeur de rouge, de vert et de bleu. Cela peut se présenter sous ces formes :
	- 0xRRggBB        -> Hexa classique : 2 digits par composante
	- 0xRgB           -> Hexa contracté : 1 digit par composante. (note, les digits sont doublés : 0xFF9911 => OxF91)
	- [int, int, int] -> RgB            : Un int de 0 à 255 par composante`)
}

function color_code(language) {
	console.log(`	Code couleur :
	En ${red}rouge${nrm} : Non supporte actuellement
	En ${yel}jaune${nrm} : Optionnel
	En ${grn}vert${nrm}  : Requis`)
};

function help() {
	console.log(`Usage : \n\tnode parser.js [OPTIONS] <file_to_parse.(json|ply)>
	Options :
	-l | --live [yes|no]        : Lance le parseur en mode live ou non (utilisé pour l'interfacement avec le rt)
	-f | --file [out]           : Compile dans un fichier portant le meme nom ou 'out' quand spécifié mais suivi de .rt
	-h | --help [json|ply|int|float|vector|color|full] : Affiche une aide complète avec exemples`);
}

module.exports.help_json = json;
module.exports.help = {'':help, 'json':json, 'ply':ply, 'int':int, 'float':float, 'vector':vector, 'color':color}
module.exports.color_code = color_code;
