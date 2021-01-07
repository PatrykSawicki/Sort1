#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <algorithm>
#include <math.h>

class Point
{
public:

    std::string name;
    float x, y;
    double dis;    //distance = (x * x + y * y);

    Point(std::string = "A", float = 0, float = 0, double = 0);

    void enter_data();


};

Point::Point(std::string c_name, float xx, float yy, double dd)
{
    name = c_name;
    x = xx;
    y = yy;
    dis = dd;
}

//--------------------------------------------------------------------------------------------------------------/
void Point::enter_data()
{
    std::cout << "Point name: "; std::cin >> name;
    std::cout << "Enter x: "; std::cin >> x;
    std::cout << "Enter y: "; std::cin >> y;

    std::cin >> name >> x >> y;

    dis = sqrt(x*x+y*y);
}

bool compare_by_dis(const Point &lhs, const Point &rhs)
{
    return lhs.dis < rhs.dis;
}
bool compare_by_y(const Point &lhs, const Point &rhs)
{
    return lhs.y < rhs.y;
}

void sort(std::vector<Point> &vp)
{
    int input = 0; // user input
    auto *comparator = &compare_by_dis;
    if(input == 0)
        comparator = &compare_by_dis;
    else if (input == 1)
        comparator = &compare_by_y;
    std::sort( vp.begin(), vp.end(),comparator );
}
//****************************************************************************************************************/


int main()
{
    int n, t; //t-tests, n-how many points,
    std::vector<Point> vp;

    std::cout << "Enter the number of tests: ";
    std::cin >> t;

    while(t)
    {
        std::cout << "Enter the number of points to be tested: ";
        std::cin >> n;

        for(int i = 1 ; i <= n; i++)
        {      
            Point pkt1;
            pkt1.enter_data();
            vp.push_back(pkt1);
        }

        sort(vp);
        std::cout << "\n";

        for(unsigned int i = 0 ; i < vp.size(); i++)
        {
            //std::cout << "Point " << i+1 << " - " <<  vp[i].name <<" ";
            std::cout << vp[i].name <<" ";
            std::cout << vp[i].x <<" ";
            std::cout << vp[i].y << std::endl;
        }
        vp.clear();
        //std::cout << "\n";

        t--;
        std::cout << std::endl;
    }
    return 0;
}
