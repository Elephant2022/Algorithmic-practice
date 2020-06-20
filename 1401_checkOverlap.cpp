#include <iostream>

class Solution
{
public:
    bool checkOverlap(int radius, int x_center, int y_center, int x1, int y1, int x2, int y2)
    {
        float midX = (x1 + x2) / 2.f;
        float midY = (y1 + y2) / 2.f;
        float diagonal = sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
        float distance = sqrtf(pow(abs(x_center - midX), 2) + pow(abs(y_center - midY), 2));

		if (distance > (radius + diagonal / 2.f))
		{
			return false;
		}
		else if (distance <= radius)
		{
			return true;
		}

        float minLengthX = radius + (x2 - x1) / 2.f;
        float minLengthY = radius + (y2 - y1) / 2.f;

        float curLengthX = abs(distance * cosf(atanf((y_center - midY) / (x_center - midX))));
        float curLengthY = abs(distance * sinf(atanf((y_center - midY) / (x_center - midX))));

        if (curLengthX <= minLengthX && curLengthY <= minLengthY)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
};

int main()
{
    Solution p;
	if (p.checkOverlap(1, 50, 50, 0, 0, 100, 100))
    {
        std::cout << "true" << std::endl;
    }
    else
    {
        std::cout << "false" << std::endl;
    }
}