//1. 난수생성기로 생성된 점수와 이에 따른 학점을 출력하는 함수를 정의합니다. 함수이름은 식별자의 규칙에 따라 만듭니다.
// //1-1. 리턴은 없고 매개변수도 없음
// //1-2. 점수를 나타내는 int형 변수와 학점을 나타내는 char형 변수를 선언합니다.
// //1-3. 점수는 rand()함수를 사용하여 50에서 100사이 값으로 할당합니다.
// //1-4. 점수(90이상,80이상,70이상,60이상,그외)에 따라 학점('A','B','C','D','F')을 할당합니다.
// //lab3에서 점수에 따라 학점을 할당하는 부분을 if-else구문/switch 구문을 둘 다 구현해 보았는데 둘 중 원하는 구문을 사용하세요.
// /1-5. score: (점수), grade: (학점)을 터미널에 출력합니다.
void studentScore()
{
    int score{};
    char grade{};
    score = rand() % 51 + 50;
    
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
std::cout << "score: " << score << "grade: " << grade << std::endl;
}
//2. 본인 분반, 본인 이름 그리고 학번을 순서대로 출력합니다.
// //분반이 00분반, 이름이 Kim Programming, 학번이 3741200이라면, 00 Kim Programming 3741200
int main()
{
std::cout << "01 Hong ye jin 2649058" << std::endl;
//3. int형 month와 day를 선언하여 다음과 같이 터미널로 입력받습니다.
// //Enter today's month as a number: (month)
// //Enter today's day: (day)
// //srand 함수의 인자를 month*day를 넣어 호출합니다.
int month{};
int day{};
std::cout << "Enter today's month as a number: ";
std::cin >> month;
std::cout << "Enter today's day: ";
std::cin >> day;
srand(month*day);
//4. 반복순서를 나타내는 변수 count를 선언하고 0으로 초기화합니다.
// //총 반복횟수를 나타내는 기호상수를 선언하고 2로 세팅합니다.
int count{0};
const int totalCount{2};
//5. do-while문에서 총 반복횟수만큼 1번 함수를 호출합니다.
do
{
    studentScore();
    count++;
} while (count < totalCount)
//6. while문에서 총 반복횟수만큼 1번 함수를 호출합니다.
count = 0;
while (count < totalCount)
{
    studentScore();
    count++;
}
//7. for문을 이용하여 총 반복횟수만큼 1번 함수를 호출합니다.
for ()
return 0;
}