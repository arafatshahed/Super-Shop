#include<bits/stdc++.h>
#include<windows.h>
#include<MMSystem.h>
using namespace std;
class processing
{
private:
    int code,codearr[50],j=0;
    double price,pricearr[50],total=0.00,quantity,stock[50];
    string name[100];
public:
    void welcome()
    {
        cout<<"\n\n\n\n\t\t\tWELCOME TO SUPER SHOPE ZONE\n\n";
        cout<<"\t\tHERE IS THE LIST OF AVAILABLE PRODUCTS\n\n"<<endl;
    }

    void getorder()
    {
        for(;;)
        {
            cout<<"Enter the Product Code : ";
            cin>>code;
            if(code==0)
            {
                break;
            }
            cout<<"Enter the quantity of the product : ";
            cin>>quantity;
            calculation();
            total=processing::ret();

        }
    }
    void calculation()
    {
        int i=1;
        if(code<2000 && code>1000)
        {
            ifstream incg("code_bdgro.txt");
            while(incg>>codearr[i])
            {
                if(codearr[i]==code)
                {
                    j=i-1;
                }
                i++;
            }
            i=0;
            ifstream inpg ("price_bdgro.txt");
            while (inpg>>pricearr[i] )
            {
                if(i==j)
                {
                    price=pricearr[i];

                    break;
                }
                i++;
            }
            i=0;
            ifstream insg ("stock_bdgro.txt");
            while (insg>>stock[i])
            {
                if((i==j && quantity>stock[i])||quantity<0)
                {
                        quantity=0;
                        cout<<"Out of stock.  Our stock is : "<<stock[i]<<endl;
                }
                i++;
            }
            ofstream outsg("stock_bdgro.txt");
            for(int k=0; k<i; k++)
            {
                int s;

                if(k==j)
                {
                    stock[k]=stock[k]-quantity;
                }
                outsg<<stock[k]<<endl;
            }
            total=total+price*quantity;
        }
        else if(code<3000 && code>2000)
        {
            ifstream incv("code_bdveg.txt");
            while(incv>>codearr[i])
            {
                if(codearr[i]==code)
                {
                    j=i-1;
                }
                i++;
            }
            i=0;


            ifstream inpv ("price_bdveg.txt");
            while (! inpv.eof() )
            {
                inpv>>pricearr[i];
                if(i==j)
                {
                    price=pricearr[i];

                    break;
                }
                i++;
            }
            i=0;
            ifstream insv ("stock_bdveg.txt");
            while (insv>>stock[i])
            {
                if((i==j && quantity>stock[i])||quantity<0)
                {
                        quantity=0;
                        cout<<"Out of stock.  Our stock is : "<<stock[i]<<endl;
                }
                i++;
            }
            ofstream outsv("stock_bdveg.txt");
            for(int k=0; k<i; k++)
            {
                if(k==j)
                {
                    stock[k]=stock[k]-quantity;
                }
                outsv<<stock[k]<<endl;
            }
            total=total+price*quantity;
        }
        else if(code<4000 && code>3000)
        {
            ifstream incbr("code_bdres.txt");
            while(incbr>>codearr[i])
            {
                if(codearr[i]==code)
                {
                    j=i-1;
                }
                i++;
            }
            i=0;

            ifstream inpbr ("price_bdres.txt");
            while (! inpbr.eof() )
            {
                inpbr>>pricearr[i];
                if(i==j)
                {
                    price=pricearr[i];

                    break;
                }
                i++;
            }
            i=0;
            ifstream insbr ("stock_bdres.txt");
            while (insbr>>stock[i])
            {
                if((i==j && quantity>stock[i])||quantity<0)
                {
                        quantity=0;
                        cout<<"Out of stock.  Our stock is : "<<stock[i]<<endl;
                }
                i++;
            }
            ofstream outsbr("stock_bdres.txt");
            for(int k=0; k<i; k++)
            {
                if(k==j)
                {
                    stock[k]=stock[k]-quantity;
                }
                outsbr<<stock[k]<<endl;
            }
            total=total+price*quantity;
        }
        else if(code<5000 && code>4000)
        {
            ifstream inccr("code_chi.txt");
            while(inccr>>codearr[i])
            {
                if(codearr[i]==code)
                {
                    j=i-1;
                }
                i++;
            }
            i=0;

            ifstream inpcr ("price_chi.txt");
            while (! inpcr.eof() )
            {
                inpcr>>pricearr[i];
                if(i==j)
                {
                    price=pricearr[i];

                    break;
                }
                i++;
            }

            i=0;
            ifstream inscr ("stock_cr.txt");
            while (inscr>>stock[i])
            {
                if((i==j && quantity>stock[i])||quantity<0)
                {
                        quantity=0;
                        cout<<"Out of stock.  Our stock is : "<<stock[i]<<endl;
                }
                i++;
            }
            ofstream outscr("stock_cr.txt");
            for(int k=0; k<i; k++)
            {
                int s;

                if(k==j)
                {
                    stock[k]=stock[k]-quantity;
                }
                outscr<<stock[k]<<endl;
            }
            total=total+price*quantity;
        }



    }
    double ret()
    {
        return total;
    }
    void exit()
    {
        cout<<"\n\tTotal cost "<<total<<endl;
        cout<<"\n\tTHANKS FOR COMING"<<endl;
    }

};


