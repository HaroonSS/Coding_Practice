var findMedianSortedArrays = function (nums1, nums2) {
    let m = nums1.length,
        n = nums2.length;
    let p1 = 0,
        p2 = 0;

    let getMin = function () {
        if (p1 < m && p2 < n) {
            return nums1[p1] < nums2[p2] ? nums1[p1++] : nums2[p2++];
        } else if (p1 < m) {
            return nums1[p1++];
        } else if (p2 < n) {
            return nums2[p2++];
        }
        return -1;
    };

    if ((m + n) % 2 === 0) {
        for (let i = 0; i < (m + n) / 2 - 1; ++i) {
            let temp = getMin();
        }
        return (getMin() + getMin()) / 2.0;
    } else {
        for (let i = 0; i < Math.floor((m + n) / 2); ++i) {
            let temp = getMin();
        }
        return getMin();
    }
};