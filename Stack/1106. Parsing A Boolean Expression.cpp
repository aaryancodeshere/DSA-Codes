class Solution {
public:

    char calculate(vector<char> temp, char op){
        if(op=='!'){
            return temp[0]=='f' ? 't' : 'f';
        }
        else if(op=='&'){
            for(int i=0; i<temp.size(); i++){
                if(temp[i]=='f')return 'f';
            }
            return 't';
        }
        else {
            for(int i=0; i<temp.size(); i++){
                if(temp[i]=='t')return 't';
            }
            return 'f';
        }
    }

    bool parseBoolExpr(string ex) {
        stack<char> s;

        for(int i=0; i<ex.size(); i++){
            if(ex[i]==',')continue;

            else if(ex[i]== ')'){
                vector<char> temp;
                while(s.top()!='('){
                    temp.push_back(s.top());
                    s.pop();
                }
                s.pop();
                s.push(calculate(temp,s.top()));
            }
            else{
                s.push(ex[i]);
            }
        }
        return s.top()=='f'?false:true;
    }

};