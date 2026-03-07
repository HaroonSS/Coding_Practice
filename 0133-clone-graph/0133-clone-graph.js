/**
 * // Definition for a _Node.
 * function _Node(val, neighbors) {
 *    this.val = val === undefined ? 0 : val;
 *    this.neighbors = neighbors === undefined ? [] : neighbors;
 * };
 */

/**
 * @param {_Node} node
 * @return {_Node}
 */
function cloneGraph(node) {
    if (!node) return null;

    const map = new Map();
    const queue = [node];

    map.set(node, { val: node.val, neighbors: [] });

    while (queue.length) {
        const curr = queue.shift();

        for (let neighbor of curr.neighbors) {

            if (!map.has(neighbor)) {
                map.set(neighbor, { val: neighbor.val, neighbors: [] });
                queue.push(neighbor);
            }

            map.get(curr).neighbors.push(map.get(neighbor));
        }
    }

    return map.get(node);
}