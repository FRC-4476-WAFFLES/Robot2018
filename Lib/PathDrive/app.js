canvas = document.querySelector('canvas')
ctx = canvas.getContext('2d')

function toRadians(degrees) {
  return degrees * Math.PI / 180
}

function drawVec(fx, fy, tx, ty) {
	const headLen = 5
	let angle = Math.atan2(fy - ty, fx - tx)

	ctx.beginPath()
	ctx.moveTo(fx, fy)
	ctx.lineTo(tx, ty)
	ctx.lineTo(tx + headLen * Math.cos(angle + Math.PI/7), ty + headLen * Math.sin(angle + Math.PI/7))
	ctx.moveTo(tx, ty)
	ctx.lineTo(tx + headLen * Math.cos(angle - Math.PI/7), ty + headLen * Math.sin(angle - Math.PI/7))
	ctx.stroke()
}

function drawPathPoint(point) {
	drawVec(point.x, point.y,
		point.x + point.weight * Math.cos(toRadians(point.angle)),
		point.y + point.weight * Math.sin(toRadians(point.angle)))
}

function bezierFromSegments(fromSeg, toSeg) {
	return [
		{x: fromSeg.x, y: fromSeg.y},
		{x: fromSeg.x + fromSeg.weight * Math.cos(toRadians(fromSeg.angle)),
		 y: fromSeg.y + fromSeg.weight * Math.sin(toRadians(fromSeg.angle))},
		{x: toSeg.x - toSeg.weight * Math.cos(toRadians(toSeg.angle)),
		 y: toSeg.y - toSeg.weight * Math.sin(toRadians(toSeg.angle))},
		{x: toSeg.x, y: toSeg.y}
	]
}

function bezierAt(points, t) {
	let negt = 1-t
	return {
		x: negt*negt*negt*points[0].x +
			3*negt*negt*t*points[1].x +
			3*negt*t*t*points[2].x +
			t*t*t*points[3].x,
		y: negt*negt*negt*points[0].y +
			3*negt*negt*t*points[1].y +
			3*negt*t*t*points[2].y +
			t*t*t*points[3].y,
	}
}

function drawBezier(points) {
	ctx.beginPath()
	ctx.moveTo(points[0].x, points[0].y)

	for(t=0; t<1; t+=0.02) {
		let point = bezierAt(points, t)
		ctx.lineTo(point.x, point.y)
	}

	ctx.lineTo(points[3].x, points[3].y)
	ctx.stroke()
}

function drawSegments(segments) {
	ctx.beginPath()
	ctx.moveTo(segments[0].x, segments[0].y)
	for(segment of segments) {
		ctx.lineTo(segment.x, segment.y)
		ctx.fillRect(segment.x - 2, segment.y - 2, 4, 4);
	}
	ctx.stroke();
}

function drawRobotPath(points) {
	let functions = [
		function(point) {
			ctx.fillStyle = 'green'
			ctx.strokeStyle = 'green'
			return point.left
		},
		function(point) {
			ctx.fillStyle = 'green'
			ctx.strokeStyle = 'green'
			return point.right
		},
		function(point) {
			ctx.fillStyle = 'black'
			ctx.strokeStyle = 'black'
			return {x: (point.left.x + point.right.x)/2, y: (point.left.y +point.right.y)/2}
		},
		function(point) {
			ctx.fillStyle = 'yellow'
			ctx.strokeStyle = 'yellow'
			return point.centre
		},
	]

	function draw() {
		for(func of functions) {
			ctx.beginPath()
			p0 = func(points[0])
			p1 = func(points[1])
			ctx.moveTo(p0.x, p0.y)
			ctx.lineTo(p1.x, p1.y)
			ctx.fillRect(p0.x - 2, p0.y - 2, 4, 4)
			ctx.stroke()
		}
		points = points.slice(1);	
		setTimeout(draw, 50);
	}

	draw();
}

function findClosestT(points, target) {
	let t = 1/2
	let p
	let lastLen = 1000000

	for(i=2; i<10; i++) {
		dt = Math.pow(1/2, i)

		let cand1t = t - dt
		let cand1p = bezierAt(bezier, t)

		let dx = target.x - p.x
		let dy = target.y - p.y
		let len = Math.sqrt(dx*dx + dy*dy)

		if(len < lastLen) {
			t -= dt
			lastLen = len
		} else {
			t += dt
		}
	}

	return p
}

ctx.translate(200, 200)
/*
path = [
	{x: 0  , y: 100, angle: 0, weight: 50},
	{x: 100, y: 0  , angle: 270, weight: 50},
	{x: 0  , y:-100, angle: 180, weight: 50},
	{x:-100, y: 0  , angle: 90, weight: 50},
	{x: 0  , y: 200, angle: 90, weight: 50},
]

ctx.strokeStyle = 'red'

realPath = []

// Generate control points
for(i=0; i<path.length; i++) {
	drawPathPoint(path[i])
	if(i < path.length - 1) {
		realPath.push(bezierFromSegments(path[i], path[i+1]))
	}
}

ctx.strokeStyle = 'blue'
ctx.fillStyle = 'green'
for(seg of realPath) {
	drawBezier(seg)
}*/
