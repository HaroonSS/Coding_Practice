var countAndSay = function(n) {
    let s = "1";   // base case

    for (let i = 2; i <= n; i++) {
        let result = "";
        let count = 1;

        for (let j = 1; j <= s.length; j++) {
            // If same char, keep counting
            if (j < s.length && s[j] === s[j - 1]) {
                count++;
            } else {
                // Say the count and the digit
                result += count + s[j - 1];
                count = 1;
            }
        }

        s = result; // move to next term
    }

    return s;
};
