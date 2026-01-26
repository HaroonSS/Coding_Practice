/**
 * @param {number[]} arr
 * @return {number[][]}
 */
var minimumAbsDifference = function(arr) {

    arr.sort((a,b) => a-b)

    let minDiff = Infinity
        for(let i =1; i< arr.length; i++) {
        if(Math.abs(arr[i-1]-arr[i]) < minDiff) {
            minDiff = Math.abs(arr[i-1]-arr[i])
        }
    }

const result = []
    for(let i =1; i<arr.length; i++) {
        if(Math.abs(arr[i-1]-arr[i]) === minDiff) {
            result.push([arr[i-1],arr[i]])
        }
    }
    return result
};