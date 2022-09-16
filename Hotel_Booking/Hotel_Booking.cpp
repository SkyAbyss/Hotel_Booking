#include <iostream>

class Hotel
{
    //initializing variables
    std::string RoomType;
    int total = 0;
    int profit = 0;
    int Bedrooms = 0;
    int Bathrooms = 0;

public:
    //creating a constructor for the class Hotel
    Hotel(std::string room_type, int bedrooms, int bathrooms)
    {
        SetBathrooms(bathrooms);
        SetBedrooms(bedrooms);
        setRoomType(room_type);
    }
    //function to modify the number of bedrooms
    void SetBedrooms(int bedrooms)
    {
        Bedrooms = bedrooms;
    }
    //function to modify the number of bathrooms
    void SetBathrooms(int bathrooms)
    {
        Bathrooms = bathrooms;
    }
    //Room type - accepted input : standard and apartment
    void setRoomType(std::string room_type)
    {
        RoomType = room_type;
    }

    void Rules()
    {
        //constraints for bedrooms and bathrooms - accepted range : [1,5]
        if (Bedrooms >= 1 && Bedrooms <= 5)
        {
            if (Bathrooms >= 1 && Bathrooms <= 5)
            {
                if (RoomType == "standard")
                {
                    Rooms();
                }
                else
                    if (RoomType == "apartment")
                    {
                        Apartment();
                    }
            }
            else
            {
                std::cout << "The number of bathrooms is not valid.\n";
            }
        }
        else
        {
            std::cout << "The number of bedrooms is not valid.\n";
        }
    }

    //calculate room price
    void Rooms()
    {
        total = (50 * Bedrooms) + (100 * Bathrooms);
        profit += total;
    }

    //calculate apartment price
    void Apartment()
    {
        total = 100 + (50 * Bedrooms) + (100 * Bathrooms);
        profit += total;
    }

    //for printing out the profit
    void Profit()
    {
        std::cout << profit;
    }
};

int main()
{
    std::string room_type;
    int bedrooms=0, bathrooms=0, n;
    Hotel hotel(room_type, bedrooms, bathrooms);

    std::cout << "Number of bookings for today: ";
    std::cin >> n;
    //Constraint for the number of rooms booked for today
    //Accepted range : [1,100]
    if (n < 1 || n>100)
    {
        return 0;
    }

    for (int i = 1; i <= n; i++)
    {
        std::cout << "\nBooking nr. : " << i << std::endl;
        std::cout << "Room type (standard / apartment):";
        std::cin >> room_type;
        std::cout << "Number of bedrooms (from 1 to 5):";
        std::cin >> bedrooms;
        std::cout << "Number of bathrooms (from 1 to 5):";
        std::cin >> bathrooms;
        hotel.setRoomType(room_type);
        hotel.SetBedrooms(bedrooms);
        hotel.SetBathrooms(bathrooms);
        hotel.Rules();
        if (i == n)
        {
            std::cout << "\nHotel profit for today:";
            hotel.Profit();
        }
    }

    return 0;
}
