#ifndef WEIRD_H
#define WEIRD_H
typedef struct {
    char arr[2];
    int i;
} Weird;
#endif

#pragma once // once를 통해 한 번만 include 될 수 있다는 것을 말해주는데
// ifndef도가 간단명료, 컴파일 시간 절약
// 전처리기가 헤더파일을 열어보아서 WEIRD_H가 정의되었나 않았나 확인해봐야하는데
// once를 이용하면 다시 안열어봐도 되기 때문에 컴파일 시간 절약
struct Weird {
    char arr[2];
    int i;
};