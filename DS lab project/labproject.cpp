 #include <iostream>
#include <fstream>
#include <string>
using namespace std;
class mid
{
public:
    int id_med;
    mid* pnext;
};
class clistMID
{
public:
    mid* phead;
    mid* ptail;

    clistMID()
    {
        phead = NULL;
        ptail = NULL;

    }
    ~clistMID()
    {
        mid* ptrav = phead;
        while (ptrav != NULL)
        {
            phead = phead->pnext;

            delete ptrav;
            ptrav = phead;
        }
    }
    void attach(mid* pnn)
    {
        if (phead == NULL)
        {
            phead = pnn;
            ptail = pnn;
        }
        else
        {
            ptail->pnext = pnn;
            ptail = pnn;
        }
    }
    void disp()
    {
        mid* ptemp;
        ptemp = phead;
        while (ptemp != NULL)
        {
            cout << ptemp->id_med << endl;
            ptemp = ptemp->pnext;
        }
    }
};
class med
{
public:
    int id_med;
    string name_med;
    int stock;
    string exp_date;
    int price;
    clistMID alt;
    med* pnext;

};
class clistmed
{
public:
    med* phead;
    med* ptail;
    clistmed()
    {
        phead = NULL;
        ptail = NULL;
    }
    ~clistmed()
    {
        med* ptrav = phead;
        while (ptrav != NULL)
        {
            phead = phead->pnext;
            delete ptrav;
            ptrav = phead;
        }
    }
    void attach(med* pnn)
    {
        if (phead == NULL)
        {
            phead = pnn;
            ptail = pnn;
        }
        else
        {
            ptail->pnext = pnn;
            ptail = pnn;
        }
    }
    void disp()
    {
        med* ptemp;
        ptemp = phead;
        while (ptemp != NULL)
        {
            cout << "id med " << ptemp->id_med << endl;
            cout << "name of med " << ptemp->name_med << endl;
            cout << "the price  " << ptemp->price << endl;
            cout << "stock" << ptemp->stock << endl;
            cout << "exp_date  " << ptemp->exp_date << endl;
            ptemp = ptemp->pnext;
        }
    }

};
class cust
{
public:
    int id_cust;
    string name_cust;
    cust* pnext;
};
class MedCust
{
public:
    int Mid;
    int Cid;
    int price;
    int day;
    int month;
    int year;
    MedCust* pnext;
};
class MC
{
public:
    int idc;
    int idm;
    int price;
    string date;
    MC* pnext;
};
class clistMC
{
public:
    MC* phead;
    MC* ptail;
    clistMC()
    {
        phead = NULL;
        ptail = NULL;
    }
    ~clistMC()
    {
        MC* ptrav = phead;
        while (ptrav != NULL)
        {
            phead = phead->pnext;
            delete ptrav;
            ptrav = phead;
        }
    }
    void attach(MC* pnn)
    {
        if (phead == NULL)
        {
            phead = pnn;
            ptail = pnn;
        }
        else
        {
            ptail->pnext = pnn;
            ptail = pnn;
        }
    }
};
class clistcust
{
public:
    cust* phead;
    cust* ptail;
    clistcust()
    {
        phead = NULL;
        ptail = NULL;
    }
    ~clistcust()
    {
        cust* ptrav = phead;
        while (ptrav != NULL)
        {
            phead = phead->pnext;
            delete ptrav;
            ptrav = phead;
        }

    }
    void attach(cust* pnn)
    {
        if (phead == NULL)
        {
            phead = pnn;
            ptail = pnn;
        }
        else
        {
            ptail->pnext = pnn;
            ptail = pnn;
        }
    }
};
class clistMedCust
{
public:
    MedCust* phead;
    MedCust* ptail;
    clistMedCust()
    {
        phead = NULL;
        ptail = NULL;
    }
    ~clistMedCust()
    {
        MedCust* ptrav = phead;
        while (ptrav != NULL)
        {
            phead = phead->pnext;
            delete ptrav;
            ptrav = phead;
        }
    }
    void attach(MedCust* pnn)
    {
        if (phead == NULL)
        {
            phead = pnn;
            ptail = pnn;
        }
        else
        {
            ptail->pnext = pnn;
            ptail = pnn;
        }
    }
    void disp()
    {
        MedCust* ptemp;
        ptemp = phead;
        while (ptemp != NULL)
        {
            cout << "______________clistMedCust is ____________" << endl;
            cout << "cust id  " << ptemp->Cid << endl;
            cout << "date " << ptemp->day << "/" << ptemp->month << "/" << ptemp->year << endl;
            cout << "med id  " << ptemp->Mid << endl;
            cout << "price  " << ptemp->price << endl;
            ptemp = ptemp->pnext;
        }
    }
    void Remove(int v)
    {
        MedCust* pTrav = phead;
        MedCust* pback = NULL;
        while (pTrav != NULL)
        {
            if (pTrav->Cid == v)
            {
                break;
            }
            pback = pTrav;
            pTrav = pTrav->pnext;

            if (pback != NULL)
            {
                pback->pnext = pTrav->pnext;
                if (ptail == pTrav)
                {
                    ptail = pback;
                }
            }
            else
            {
                phead = pTrav->pnext;
            }

        }
        delete pTrav;
    }
};
void addstock(med* ptravmed, clistmed l1)
{
    int newstock;///////////add stock
    fstream filemed;
    cout << "to update stock number";
    cout << "enter the number to add it in all stock";
    filemed.open("med.txt");
    cin >> newstock;
    ptravmed = l1.phead;
    if (!filemed.is_open())
    {
        cout << "error in openning";
    }
    else
    {
        while (ptravmed != NULL)
        {

            if (ptravmed->stock == 0)
            {
                ptravmed->stock = newstock;
            }

            filemed << ptravmed->id_med << ","
                << ptravmed->name_med << ","
                << ptravmed->stock << ","
                << ptravmed->price << ","
                << ptravmed->exp_date << ",";
            mid* pt = new mid;
            pt = ptravmed->alt.phead;
            while (pt != NULL)
            {
                filemed << pt->id_med;
                pt = pt->pnext;
            }
            filemed << endl;
            ptravmed = ptravmed->pnext;
        }
        cout << "added stock done";
    }

    filemed.close();
}
void add_tomedcust(MedCust* ptravmc, clistMedCust& l3, int meeid, int custid, int x)
{
    int day;
    int month;
    int year;
    cout << "enter day" << endl;
    cin >> day;
    cout << "enter month " << endl;
    cin >> month;
    cout << "enter year" << endl;
    cin >> year;
    MedCust* pnn3 = new MedCust();
    pnn3->Mid = meeid;
    pnn3->Cid = custid;
    pnn3->price = x;
    pnn3->day = day;
    pnn3->month = month;
    pnn3->year = year;
    pnn3->pnext = NULL;
    l3.attach(pnn3);
    cout << "attached done" << endl;
}
void medcheck_add(med* ptravmed, MedCust* ptravmc, clistMedCust& l3, int custid, clistmed& l1)
{
    int alt;
    int med_id;
    cout << "what is ur medicine id " << endl;
    cin >> med_id;
    ptravmed = l1.phead;
    fstream filemed;
    med* ptravmed3;
    ptravmed3 = l1.phead;
    filemed.open("med.txt");
    while (ptravmed != NULL)
    {
        if (ptravmed->id_med == med_id)
        {
            if (ptravmed->stock == 0)/////lw el stock b zero hay5tar wahda mn el alt
            {
                cout << "out of stock" << endl;
                cout << "you can choose from alt list" << endl;
                ptravmed->alt.disp();
                cin >> alt;
                med* ptravmed2 = l1.phead;
                while (ptravmed2 != NULL)
                {
                    if (ptravmed2->id_med == alt)
                    {
                        cout << "id med " << ptravmed2->id_med << endl;
                        cout << "name of med " << ptravmed2->name_med << endl;
                        cout << "the price  " << ptravmed2->price << endl;
                        cout << "stock " << ptravmed2->stock << endl;
                        cout << "exp_date  " << ptravmed2->exp_date << endl;
                        add_tomedcust(ptravmc, l3, med_id, custid, ptravmed2->price);
                        ptravmed = l1.phead;
                        while (ptravmed != NULL)
                        {
                            if (ptravmed->id_med == alt)
                            {
                                ptravmed->stock--;
                            }
                            filemed << ptravmed->id_med << ","
                                << ptravmed->name_med << ","
                                << ptravmed->stock << ","
                                << ptravmed->price << ","
                                << ptravmed->exp_date << ",";
                            mid* pt = new mid;
                            pt = ptravmed->alt.phead;
                            while (pt != NULL)
                            {
                                filemed << pt->id_med;
                                pt = pt->pnext;
                            }
                            filemed << endl;
                            ptravmed = ptravmed->pnext;
                        }
                    }
                    ptravmed2 = ptravmed2->pnext;
                }
                break;

            }
            else///lw mawgod fl stock 3ady
            {
                cout << "medicine name : " << ptravmed->name_med << endl;
                cout << " medicine price : " << ptravmed->price << endl;
                cout << "exp-date of the medicine: " << ptravmed->exp_date << endl;
                cout << "stock of this medicine :" << ptravmed->stock << endl;
                add_tomedcust(ptravmc, l3, med_id, custid, ptravmed->price);
                ptravmed = l1.phead;
                while (ptravmed3 != NULL)
                {
                    if (ptravmed3->id_med == med_id)
                    {
                        ptravmed3->stock--;
                    }
                    filemed << ptravmed3->id_med << ","
                        << ptravmed3->name_med << ","
                        << ptravmed3->stock << ","
                        << ptravmed3->price << ","
                        << ptravmed3->exp_date << ",";
                    mid* pt = new mid;
                    pt = ptravmed3->alt.phead;
                    while (pt != NULL)
                    {
                        filemed << pt->id_med;
                        pt = pt->pnext;
                    }
                    filemed << endl;
                    ptravmed3 = ptravmed3->pnext;
                }
            }
            break;
        }
        ptravmed = ptravmed->pnext;
    }

}
void custcheck(cust* ptrav, int cust_id, clistcust& l2)
{
    fstream filecust;
    cust* pnn2;
    ptrav = l2.phead;
    int i;
    i = 0;
    string newname;
    while (ptrav != NULL)
    {

        if (ptrav->id_cust == cust_id)
        {
            cout << "hello  " << ptrav->name_cust << endl;
            i = 1;
        }
        ptrav = ptrav->pnext;
    }
    if (i == 0)
    {
        filecust.open("cust.txt", ios::in | ios::out | ios::app);
        cout << "enter ur name to save it in our system " << endl;
        cin >> newname;
        pnn2 = new cust();
        pnn2->name_cust = newname;
        pnn2->id_cust = cust_id;
        pnn2->pnext = NULL;
        l2.attach(pnn2);
        if (!filecust.is_open())
        {
            cout << "not open" << endl;
        }
        else
        {
            filecust << endl;
            filecust << newname << "," << cust_id;
            cout << "saved" << endl;
        }

    }
}
int main()
{
    med* pnn;
    clistmed l1;
    cust* pnn2;
    clistcust l2;
    MedCust* pnn3;
    clistMedCust l3;
    fstream filemed;
    fstream filecust;
    string x;
    string y;
    int custid;
    string cust_name;
    string day[5];
    string month[5];
    string year[4];
    filemed.open("med.txt");
    filecust.open("cust.txt");
    if (!filemed.is_open() || !filecust.is_open())
    {
        cout << "NOT OPENED" << endl;
    }
    else
    {
        cout << "welcome" << endl;

        while (getline(filemed, x))
        {
            int ct = 1;
            for (int i = 0; i < x.length(); i++)
            {
                if (x[i] == ',')
                {
                    ct++;
                }
            }
            if (ct == 5)
            {
                string temp[5];
                int it = 0;
                for (int i = 0; i < x.length(); i++)
                {
                    if (x[i] == ',')
                    {
                        it++;
                    }
                    else
                    {
                        temp[it] += x[i];
                    }
                }
                med* pnn = new med();
                pnn->id_med = stoi(temp[0]);
                pnn->name_med = temp[1];
                pnn->stock = stoi(temp[2]);
                pnn->price = stoi(temp[3]);
                pnn->exp_date = temp[4];
                pnn->pnext = NULL;
                l1.attach(pnn);
            }

            else
            {
                int nalt = ct - 5;
                string* temp = new string[ct];
                int it = 0;
                for (int i = 0; i < x.length(); i++)
                {
                    if (x[i] == ',')
                    {
                        it++;
                    }
                    else
                    {
                        temp[it] += x[i];
                    }
                }
                med* pnn = new med();
                pnn->id_med = stoi(temp[0]);
                pnn->name_med = temp[1];
                pnn->stock = stoi(temp[2]);
                pnn->price = stoi(temp[3]);
                pnn->exp_date = temp[4];
                for (int k = 5; k < ct; k++)
                {
                    mid* pt = new mid;
                    pt->id_med = stoi(temp[k]);
                    pt->pnext = NULL;
                    pnn->alt.attach(pt);
                }
                pnn->pnext = NULL;
                l1.attach(pnn);

            }
        }
        filemed.close();
        while (getline(filecust, y))
        {
            string temp2[2];
            int it2 = 0;
            for (int i = 0; i < y.length(); i++)
            {
                if (y[i] == ',')
                {
                    it2++;
                }
                else
                {
                    temp2[it2] += y[i];
                }
            }
            pnn2 = new cust();
            pnn2->name_cust = (temp2[0]);
            pnn2->id_cust = stoi(temp2[1]);
            pnn2->pnext = NULL;
            l2.attach(pnn2);


        }
        filecust.close();
    }
    med* ptravmed;
    ptravmed = l1.phead;
    cust* ptravcust;
    ptravcust = l2.phead;
    MedCust* ptravmc;
    ptravmc = l3.phead;
    for (;;)
    {
        cout << "if you want to buy medicine press 1" << endl;
        cout << "if you want to check medicine exp-date by med_id  press 2" << endl;
        cout << "if you want to check medicine stock by med_id press 3" << endl;
        cout << "if you want to Increase the quantity of all medicine that are zero in stock press 4" << endl;
        cout << "if you want to return medicine press 5" << endl;
        cout << "if you want to Display the income of a specific date press 6" << endl;
        cout << "if you want to Display the medicine with an expiry date within a week. press 7" << endl;
        cout << "if you want to Display the list of med cust press 8" << endl;
        cout << "if you want to exit press 9" << endl;
        int p;
        cin >> p;
        if (p == 1)
        {
            cout << "enter ur id" << endl;
            cin >> custid;
            custcheck(ptravcust, custid, l2);
            medcheck_add(ptravmed, ptravmc, l3, custid, l1);

        }
        if (p == 2)
        {
            cout << "enter the med_id to check the exp-date" << endl;
            int medd_id;
            cin >> medd_id;
            int dd;
            int mm;
            int yy;
            int d;
            int m;
            int ye;
            while (ptravmed != NULL)
            {
                if (ptravmed->id_med == medd_id)
                {
                    day[0] = ptravmed->exp_date[0];
                    day[1] = ptravmed->exp_date[1];
                    d = stoi(day[0] + day[1]);
                    month[0] = ptravmed->exp_date[2];
                    month[1] = ptravmed->exp_date[3];
                    m = stoi(month[0] + month[1]);
                    year[0] = ptravmed->exp_date[4];
                    year[1] = ptravmed->exp_date[5];
                    year[2] = ptravmed->exp_date[6];
                    year[3] = ptravmed->exp_date[7];
                    ye = stoi(year[0] + year[1] + year[2] + year[3]);
                    cout << "enter the date " << endl;
                    cout << "day" << endl;
                    cin >> dd;
                    cout << "month" << endl;
                    cin >> mm;
                    cout << "year" << endl;
                    cin >> yy;
                    if (ye == yy || ye < yy)
                    {
                        if (m < mm)
                        {
                            if (d < dd)
                            {
                                cout << "its expired";
                            }

                        }
                        else
                        {
                            cout << "its not expired";
                        }


                    }
                    else
                    {
                        cout << "its not expired";
                    }

                }
                ptravmed = ptravmed->pnext;
            }
        }
        if (p == 3)
        {
            cout << "enter the med_id to check its stock" << endl;
            int medd_id;
            cin >> medd_id;

            while (ptravmed != NULL)
            {
                if (ptravmed->id_med == medd_id)
                {
                    cout << ptravmed->stock;
                }
                ptravmed = ptravmed->pnext;
            }
        }
        if (p == 4)
        {
            addstock(ptravmed, l1);
        }
        if (p == 5)
        {
            int cust_idd;
            int med_idd;
            filemed.open("med.txt");
            cout << "enter ur id ";
            cin >> cust_idd;
            cout << "enter ur medicine id" << endl;
            cin >> med_idd;
            ptravmc = l3.phead;
            MedCust* pback = NULL;
            while (ptravmc != NULL)
            {
                if (ptravmc == l3.phead && ptravmc->Cid == cust_idd)
                {
                    l3.phead = ptravmc->pnext;
                }
                if (ptravmc->Cid == cust_idd && ptravmc != l3.phead)
                {
                    pback->pnext = ptravmc->pnext;

                }
                if (ptravmc->Cid == cust_idd && ptravmc->pnext == l3.ptail)
                {
                    l3.ptail = ptravmc;
                }
                pback = ptravmc;
                ptravmc = ptravmc->pnext;
            }
            cout << "returned done" << endl;
            ptravmed = l1.phead;
            while (ptravmed != NULL)
            {
                if (ptravmed->id_med == med_idd)
                {
                    ptravmed->stock++;
                }
                filemed << ptravmed->id_med << ","
                    << ptravmed->name_med << ","
                    << ptravmed->stock << ","
                    << ptravmed->price << ","
                    << ptravmed->exp_date << ",";
                mid* pt = new mid;
                pt = ptravmed->alt.phead;
                while (pt != NULL)
                {
                    filemed << pt->id_med;
                    pt = pt->pnext;
                }
                filemed << endl;
                ptravmed = ptravmed->pnext;
            }

        }
        if (p == 6)
        {
            int dayy;
            int monthh;
            int yearr;
            int income;
            cout << "enter the date " << endl;
            cout << "day" << endl;
            cin >> dayy;
            cout << "month" << endl;
            cin >> monthh;
            cout << "year" << endl;
            cin >> yearr;
            income = 0;
            ptravmc = l3.phead;
            while (ptravmc != NULL)
            {
                if (ptravmc->day == dayy && ptravmc->month == monthh && ptravmc->year == yearr)
                {
                    income += ptravmc->price;
                }
                ptravmc = ptravmc->pnext;
            }
            cout << income << "  L.E" << endl;
        }
        if (p == 7)
        {
            ptravmed = l1.phead;
            int dayy;
            int monthh;
            int d;
            int m;
            int mm = 0;
            int z = 0;
            int w = 0;
            cout << "enter the date " << endl;
            cout << "day" << endl;
            cin >> dayy;
            cout << "month" << endl;
            cin >> monthh;
            while (ptravmed != NULL)
            {
                day[0] = ptravmed->exp_date[0];
                day[1] = ptravmed->exp_date[1];
                d = stoi(day[0] + day[1]);
                month[0] = ptravmed->exp_date[2];
                month[1] = ptravmed->exp_date[3];
                m = stoi(month[0] + month[1]);
                if (m <= monthh)
                {
                    for (int i = 1; i <= 7; i++)
                    {
                        z = d + 1;
                        if (z == 31)
                        {
                            z = 1;
                        }
                    }
                    w = dayy;
                    int ctt = 0;
                    for (int i = z; i >= dayy; i--)
                    {
                        if (w == 1)
                        {
                            w = 30;
                        }
                        if (z == w)
                        {
                            cout << ptravmed->name_med << endl;
                            break;
                        }
                        w--;
                        ctt++;
                        if (ctt == 7)
                        {
                            break;
                        }

                    }

                }






                ptravmed = ptravmed->pnext;
            }
        }
        if (p == 8)
        {
            l3.disp();
        }
        if (p == 9)
        {
            break;
        }
    }
}



