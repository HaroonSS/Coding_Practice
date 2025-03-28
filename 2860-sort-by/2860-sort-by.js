/**
 * @param {Array} arr
 * @param {Function} fn
 * @return {Array}
 */
const sortBy = function(arr, fn) {
    return arr.sort((x, y) => fn(x)-fn(y))
};