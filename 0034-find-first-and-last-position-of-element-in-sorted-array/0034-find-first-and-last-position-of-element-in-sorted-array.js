/**
 * @param {number[]} nums
 * @param {number} target
 * @return {number[]}
 */
function searchRange(nums, target) {
  return [find(true), find(false)];

  function find(isFirst) {
    let l = 0, r = nums.length - 1, idx = -1;

    while (l <= r) {
      const mid = Math.floor((l + r) / 2);

      if (nums[mid] === target) {
        idx = mid;
        if (isFirst) r = mid - 1;
        else l = mid + 1;
      } else if (nums[mid] < target) {
        l = mid + 1;
      } else {
        r = mid - 1;
      }
    }

    return idx;
  }
}
