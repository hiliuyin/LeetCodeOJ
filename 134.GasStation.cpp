/*
There are N gas stations along a circular route, where the amount of gas at station i is gas[i].
You have a car with an unlimited gas tank and it costs cost[i] of gas to travel from station i to its next station (i+1).
You begin the journey with an empty tank at one of the gas stations.
Return the starting gas station's index if you can travel around the circuit once, otherwise return -1.

Note:
The solution is guaranteed to be unique.
*/




int canCompleteCircuit(vector<int> &gas, vector<int> &cost)
{
    if (gas.size() != cost.size()) return -1;

    int stationNum = (int)gas.size();
    
    std::vector<int> gasRemaining;
    for (int i = 0; i < gas.size(); ++i)
    {
        gasRemaining.push_back(gas[i] - cost[i]);
    }

    bool founded = false;
    int startingStation = -1;

    for (int j = 0; j < stationNum; )
    {
        if (gasRemaining[j] < 0)
        {
            ++j;
            continue;
        }
        
        startingStation = j;
        int k = startingStation;
        int netGas = 0;
        do
        {
            netGas += gasRemaining[k];
            
            if (netGas < 0)
            {
                j = k+1;
                break;
            }
            
            ++k;
            k = (k >= stationNum) ? (k%stationNum) : k;
            
            if (k == startingStation)
            {
                founded = true;
                break;
            }
        } while (true);
        
        if (founded)
            break;
    }
    
    return founded ? startingStation : (-1);
}
