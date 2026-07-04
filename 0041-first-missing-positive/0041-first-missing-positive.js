var firstMissingPositive = function (nums) {
    let n = nums.length;
    const seen = new Array(n + 1).fill(false); // Array for lookup
    // Mark the elements from nums in the lookup array
    for (const num of nums) {
        if (num > 0 && num <= n) {
            seen[num] = true;
        }
    }
    // Iterate through integers 1 to n
    // return smallest missing positive integer
    for (let i = 1; i <= n; i++) {
        if (!seen[i]) {
            return i;
        }
    }
    // If seen contains all elements 1 to n
    // the smallest missing positive number is n + 1
    return n + 1;
};