// Copyright 2021 NNTU-CS
int countPairs1(int *arr, int len, int value) {
    int res = 0;
    for (int i = 0; i < len; i++) {
        for (int j = i + 1; j < len; j++) {
            if (arr[i] + arr[j] == value) res++;
        }
    }
    if (res == 0) return 0;
    return res;
}
int countPairs2(int *arr, int len, int value) {
    int res = 0;
    int r = len - 1;
    while (arr[r] >= value) {
        r--;
    }
    for (int i = 0; i < r; i++) {
        for (int j = r; i < j; j--) {
            if (arr[i] + arr[j] == value) res++;
        }
    }
    if (res == 0) return 0;
    return res;
}
int countPairs3(int *arr, int len, int value) {
    int res = 0;
    int z, l, r, m;
    for (int i = 0; i < len; i++) {
        l = i + 1;
        r = len - 1;
        z = value - arr[i];
        while (l <= r) {
            m = (l + r) / 2;
            if (arr[m] < z) {
                l = m + 1;
            } else {
                if (arr[m] > z) {
                    r = m - 1;
                } else {
                    res++;
                    int niz = m - 1;
                    int verh = m + 1;
                    while ((arr[m] == arr[niz]) && niz > i) {
                        res++;
                        niz--;
                    }
                    while ((arr[m] == arr[verh]) && verh > i) {
                        res++;
                        verh++;
                    }
                    break;
                }
            }
        }
    }
    if (res != 0) return res;
    return 0;
}