class bd_grocery:public processing
{
private:
    int c,i=0,codes[50],j;
    double q,total=0.00,prices[50];
    string names[50];
public:
    void welcome()
    {
        processing::welcome();
    }
    void getlist()
    {
        int i=0;

        ifstream inc_bg("code_bdgro.txt");
        while(inc_bg>>codes[i])
        {
            i++;
        }
        j=i;
        i=0;
        ifstream inng_bg("name_bdgro.txt");
        while(inng_bg>>names[i])
        {
            i++;
        }
        i=0;
        ifstream inp_bg("price_bdgro.txt");
        while(inp_bg>>prices[i])
        {
            i++;
        }

    }
    void showlist()
    {
        int c;
        cout<<"\tIndex 	Product Code 	Product Name	Price"<<endl;
        for(c=0; c<j; c++)
        {
            cout<<"\t"<<c+1<<"\t"<<codes[c]<<"\t\t"<<names[c]<<"\t\t"<<prices[c]<<" Taka"<<endl;
        }
        cout<<"\tIF YOU WANT TO EXIT, PRESS '0' IN PRODUCT CODE"<<endl;
    }
    void get_Order()
    {
        processing::getorder();
    }
    void exit()
    {
        processing::exit();
    }
};


class bd_vegetable:public processing
{
private:
    int c,i=0,codes[50],j;
    double q,total=0.00,prices[50];
    string names[50];
public:
    void welcome()
    {
        processing::welcome();
    }
    void getlist()
    {
        int i=0;

        ifstream inc_bv("code_bdveg.txt");
        while(inc_bv>>codes[i])
        {
            i++;
        }
        j=i;
        i=0;
        ifstream inng_bv("name_bdveg.txt");
        while(inng_bv>>names[i])
        {
            i++;
        }
        i=0;
        ifstream inp_bv("price_bdveg.txt");
        while(inp_bv>>prices[i])
        {
            i++;
        }

    }
    void showlist()
    {
        int c;
        cout<<"\tIndex 	Product Code 	Product Name	Price"<<endl;
        for(c=0; c<j; c++)
        {
            cout<<"\t"<<c+1<<"\t"<<codes[c]<<"\t\t"<<names[c]<<"\t\t"<<prices[c]<<" Taka"<<endl;
        }
        cout<<"\tIF YOU WANT TO EXIT, PRESS '0' IN PRODUCT CODE"<<endl;
    }
    void get_Order()
    {
        processing::getorder();
    }
    void exit()
    {
        processing::exit();
    }
};


