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
/*

```
Example (n = 5):

1
11      (one 1)
21      (two 1s)
1211    (one 2, one 1)
111221  (one 1, one 2, two 1s)


Read previous string → count consecutive digits → write count + digit
```
*/
