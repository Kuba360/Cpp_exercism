#include "flower_field.h"

namespace flower_field {

    std::vector<std::string> annotate(std::vector<std::string> input){
        if(input.empty())return input;

        std::size_t rows=input.size();
        std::size_t columns=input[0].size();

        for(std::size_t r=0;r<rows;r++){
            for(std::size_t c=0;c<columns;c++){
                if(input[r][c]==' '){
                    int x=0;
                    for(int i=-1;i<=1;i++){
                        for(int j=-1;j<=1;j++){
                            if(i==0 && j==0)continue;

                            int nr=static_cast<int>(r)+i;
                            int nc=static_cast<int>(c)+j;

                            if(nr>=0 && nr<static_cast<int>(rows)&&
                                nc>=0 && nc<static_cast<int>(columns)){
                                    if(input[r+i][c+j]=='*')x++;
                                }
                        }
                    }
                    if(x>0){
                        input[r][c]='0'+x;
                    }
                }
            }
        }
        return input;
    }

}  // namespace flower_field
