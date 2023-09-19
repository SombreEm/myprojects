#include <iostream>
#include <string>
using namespace std;
class Image {
private:
    unsigned short int width;
    unsigned short int height;
    string name;
    string extension;
    unsigned short int imageWeightInByte;
public:
    string format;
    string comment;
    string tags[100];
    unsigned short int rating;
    Image(unsigned short int inputWidth = 1000, unsigned short int inputHeight = 1000) {
        width = inputWidth;
        height = inputHeight;
        format = "";
        comment = "";
        extension = ".jpg";
        generateName(); 
        rating = 0;
        imageWeightInByte = width * height * 3;
    }
    void generateName() {
        name = "Image" + extension;
        for (int i = 0; i < name.size(); i++) {
            if (isdigit(name[i])) {
                name[i] = '.';
            }
        }
    }
    // GET
    unsigned short int getWidth() { return width; }
    unsigned short int getImageWeightInByte() { return imageWeightInByte; }
    string getName() { return name; }

    // SET
    void setWidth(unsigned short int inputWidth) {
        if (inputWidth > 500 && inputWidth < 10000) {
            width = inputWidth;
            imageWeightInByte = width * height * 3;
        }
    }
    void setExtension(const string& newExtension) {
        if (newExtension == ".jpg" || newExtension == ".png" || newExtension == ".tiff") {
            extension = newExtension;
            generateName();
        }
    }
    double getImageSize(const string& unit) {
        if (unit == "KB") {
            return static_cast<double>(imageWeightInByte) / 1024;
        }
        else if (unit == "MB") {
            return static_cast<double>(imageWeightInByte) / (1024 * 1024);
        }
        else if (unit == "GB") {
            return static_cast<double>(imageWeightInByte) / (1024 * 1024 * 1024);
        }
        else {
            cout << "Невідома одиниця виміру: " << unit << endl;
            return -1.0;
        }
    }
};
int main() {
    Image first{ 640, 1280 };
    cout << "Image Name: " << first.getName() << endl;
    first.setWidth(800);
    first.setExtension(".png");
    cout << "Updated Image Name: " << first.getName() << endl;
    double sizeInKB = first.getImageSize("KB");
    double sizeInMB = first.getImageSize("MB");
    double sizeInGB = first.getImageSize("GB");
    cout << "Image Size in Kilobytes (KB): " << sizeInKB << " KB" << endl;
    cout << "Image Size in Megabytes (MB): " << sizeInMB << " MB" << endl;
    cout << "Image Size in Gigabytes (GB): " << sizeInGB << " GB" << endl;

    return 0;
}