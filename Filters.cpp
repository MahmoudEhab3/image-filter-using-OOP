//FCAI – OOP Programming – 2023 - Assignment 1
//Program Name: CS213-2023-20220433-20200660-20220457-A1-Part1.cpp
//Author1 and ID and Email:	"Moaz Mohamed Esmail AbdElhalim" 20220433 moazmohamed.ba@gmail.com
//Author2 and ID and Email:	"Youssef Mohsen Muhammad Abdullah" 20200660 alshbyoussef@gmail.com
//Author3 and ID and Email: "Mahmoud Ehab Helmy" 20220457 Mahmoudehab3214@gmail.com

#include <iostream>
#include <fstream>
#include <cstring>
#include <cmath>
#include <vector>
#include "bmplib.h"

using namespace std;
unsigned char image[SIZE][SIZE];
unsigned char image2[SIZE][SIZE];
unsigned char answer[SIZE][SIZE];

//main menu
vector<string>v={"Black and White","Invert image","Merge images","Flip image","Rotate image","Darken and Lighten","Enlarge Image","Shrink Image"};

//to show all filters
void menu();

//to input image in program.
void loadImage ();

//to save image in files.
void saveImage ();

// filters

///black And White
//produce another version of the image that is black and white.
void blackAndWhite();

///Invert Image
//produce the negative of the image, and you can store it in the file name you give.
void invertImage();

///Merge Image
//take another image and then merge it with the first image
void mergeImages();

///Flip Image
//flip the image horizontally or vertically
void flipImage();

///Rotate Image
//#rotate image 90degree or 180 degree or 270 degree based on user
void rotateImage();

///Darken and lighten
//make the image darker or lighter by 50%
void darkenAndLighten();

///Enlarge Image
//enlarge one of the four quarters of the image into a separate new image
void enlargeImage();

///Shrink Image
//shrink the image dimensions to 1/2, 1/3 or 1/4 the original dimensions
void shrinkimage();



int main() {
    cout<<"Hello World\n";
    loadImage();
    menu();
    saveImage();
    cout<<"Bay\n";
    return 0;
}

//_________________________________________

void menu(){
    int x;
    do {
        cout<<"\tAll filters\n";
        for (int i = 0; i < v.size(); ++i) {
            cout<<"press "<< i+1<<" for "<<v[i]<<endl;
        }
        cout<<"or press 0 to exit\n";
        cout<<"Please Enter number: \n";
        cin>>x;
        switch (x) {
            case 0:
                return;
                break;
            case 1:
                blackAndWhite();
                break;
            case 2:
                invertImage();
                break;
            case 3:
                mergeImages();
                break;
            case 4:
                flipImage();
                break;
            case 5:
                rotateImage();
                break;
            case 6:
                darkenAndLighten();
                break;
            case 7:

                break;

            case 8:
                enlargeImage();
                break;
            case 9:
                shrinkimage();
                break;


        }
    }while(1);

}

//_________________________________________
void loadImage () {
    char imageFileName[100];

    // Get gray scale image file name
    cout << "Enter the source image file name: \n";
    cin >> imageFileName;

    // Add to it .bmp extension and load image
    strcat (imageFileName, ".bmp");
    readGSBMP(imageFileName, image);
}

//_________________________________________
void saveImage () {
    char imageFileName[100];

    // Get gray scale image target file name
    cout << "Enter the target image file name: \n";
    cin >> imageFileName;

    // Add to it .bmp extension and load image
    strcat (imageFileName, ".bmp");
    writeGSBMP(imageFileName, image);
}

//_________________________________________
void blackAndWhite(){
    long long avg=0;
    for (int i = 0; i < 256; ++i) {
        for (int j = 0; j < 256; ++j) {
            avg+=image[i][j];
        }
    }
    avg/=256*256;
    for (int i = 0; i < 256; ++i) {
        for (int j = 0; j < 256; ++j) {
            image[i][j]= image[i][j]>avg ? 255:0;
        }
    }
};

//_________________________________________
void invertImage(){
    for (int i = 0; i < 256; ++i) {
        for (int j = 0; j < 256; ++j) {
            image[i][j]= 255-image[i][j];
        }
    }
};

//_________________________________________
void mergeImages(){
    //get the 2nd image and save it in image2
    {
        cout<<"Please enter name of image file to merge with: \n";
        char imageFileName[100];
        cin>>imageFileName;
        strcat (imageFileName, ".bmp");
        readGSBMP(imageFileName, image2);
    }
    //loop over pixels
    for (int i = 0; i < SIZE; ++i) {
        for (int j = 0; j < SIZE; ++j) {
            //get average of 2 pixels and then save it in image
            int avg=(image[i][j]+image2[i][j])/2;
            image[i][j] =avg;
        }
    }

};

//_________________________________________
void flipImage(){
    cout<<"\tAll flip options\n press 0 for flip horizontally \n press 1 for flip vertically\n Please Enter number: \n";
    int choice;
    cin>>choice;
    switch (choice) {
        case 0:
            //flip horizontally image from math principles turn (x,y) to (x,-y)
            for (int i = 0; i < SIZE; ++i) {
                for (int j = 0; j < SIZE; ++j) {
                    answer[i][SIZE-1-j]=image[i][j];
                }
            }
            break;
        case 1:
            //flip vertically image from math principles turn (x,y) to (-x,y)
            for (int i = 0; i < SIZE; ++i) {
                for (int j = 0; j < SIZE; ++j) {
                    answer[SIZE-1-i][j]=image[i][j];
                }
            }
            break;
    }

    //to save image we take the data from answer var to image var to make other changes on it
    for (int i = 0; i < SIZE; ++i) {
        for (int j = 0; j < SIZE; ++j) {
            image[i][j]=answer[i][j];
        }
    }
};

