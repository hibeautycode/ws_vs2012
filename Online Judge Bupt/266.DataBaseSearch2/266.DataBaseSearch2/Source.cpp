#include<stdio.h>
#include<string.h>
struct student{
    char name[50];
    char sex[10];
    int year;
    int month;
    int day;
}stu[501];
student match;
void make(char s[]){
    char first = s[0];
    switch(first){
    case 'N':{
        int i;
        for(i = 6; s[i] != '\''; i++){
            match.name[i - 6] = s[i];
        }
        match.name[i - 6] = 0;
        break;
             }
    case 'S':{
        int i;
        for(i = 5; s[i] != '\''; i++){
            match.sex[i - 5] = s[i];
        }
        match.sex[i - 5] = 0;
        break;
             }
    case 'B':{
        int diff = 0;
        if(s[10] == '*'){
            diff -= 3;
        }
        else {
            int y = 0;
            for(int j = 10; j <= 13; j++){
                y = y * 10 + s[j] - '0';
            }
            match.year = y;
        }
        if(s[15 + diff] == '*'){
            diff -= 1;
        }
        else {
            match.month = (s[15 + diff] - '0') * 10 + (s[16 + diff] - '0');
        }
        if(s[18 + diff] != '*'){
            match.day = (s[18 + diff] - '0') * 10 + (s[19 + diff] - '0');
        }
             }
    }
}
           
int main(){
    int t;
    while(scanf("%d", &t) != EOF){
        for(int a = 0; a < t; a++){
            int n, m;
            scanf("%d%d", &n, &m);
            for(int i = 1; i<= n; i++){
                scanf("%s%s%d/%d/%d", stu[i].name, stu[i].sex, &stu[i].year, &stu[i].month, &stu[i].day);
            }
            for(int i = 1; i <= m; i++){
                match.name[0] = match.sex[0] = 0;
                match.year = match.month = match.day = -1;
                char s[100];
                getchar();
                scanf("%[^\n]", s);
                char inst[4][100];
                int idx = 0;
                int which = 1;
                int j;
                for(j = 0; s[j] != 0; j++){
                    if(s[j] == ' '){
                        inst[which][j - idx] = 0;
                        idx = j + 1;
                        which ++;
                    }
                    else {
                        inst[which][j - idx] = s[j];
                    }
                }
                inst[which][j - idx] = 0;
                for(int k = 1; k <= which; k++){
                    make(inst[k]);
                }
                bool flag = false;
                for(int k = 1; k <= n; k++){
                    if((match.name[0] == 0 || strcmp(stu[k].name, match.name) == 0) &&
                        (match.sex[0] == 0 || strcmp(stu[k].sex, match.sex) == 0) &&
                        (match.year == -1 || stu[k].year == match.year) &&
                        (match.month == -1 || stu[k].month == match.month) &&
                        (match.day == -1 || stu[k].day == match.day)) {
                        printf("%s\n", stu[k].name);
                        flag = true;
                    }
                }
                if(flag == false) printf("NULL\n");
            }
        }
    }
    return 0;
}