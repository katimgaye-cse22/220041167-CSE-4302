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
        cout<<"Title: "<<title<<endl;
        cout<<"Artist: "<<artist<<endl;
        cout<<"price: "<<price<<endl;
    }
    virtual void applyDiscount(float percentage){}
    virtual ~Artwork(){
    cout<<"Base destroyed"<<endl;}
};
class Painting: public Artwork{
private:
    string medium;
    float discountPrice;
public:
    Painting(string t,string a,int p,string m):Artwork(t,a,p),medium(m){}
    void displayDetails(){
        Artwork::displayDetails();
        cout<<"Discount Price: "<<discountPrice<<endl;
        cout<<"Medium: "<<medium<<endl;

    }
    void applyDiscount(float percentage){
        discountPrice=price-(price*percentage/100);
    }
    ~Painting(){cout<<"Painting destroyed"<<endl;}
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
    ~Sculpture(){cout<<"Sculpture destroyed"<<endl;}
};
class DigitalArt: public Artwork{
private:
    string resolution;
    float discountPrice;
public:
    DigitalArt(string t,string a,int p,string m):Artwork(t,a,p),resolution(m){}
    void displayDetails(){
        Artwork::displayDetails();
        cout<<"Discount Price: "<<discountPrice<<endl;
        cout<<"Resolution: "<<resolution<<endl;

    }
    void applyDiscount(float percentage){
        discountPrice=price-(price*(percentage+1)/100);
    }
    ~DigitalArt(){cout<<"DigitalArts destroyed"<<endl;}
};
void DisplayGalleryDetails(Artwork *arts[],int s){
    for(int i=0;i<s;i++){
        arts[i]->displayDetails();
        cout<<endl<<endl;
    }
}
int main(){
     Artwork* arts[10];
     arts[0]=new Painting("Painting 1","Person 1",100000,"Acrylic");
     arts[1]=new Sculpture("Sculpture 1","Person 2",100000,"Bronze");
     arts[2]=new DigitalArt("NFT 1","Unknown",100000,"800x600");
     for (int i=0;i<3;i++){
        arts[i]->applyDiscount(5);
     }
     DisplayGalleryDetails(arts, 3);
     for (int i=0;i<3;i++){
        delete arts[i];
     }
     return 0;
}

