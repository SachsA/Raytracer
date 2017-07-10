module.exports.buffer_hdr = function () {
	var size  = 4;		// Magic number
	size += 20;		// Version du compileur
	size += 512;		// Nom de la scène
	size += 4;		// Nombre d'objets compris dans la scène
	size += 4;		// Nombre de lumières à afficher
	return (size);
}

module.exports.buffer_obj = function () {
	var size  = 4;	// Type d'objet
	size += 4;	// Rayon de l'objet
	size += 4;	// Angle de l'objet
	size += 4;	// Indice de réflexion de l'objet
	size += 4;	// Indice de réfraction de l'objet
	size += 4 * 3;	// Rotation de l'objet (xyz)
	size += 4 * 3;	// Position de l'objet (xyz)
	size += 4 * 3;	// Extremum de l'objet (xyz)
	size += 4 * 3;	// Extremum sup de l'objet (xyz)
	size += 4 * 3;	// Extremum inf de l'objet (xyz)
	size += 1 * 4;	// Couleur de l'objet (xyz)
	size += 1;
	size += 1024;	// Path de la texture
	return (size);
}

module.exports.buffer_lights = function () {
	size  = 4 * 3;	// Position de la lumiere
	size += 1 * 4;	// Couleur de la lumière
	return (size);
}

module.exports.check = function (val) {
	const hex = /^((0x)|(#))([0-9abcdef]{3,6})$/gi
	const rgb = /^([0-9]{1,3}((, )|(,))?){3}$/gi
	if (val instanceof Array == true)
		return (1);
	else if (hex.exec(val))
		return (2);
	else if (rgb.exec(val))
		return (3);
	else
		return (0);
}

module.exports.color_hex = function (val) {
	var hex = val.replace(/(#|0[xX])/g, '');
	if (module.exports.check(val) != 1 || !([3, 6].indexOf(hex.length))) {
		console.error(`La valeur ne correspond à auccun format connu. -h color pour plus d'infos`);
		return (null);
	}
	hex = hex.match(new RegExp(`(.{${hex.length / 3}, })`, 'g'));
	for (var i = 0; i < hex.length; ++i) {
		hex[i] = parseInt(((hex[i].length == 1) ? hex[i] + hex[i] : hex[i]) , 16);
		if (isNaN(hex[i]))
			return (null);
	}
	hex[3] = 255;
	return (hex);
}

module.exports.color_rgb = function (val) {
	if (module.exports.check(val) != 2 || val.length != 3 || val.length != 4) {
		console.error(`La valeur ne correspond à auccun format connu. -h color pour plus d'infos`);
		return (null);
	}
	for (var i = 0; i < 3; ++i) {
		val[i] = parseInt(val[i], 10);
		if (isNaN(val[i]))
			return (null);
	}
	if (val[3] !== undefined) {
		val[3] = parseInt(val[3], 10);
		if (isNaN(val[3]))
			return (null);
	} else {
		val[3] = 255;
	}
	return (val);
}

module.exports.color_arr = function (val) {
	if (val instanceof Array && val.length != 3) {
		console.error(`La valeur ne correspond à auccun format connu. -h color pour plus d'infos`);
		return (null);
	}
	else if (val instanceof Array) {
		if (val[3] === undefined) {
			val[3] = 255;
		}
		return (val);
	}
	rgb = val.split(',');
	for (var i = 0; i < 3; ++i) {
		if (typeof rgb[i] != 'number' || rgb[i] < 0 || rgb[i] > 255)
			return (null);
	}
	if (rgb[3] !== undefined) {
		if (typeof rgb[3] != 'number' || rgb[3] < 0 || rgb[3] > 255)
			return (null);
	}
	return (rgb);
}

module.exports.color = function (val) {
	if (val === undefined)
		return ([255, 255, 255, 255]);
	switch (module.exports.check(val)) {
		case 1:
			return (module.exports.color_arr(val));
		case 2:
			return (module.exports.color_rgb(val));
		case 3:
			return (module.exports.color_hex(val));
		default:
			console.error(`La valeur ne correspond à auccun format connu. -h color pour plus d'infos`);
			return (null);
	}
}

module.exports.texture = function (val) {
	if (val === undefined)
		return (null);
	else if (typeof val === 'string')
		return (val);
	return (null);
}

module.exports.coord = function (val) {
	if (val === undefined)
		return ([0, 0, 0]);
	else if (val instanceof Array);
	else if (typeof val == 'string')
		val = val.split(',');
	else
		return (null);

	if (val.length != 3)
	 	return (null)
	for (var i in val) {
		if (typeof val[i] != 'number') {
			if (isNaN((val[i] = parseFloat(val[i])))) {
				console.error(`La valeur ne correspond à auccun format connu. -h vector pour plus d'infos`);
				return (null);
			}
		}
	}
	return (val);
}

module.exports.float = function (val) {
	const float = /^-?\d+\.?\d*$/

	if (val === undefined)
		return (0.0);
	else if (typeof val == "number")
		return (val);
	else if (typeof val == 'string')
	{
		r = parseFloat(val);
		if (isNaN(r))
			return (null);
		return (r);
	}
	else {
		console.error(`La valeur ne correspond à auccun format connu. -h int pour plus d'infos`);
		return (NaN);
	}
}

module.exports.config = function (val) {
	var ret = {"cluster":false, "threads":false, "aliasing":0};

	if (val === undefined)
		return (ret);
	if (val.cluster !== undefined && val.cluster === Boolean())
		ret.cluster = val.cluster;
	if (val.threads !== undefined && val.cluster === Boolean())
		ret.threads = val.threads;
	if (val.aliasing !== undefined && typeof val.aliasing == 'number')
		ret.aliasing = val.aliasing;
};
