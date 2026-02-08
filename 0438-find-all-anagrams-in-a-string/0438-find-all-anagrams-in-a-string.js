/**
 * @param {string} s
 * @param {string} p
 * @return {number[]}
 */
function findAnagrams(s, p) {
  const res = [];
  if (p.length > s.length) return res;

  const freqP = new Array(26).fill(0);
  const freqS = new Array(26).fill(0);
  const offset = 'a'.charCodeAt(0);

  // Build frequency for p
  for (let ch of p) {
    freqP[ch.charCodeAt(0) - offset]++;
  }

  let left = 0;

  for (let right = 0; right < s.length; right++) {
    // Add right char to window
    freqS[s.charCodeAt(right) - offset]++;

    // Keep window size == p.length
    if (right - left + 1 > p.length) {
      freqS[s.charCodeAt(left) - offset]--;
      left++;
    }

    // Compare both freq arrays
    if (right - left + 1 === p.length && isSame(freqP, freqS)) {
      res.push(left);
    }
  }

  return res;
}

// Helper to compare 26-sized arrays
function isSame(a, b) {
  for (let i = 0; i < 26; i++) {
    if (a[i] !== b[i]) return false;
  }
  return true;
}
