#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int scores[30]; // 30명의 학생 성적 저장
    int sum = 0;
    double average;
    int studentNumber;

    // 난수 생성 초기화
    srand(time(0));

    // 성적 데이터 초기화
    for (int i = 0; i < 30; i++) {
        scores[i] = rand() % 101; // 0 ~ 100 사이의 난수 생성
        sum += scores[i];
    }

    // 평균 계산
    average = sum / 30.0;
    printf("학급 평균 점수: %.2f\n", average);

    return 0;
}
