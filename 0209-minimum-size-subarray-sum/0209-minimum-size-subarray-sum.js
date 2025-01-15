/**
 * @param {number} target
 * @param {number[]} nums
 * @return {number}
 */
/**
 * @param {number} target
 * @param {number[]} nums
 * @return {number}
 */
var minSubArrayLen = function(target, nums) {
    let left = 0;
    let currSum = 0;
    let minLen = Infinity;

    for (let right = 0; right < nums.length; right++) {
        currSum += nums[right];

        // Shrink the window from the left while the sum is >= target
        while (currSum >= target) {
            minLen = Math.min(minLen, right - left + 1);
            currSum -= nums[left];
            left++;
        }
    }

    return minLen === Infinity ? 0 : minLen;
};




 /*
var minSubArrayLen = function(target, nums) {
    let minLen = Infinity; // Start with a very large value
    for (let i = 0; i < nums.length; i++) {
        let currSum = 0;
        for (let j = i; j < nums.length; j++) {
            currSum += nums[j];
            if (currSum >= target) { // Check for >= target
                minLen = Math.min(minLen, j - i + 1);
                break; // No need to check longer subarrays for this `i`
            }
        }
    }
    return minLen === Infinity ? 0 : minLen; // If no valid subarray, return 0
};*/
