class Solution {
public:
    int countDaysTogether(string arriveAlice, string leaveAlice, string arriveBob, string leaveBob) {
        int start = max(stoi( arriveBob.substr(0,2))*100 + stoi( arriveBob.substr(3))  , stoi( arriveAlice.substr(0,2))*100 + stoi( arriveAlice.substr(3)));

        int end = min(stoi( leaveBob.substr(0,2))*100 + stoi( leaveBob.substr(3))  , stoi( leaveAlice.substr(0,2))*100 + stoi( leaveAlice.substr(3)));

        if(start > end ) return 0;
        vector<int>day={31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        int ms = start / 100;
        int ds = start % 100;
        int me = end /100;
        int de = end% 100;
 
        if( ms==me) return de - ds +1;
        int ans = day[ms-1] - ds + 1;
        ms++;
        while( ms != me ){
            ans= ans+ day[ms-1];
            ms++;
        }
        ans = ans + de;
        return ans;
    }
};