/**
 * @param {number[][]} times
 * @param {number} n
 * @param {number} k
 * @return {number}
 */
var networkDelayTime = function(times, n, k) {
    const dist = new Array(n + 1).fill(Infinity);
    dist[k] = 0;

    for (let i = 1; i < n; i++) {
        for (const [u, v, w] of times) {
            if (dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
            }
        }
    }

    const res = Math.max(...dist.slice(1));
    return res === Infinity ? -1 : res;
};