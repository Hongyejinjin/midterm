#!/bin/bash

# 1. 테스트 설정
SCORE=0
TEST_ID="3741200" # 채점에 사용할 샘플 학번
YEAR=2026         # 기호상수(올해) 예상값

echo "--- [과제 채점 시작] ---"

# 2. 컴파일
g++ lab2.cpp -o assignment 2>/dev/null
if [ $? -ne 0 ]; then
    echo "에러: 컴파일 실패 (0점)"
    exit 0
fi

# 3. 프로그램 실행 (학번 입력 주입)
# 학생의 출력 결과 전체를 변수에 담습니다.
OUTPUT=$(echo "$TEST_ID" | ./assignment)

# 4. 항목별 채점 (각 1점)

# [1] 분반, 이름, 학번변수 출력
echo "$OUTPUT" | grep -qE ".+ .+ $TEST_ID" && { ((SCORE++)); echo "1번 통과 (+1)"; } || echo "1번 실패"

# [2] sizeof(int) 출력
echo "$OUTPUT" | grep -qE "size of .+: 4" && { ((SCORE++)); echo "2번 통과 (+1)"; } || echo "2번 실패"

# [3] 기호상수(올해) 출력
echo "$OUTPUT" | grep -q "$YEAR" && { ((SCORE++)); echo "3번 통과 (+1)"; } || echo "3번 실패"

# [4] int형 나눗셈 (typeid 및 결과)
INT_RES=$((TEST_ID / YEAR))
echo "$OUTPUT" | grep -qE "(int|i): $INT_RES" && { ((SCORE++)); echo "4번 통과 (+1)"; } || echo "4번 실패"

# [5] double형 나눗셈 (typeid 및 결과)
DBL_RES=$(python3 -c "print(round($TEST_ID / $YEAR, 2))")
echo "$OUTPUT" | grep -qE "(double|d): $DBL_RES" && { ((SCORE++)); echo "5번 통과 (+1)"; } || echo "5번 실패"

# [6] 학번 + 1 (단순 할당)
ID6=$((TEST_ID + 1))
echo "$OUTPUT" | grep -q "$ID6" && { ((SCORE++)); echo "6번 통과 (+1)"; } || echo "6번 실패"

# [7] 학번 + 1 (+= 연산자)
ID7=$((ID6 + 1))
echo "$OUTPUT" | grep -q "$ID7" && { ((SCORE++)); echo "7번 통과 (+1)"; } || echo "7번 실패"

# [8] 학번 + 1 (전위 증가 ++id)
ID8=$((ID7 + 1))
echo "$OUTPUT" | grep -q "$ID8" && { ((SCORE++)); echo "8번 통과 (+1)"; } || echo "8번 실패"

# [9] 후위 증가 (id++) - 출력 시점에는 증가 전 값이 찍혀야 함
echo "$OUTPUT" | grep -q "$ID8" && { ((SCORE++)); echo "9번 통과 (+1)"; } || echo "9번 실패"

# [10] 최종 학번 출력 (후위 증가가 반영된 값)
ID10=$((ID8 + 1))
echo "$OUTPUT" | grep -q "$ID10" && { ((SCORE++)); echo "10번 통과 (+1)"; } || echo "10번 실패"

echo "-----------------------"
echo "최종 취득 점수: $SCORE / 10"

exit 0