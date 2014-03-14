// Insert Interval 
// Given a set of non-overlapping intervals, insert a new interval into the intervals (merge if necessary).
// 
// You may assume that the intervals were initially sorted according to their start times.
// 
// Example 1:
// Given intervals [1,3],[6,9], insert and merge [2,5] in as [1,5],[6,9].
// 
// Example 2:
// Given [1,2],[3,5],[6,7],[8,10],[12,16], insert and merge [4,9] in as [1,2],[3,10],[12,16].
// 
// This is because the new interval [4,9] overlaps with [3,5],[6,7],[8,10].
//

// An O(n) complexity
bool myCompare(const Interval &i1, const Interval &i2)
{
    return i1.start < i2.start;
}

vector<Interval> insert(vector<Interval> &intervals, Interval newInterval)
{
    if (intervals.size() == 0) return {newInterval};

    vector<Interval> result;
    for (int i = 0; i < intervals.size(); ++i)
    {
        if (intervals[i].end < newInterval.start || intervals[i].start > newInterval.end)
        {
            result.push_back(intervals[i]);
            continue;
        }
        
        if (intervals[i].start < newInterval.start)
            newInterval.start = intervals[i].start;
        if (intervals[i].end > newInterval.end)
            newInterval.end = intervals[i].end;
    }
    result.push_back(newInterval);
    
    std::sort(result.begin(), result.end(), myCompare);

    return result;
}

// TODO: O(lgn) complexity, binary search
