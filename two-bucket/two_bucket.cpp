#include "two_bucket.h"
#include <numeric>
#include <vector>
#include <queue>
#include <stdexcept>
namespace two_bucket {
    void pour(int& from, int& to, int limit){
        int amount=limit-to;

        if(from<amount)amount=from;
        from-=amount;
        to+=amount;
    }

measure_result measure(int bucket1_capacity, int bucket2_capacity,
                       int target_volume, bucket_id start_bucket){

        int max_capacity=(bucket1_capacity>bucket2_capacity)?bucket1_capacity:bucket2_capacity;
        if(target_volume%(std::gcd(bucket1_capacity,bucket2_capacity))!=0 || target_volume>max_capacity){
            throw std::runtime_error(" ");
        }

        state_t start_state={(start_bucket==bucket_id::one)?bucket1_capacity:0,
                            (start_bucket==bucket_id::two)?bucket2_capacity:0,
                            1

        };
        std::queue<state_t> queue;
        queue.push(start_state);

        std::vector<bool> visited((bucket1_capacity+1)*(bucket2_capacity+1),false);
        int one_row=bucket2_capacity+1;
        visited[start_state.bucket_1*one_row+start_state.bucket_2]=true;
        measure_result output={};
        if(start_bucket==bucket_id::one){
            visited[one_row*0+bucket2_capacity]=true;
        }else if(start_bucket==bucket_id::two){
            visited[one_row*bucket1_capacity+0]=true;
        }

        while(!queue.empty()){
            state_t current=queue.front();
            queue.pop();

            if(current.bucket_1==target_volume){
                output.goal_bucket=bucket_id::one;
                output.num_moves=current.moves;
                output.other_bucket_volume=current.bucket_2;
                return output;
            }
            if(current.bucket_2==target_volume){
                output.goal_bucket=bucket_id::two;
                output.num_moves=current.moves;
                output.other_bucket_volume=current.bucket_1;
                return output;
            }

            int num=0;
            state_t next_states[6];
            next_states[num++]={bucket1_capacity,current.bucket_2,current.moves+1};

            next_states[num++]={current.bucket_1,bucket2_capacity,current.moves+1};

            next_states[num++]={0,current.bucket_2,current.moves+1};

            next_states[num++]={current.bucket_1,0,current.moves+1};

            int b1=current.bucket_1, b2=current.bucket_2;
            pour(b1,b2,bucket2_capacity);
            next_states[num++]={b1,b2,current.moves+1};

            b1=current.bucket_1, b2=current.bucket_2;
            pour(b2,b1,bucket1_capacity);
            next_states[num++]={b1,b2,current.moves+1};

            for(auto s:next_states){
                int index=s.bucket_1*one_row+s.bucket_2;
                if(!visited[index]){
                    visited[index]=true;
                    queue.push(s);
                }
            }
        }
        return output;
    }
}  // namespace two_bucket