class bd_restaurants:public processing
{
private:
    int c,i=0,codes[50],j;
    double q,total=0.00,prices[50];
    string names[50];
public:
    void welcome()
    {
        processing::welcome();
    }
    void getlist()
    {
        int i=0;

        ifstream inc_br("code_bdres.txt");
        while(inc_br>>codes[i])
        {
            i++;
        }
        j=i;
        i=0;
        ifstream inng_br("name_bdres.txt");
        while(inng_br>>names[i])
        {
            i++;
        }
        i=0;
        ifstream inp_br("price_bdres.txt");
        while(inp_br>>prices[i])
        {
            i++;
        }

    }
    void showlist()
    {
        int c;
        cout<<"\tIndex 	Product Code 	Product Name	Price"<<endl;
        for(c=0; c<j; c++)
        {
            cout<<"\t"<<c+1<<"\t"<<codes[c]<<"\t\t"<<names[c]<<"\t\t"<<prices[c]<<" Taka"<<endl;
        }
        cout<<"\tIF YOU WANT TO EXIT, PRESS '0' IN PRODUCT CODE"<<endl;
    }
    void get_Order()
    {
        processing::getorder();
    }
    void exit()
    {
        processing::exit();
    }
};
class c_restaurants:public processing
{
private:
    int c,i=0,codes[50],j;
    double q,total=0.00,prices[50];
    string line,names[50];
public:
    void welcome()
    {
        processing::welcome();
    }
    void getlist()
    {
        int i=0;
        ifstream inc_chi("code_chi.txt");
        while(inc_chi>>codes[i])
        {
            i++;
        }
        j=i;
        i=0;
        ifstream inng_chi("name_chi.txt");
        while(inng_chi>>names[i])
        {
            i++;
        }
        i=0;
        ifstream inp_chi("price_chi.txt");
        while(inp_chi>>prices[i])
        {
            i++;
        }

    }
    void showlist()
    {
        int c;
        cout<<"\tIndex 	Product Code 	Product Name	Price"<<endl;
        for(c=0; c<j; c++)
        {
            cout<<"\t"<<c+1<<"\t"<<codes[c]<<"\t\t"<<names[c]<<"\t\t"<<prices[c]<<" Taka"<<endl;
        }
        cout<<"\tIF YOU WANT TO EXIT, PRESS '0' IN PRODUCT CODE"<<endl;
    }
    void get_Order()
    {
        processing::getorder();
    }
    void exit()
    {
        processing::exit();
    }
};
class all
{

private:
    int menu_option;
public:
    void show_category()
    {
        cout<<"\n\n\t\t\t1. BANGLADESHI GROCERY SHOP"<<endl;
        cout<<"\t\t\t2. BANGLADESHI VEGITABLE SHOP"<<endl;
        cout<<"\t\t\t3. BANGLADESHI RESTAURANTS SHOP"<<endl;
        cout<<"\t\t\t4. CHINESE RESTAURANTS SHOP"<<endl;
        cout<<"\t\t\t5. BANGLADESHI GROCERY, RESTAURANTS & VEGITABLE SHOP"<<endl;
    }
    void get_data(bd_grocery gro, bd_vegetable veg, bd_restaurants res, c_restaurants cr)
    {
        cin>>menu_option;
        system("cls");
        switch(menu_option)
        {

        case 1:
        {
            gro.welcome();
            gro.getlist();
            gro.showlist();
            gro.get_Order();
            gro.exit();
            break;
        }
        case 2:
        {
            veg.welcome();
            veg.getlist();
            veg.showlist();
            veg.get_Order();
            veg.exit();
            break;
        }
        case 3:
        {
            res.welcome();
            res.getlist();
            res.showlist();
            res.get_Order();
            res.exit();
            break;
        }
        case 4:
        {
            cr.welcome();
            cr.getlist();
            cr.showlist();
            cr.get_Order();
            cr.exit();
            break;
        }

        case 5:
        {
            gro.welcome();
            gro.getlist();
            gro.showlist();
            veg.getlist();
            veg.showlist();
            res.getlist();
            res.showlist();
            gro.get_Order();
            gro.exit();
            break;

        }
        }

    }

};
class admin
{

private:
    int op1,price[50],code[50],b,c,i=0,j,k;
    string password,name[50],newn;

public:
    int login()
    {
        //start:
        cout << "\n\n\t\t\tWELCOME TO SUPER SHOP ZONE ADMIN PANEL" << endl;
        cout << "\t\t\tLOGIN USING YOUR ADMINASTRATOR PASSWORD : ";
        cin>>password;
        if(password=="123")
        {
            return 1;
        }
        else
        {
            //goto start;
            return 2;
        }

    }
    void showfunc(bd_grocery gro,bd_vegetable veg, bd_restaurants res,c_restaurants cr)
    {
        cout<<"\n\n\t\t1. BD GROCERY"<<endl;
        cout<<"\t\t2. BD VEGITABLE"<<endl;
        cout<<"\t\t3. BD RESTAURANT"<<endl;
        cout<<"\t\t4. CHINESE RESTAURANT"<<endl;
        cin>>op1;
        system("cls");
        if(op1==1)
        {
            int op2;
            show_option();

            cin>>op2;
            system("cls");
            switch(op2)
            {
            case 1:
            {
                add_gro(gro);
                break;
            }

            case 2:
            {
                edit_gro(gro);
                break;

            }
            case 3:
            {
                delete_gro(gro);
                break;
            }
            }
        }
        else if(op1==2)
        {
            int op2;
            show_option();

            cin>>op2;
            system("cls");
            switch(op2)
            {
            case 1:
            {
                add_veg(veg);
                break;
            }

            case 2:
            {
                edit_veg(veg);
                break;

            }
            case 3:
            {
                delete_veg(veg);
                break;
            }
            }

        }
        else if(op1==3)
        {
            int op2;
            show_option();

            cin>>op2;
            system("cls");
            switch(op2)
            {
            case 1:
            {
                add_res(res);
                break;
            }

            case 2:
            {
                edit_res(res);
                break;


            }
            case 3:
            {
                delete_res(res);
                break;

            }
            }

        }
        else if(op1==4)
        {
            int op2;
            show_option();

            cin>>op2;
            system("cls");
            switch(op2)
            {
            case 1:
            {
                add_cr(cr);
                break;
            }

            case 2:
            {
                edit_cr(cr);
                break;
            }
            case 3:
            {
                delete_cr(cr);
                break;
            }
            }

        }




    }

