var insert = function(intervals, newInterval) {
    let res = [];
    let i = 0;

    // 1️ Add all intervals that END before newInterval STARTS
    // No overlap possible here
    while (i < intervals.length && intervals[i][1] < newInterval[0]) {
        res.push(intervals[i]);
        i++;
    }
    // 2️ Merge all intervals that OVERLAP with newInterval
    // Overlap condition:
    // current.start <= newInterval.end
    while (i < intervals.length && intervals[i][0] <= newInterval[1]) {
        // Expand newInterval to include current interval
        newInterval[0] = Math.min(newInterval[0], intervals[i][0]);
        newInterval[1] = Math.max(newInterval[1], intervals[i][1]);
        i++;
    }
    // 3️ Add the merged newInterval
    res.push(newInterval);

    // 4️ Add all remaining intervals
    while (i < intervals.length) {
        res.push(intervals[i]);
        i++;
    }
    return res;
};/*

### Example

```
intervals = [[1,3], [6,9]]
newInterval = [2,5]
```

### What happens

```
[1,3] overlaps with [2,5]  → merge → [1,5]
[6,9] does NOT overlap     → stop merging
Insert merged interval
Add remaining [6,9]
```

### Final Answer

```
[[1,5], [6,9]]
```

### Memory Hook 🧠

```
Overlap if: current.start <= new.end
```
*/