/**
 * @param {string} pattern
 * @param {string} s
 * @return {boolean}
 */
var wordPattern = function(pattern, s) {
    
    let arr = s.split(" ");
    let mapPatternToWord = new Map();
    let mapWordToPattern = new Map();
    
    if (pattern.length !== arr.length) {
        return false;
    }
    
    for (let i = 0; i < pattern.length; i++) {
        const char = pattern[i];
        const word = arr[i];
        
        if ((mapPatternToWord.has(char) && mapPatternToWord.get(char) !== word) ||
            (mapWordToPattern.has(word) && mapWordToPattern.get(word) !== char)) {
            return false;
        }
        
        mapPatternToWord.set(char, word);
        mapWordToPattern.set(word, char);
    }
    
    return true;
};