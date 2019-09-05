class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& T) {
        vector<int> waitday( T.size(), 0 ) ;
        stack<int> warmerday;
        
        for( int i = T.size()-1; i>-1 ; --i )
        {
            while( !warmerday.empty() and T[i] >= T[warmerday.top()] )
                warmerday.pop() ;
            
            if( warmerday.empty() )
                waitday[i] = 0 ;
            else
                waitday[i] = warmerday.top() - i ;
            
            warmerday.push( i );
        }
        
        return waitday ;
    }
};
