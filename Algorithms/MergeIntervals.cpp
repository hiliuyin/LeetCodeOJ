// Merge Intervals
// Given a collection of intervals, merge all overlapping intervals.
// 
// For example,
// Given [1,3],[2,6],[8,10],[15,18],
// return [1,6],[8,10],[15,18].

// sort, then merge
bool myCompare(const Interval &i1, const Interval &i2)
{
    return i1.start < i2.start;
}

vector<Interval> merge(vector<Interval> &intervals) 
{
    if (intervals.size() <= 1) return intervals;
    
    std::sort(intervals.begin(), intervals.end(), myCompare);
    
    vector<Interval> result;
    Interval dummy{intervals[0]};
    for (int i = 1; i < intervals.size(); ++i)
    {
        if (dummy.end >= intervals[i].start)
        {
            if (dummy.end < intervals[i].end)
                dummy.end = intervals[i].end;
        }
        else
        {
            result.push_back(dummy);
            dummy = intervals[i];
        }
    }
    result.push_back(dummy);
    
    return result;
}
