#include<bits/stdc++.h>
using namespace std;
template<typename T>
struct BinaryIndexedTree{int N,max_2beki;vector<T>data;
  BinaryIndexedTree(int size){N=size+3;
    data.assign(N+1,0);max_2beki=1;
    while(max_2beki*2<=N)max_2beki*=2;
  }
  T sum(int k) const {
    if (k < 0) return 0;
    T ret = 0;
    ++k;
    while (k > 0) {
      ret += data[k];
      k -= k & -k;
    }
    return ret;
  }
  inline T sum(int l, int r) const { return sum(r) - sum(l - 1); }
  inline T operator[](int k) const { return sum(k) - sum(k - 1); }
  void add(int k, T x) {
    ++k;
    while (k <= N) {
      data[k] += x;
      k += k & -k;
    }
  }
  void imos(int l, int r, T x) {
    add(l, x);
    add(r + 1, -x);
  }
  int lower_bound(T w) {
    if (w <= 0) return 0;
    int x = 0;
    for (int k = max_2beki; k > 0; k /= 2) {
      if (x + k <= N - 1 && data[x + k] < w) {
        w -= data[x + k];
        x += k;
      }
    }
    return x;
  }
  int upper_bound(T w) {
    if (w < 0) return 0;
    int x = 0;
    for (int k = max_2beki; k > 0; k /= 2) {
      if (x + k <= N - 1 && data[x + k] <= w) {
        w -= data[x + k];
        x += k;
      }
    }
    return x;
  }
};
using namespace std;
namespace fastio {
static constexpr int SZ = 1 << 17;
char ibuf[SZ], obuf[SZ];
int pil = 0, pir = 0, por = 0;
struct Pre {
  char num[40000];
  constexpr Pre() : num() {
    for (int i = 0; i < 10000; i++) {
      int n = i;
      for (int j = 3; j >= 0; j--) {
        num[i * 4 + j] = n % 10 + '0';
        n /= 10;
      }
    }
  }
} constexpr pre;
inline void load() {
  memcpy(ibuf, ibuf + pil, pir - pil);
  pir = pir - pil + fread(ibuf + pir - pil, 1, SZ - pir + pil, stdin);
  pil = 0;
}
inline void flush() {
  fwrite(obuf, 1, por, stdout);
  por = 0;
}
inline void rd(char& c) { c = ibuf[pil++]; }
template <typename T>
inline void rd(T& x) {
  if (pil + 32 > pir) load();
  char c;
  do
    c = ibuf[pil++];
  while (c < '-');
  bool minus = 0;
  if (c == '-') {
    minus = 1;
    c = ibuf[pil++];
  }
  x = 0;
  while (c >= '0') {
    x = x * 10 + (c & 15);
    c = ibuf[pil++];
  }
  if (minus) x = -x;
}
inline void rd() {}
template <typename Head, typename... Tail>
inline void rd(Head& head, Tail&... tail) {
  rd(head);
  rd(tail...);
}
inline void wt(char c) { obuf[por++] = c; }
template <typename T>
inline void wt(T x) {
  if (por > SZ - 32) flush();
  if (!x) {
    obuf[por++] = '0';
    return;
  }
  if (x < 0) {
    obuf[por++] = '-';
    x = -x;
  }
  int i = 12;
  char buf[16];
  while (x >= 10000) {
    memcpy(buf + i, pre.num + (x % 10000) * 4, 4);
    x /= 10000;
    i -= 4;
  }
  int d = x < 100 ? (x < 10 ? 1 : 2) : (x < 1000 ? 3 : 4);
  memcpy(obuf + por, pre.num + x * 4 + 4 - d, d);
  por += d;
  memcpy(obuf + por, buf + i + 4, 12 - i);
  por += 12 - i;
}
inline void wt() {}
template <typename Head, typename... Tail>
inline void wt(Head head, Tail... tail) {
  wt(head);
  wt(tail...);
}
template<typename T>
inline void wtn(T x){
  wt(x, '\n');
}
struct Dummy {
  Dummy() { atexit(flush); }
} dummy;}
using fastio::rd;using fastio::wt;using fastio::wtn;
int main(){int N,Q;rd(N,Q);
  BinaryIndexedTree<long long> bit(N);
  for (int i = 1; i <= N; i++) {
    int n;
    rd(n);
    bit.data[i] += n;
    int j = i + (i & -i);
    if (j <= N) bit.data[j] += bit.data[i];
  }
  for (int i = 0; i < Q; i++) {
    int x, y, z;rd(x, y, z);
    if (x)wtn(bit.sum(y, z - 1));
    else bit.add(y, z);
  }
}