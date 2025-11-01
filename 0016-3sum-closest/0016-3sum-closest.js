/**
 * @param {number[]} nums
 * @param {number} target
 * @return {number}
 */
function threeSumClosest(nums, target) {
  nums.sort((a, b) => a - b); // Step 1: Sort the array
  let closestSum = Infinity;

  for (let i = 0; i < nums.length - 2; i++) {
    let left = i + 1;
    let right = nums.length - 1;

    while (left < right) {
      const sum = nums[i] + nums[left] + nums[right];

      // Step 2: Update closest sum if found closer
      if (Math.abs(target - sum) < Math.abs(target - closestSum)) {
        closestSum = sum;
      }

      // Step 3: Move pointers based on comparison
      if (sum < target) {
        left++;
      } else if (sum > target) {
        right--;
      } else {
        return sum; // Exact match found
      }
    }
  }

  return closestSum;
}
