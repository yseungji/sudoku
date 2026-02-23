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
    int yto = y / 3 * 3;
    int xto = x / 3 * 3;

    for(int i=yto;i<yto+3;i++) {
        for(int j=xto;j<xto + 3;j++){
            possible[sudoku[i][j]] = false;
        }
    }
}

void recursion(int now) {
    if(now >= jump.size()){
        //출력후 프로그램 종료.
        output();
        //outputans();
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