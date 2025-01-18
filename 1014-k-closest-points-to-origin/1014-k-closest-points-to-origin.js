/**
 * @param {number[][]} points
 * @param {number} k
 * @return {number[][]}
 */
var kClosest = function(points, k) {
    // Calculate distance and store points with their distance
    return points
        .map(point => [point, point[0] ** 2 + point[1] ** 2]) // Pair points with their distances
        .sort((a, b) => a[1] - b[1]) // Sort by distance
        .slice(0, k) // Take the first k elements
        .map(pair => pair[0]); // Extract points
};
