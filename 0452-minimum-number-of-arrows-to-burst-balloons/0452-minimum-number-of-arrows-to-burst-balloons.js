/**
 * @param {number[][]} points
 * @return {number}
 */
var findMinArrowShots = function(points) {
    if (points.length === 0) return 0;

    // Sort balloons by their ending points
    points.sort((a, b) => a[1] - b[1]);

    let arrows = 1; // Start with one arrow
    let currentEnd = points[0][1]; // Position of the first arrow

    for (let i = 1; i < points.length; i++) {
        // If the current balloon starts after the last arrow position
        if (points[i][0] > currentEnd) {
            arrows++; // Need a new arrow
            currentEnd = points[i][1]; // Update arrow position
        }
    }

    return arrows;
};
