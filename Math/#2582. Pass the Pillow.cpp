class Solution {
public:
    int passThePillow(int n, int time) {
        int pos=1;
        bool front=true;
        while(time--){
            if(pos==n && front){
                front=false;
            }
            if(pos==1 && !front){
                front = true;
            }

            if(front){
                pos++;
            }
            else{
                pos--;
            }
        }
        return pos;
    }
};