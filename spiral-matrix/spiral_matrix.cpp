#include "spiral_matrix.h"
namespace spiral_matrix {

    std::vector<std::vector<uint32_t>> spiral_matrix(int x){
        if(x==0)return {};
        std::vector<std::vector<uint32_t>> spiral(x,std::vector<uint32_t>(x));
    int top=0;
    int left=0;
    int bottom=x-1;
    int right=x-1;
    int n=1;
    while(top<=bottom && left<=right){
       for(int col=left;col<=right;col++){
            spiral[top][col]=n++;
       } 

       for(int row=top+1;row<=bottom;row++){
            spiral[row][right]=n++;
       } 

       for(int col=right-1;col>=left;col--){
            spiral[bottom][col]=n++;
       } 
       for(int row=bottom-1;row>top;row--){
            spiral[row][left]=n++;
       } 
       top++;
       left++;
       bottom--;
       right--;
    }
    return spiral;
    }
}  // namespace spiral_matrix
