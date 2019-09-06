struct Comp
{
    bool operator()( const std::pair<int, int> &i, const std::pair<int, int> &j ) { return i.first < j.first ; }
};

class Solution {
public:
    vector<vector<int>> allCellsDistOrder(int R, int C, int r0, int c0) {
        std::vector<std::pair<int, int>> dists ;
        std::vector<vector<int>> exact ;
        //std::vector<std::pair<int, std::vector<int>>> dists ;

        int icount = 0 ;
        for( int i = 0 ; i < R ; ++i )
            for( int j = 0 ; j < C ; ++j )
            {
                dists.push_back( std::pair<int,int>( std::abs(i-r0)+std::abs(j-c0), icount++ ) ) ;
                exact.push_back( std::vector<int>{ i, j } ) ;
            }

        std::sort( dists.begin(), dists.end(), Comp() );

        vector<vector<int>> ret ;
        for( auto x : dists)
            ret.push_back( std::move( exact[x.second] ) );

        return ret ;
    }
};