    void show_option()
    {
        system("cls");
        system("color F0");
        cout<<"\n\t\t1. ADD PRODUCT"<<endl;
        cout<<"\n\t\t2. EDIT PRODUCT"<<endl;
        cout<<"\n\t\t3. DELETE PRODUCT"<<endl;
    }
    void add_gro(bd_grocery gro)
    {
        cout<<"\n\n\t\tHere you can add products to Bangladeshi Grocery "<<endl;
        gro.getlist();
        gro.showlist();
        ifstream incg("code_bdgro.txt");
        while(incg>>code[i])
        {
            i++;
        }
        incg.close();
        cout<<"Enter the new product's code : ";
        cin>>b;
        ofstream outcg("code_bdgro.txt");
        for(j=0; j<i; j++)
        {
            outcg<<code[j]<<"\n";
        }
        price[j+1]=b;
        outcg<<price[j+1];
        i=0;
        j=0;
        ifstream inng("name_bdgro.txt");
        while(inng>>name[i])
        {
            i++;
        }
        inng.close();
        cout<<"Enter the new product's name : ";
        cin>>newn;
        ofstream outng("name_bdgro.txt");
        for(j=0; j<i; j++)
        {
            outng<<name[j]<<"\n";
        }
        name[j+1]=newn;
        outng<<name[j+1]<<"\n";
        i=0;
        j=0;


        ifstream inpg("price_bdgro.txt");
        while(inpg>>price[i])
        {
            i++;
        }
        inpg.close();
        cout<<"Enter the new product's price : ";
        cin>>b;
        ofstream outpg("price_bdgro.txt");
        for(j=0; j<i; j++)
        {
            outpg<<price[j]<<"\n";
        }
        price[j+1]=b;
        outpg<<price[j+1];

    }
    void edit_gro(bd_grocery gro)
    {
        cout<<"\n\n\t\tHere you can edit products of Bangladeshi Grocery"<<endl;
        gro.getlist();
        gro.showlist();
        ifstream incg("code_bdgro.txt");
        while(incg >> code[i])
        {
            i++;
        }
        incg.close();
        cout<<"Enter the position ";
        cin>>b;
        cout<<"Enter the updated code ";
        cin>>c;
        ofstream outcg("code_bdgro.txt");
        for(j=0; j<i; j++)
        {
            if(j==b-1)
            {
                code[j]=c;
            }
            outcg<<code[j]<<"\n";
        }
        i=0;
        j=0;

        ifstream in("name_bdgro.txt");
        while(in>>name[i])
        {
            i++;
        }
        in.close();
        cout<<"Enter the new name ";
        cin>>newn;
        ofstream out("name_bdgro.txt");
        for(j=0; j<i; j++)
        {
            if(j==b-1)
            {
                name[j]=newn;
            }
            out<<name[j]<<"\n";
        }
        i=0;
        j=0;
        ifstream inpg("price_bdgro.txt");
        while(inpg >> price[i])
        {
            i++;
        }
        inpg.close();
        cout<<"Enter the updated price ";
        cin>>c;
        ofstream outpg("price_bdgro.txt");
        for(j=0; j<i; j++)
        {
            if(j==b-1)
            {
                price[j]=c;
            }
            outpg<<price[j]<<"\n";
        }



    }
    void delete_gro(bd_grocery gro)
    {
        cout<<"\n\n\t\tHere you can delete products of Bangladeshi Grocery"<<endl;
        gro.getlist();
        gro.showlist();
        ifstream incg("code_bdgro.txt");
        while(incg >> code[i])
        {
            i++;
        }
        incg.close();
        cout<<"Enter the position ";
        cin>>b;
        ofstream outcg("code_bdgro.txt");
        for(j=0; j<i; j++)
        {
            if(j==b-1)
            {

            }
            else
                outcg<<code[j]<<"\n";
        }
        i=0;
        j=0;

        ifstream inng("name_bdgro.txt");
        while(inng>>name[i])
        {
            i++;
        }
        inng.close();
        ofstream outng("name_bdgro.txt");
        for(j=0; j<i; j++)
        {
            if(j==b-1)
            {

            }
            else
                outng<<name[j]<<"\n";
        }
        i=0;
        j=0;
        ifstream inpg("price_bdgro.txt");
        while(inpg >> price[i])
        {
            i++;
        }
        inpg.close();
        ofstream outpg("price_bdgro.txt");
        for(j=0; j<i; j++)
        {
            if(j==b-1)
            {

            }
            else
                outpg<<price[j]<<"\n";
        }



    }

