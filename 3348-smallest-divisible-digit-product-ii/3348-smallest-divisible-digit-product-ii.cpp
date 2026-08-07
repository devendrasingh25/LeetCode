class Solution {
public:
    struct Exp { int a, b, c, d; };

    Exp EXP[10] = {
        {0,0,0,0}, // 0 
        {0,0,0,0}, // 1
        {1,0,0,0}, // 2
        {0,1,0,0}, // 3
        {2,0,0,0}, // 4
        {0,0,1,0}, // 5
        {1,1,0,0}, // 6
        {0,0,0,1}, // 7
        {3,0,0,0}, // 8
        {0,2,0,0}, // 9
    };

    int minCount(long long ra, long long rb, long long rc, long long rd) {
        ra = max(0LL, ra); rb = max(0LL, rb);
        rc = max(0LL, rc); rd = max(0LL, rd);
        long long best = LLONG_MAX;
        long long lim = min(ra, rb);
        for (long long m6 = 0; m6 <= lim; m6++) {
            long long costA = (ra - m6 + 2) / 3; 
            long long costB = (rb - m6 + 1) / 2; 
            long long cost = m6 + costA + costB;
            best = min(best, cost);
        }
        if (best == LLONG_MAX) best = 0;
        return (int)(rc + rd + best);
    }

    string greedyFill(long long ra, long long rb, long long rc, long long rd, long long m) {
        ra = max(0LL, ra); rb = max(0LL, rb);
        rc = max(0LL, rc); rd = max(0LL, rd);
        if (ra == 0 && rb == 0 && rc == 0 && rd == 0) {
            return string(m, '1');
        }
        string res;
        res.reserve(m);
        long long curA = ra, curB = rb, curC = rc, curD = rd;
        for (long long pos = 0; pos < m; pos++) {
            long long remAfter = m - pos - 1;
            int chosen = -1;
            long long nA, nB, nC, nD;
            for (int dig = 1; dig <= 9; dig++) {
                Exp &e = EXP[dig];
                nA = max(0LL, curA - e.a);
                nB = max(0LL, curB - e.b);
                nC = max(0LL, curC - e.c);
                nD = max(0LL, curD - e.d);
                if (minCount(nA, nB, nC, nD) <= remAfter) {
                    chosen = dig;
                    curA = nA; curB = nB; curC = nC; curD = nD;
                    break;
                }
            }
            res.push_back('0' + chosen);
            if (curA == 0 && curB == 0 && curC == 0 && curD == 0) {
                res += string(remAfter, '1');
                return res;
            }
        }
        return res;
    }

    string smallestNumber(string num, long long t) {
        long long temp = t;
        long long A = 0, B = 0, C = 0, D = 0;
        while (temp % 2 == 0) { temp /= 2; A++; }
        while (temp % 3 == 0) { temp /= 3; B++; }
        while (temp % 5 == 0) { temp /= 5; C++; }
        while (temp % 7 == 0) { temp /= 7; D++; }
        if (temp != 1) return "-1";

        int n = num.size();
        vector<int> digits(n);
        for (int i = 0; i < n; i++) digits[i] = num[i] - '0';

        vector<long long> prefA(n+1,0), prefB(n+1,0), prefC(n+1,0), prefD(n+1,0);
        for (int i = 0; i < n; i++) {
            Exp e = (digits[i] == 0) ? Exp{0,0,0,0} : EXP[digits[i]];
            prefA[i+1] = prefA[i] + e.a;
            prefB[i+1] = prefB[i] + e.b;
            prefC[i+1] = prefC[i] + e.c;
            prefD[i+1] = prefD[i] + e.d;
        }

        int firstZero = -1;
        for (int i = 0; i < n; i++) if (digits[i] == 0) { firstZero = i; break; }

        bool zeroFreeFull = (firstZero == -1);
        int p0 = zeroFreeFull ? n-1 : min(n-1, firstZero);

        
        if (zeroFreeFull && prefA[n]>=A && prefB[n]>=B && prefC[n]>=C && prefD[n]>=D) {
            return num;
        }

        int R0 = minCount(A, B, C, D);

        int pivot = -1, chosenD = -1;
        int detailedLo = max(0, n - R0);

        
        for (int p = p0; p >= detailedLo; p--) {
            long long baseA = prefA[p], baseB = prefB[p], baseC = prefC[p], baseD = prefD[p];
            long long m = n - 1 - p;
            int startD = digits[p] + 1;
            for (int d = startD; d <= 9; d++) {
                Exp &e = EXP[d];
                long long la = max(0LL, A - baseA - e.a);
                long long lb = max(0LL, B - baseB - e.b);
                long long lc = max(0LL, C - baseC - e.c);
                long long ld = max(0LL, D - baseD - e.d);
                if (minCount(la, lb, lc, ld) <= m) {
                    pivot = p; chosenD = d;
                    break;
                }
            }
            if (pivot != -1) break;
        }

       
        if (pivot == -1) {
            int start = min(detailedLo - 1, p0);
            for (int p = start; p >= 0; p--) {
                if (digits[p] != 9) {
                    pivot = p;
                    chosenD = digits[p] + 1;
                    break;
                }
            }
        }

        if (pivot != -1) {
            long long baseA = prefA[pivot], baseB = prefB[pivot], baseC = prefC[pivot], baseD = prefD[pivot];
            Exp &e = EXP[chosenD];
            long long la = max(0LL, A - baseA - e.a);
            long long lb = max(0LL, B - baseB - e.b);
            long long lc = max(0LL, C - baseC - e.c);
            long long ld = max(0LL, D - baseD - e.d);
            long long m = n - 1 - pivot;
            string suffix = greedyFill(la, lb, lc, ld, m);
            return num.substr(0, pivot) + char('0' + chosenD) + suffix;
        }

       
        long long L = max((long long)n + 1, (long long)R0);
        return greedyFill(A, B, C, D, L);
    }
};