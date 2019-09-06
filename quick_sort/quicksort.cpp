#include <vector>
#include <iostream>

void houtputarr( std::vector<int> &arr, const std::string &info )
{
    std::cout << info << " : " ;
    for( auto x : arr )
        std::cout << x << "  " ;
    std::cout << std::endl ; 
}

int middlethree( std::vector<int> &arr, int left, int right )
{
    int mid = ( left + right ) / 2 ;
    if( arr[left] > arr[mid] )
        std::swap( arr[left], arr[mid] ) ;
    if( arr[left] > arr[right] )
        std::swap( arr[left], arr[right] ) ;
    if( arr[mid] > arr[right] )
        std::swap( arr[mid], arr[right] ) ;

    //houtputarr( arr, "In middle of middle three " );
    //std::cout << "In middle of middle three : " << std::endl ;
    //for( auto x : arr )
    //    std::cout << x <<  "  " ;
    //std::cout << std::endl ; 

    std::swap( arr[mid], arr[right-1] );
    //houtputarr( arr, "After swap " );

    return arr[right-1] ;
} 

void insertsort( std::vector<int> &arr, int left, int right )
{
    //std::cout << left << "  " << right << std::endl ;
    for( int i = left+1 ; i < right+1 ; ++i )
    {
        int tmp = std::move( arr[i] );
        int j = i - 1 ;
        for( ; j >= left ; --j )
        {
            if( tmp < arr[j] )
            {
                arr[j+1] = std::move( arr[j] );
            }
            else
                break ;
        }
        arr[j+1] = tmp ;
    }
    return ;
}

void quicksort( std::vector<int> &arr, int left, int right )
{
    if( right-left >= 5 )
    {
        int pivot = middlethree( arr, left, right );
        int i = left ;
        int j = right-1 ;
//    houtputarr( arr, "hsd go to inner loop " );
        while( true )
        {
            while( arr[++i] < pivot ) { }
            while( arr[--j] > pivot ) { }
            if( i < j )
                std::swap( arr[i], arr[j] );
            else
                break ;
            //std::cout << i << " " << j << "  " << arr[i] << "  " << arr[j] << std::endl ;
            //houtputarr( arr, "inner loop " );
        }
    //houtputarr( arr, "before quick swap " );
        std::swap( arr[i], arr[right-1] );
    //houtputarr( arr, "after quick swap " );
        // please valid arr[right-1] ?= pivot ;

    //    std::cout << "pivot is " << i << "  " << pivot << std::endl ; ;
    //for( auto x : arr )
    //    std::cout << x <<  "  " ;
    //std::cout << std::endl ; 

        quicksort( arr, left, i-1 );
        quicksort( arr, i+1,  right );
    }
    else
        insertsort( arr, left, right );
}

void quicksort( std::vector<int> &arr )
{
    quicksort( arr, 0, arr.size()-1 );
}

int main() 
{
    std::vector<int> arr{ 13,65,26,32,24,31,19,16,68,21 };
    for( auto x : arr )
        std::cout << x <<  "  " ;
    std::cout << std::endl ; 

    quicksort( arr ) ;
    for( auto x : arr )
        std::cout << x <<  "  " ;
    std::cout << std::endl ; 


}