    void add_veg(bd_vegetable veg)
    {
        cout<<"\n\n\t\tHere you can add products to Bangladeshi Vegitable Shop "<<endl;
        veg.getlist();
        veg.showlist();
        ifstream incv("code_bdveg.txt");
        while(incv>>code[i])
        {
            i++;
        }
        incv.close();
        cout<<"Enter the new product's code : ";
        cin>>b;
        ofstream outcv("code_bdveg.txt");
        for(j=0; j<i; j++)
        {
            outcv<<code[j]<<"\n";
        }
        price[j+1]=b;
        outcv<<price[j+1];
        i=0;
        j=0;
        ifstream innv("name_bdveg.txt");
        while(innv>>name[i])
        {
            i++;
        }
        innv.close();
        cout<<"Enter the new product's name : ";
        cin>>newn;
        ofstream outnv("name_bdveg.txt");
        for(j=0; j<i; j++)
        {
            outnv<<name[j]<<"\n";
        }
        name[j+1]=newn;
        outnv<<name[j+1]<<"\n";
        i=0;
        j=0;


        ifstream inpv("price_bdveg.txt");
        while(inpv>>price[i])
        {
            i++;
        }
        inpv.close();
        cout<<"Enter the new product's price : ";
        cin>>b;
        ofstream outpv("price_bdveg.txt");
        for(j=0; j<i; j++)
        {
            outpv<<price[j]<<"\n";
        }
        price[j+1]=b;
        outpv<<price[j+1];

    }

