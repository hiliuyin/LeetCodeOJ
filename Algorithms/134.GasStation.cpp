/*
There are N gas stations along a circular route, where the amount of gas at station i is gas[i].
You have a car with an unlimited gas tank and it costs cost[i] of gas to travel from station i to its next station (i+1).
You begin the journey with an empty tank at one of the gas stations.
Return the starting gas station's index if you can travel around the circuit once, otherwise return -1.

Note:
The solution is guaranteed to be unique.
*/

int canCompleteCircuit(std::vector<int>& gas, std::vector<int>& cost)
{
    if (gas.size() != cost.size()) return -1;
    
    const int stationNum = (int)gas.size();
    int startingStation = -1;
    for (int i = 0; i < stationNum; )
    {
        if (gas[i] - cost[i] < 0)
        {
            ++i;
            continue;
        }
        
        startingStation = i;
        int k = startingStation;
        int netGas = 0;
        for (;;)
        {
            netGas += gas[k%stationNum] - cost[k%stationNum];
            
            if (netGas < 0)
            {
                i = k+1;
                break;
            }
            
            ++k;
            if (k%stationNum == startingStation)
            {
                return startingStation;
            }
        }
    }
    
    return -1;
}
