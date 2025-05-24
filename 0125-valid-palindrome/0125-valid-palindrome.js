/**
 * @param {string} s
 * @return {boolean}
 */
// var isPalindrome = function(s) {
//     const tempStr = s.replace(/[^a-zA-Z0-9]/g, '').toLowerCase()
//     return tempStr === tempStr.split('').reverse().join('')
    
// };

var isPalindrome = function(s) {
    const tempStr = s.replace(/[^a-zA-Z0-9]/g, '').toLowerCase()
    let left = 0, right = tempStr.length-1

    while(left < right){
        if (tempStr[left++] !== tempStr[right--])
        return false
    }
    return true
    
};