    void edit_veg(bd_vegetable veg)
    {
        cout<<"\n\n\t\tHere you can edit products of Bangladeshi Vegitable shop "<<endl;
        veg.getlist();
        veg.showlist();
        ifstream incv("code_bdveg.txt");
        while(incv >> code[i])
        {
            i++;
        }
        incv.close();
        cout<<"Enter the position ";
        cin>>b;
        cout<<"Enter the updated code ";
        cin>>c;
        ofstream outcv("code_bdveg.txt");
        for(j=0; j<i; j++)
        {
            if(j==b-1)
            {
                code[j]=c;
            }
            outcv<<code[j]<<"\n";
        }
        i=0;
        j=0;

        ifstream innv("name_bdveg.txt");
        while(innv>>name[i])
        {
            i++;
        }
        innv.close();
        cout<<"Enter the new name ";
        cin>>newn;
        ofstream outnv("name_bdveg.txt");
        for(j=0; j<i; j++)
        {
            if(j==b-1)
            {
                name[j]=newn;
            }
            outnv<<name[j]<<"\n";
        }
        i=0;
        j=0;
        ifstream inpv("price_bdveg.txt");
        while(inpv >> price[i])
        {
            i++;
        }
        inpv.close();
        cout<<"Enter the updated price ";
        cin>>c;
        ofstream outpv("price_bdveg.txt");
        for(j=0; j<i; j++)
        {
            if(j==b-1)
            {
                price[j]=c;
            }
            outpv<<price[j]<<"\n";
        }



    }
    void delete_veg(bd_vegetable veg)
    {
        cout<<"\n\n\t\tHere you can delete products of Bangladeshi Vegitable shop "<<endl;
        veg.getlist();
        veg.showlist();
        ifstream incv("code_bdveg.txt");
        while(incv >> code[i])
        {
            i++;
        }
        incv.close();
        cout<<"Enter the position ";
        cin>>b;
        ofstream outcv("code_bdveg.txt");
        for(j=0; j<i; j++)
        {
            if(j==b-1)
            {

            }
            else
                outcv<<code[j]<<"\n";
        }
        i=0;
        j=0;

        ifstream innv("name_bdveg.txt");
        while(innv>>name[i])
        {
            i++;
        }
        innv.close();
        ofstream outnv("name_bdveg.txt");
        for(j=0; j<i; j++)
        {
            if(j==b-1)
            {

            }
            else
                outnv<<name[j]<<"\n";
        }
        i=0;
        j=0;
        ifstream inpv("price_bdveg.txt");
        while(inpv >> price[i])
        {
            i++;
        }
        inpv.close();
        ofstream outpv("price_bdveg.txt");
        for(j=0; j<i; j++)
        {
            if(j==b-1)
            {

            }
            else
                outpv<<price[j]<<"\n";
        }



    }

