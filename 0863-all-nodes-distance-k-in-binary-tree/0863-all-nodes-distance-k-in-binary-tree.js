/**
 * Definition for a binary tree node.
 * function TreeNode(val) {
 *     this.val = val;
 *     this.left = this.right = null;
 * }
 */
/**
 * @param {TreeNode} root
 * @param {TreeNode} target
 * @param {number} k
 * @return {number[]}
 */
var distanceK = function(root, target, k) {

    // Step 1: Build parent map
    const parentMap = new Map();

    function buildParent(node, parent) {
        if (!node) return;

        if (parent) {
            parentMap.set(node, parent);
        }

        buildParent(node.left, node);
        buildParent(node.right, node);
    }

    buildParent(root, null);

    // Step 2: BFS from target
    const queue = [target];
    const visited = new Set();
    visited.add(target);

    let distance = 0;

    while (queue.length > 0) {
        const size = queue.length;

        if (distance === k) {
            return queue.map(node => node.val);
        }

        for (let i = 0; i < size; i++) {
            const node = queue.shift();

            const neighbors = [
                node.left,
                node.right,
                parentMap.get(node)
            ];

            for (let neighbor of neighbors) {
                if (neighbor && !visited.has(neighbor)) {
                    visited.add(neighbor);
                    queue.push(neighbor);
                }
            }
        }

        distance++;
    }

    return [];
};