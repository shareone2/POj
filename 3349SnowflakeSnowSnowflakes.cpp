#include <iostream>
#include <cstdio>

#define MAX 100007

using namespace std;

int snow_head[MAX], next[MAX], node[MAX][10], cnt = 1; 

int read();
void combine(int *base, int sum);
bool judge(int *base, int sum);

int main() {
	int n = read(); //数据量 
	while (n--) { //输入 
		int base[10], sum = 0; //bas指的是，sum表示当前雪花的质量 
	    for (int i = 0; i < 6; i++) { //输入 
	    	base[i] = read(); //第i掰的质量 
	    	sum += base[i]; //质量和相加 
		}
		sum %= MAX; //模上质数，方便找到表头 
		if (judge(base, sum)) { // 判断 
			printf("Twin snowflakes found.\n");
			return 0;
		} else {
			combine(base, sum); //合并 
		}
	}
	printf("No two snowflakes are alike.\n");
	return 0;
}

int read() { //快读。 
    int x = 0;
    char ch = getchar();
    while (ch < '0' || ch > '9') ch = getchar();
    while (ch >= '0' && ch <= '9') {
        x = x * 10 + ch - 48;
        ch = getchar();
    }
    return x;
}

void combine(int *base, int sum){
	next[cnt] = snow_head[sum]; //链表头插法第一步 
	snow_head[sum] = cnt; //链表头插法第二步 
	for (int i = 0; i < 6; i++) { //每瓣的质量进行相应的赋值 
		node[cnt][i] = base[i];
	}
	cnt++; //编号加一
	return ;
}

bool judge(int *base, int sum) {
	for (int i = snow_head[sum]; i; i = next[i]) { //第i个雪花 
		for (int j = 0; j < 6; j++) { //第i个雪花的第j片花瓣 
			for (int k = 0; k < 6; k++) { //选定雪花的第k个花瓣 
				if (node[i][j] == base[k]) {
				   int t = 0;
				   while (t < 6) { //顺时针比较 
				   	    t++;
				        int a = (j + t) % 6, b = (k + t) % 6;
				        if (t == 6) {
				            return 1;	
						} else if (node[i][a] != base[b]) {
				        	break;
						}
				    }
				    t = 0;
                    while (t < 6) { //逆时针比较 
                        t++; 
                        int a = (j + t) % 6, b = (k + 6 - t) % 6;
                        if (t == 6) {
                            return 1;
                        } else if (node[i][a] != base[b]) {
                        	break;
						}
                    }
				}
			}
		}
	}
	return 0;
}