    void add_res(bd_restaurants res)
    {
        cout<<"\n\n\t\tHere you can add products to Bangladeshi Restaurant "<<endl;
        res.getlist();
        res.showlist();
        ifstream incbr("code_bdres.txt");
        while(incbr>>code[i])
        {
            i++;
        }
        incbr.close();
        cout<<"Enter the new product's code : ";
        cin>>b;
        ofstream outcbr("code_bdres.txt");
        for(j=0; j<i; j++)
        {
            outcbr<<code[j]<<"\n";
        }
        price[j+1]=b;
        outcbr<<price[j+1];
        i=0;
        j=0;
        ifstream innbr("name_bdres.txt");
        while(innbr>>name[i])
        {
            i++;
        }
        innbr.close();
        cout<<"Enter the new product's name : ";
        cin>>newn;
        ofstream outnbr("name_bdres.txt");
        for(j=0; j<i; j++)
        {
            outnbr<<name[j]<<"\n";
        }
        name[j+1]=newn;
        outnbr<<name[j+1]<<"\n";
        i=0;
        j=0;


        ifstream inpbr("price_bdres.txt");
        while(inpbr>>price[i])
        {
            i++;
        }
        inpbr.close();
        cout<<"Enter the new product's price : ";
        cin>>b;
        ofstream outpbr("price_bdres.txt");
        for(j=0; j<i; j++)
        {
            outpbr<<price[j]<<"\n";
        }
        price[j+1]=b;
        outpbr<<price[j+1];

    }
    void edit_res(bd_restaurants res)
    {
        cout<<"\n\n\t\tHere you can edit products of Bangladeshi Restaurant "<<endl;
        res.getlist();
        res.showlist();
        ifstream incbr("code_bdres.txt");
        while(incbr >> code[i])
        {
            i++;
        }
        incbr.close();
        cout<<"Enter the position ";
        cin>>b;
        cout<<"Enter the updated code ";
        cin>>c;
        ofstream outcbr("code_bdres.txt");
        for(j=0; j<i; j++)
        {
            if(j==b-1)
            {
                code[j]=c;
            }
            outcbr<<code[j]<<"\n";
        }
        i=0;
        j=0;

        ifstream innbr("name_bdres.txt");
        while(innbr>>name[i])
        {
            i++;
        }
        innbr.close();
        cout<<"Enter the new name ";
        cin>>newn;
        ofstream outnbr("name_bdres.txt");
        for(j=0; j<i; j++)
        {
            if(j==b-1)
            {
                name[j]=newn;
            }
            outnbr<<name[j]<<"\n";
        }
        i=0;
        j=0;
        ifstream inpbr("price_bdres.txt");
        while(inpbr >> price[i])
        {
            i++;
        }
        inpbr.close();
        cout<<"Enter the updated price ";
        cin>>c;
        ofstream outpbr("price_bdres.txt");
        for(j=0; j<i; j++)
        {
            if(j==b-1)
            {
                price[j]=c;
            }
            outpbr<<price[j]<<"\n";
        }



    }
    void delete_res(bd_restaurants res)
    {
        cout<<"\n\n\t\tHere you can delete products of Bangladeshi Restaurant "<<endl;
        res.getlist();
        res.showlist();
        ifstream incbr("code_bdres.txt");
        while(incbr >> code[i])
        {
            i++;
        }
        incbr.close();
        cout<<"Enter the position ";
        cin>>b;
        ofstream outcbr("code_bdres.txt");
        for(j=0; j<i; j++)
        {
            if(j==b-1)
            {

            }
            else
                outcbr<<code[j]<<"\n";
        }
        i=0;
        j=0;

        ifstream innbr("name_bdres.txt");
        while(innbr>>name[i])
        {
            i++;
        }
        innbr.close();
        ofstream outnbr("name_bdres.txt");
        for(j=0; j<i; j++)
        {
            if(j==b-1)
            {

            }
            else
                outnbr<<name[j]<<"\n";
        }
        i=0;
        j=0;
        ifstream inpbr("price_bdres.txt");
        while(inpbr >> price[i])
        {
            i++;
        }
        inpbr.close();
        ofstream outpbr("price_bdres.txt");
        for(j=0; j<i; j++)
        {
            if(j==b-1)
            {

            }
            else
                outpbr<<price[j]<<"\n";
        }



    }

