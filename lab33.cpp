#include <iostream>


// 리턴형이 있는 함수와 재귀함수, 반복문을 사용하는 함수 등 사용자 정의 함수들을 만들어서 테스트해봅니다. 
// 함수이름은 식별자의 규칙에 따라 만듭니다.
// 1. 함수 선언 후, 2. main에서 함수를 호출, 이후 3. 함수 정의를 합니다. 

// 1. 함수 선언
// 1-1. 리턴형은 int형, 매개변수는 없음, 터미널로 int형 값을 입력받고 이를 리턴하는 함수를 선언
int inputInteger()
{
    int value{};
    std::cout << "Enter the value: " << std::endl;
    std::cin >> value;
    return value;
}
// 1-2. 리턴형은 bool형, 매개변수는 int형 1개, 매개변수가 0~100이면 true, 그렇지 않으면 false를 리턴하는 함수 선언
bool isValidvalue(int)
{
    int score{};
    return score >= 0 && score <= 100;
}
// 1-3. 리턴형은 char형, 매개변수는 int형 1개, 매개변수 값 (90이상,80이상,70이상,60이상,그외)에 따라 char형 ('A','B','C','D','F')을 리턴하는 함수 선언
char score2grade(int)
{
    int score{};
    char grade{};
   
    if (score >= 90) {
            grade = 'A';
        }
        else if (score >= 80) {
            grade = 'B';
        }
        else if (score >= 70) {
            grade = 'C';
        }
        else if (score >= 60) {
            grade = 'D';
        }
        else {
            grade = 'F';
        }
    
}
// 1-4. 재귀함수 power를 선언, 리턴형은 double형, 매개변수는 double형 2개, 최종 리턴은 매개변수1^매개변수2
double power(double x, double y)
{
    if (y == 0)
        return 1;
    return x * power(x, y-1);
}
// 1-5. 반복문을 사용하는 getPower함수를 선언, 리턴형은 double형, 매개변수는 double형 2개
double getPower(double x, double y)
{
    int p{1};
    for (int i = 0; i < y; ++i)
        p *= x;
    return p;
}
// 2-0. 본인 분반, 본인 이름 그리고 학번을 순서대로 출력합니다. 
//분반이 00분반, 이름
//main이 Kim Programming, 학번이 3741200이라면, 00 Kim Programming 3741200 
int main()
{    
    std::cout << 
    
    
    
    
    
    return 0;
}
// 2-1. 점수를 나타내는 int형 변수에 1-1함수의 리턴값을 할당
int score{};
score = inputInteger();
// 2-2. 1-2함수(인자는 2-1변수)의 리턴값이 false면 프로그램 종료 (사전정의함수인 exit함수 사용)
if (!isValidvalue(score))
    std::exit(-1);
// 2-3. 1-3함수(인자는 2-1변수)의 리턴값을 터미널로 출력
std::cout << 
// 2-4. 1-4함수의 리턴값을 터미널로 출력 (인자는 원하는 값을 넣으세요)

// 2-5. 1-5함수의 리턴값을 터미널로 출력 (인자는 원하는 값을 넣으세요)

// 2-6. 사전정의함수 pow를 이용하여 2-5와 같은 인자를 넣어 같은 결과가 나오는지 터미널로 출력하여 확인

// 3. 함수 정의
// 3-1. 1-1함수 정의

// 3-2. 1-2함수 정의

// 3-3. 1-3함수 정의 

// 3-4. 1-4함수 정의: 매개변수2가 0이면 1을 리턴, 매개변수1*power(매개변수1,매개변수2-1)을 리턴

// 3-5. 1-5함수 정의: 반복문으로 매개변수1^매개변수2을 구현.
