#include <iostream>
#include <list>
#include <string>
#include <cctype>
#include <chrono>
using namespace std;
class thisinh {
    private:
        int id;
        string ten;
        int phongthi;
        double diemthi;
    public:
        bool isValidName(string ten) {
                if (ten.empty()) return false;
                for(char c : ten) {
                    if(isdigit(c)) {
                        return false;
                    }
                }
                return true;
            }
        void input(int index) {
            cout<<"Vui lòng nhập thông tin thí sinh thứ "<<index+1<<":"<<endl;
            cout<<"Số báo danh:" << endl;
            cin>>id;
            cin.ignore();
            cout<<"Họ và tên:" << endl;
            do {
                getline(cin, ten);
                if(!isValidName(ten)) {
                    cout<<"Tên không hợp lệ!"<<endl;
                    cout<<"Vui lòng nhập lại họ và tên:"<<endl;
                }
            } while (!isValidName(ten));
            cout<<"Phòng thi:" << endl;
            cin>>phongthi;
            cout<<"Điểm thi:" << endl;
            cin>>diemthi;
        }
        void display() {
            cout<<"Số báo danh: "<<id<<endl;
            cout<<"Họ và tên: "<<ten<<endl;
            cout<<"Phòng thi: "<<phongthi<<endl;
            cout<<"Điểm thi: "<<diemthi<<endl;
        }
    };
int main() {
    cout<<"------Menu Quản Lý Thí Sinh------"<<endl;
    cout<<"1. Thêm thí sinh"<<endl;
    cout<<"2. Hiển thị danh sách thí sinh"<<endl;
    cout<<"3. Tìm thí sinh theo số báo danh"<<endl;
    cout<<"4. Xóa thí sinh theo số báo danh"<<endl;
    cout<<"5. Sắp xếp thí sinh theo điểm thi"<<endl;
    int choice;
    cin>>choice;
    if (choice <= 0 || choice > 5) {
        cout<<"Lựa chọn không hợp lệ!"<<endl;
        return 0;
    }
    switch(choice) {
        case 1: {
            list<thisinh> danhsachthisinh;
            int n;
            cout<< "Số thí sinh thêm vào danh sách: "<<endl;
            cin>>n;
            do{
                for (int i = 0; i < n; i++) {
                thisinh candidates;
                candidates.input(i);
                danhsachthisinh.push_back(candidates);
                cout<<"Đã nhập xong thí sinh thứ "<<i+1<<endl;
                }
            } while (danhsachthisinh.size() == n-1);
            cout<<"Đã hoàn tất nhập xong "<<n<<" thí sinh"<<endl;
        }
    }
}