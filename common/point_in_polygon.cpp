// https://observablehq.com/@tmcw/understanding-point-in-polygon

module.exports = function (point, vs) {
    // ray-casting algorithm based on
    // http://www.ecse.rpi.edu/Homepages/wrf/Research/Short_Notes/pnpoly.html

    var x = point[0], y = point[1];

    var inside = false;
    for (var i = 0, j = vs.length - 1; i < vs.length; j = i++) {
        var xi = vs[i][0], yi = vs[i][1];
        var xj = vs[j][0], yj = vs[j][1];

        var intersect = ((yi > y) != (yj > y))
            && (x < (xj - xi) * (y - yi) / (yj - yi) + xi);
        if (intersect) inside = !inside;
    }

    return inside;
};

/*

The gist of this solution to the the Point in Polygon problem is:

1. Cast a ray (essentially ‘draw a line’) from the left side of the drawing until it hits the point.
2. Count the number of edges it crosses before it gets to the point
3. If that number is odd, then the point is in the polygon. If it's even (including 0) it's not in the polygon.

*/