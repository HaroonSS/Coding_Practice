class Solution {
public:
    void generateCombinations(int index, string &digits, string &current, vector<string> &result, vector<string> &digitToLetters) {
        // Base case: if the current combination's length matches the input length
        if (index == digits.size()) {
            result.push_back(current);
            return;
        }

        // Get the possible letters for the current digit
        string letters = digitToLetters[digits[index] - '0'];
        for (char letter : letters) {
            current.push_back(letter); // Add the current letter
            generateCombinations(index + 1, digits, current, result, digitToLetters); // Recur for the next digit
            current.pop_back(); // Backtrack
        }
    }

    vector<string> letterCombinations(string digits) {
        if (digits.empty()) return {}; // Edge case: empty input
        
        // Map of digits to corresponding letters
        vector<string> digitToLetters = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        vector<string> result;
        string current;

        // Start generating combinations
        generateCombinations(0, digits, current, result, digitToLetters);
        return result;
    }
};
