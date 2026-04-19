#include <iostream>

const double taxRate{0.10};
const double taxClothing{0.05};
const double taxCosmetics{0.15};
const double taxElectronics{0.10};
const int priceUnit{1000};
const int priceTax{50000};
const int priceMin{10000};
const int priceMax{100000};

    //지역 상수는 함수가 시작될 때 생성되어 함수가 종료되면 같이 삭제된다. 전역 상수는 프로그램이 시작될 때 생성되어 프로그램이 종료되면 삭제된다.

enum item
{
    clothing,
    cosmetics,
    electronics,
    numOfItems
};

    //열거형은 첫 번째 단어에 0부터 부여되기에 4개의 단어를 사용할 경우 마지막 단어에 3이 부여되기에 품목수가 열거형의 마지막이 되는 것이다.

void setItem(item&);

    //리턴이 없고 매개변수를 참조로 할 경우, 매개변수의 원본을 직접 다루는 작업이므로 리턴이 있고 매개변수를 없게 하는 경우보다 불필요한 복사를 줄일 수 있는 장점이 있다.

void printItem(const item);

    //const가 있으면 함수가 진행되는 동안 해당 값을 수정할 수 없다. const가 없으면 해당 값을 수정할 수 있다.

struct itemPrice
{
    item itemType{};
    int price{};
    double priceIncludingTax{};
};

void setPrice(int&);

double getTaxRate(int, item);

void showItemPrice(int);

void showItemPrice(int, int);

//오버로딩

//진입점 함수, 진입점 함수로 프로그램을 실행시키면 제어가 운영 체제에서 컴퓨터 프로그램으로 이동하고 프로세서인 CPU는 코드에 진입하여 실행을 시작한다.

int main()
{
    std::cout << "01 Hong ye jin 2649058" << std::endl;
    std::cout << "Enter item count: ";
    int itemCount{};
    std::cin >> itemCount;

    //식별자 단일 정의 규칙은 한 함수 내에서 한 식별자는 하나의 역할만 수행할 수 있다는 것으로, 똑같은 단어에 다중 정의가 불가능하다는 것이다.

    srand(itemCount);

    //난수 생성기는 시퀀스에 따라 실행하는데, 시드를 설정하여 시퀀스가 아닌 이 시드 안에서 작업을 실행할 수 있도록 해주는 것이다.
    
    showItemPrice(itemCount);
    return 0;
}
void setItem(item& s1)
    {
        s1 = static_cast<item>(rand() % numOfItems); //형변환

    }

    void printItem(const item s2)
    {
        switch(s2) {
            case clothing:
                std::cout << "CLOTHING, ";
            case cosmetics:
                std::cout << "COSMETICS, ";
            case electronics:
                std::cout << "ELECTRONICS, ";
            }
    }
    void setPrice(int& s3)
    {
        s3 = rand() % (priceMax + 1) + priceMin;
    }

    double getTaxRate(int s4, item s5)
    {
        if (s4 < priceTax) {
            switch(s5) {
                case clothing:
                    return taxClothing;
                case cosmetics:
                    return taxCosmetics;
                case electronics:
                    return taxElectronics;
            }
        }
        return taxRate;
    }
    // return은 함수 자체를 끝내는 것을 말하고 break는 반복구문, 루프를 빠져나올 때 사용하는 것이다.

    void showItemPrice(int s6)
    {
        itemPrice p{};
        for (int i = 0; i < s6; i++)
        {
            setItem(p.itemType);
            setPrice(p.price);
            p.priceIncludingTax = p.price * (1 + getTaxRate(p.price, p.itemType));
            printItem(p.itemType);
            std::cout << p.priceIncludingTax << " (" << p.price << ", " << getTaxRate(p.price, p.itemType) << ", " << p.price * getTaxRate(p.price, p.itemType) << ")" << std::endl; 
        }
    }
