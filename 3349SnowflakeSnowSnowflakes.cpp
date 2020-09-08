#include <iostream>
#include <cstdio>

#define MAX 100007

using namespace std;

int snow_head[MAX], next[MAX], node[MAX][10], cnt = 1; 

int read();
void combine(int *base, int sum);
bool judge(int *base, int sum);

int main() {
	int n = read(); //������ 
	while (n--) { //���� 
		int base[10], sum = 0; //basָ���ǣ�sum��ʾ��ǰѩ�������� 
	    for (int i = 0; i < 6; i++) { //���� 
	    	base[i] = read(); //��i�������� 
	    	sum += base[i]; //��������� 
		}
		sum %= MAX; //ģ�������������ҵ���ͷ 
		if (judge(base, sum)) { // �ж� 
			printf("Twin snowflakes found.\n");
			return 0;
		} else {
			combine(base, sum); //�ϲ� 
		}
	}
	printf("No two snowflakes are alike.\n");
	return 0;
}

int read() { //����� 
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
	next[cnt] = snow_head[sum]; //����ͷ�巨��һ�� 
	snow_head[sum] = cnt; //����ͷ�巨�ڶ��� 
	for (int i = 0; i < 6; i++) { //ÿ�������������Ӧ�ĸ�ֵ 
		node[cnt][i] = base[i];
	}
	cnt++; //��ż�һ
	return ;
}

bool judge(int *base, int sum) {
	for (int i = snow_head[sum]; i; i = next[i]) { //��i��ѩ�� 
		for (int j = 0; j < 6; j++) { //��i��ѩ���ĵ�jƬ���� 
			for (int k = 0; k < 6; k++) { //ѡ��ѩ���ĵ�k������ 
				if (node[i][j] == base[k]) {
				   int t = 0;
				   while (t < 6) { //˳ʱ��Ƚ� 
				   	    t++;
				        int a = (j + t) % 6, b = (k + t) % 6;
				        if (t == 6) {
				            return 1;	
						} else if (node[i][a] != base[b]) {
				        	break;
						}
				    }
				    t = 0;
                    while (t < 6) { //��ʱ��Ƚ� 
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
