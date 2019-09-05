class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& T) {
        vector<int> waitday( T.size(), 0 ) ;
        
        for( int i = T.size()-2; i>-1 ; --i )
        {
            for( int j = i + 1; j < T.size() ; j+=waitday[j] )
            {
                if( T[i] < T[j] )
                {
                    waitday[i] = j - i ;
                    break ;
                }
                else if( waitday[j] == 0 )
                    break ;
            }            
        }
        
        return waitday ;
    }
};
