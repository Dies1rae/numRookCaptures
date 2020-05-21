#include <iostream>
#include <vector>
using namespace std;
int numRookCaptures(vector<vector<char>>& board); // @suppress('Symbol is not resolved')
int main() {
	vector<vector<char>> B = {{'.','.','.','.','.','.','.','.'},{'.','.','.','p','.','.','.','.'},{'.','.','.','p','.','.','.','.'},{'p','p','.','R','.','p','B','.'},{'.','.','.','.','.','.','.','.'},{'.','.','.','B','.','.','.','.'},{'.','.','.','p','.','.','.','.'},{'.','.','.','.','.','.','.','.'}};
	cout << numRookCaptures(B) << endl;
	return 0;
}
int numRookCaptures(vector<vector<char>>& board) {
    int ptrend = 0;
    int rX=0,rY=0;
    for(auto  ptr0 = 0; ptr0 < board.size(); ptr0++){
    	for(auto  ptr1 = 0; ptr1 < board[ptr0].size(); ptr1++){
    		if(board[ptr0][ptr1] == 'R'){
    			rX = ptr0;
    			rY = ptr1;
    		}
    	}
    }
    for(int ptrY = rY - 1; ptrY > -1; ptrY--){
    	if(board[rX][ptrY] == '.' || board[rX][ptrY] == 'p'){
    		if(board[rX][ptrY] == 'p'){
    			ptrend++;
    			ptrY = -1;
    		}
    		else if (board[rX][ptrY] == '.'){
    			continue;
    		}
    	}
    	else{
    		break;
    	}
    }
    for(auto ptrY = rY + 1; ptrY < 8; ptrY++){
    	if(board[rX][ptrY] == '.' || board[rX][ptrY] == 'p'){
    		if(board[rX][ptrY] == 'p'){
    			ptrend++;
    			ptrY = 8;
    		}
    		else if (board[rX][ptrY] == '.'){
    			continue;
    		}
    	}
    	else{
    		break;
    	}
    }

    for(int ptrX = rX - 1; ptrX > -1; ptrX--){
    	if(board[ptrX][rY] == '.' || board[ptrX][rY] == 'p'){
    		if(board[ptrX][rY] == 'p'){
    			ptrend++;
    			ptrX = -1;
    		}
    		else if (board[ptrX][rY] == '.'){
    			continue;
    		}
    	}
    	else{
    		break;
    	}
    }
    for(auto ptrX = rX + 1; ptrX < 8; ptrX++){
    	if(board[ptrX][rY] == '.' || board[ptrX][rY] == 'p'){
    		if(board[ptrX][rY] == 'p'){
    			ptrend++;
    			ptrX = 8;
    		}
    		else if (board[ptrX][rY] == '.'){
    			continue;
    		}
    	}
    	else{
    		break;
    	}
    }
    return ptrend;
}
