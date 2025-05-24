/**
 * @param {string} s
 * @return {boolean}
 */
var isPalindrome = function(s) {
    const tempStr = s.replace(/[^a-zA-Z0-9]/g, '').toLowerCase()
    return tempStr === tempStr.split('').reverse().join('')
    
};