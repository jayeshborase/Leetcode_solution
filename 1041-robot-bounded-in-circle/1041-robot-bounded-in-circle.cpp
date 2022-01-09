class Solution {
public:
    bool isRobotBounded(string in) {
        int x = 0, y = 0;
        string pos = "north";
        for(int i = 0; i < in.length(); i++){
            if(in[i] == 'G'){
                if(pos == "north")
                    y++;
                else if(pos == "south")
                    y--;
                else if(pos == "west")
                    x++;
                else if(pos == "east")
                    x--;
            }    
            else if(in[i] == 'L'){
                if(pos == "north")
                    pos = "west";
                else if(pos == "west")
                    pos = "south";
                else if(pos == "south")
                    pos = "east";
                else 
                    pos = "north";
            }    
            else if(in[i] == 'R'){
                if(pos == "north")
                    pos = "east";
                else if(pos == "east")
                    pos = "south";
                else if(pos == "south")
                    pos = "west";
                else
                    pos = "north";
            }    
        }
         
        
        if(x == 0 && y == 0)
            return 1;
        
        if(pos != "north")
            return 1;
        else
            return 0;
    }
};