//_________________________________________
void rotateImage(){
    cout<<"\tAll Rotate Options \npress 0 for rotate 90 degree \npress 1 for rotate 180 degree \npress 2 for rotate 270 degree\n Please Enter number: \n";
    int choice;
    cin>>choice;
    switch (choice) {
        case 0:
            //to rotate 90 degree turn (x,y) to (-y,x)
            for (int i = 0; i < SIZE; ++i) {
                for (int j = 0; j < SIZE; ++j) {
                    answer[j][i]=image[255-i][j];
                }
            }
            break;
        case 1:
            //to rotate 180 degree turn (x,y) to (-x,-y)
            for (int i = 0; i < SIZE; ++i) {
                for (int j = 0; j < SIZE; ++j) {
                    answer[i][j]=image[255-i][255-j];
                }
            }
            break;
        case 2:
            //to rotate 270 degree turn (x,y) to (y,-x)
            for (int i = 0; i < SIZE; ++i) {
                for (int j = 0; j < SIZE; ++j) {
                    answer[j][i]=image[i][255-j];
                }
            }
            break;
    }

    //to save image we take the data from answer var to image var to make other changes on it
    for (int i = 0; i < SIZE; ++i) {
        for (int j = 0; j < SIZE; ++j) {
            image[i][j]=answer[i][j];
        }
    }

}

//_________________________________________
void darkenAndLighten(){

    //get average of pixels
    long long avg=0;
    for (int i = 0; i < SIZE; ++i) {
        for (int j = 0; j < SIZE; ++j) {
            avg+=image[i][j];
        }
    }
    avg/=SIZE*SIZE;

    //get input from user
    cout<<"\tDarken and Lighten options \n press 0 for darken \n press 1 for lighten\n Please Enter number: \n";
    int choice;
    cin>>choice;

    //swtich case to go to case what we want
    switch (choice) {
        case 0:
            for (int i = 0; i < SIZE; ++i) {
                for (int j = 0; j < SIZE; ++j) {
                    image[i][j]=.5*image[i][j];
                }
            }
            break;
        case 1:
            for (int i = 0; i < SIZE; ++i) {
                for (int j = 0; j < SIZE; ++j) {
                    image[i][j]=.5*image[i][j]+avg;
                }
            }
            break;
    }
}
//_________________________________________________________
void enlargeImage(){
    cout<<"Please enter: \n 0 enlarge the first quartile \n 1 enlarge the second quartile \n "
          "2 enlarge the third quartile\n 3 enlarge the fourth quartile\n";
    int choice;
    cin>>choice;
    switch (choice){
        case 0 : // first quartile
            for (int i = 0; i < SIZE/2; i++) {
                for (int j = 0; j < SIZE/2 ; j++) {//1st
                    int nx=2*i,ny=2*j;
                    answer[nx][ny]=image[i][j];
                    answer[nx+1][ny]=image[i][j];
                    answer[nx][ny+1]=image[i][j];
                    answer[nx+1][ny+1]=image[i][j];
                }
            }
            break;
        case 1: // second quartile
            for (int i = 0; i < SIZE/2; i++) { //2nd
                for (int j = 128; j < SIZE; j++) {
                    int nx=2*(i),ny=2*(j-128);
                    answer[nx][ny]=image[i][j];
                    answer[nx+1][ny]=image[i][j];
                    answer[nx][ny+1]=image[i][j];
                    answer[nx+1][ny+1]=image[i][j];
                }
            }
            break;
        case 2 : // third quartile
            for (int i = 128; i < SIZE; i++) {
                for (int j = 0; j < SIZE/2; j++) {//3rd
                    int nx=2*(i-128),ny=2*(j);
                    answer[nx][ny]=image[i][j];
                    answer[nx+1][ny]=image[i][j];
                    answer[nx][ny+1]=image[i][j];
                    answer[nx+1][ny+1]=image[i][j];
                }
            }
            break;
        case 3: // fourth quartile
            for (int i = 128; i < SIZE; i++) { //4th
                for (int j = 128; j < SIZE; j++) {
                    int nx=2*(i-128),ny=2*(j-128);
                    answer[nx][ny]=image[i][j];
                    answer[nx+1][ny]=image[i][j];
                    answer[nx][ny+1]=image[i][j];
                    answer[nx+1][ny+1]=image[i][j];
                }
            }
            break;
    }
    for (int i = 0; i < SIZE; ++i) {
        for (int j = 0; j < SIZE; ++j) {
            image[i][j]=answer[i][j];
        }
    }
}
//____________________________________________________________
void shrinkimage() {
    int n;
    cout << "Shrink to 1-(1/2) 2-(1/3)  3-(1/4)?" << endl;
    cin >> n;
    if (n == 1) {
        int new_width = SIZE / 2;
        int new_height = SIZE / 2;

        for (int y = 0; y < new_height; y++) {
            for (int x = 0; x < new_width; x++) {
                answer[y][x] = image[y * 2][x * 2];
            }
        }
    }
    if (n == 2) {
        int new_width = SIZE / 3;
        int new_height = SIZE / 3;

        for (int y = 0; y < new_height; y++) {
            for (int x = 0; x < new_width; x++) {
                answer[y][x] = image[y * 3][x * 3];
            }
        }
    }
    if (n == 3) {
        int new_width = SIZE / 4;
        int new_height = SIZE / 4;

        for (int y = 0; y < new_height; y++) {
            for (int x = 0; x < new_width; x++) {
                answer[y][x] = image[y * 4][x * 4];
            }
        }
    }

    for (int i = 0; i < SIZE; ++i) {
        for (int j = 0; j < SIZE; ++j) {
            image[i][j]=answer[i][j];
        }
    }
}
