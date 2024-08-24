

#include <iostream>
#include <vector>

using namespace std;

class HotelRoom {
public:
    HotelRoom(int bedrooms, int bathrooms) 
    : bedrooms_(bedrooms), bathrooms_(bathrooms) {}
    
    int get_price() {
        return 50*bedrooms_ + 100*bathrooms_;
    }
private:
    int bedrooms_;
    int bathrooms_;
};

class HotelApartment : public HotelRoom {
public:
    HotelApartment(int bedrooms, int bathrooms) 
    : HotelRoom(bedrooms, bathrooms) {}

    int get_price() {
        return HotelRoom::get_price() + 100;
    }
};

int main() {
    int n;
    cin >> n;
    vector<HotelRoom*> rooms;
    vector<HotelApartment*> apartments;
    for (int i = 0; i < n; ++i) {
        string room_type;
        int bedrooms;
        int bathrooms;
        cin >> room_type >> bedrooms >> bathrooms;
        if (room_type == "standard") {
            rooms.push_back(new HotelRoom(bedrooms, bathrooms));
        } else {
            apartments.push_back(new HotelApartment(bedrooms, bathrooms));
        }
    }

    int total_profit = 0;
    for (HotelRoom* room : rooms) {
        total_profit += room->get_price();
    }
    for (HotelApartment* apartment: apartments){
        total_profit += apartment->get_price();
    }
    cout << total_profit << endl;

    for (HotelRoom* room : rooms) {
        delete room;
    }
    rooms.clear();
    for (HotelApartment* apartment: apartments){
        delete apartment;
    }
    apartments.clear();

    return 0;
}