/**
 * @param {number[]} nums
 * @return {number[]}
 */
var constructTransformedArray = function(nums) {
    const result = []
    const numsLength = nums.length
    for(let i =0; i< numsLength; i++) {
        if(nums[i] > 0) {
        result[i] = nums[(i+nums[i])%numsLength]
        } else if (nums[i] < 0) {
            const index = (i-Math.abs(nums[i])) < 0 ? ((i-Math.abs(nums[i]))%numsLength + numsLength)%numsLength : (i-Math.abs(nums[i]))
        result[i] = nums[index]
        } else {
    result[i] = nums[i]
        }
    }

    return result
};