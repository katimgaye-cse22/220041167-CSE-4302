 #include<iostream>
#include<string>
using namespace std;
class Artwork{
protected:
    string title;
    string artist;
    int price;
public:
    Artwork(string t,string a,int p):title(t),artist(a),price(p){}
    virtual void displayDetails(){
        cout<<"Display title: "<<title<<endl;
        cout<<"Dipslay artist: "<<artist<<endl;
        cout<<"Display price: "<<price<<endl;
    }

    ~Artwork(){}
};
class Painting: public Artwork{
private:
    string medium;
public:
    Painting(string t,string a,int p,string m):Artwork(t,a,p),medium(m){}
    void displayDetails(){
        Artwork::displayDetails();
        cout<<"Medium: "<<medium<<endl;
    }
};
class Sculpture: public Artwork{
private:
    string material;
public:
    Sculpture(string t,string a,int p,string m):Artwork(t,a,p),material(m){}
    void displayDetails(){
        Artwork::displayDetails();
        cout<<"Material: "<<material<<endl;
    }
};
class DigitalArt: public Artwork{
private:
    string resolution;
public:
    DigitalArt(string t,string a,int p,string m):Artwork(t,a,p),resolution(m){}
    void displayDetails(){
        Artwork::displayDetails();
        cout<<"Resolution: "<<resolution<<endl;
    }
};

int main(){
     Artwork* arts[10];
     arts[0]=new Painting("Painting 1","Person 1",100000,"Acrylic");
     arts[1]=new Sculpture("Sculpture 1","Person 2",100000,"Bronze");
     arts[2]=new DigitalArt("NFT 1","Unknown",100000,"800x600");

     return 0;
}
