/**

                                    _ooOoo_
                                   o8888888o
                                   88" . "88
                                   (| -_- |)
                                    O\ = /O
                                ____/`---'\____
                              .   ' \\| |// `.
                               / \\||| : |||// \
                             / _||||| -:- |||||- \
                               | | \\\ - /// | |
                             | \_| ''\---/'' | |
                              \ .-\__ `-` ___/-. /
                           ___`. .' /--.--\ `. . __
                        ."" '< `.___\_<|>_/___.' >'"".
                       | | : `- \`.;`\ _ /`;.`/ - ` : | |
                         \ \ `-. \_ __\ /__ _/ .-` / /
                 ======`-.____`-.___\_____/___.-`____.-'======
                                    `=---='

                 .............................................
                          佛祖保佑             永无BUG
                  佛曰:
                          写字楼里写字间，写字间里程序员；
                          程序人员写程序，又拿程序换酒钱。
                          酒醒只在网上坐，酒醉还来网下眠；
                          酒醉酒醒日复日，网上网下年复年。
                          但愿老死电脑间，不愿鞠躬老板前；
                          奔驰宝马贵者趣，公交自行程序员。
                          别人笑我忒疯癫，我笑自己命太贱；
                          不见满街漂亮妹，哪个归得程序员？

               __------__
             /~          ~\                       ,%%%%%%%%,
            |    //^\\//^\|                     ,%%/\%%%%/\%%
          /~~\  ||  o| |o|:~\                  ,%%%\c "" J/%%%
         | |6   ||___|_|_||:|         %.       %%%%/ o  o \%%%
          \__.  /      o  \/'         `%%.     %%%%    _  |%%%
           |   (       O   )           `%%     `%%%%(__Y__)%%'
  /~~~~\    `\  \         /            //       ;%%%%`\-/%%%'
| |~~\ |     )  ~------~`\            ((       /  `%%%%%%%'
/' |  | |   /     ____ /~~~)\          \\    .'          |
(_/'   | | |     /'    |    ( |         \\  /       \  | |
      | | |     \    /   __)/ \          \\/         ) | |
      \  \ \      \/    /' \   `\         \         /_ | |__
        \  \|\        /   | |\___|        (___________)))))))  攻城狮
          \ |  \____/     | |
          /^~  \        _/ <
         |  |         \       \                神兽保佑，通通AC
         |  | \        \        \
         -^-\  \       |         )
              `\_______/^\______/   程序猿

*/
#include <cstdio>
#include <set>
#include <map>
#include <ctime>
#include <cctype>
#include <string>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <assert.h>
#include <algorithm>
#include <iostream>
#include <climits>
#include <queue>
#include <vector>

#define dte(x) cout << #x << " = " << x << endl;
#define scaf2(x,y) scaf(x), scaf(y)
#define mkp make_pair
  
using namespace std;
template<typename T>inline void scaf(T&v)
{
    char ch = getchar(); int sgn = 1;
    for(; '-' != ch && (ch < '0' || ch > '9'); ch = getchar()); if ('-' == ch) sgn = -1,v = 0; else v = ch - '0';
    for(ch = getchar(); ch >= '0' && ch <= '9'; ch = getchar()) v = (v << 1) +(v << 3) + ch - '0'; v *= sgn;
}
typedef long long LL;
typedef unsigned long long ULL;
typedef pair <int, int> PII;
const int maxN = 1e5 + 10;
const int mod = 1e9 + 7;
const double eps = 1e-4;
//const double pi = acos(-1.0);

int a[maxN];
PII gcds[maxN];
map<int, LL>cMap;

inline void solve(const int& n)
{
	int i, j, k, top = 0, cur, g;
	for (i = 1; i <= n; ++ i)
	{
		for (j = 0; j < top; ++ j) gcds[j].first = __gcd(gcds[j].first, a[i]);
		gcds[top ++] = mkp(a[i], 1);
		cur = 1;
		for (j = 1; j < top; ++ j)
			if (gcds[cur - 1].first == gcds[j].first) gcds[cur - 1].second += gcds[j].second;
			else gcds[cur ++] = gcds[j];
		top = cur;
		cur = 1;
		for (j = 0; j < top; ++ j)
		{
			g = gcds[j].first;
			cMap[g] += gcds[j].second;
			cur += gcds[j].second;
		}
//		for (map<int, LL>::iterator iter = cMap.begin(); iter != cMap.end(); ++ iter)
//		{
//			printf("%d %I64d\n", iter -> first, iter -> second);
//		}
//		for (j = 0; j < top; ++ j)
//		{
//			printf("#%d %d\n", gcds[j].first, gcds[j].second);
//		}
//		puts("---------");
	}
}

int main()
{
	int i, j, k, n, m;
	int t, tt = 0;
	scanf("%d", &n);
	for (i = 1; i <= n; ++ i)
	{
		scanf("%d", &a[i]);
	}
	solve(n);
	int Q;
	scanf("%d", &Q);
	while (Q --)
	{
		scanf("%d", &m);
		printf("%I64d\n", cMap[m]);
	}
	return 0;
}
