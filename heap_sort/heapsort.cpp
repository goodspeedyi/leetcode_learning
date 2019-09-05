#include <iostream>
#include <vector>

void percolatedown()
{
    
}

void heapsort( std::vector<int> &arr )
{
    // build heap
    for( int i = 1 ; i < arr.size() ; ++i  )
    {
        // percolate up
        int tmp = std::move( arr[i] );
        int j = i + 1 ;
        for( ; j > 0 ; j /= 2 )
        {
            if( arr[j/2-1] < tmp )
                arr[j-1] = std::move( arr[j/2-1] ) ; 
            else
                break ;
        }
        arr[j-1] = tmp ;
    }

    // sort heap
    int currentsize = arr.size() ;
    for( int i = 0 ; i < arr.size()-1 ; ++i )
    {
        // percolate down
        int tmp = std::move( arr[0] );
        int tail = std::move( arr[currentsize-1] ) ;
        int j = 1 ;
        for( ; j < currentsize-1 ;  )
        {
            int childr = j * 2 ;
            int maxchild ;
            if( childr > currentsize )
                break ;
            else if( ( childr + 1 ) > currentsize )
                maxchild = arr[childr-1] ;
            else
                maxchild = arr[childr-1] > arr[childr] ? arr[childr-1] : arr[childr] ;

            if( tail > maxchild )
                break ;

            if( arr[childr-1] > arr[childr] )
            {
                arr[j-1] = std::move( arr[childr-1] );
                j = childr ;
            }
            else
            {
                arr[j-1] = std::move( arr[childr] ) ;
                j = childr + 1;
            }
        }
        arr[j-1] = tail ;
        arr[currentsize-1] = tmp ;    
        --currentsize ;
    }
    
} 

int main()
{
    // [13,21,16,24,31,19,68,65,26,32]
    std::vector<int> cor={13,21,16,24,31,19,68,65,26,32};
    std::vector<int> arr={ 13,65,26,32,24,31,19,16,68,21 };
    for( auto x : cor )
        std::cout << x << "  " ;
    std::cout << std::endl ;

    heapsort( arr );
    for( auto x : arr )
        std::cout << x << "  " ;
    std::cout << std::endl ;
}
