#include "pascals_triangle.h"

namespace pascals_triangle {

    std::vector<std::vector<int>> generate_rows(int r){
        std::vector<std::vector<int>> s(r);
        for(int i=0;i<r;i++){
            s[i].resize(i+1);
        }

        if(r<1)return s;
        
        s[0]={1};
        if(r==1)return s;
        for(int i=1;i<r;i++){
            s[i][0]=1;
            for(int j=1;j<=i;j++){
                if(j>i-1){
                    s[i][j]=s[i-1][j-1];
                }else{
                    s[i][j]=s[i-1][j-1]+s[i-1][j];
                }
            }
        }
        return s;
    }

}  // namespace pascals_triangle
