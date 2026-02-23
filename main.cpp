//스도쿠
#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> P;
int sudoku[9][9] ;
vector <P> jump;
void input();
void possible_num (int y, int x, bool possible[]);
void output();
void recursion(int now);
bool ans = false;
void outputans();
int main()
{
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    input();
    for(int i=0;i<9;i++){
        for(int j=0;j<9;j++){
            if(sudoku[i][j]==0){
                jump.push_back(make_pair(i,j));
            }
        }
    }

    recursion(0); //매개변수로 now 현재 순서
    
    return 0;
}


void input(){
    for(int i=0;i<9;i++){
            string s;
            cin >> s;
            for(int j=0;j<9;j++){
                sudoku[i][j] = s[j] - '0';
            }
        }
    return;
}

void output() {
    for(int i=0;i<9;i++){
        for(int j=0;j<9;j++){
            cout << sudoku[i][j];
        }
        cout << '\n';
    }
    cout << '\n';
}

void outputans(){
    for(int i=0;i<jump.size();i++){
        cout << sudoku[jump[i].first][jump[i].second];
    }
}

void possible_num (int y, int x, bool possible[]) {
    typedef struct Case {
        int xfrom;
        int yfrom;
        int xto;
        int yto;
    }Case;
    for(int i=1;i<=9;i++) possible[i] = true; 
    for(int i=0;i<9;i++) {  //같은 행에 있는 수 찾기
        int fillnum = sudoku[y][i];
        possible[fillnum] = false;
    }
    for(int i=0;i<9;i++) {  //같은 열에 있는 수 찾기
        int fillnum = sudoku[i][x];
        possible[fillnum] = false;
    }
    //3*3 섹터 있는 수 찾기
    Case cc[9];
    cc[0].xfrom=0; cc[0].xto=2;
    cc[0].yfrom=0; cc[0].yto=2;
    cc[1].xfrom=3; cc[1].xto=5;
    cc[1].yfrom=0; cc[1].yto=2;
    cc[2].xfrom=6; cc[2].xto=8;
    cc[2].yfrom=0; cc[2].yto=2;
    cc[3].xfrom=0; cc[3].xto=2;
    cc[3].yfrom=3; cc[3].yto=5;
    cc[4].xfrom=3; cc[4].xto=5;
    cc[4].yfrom=3; cc[4].yto=5;
    cc[5].xfrom=6; cc[5].xto=8;
    cc[5].yfrom=3; cc[5].yto=5;
    cc[6].xfrom=0; cc[6].xto=2;
    cc[6].yfrom=6; cc[6].yto=8;
    cc[7].xfrom=3; cc[7].xto=5;
    cc[7].yfrom=6; cc[7].yto=8;
    cc[8].xfrom=6; cc[8].xto=8;
    cc[8].yfrom=6; cc[8].yto=8;

    for(int k=0;k<9;k++){
        if((y >= cc[k].yfrom && y<=cc[k].yto) && (x>=cc[k].xfrom && x<=cc[k].xto)){
            for(int i=cc[k].yfrom;i<=cc[k].yto;i++){
                for(int j=cc[k].xfrom;j<=cc[k].xto;j++){
                    possible[sudoku[i][j]] = false;
                }
            }
        }
    }
}

void recursion(int now) {
    if(now >= jump.size()){
        //출력후 프로그램 종료.
        //output();
        outputans();
        exit(0);
    }
    int y,x;
    y=jump[now].first; x = jump[now].second;
    bool possible[9+1]; //1~9까지 가능한 수 찾기
    for(int i=1;i<=9;i++){
        possible[i] = true;
    }
    possible_num(y,x, possible);
    for(int i=1;i<=9;i++){
        if(possible[i] == true) {
            sudoku[y][x] = i;
            recursion(now+1);
        }
    }
    sudoku[y][x] = 0;
    
    return;
}