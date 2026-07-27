#include <string>

namespace targets {
    class Alien{
        public:
            Alien(int x, int y){
              x_coordinate=x;
              y_coordinate=y;
            }

            int get_health(){
                return health;
            }
            int x_coordinate=0;
            int y_coordinate=0;

            bool hit(){
                health--;
                if(health<0) health=0;
                return true;
            }
            bool is_alive(){
                return get_health()>0;
            }
            bool teleport(int x_new, int y_new){
                x_coordinate=x_new;
                y_coordinate=y_new;
                return true;
            }
            bool collision_detection(Alien a){
                return a.x_coordinate==x_coordinate &&a.y_coordinate==y_coordinate;
            }
        private:
            int health=3;
    };

}  // namespace targets
