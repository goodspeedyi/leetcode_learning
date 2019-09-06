struct Comp
{
    bool operator()( const std::pair<int, std::vector<int>> &i, const std::pair<int, std::vector<int>> &j ) { return i.first < j.first ; }
};

class Solution {
public:
    vector<vector<int>> allCellsDistOrder(int R, int C, int r0, int c0) {
        std::vector<std::pair<int, std::vector<int> > > dists ;

        for( int i = 0 ; i < R ; ++i )
            for( int j = 0 ; j < C ; ++j )
                dists.push_back(
                        std::pair<int, vector<int>>(
                        std::abs(i-r0)+std::abs(j-c0), vector<int>{i,j} )
                        );

        std::sort( dists.begin(), dists.end(), Comp() );

        vector<vector<int>> ret ;
        for( auto x : dists)
            ret.push_back( x.second );

        return ret ;
    }
};



