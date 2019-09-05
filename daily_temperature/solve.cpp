class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& T) {
        vector<int> waitday( T.size(), 0 ) ;
        stack<int> nonwarmday;
        
        for( int i = 0 ; i < T.size()-1 ; ++i )
        {
            if( T[i+1] > T[i] )
            {
                waitday[i] = 1 ;
                
                while( !nonwarmday.empty() )
                {
                    auto cur = nonwarmday.top() ;
                    if( T[i+1] > T[cur] )
                    {
                        waitday[cur] = i + 1 - cur ;
                        nonwarmday.pop() ;
                    }
                    else
                        break ;
                }
            }
            else
                nonwarmday.push( i );
        }
        
        return waitday ;
    }
};
