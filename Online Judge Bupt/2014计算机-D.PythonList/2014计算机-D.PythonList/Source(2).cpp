#include<stdio.h>
#include<string.h>
#include<vector>
#include<algorithm>
using namespace std;
int main(){
    int t;
    while(scanf("%d", &t) != EOF){
        for(int a = 1; a <= t; a++){
            int n;
            scanf("%d", &n);
            //getchar();
            vector<int> Q[100];
            char name[100][100];
            int size = 0;
            for(int i = 1; i <= n; i++){
                char sName[100];
                getchar();
                scanf("%[^=.[]", sName);
                int idx = -1;
                for(int j = 0; j < 100; j++){
                    if(strcmp(name[j], sName) == 0){
                        idx = j;
                    }
                }
                char next;
                scanf("%c", &next);
                if(next == '.'){
                    char inst[10];
                    scanf("%[^(]", inst);
                    if(strcmp(inst, "sort") == 0){
                        char jump[10];
                        scanf("%s", jump);
                        sort(Q[idx].begin(), Q[idx].end());
                    }
                    else if(strcmp(inst, "append") == 0){
                        char jump;
                        scanf("%c", &jump);
                        int x;
                        scanf("%d", &x);
                        Q[idx].push_back(x);
                        scanf("%c", &jump);
                        //getchar();
                    }
                }
                else if (next == '='){
                    if(idx == - 1) {
                        idx = size++;
                        int j;
                        for(j = 0; sName[j] != 0; j++){
                            name[idx][j] = sName[j];
                        }
                        name[idx][j] = 0;
                    }
                    while(Q[idx].empty() != true) Q[idx].pop_back();
                    char jump[10];
                    scanf("%s", jump);
                }
                else if (next == '['){
                    int ix;
                    scanf("%d", &ix);
                    if(ix >= Q[idx].size()){
                        printf("ERROR\n");
                    }
                    else printf("%d\n", Q[idx].at(ix));
                    char jump[10];
                    scanf("%s", jump);
                }
            }
        }
    }
    return 0;
}