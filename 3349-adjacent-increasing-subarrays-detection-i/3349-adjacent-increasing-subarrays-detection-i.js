function isStrictlyIncreasing(nums, start, k) {
    for (let i = start; i < start + k - 1; i++) {
        if (nums[i] >= nums[i + 1]) return false;
    }
    return true;
}

function hasIncreasingSubarrays(nums, k) {
    const n = nums.length;
    if (n < 2 * k) return false;

    for (let i = 0; i <= n - 2 * k; i++) {
        if (isStrictlyIncreasing(nums, i, k) && isStrictlyIncreasing(nums, i + k, k)) {
            return true;
        }
    }

    return false;
}