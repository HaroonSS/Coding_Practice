var calculate = function(s) {
    let stack = [];
    let num = 0;
    let sign = '+';

    for (let i = 0; i < s.length; i++) {
        let ch = s[i];

        if (ch >= '0' && ch <= '9') {
            num = num * 10 + (ch - '0');
        }

        // If operator or end of string
        if ((ch < '0' || ch > '9') && ch !== ' ' || i === s.length - 1) {
            if (sign === '+') {
                stack.push(num);
            } else if (sign === '-') {
                stack.push(-num);
            } else if (sign === '*') {
                stack.push(stack.pop() * num);
            } else if (sign === '/') {
                let prev = stack.pop();
                stack.push(Math.trunc(prev / num)); // truncate toward 0
            }

            sign = ch;
            num = 0;
        }
    }

    // Sum everything
    return stack.reduce((a, b) => a + b, 0);
};/*

---

# Simple Explanation

* Build full number (`num`)
* On operator:

  * `+` → push num
  * `-` → push -num
  * `*` → pop, multiply, push back
  * `/` → pop, divide, push back
* Final answer = sum of stack

---

# Tiny Example (Short)

```
s = "3+2*2"

3     → push 3
2*2   → pop 3? no → pop 2 → 2*2 = 4
stack = [3, 4]

Answer = 7
```
* and / resolve immediately, + and - go to stack
*/