    void add_cr(c_restaurants cr)
    {
        cout<<"\n\n\t\tHere you can add products to Chinese Restaurant "<<endl;
        cr.getlist();
        cr.showlist();
        ifstream inccr("code_chi.txt");
        while(inccr>>code[i])
        {
            i++;
        }
        inccr.close();
        cout<<"Enter the new product's code : ";
        cin>>b;
        ofstream outccr("code_chi.txt");
        for(j=0; j<i; j++)
        {
            outccr<<code[j]<<"\n";
        }
        price[j+1]=b;
        outccr<<price[j+1];
        i=0;
        j=0;
        ifstream inncr("name_chi.txt");
        while(inncr>>name[i])
        {
            i++;
        }
        inncr.close();
        cout<<"Enter the new product's name : ";
        cin>>newn;
        ofstream outncr("name_chi.txt");
        for(j=0; j<i; j++)
        {
            outncr<<name[j]<<"\n";
        }
        name[j+1]=newn;
        outncr<<name[j+1]<<"\n";
        i=0;
        j=0;


        ifstream inpcr("price_chi.txt");
        while(inpcr>>price[i])
        {
            i++;
        }
        inpcr.close();
        cout<<"Enter the new product's price : ";
        cin>>b;
        ofstream outpcr("price_chi.txt");
        for(j=0; j<i; j++)
        {
            outpcr<<price[j]<<"\n";
        }
        price[j+1]=b;
        outpcr<<price[j+1];

    }
    void edit_cr(c_restaurants cr)
    {
        cout<<"\n\n\t\tHere you can edit products of Chinese Restaurant "<<endl;
        cr.getlist();
        cr.showlist();
        ifstream inccr("code_chi.txt");
        while(inccr >> code[i])
        {
            i++;
        }
        inccr.close();
        cout<<"Enter the position ";
        cin>>b;
        cout<<"Enter the updated code ";
        cin>>c;
        ofstream outccr("code_chi.txt");
        for(j=0; j<i; j++)
        {
            if(j==b-1)
            {
                code[j]=c;
            }
            outccr<<code[j]<<"\n";
        }
        i=0;
        j=0;

        ifstream inncr("name_chi.txt");
        while(inncr>>name[i])
        {
            i++;
        }
        inncr.close();
        cout<<"Enter the new name ";
        cin>>newn;
        ofstream outncr("name_chi.txt");
        for(j=0; j<i; j++)
        {
            if(j==b-1)
            {
                name[j]=newn;
            }
            outncr<<name[j]<<"\n";
        }
        i=0;
        j=0;
        ifstream inpcr("price_chi.txt");
        while(inpcr >> price[i])
        {
            i++;
        }
        inpcr.close();
        cout<<"Enter the updated price ";
        cin>>c;
        ofstream outpcr("price_chi.txt");
        for(j=0; j<i; j++)
        {
            if(j==b-1)
            {
                price[j]=c;
            }
            outpcr<<price[j]<<"\n";
        }
    }
    void delete_cr(c_restaurants cr)
    {
        cout<<"\n\n\t\tHere you can delete products of Chinese Restaurant "<<endl;
        cr.getlist();
        cr.showlist();
        ifstream inccr("code_chi.txt");
        while(inccr >> code[i])
        {
            i++;
        }
        inccr.close();
        cout<<"Enter the position ";
        cin>>b;
        ofstream outccr("code_chi.txt");
        for(j=0; j<i; j++)
        {
            if(j==b-1)
            {

            }
            else
                outccr<<code[j]<<"\n";
        }
        i=0;
        j=0;

        ifstream inncr("name_chi.txt");
        while(inncr>>name[i])
        {
            i++;
        }
        inncr.close();
        ofstream outncr("name_chi.txt");
        for(j=0; j<i; j++)
        {
            if(j==b-1)
            {

            }
            else
                outncr<<name[j]<<"\n";
        }
        i=0;
        j=0;
        ifstream inpcr("price_chi.txt");
        while(inpcr >> price[i])
        {
            i++;
        }
        inpcr.close();
        ofstream outpcr("price_chi.txt");
        for(j=0; j<i; j++)
        {
            if(j==b-1)
            {

            }
            else
                outpcr<<price[j]<<"\n";
        }



    }

};
int main()
{
    char op,op1;
    bd_grocery gro;
    bd_vegetable veg;
    bd_restaurants res;
    c_restaurants cr;
    all sp;
    admin ad;
beg:
    system("color 80");
    cout<<"\n\n\t\t\t'c' FOR CUSTOMER\n\t\t\t'a' FOR ADMIN  : ";
    cin>>op1;
    system("cls");
    if(op1=='c')
    {
        for(;;)
        {
            sp.show_category();
            PlaySound(TEXT("welcome_customer.wav"),NULL,SND_SYNC);
            sp.get_data(gro,veg,res,cr);
            goto beg;

        }

    }
    else if(op1=='a')
    {
        PlaySound(TEXT("welcome_admin.wav"),NULL,SND_SYNC);
start:
        int pass;
        if(ad.login()==1)
        {
            system("cls");
            system("color 2F");
            for(;;)
            {
                char opt1;
                ad.showfunc(gro,veg,res,cr);
                cout<<"\n\n\t\t\tTo continue press 'y' : ";
                cin>>opt1;
                system("cls");
                if(opt1!='y')
                {
                    goto beg;
                }

            }


        }
        else
        {
            system("cls");
            cout<<"\n\n\t\tWRONG PASSWORD ! TRY AGAIN\a"<<endl;
            system("color CF");
            goto start;
        }

    }
}






