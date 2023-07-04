#include "GenList.h"	
#include<cstdlib>
class CM //commodity
{
public:
	string name;
	double price;
	int num;
	CM()
	{

	}
	CM(string a,double b,int c)
	{
		this->name = a;
		this->price = b;
		this->num = c;
    }
	 CM& operator=(CM& a)
	{
		price = a.price;
		num = a.num;
		
	
		name = a.name;
		return *this;
	}
	 friend ostream& operator<<(ostream& out, CM& v);
};
ostream& operator<<(ostream& out, CM& v)
{
	out << v.name << " "  << v.price<<" " << v.num ;
	return out;
}
int main()
{
	//建立广义表
	//创建大类别的广义表
	GenList<CM> Supermaket;
	
	GenList<CM> HDN;//daily necessities
	GenList<CM> HFD;//food
	GenList<CM> HEA;//Electrical appliances
	//GenList<CM> HOH;//others
	//GenListNode<CM>OH(LIST, NULL); OH.hLink = HOH.GetHead();
	GenListNode<CM>EA(LIST, NULL); EA.hLink = HEA.GetHead();
	GenListNode<CM>FD(LIST, &EA); FD.hLink = HFD.GetHead();
	GenListNode<CM>DN(LIST, &FD); DN.hLink = HDN.GetHead();
	Supermaket.GetHead()->tLink = &DN;
	//大类DN以及其具体商品的完善
	GenList<CM> HCO;//cloth 
	GenList<CM> HPC;//Personal care
	GenList<CM> HFN;//furniture
	GenListNode<CM> CO(LIST, NULL); CO.hLink = HCO.GetHead();
	GenListNode<CM> PC(LIST, &CO); PC.hLink = HPC.GetHead();
	GenListNode<CM> FN(LIST, &PC); FN.hLink = HFN.GetHead();
	HDN.GetHead()->tLink = &FN;
	 //1.FN的完善
	 CM fn1("furniture1", 155.5, 5);
	 CM fn2("furniture2", 255.5, 4);
	 CM fn3("furniture3", 355.5, 3);
	
	GenListNode<CM> FN3(ATOM, NULL,fn3); 
	GenListNode<CM> FN2(ATOM, &FN3, fn2);
	GenListNode<CM> FN1(ATOM, &FN2, fn1);
	HFN.GetHead()->tLink = &FN1;
	//2.PC的完善
	CM pc1("personal care1", 50, 100);
	CM pc2("personal care2", 155.5, 50);
	CM pc3("personal care3", 299.9, 10);
	GenListNode<CM> PC3(ATOM, NULL, pc3);
	GenListNode<CM> PC2(ATOM, &PC3, pc2);
	GenListNode<CM> PC1(ATOM, &PC2, pc1);
	HPC.GetHead()->tLink = &PC1;
	//3.CO的完善
	CM co1("cloth1", 99.9, 50);
	CM co2("cloth2", 49.9, 200);
	CM co3("cloth3", 199.9, 20);
	GenListNode<CM> CO3(ATOM, NULL, co3);
	GenListNode<CM> CO2(ATOM, &CO3, co2);
	GenListNode<CM> CO1(ATOM, &CO2, co1);
	HCO.GetHead()->tLink = &CO1;
	//大类FD以及其具体商品的完善
	GenList<CM> HVE;//vegetable
	GenList<CM> HOI;//oil
	GenList<CM> HMI;//milk
	GenListNode<CM> MI(LIST, NULL); MI.hLink = HMI.GetHead();
	GenListNode<CM> OI(LIST, &MI); OI.hLink = HOI.GetHead();
	GenListNode<CM> VE(LIST, &OI); VE.hLink = HVE.GetHead();
	HFD.GetHead()->tLink = &VE;
	//1.MI的完善
	CM mi1("milk1", 5.5, 100);
	CM mi2("milk2", 7.8, 50);
	CM mi3("milk3", 10.0, 20);

	GenListNode<CM> MI3(ATOM, NULL, mi3);
	GenListNode<CM> MI2(ATOM, &MI3, mi2);
	GenListNode<CM> MI1(ATOM, &MI2, mi1);
	HMI.GetHead()->tLink = &MI1;

	//2.OI的完善
	CM oi1("oil1", 50, 100);
	CM oi2("oil2", 69.9, 70);
	CM oi3("oil3", 111.1, 80);
	GenListNode<CM> OI3(ATOM, NULL, oi3);
	GenListNode<CM> OI2(ATOM, &OI3, oi2);
	GenListNode<CM> OI1(ATOM, &OI2, oi1);
	HOI.GetHead()->tLink = &OI1;

	//3.VE的完善
	CM ve1("vegetable1", 6.6, 100);
	CM ve2("vegetable2", 4.4, 200);
	CM ve3("vegetable3", 2.3, 100);
	GenListNode<CM> VE3(ATOM, NULL, ve3);
	GenListNode<CM> VE2(ATOM, &VE3, ve2);
	GenListNode<CM> VE1(ATOM, &VE2, ve1);
	HVE.GetHead()->tLink = &VE1;

	//大类EA以及其具体商品的完善
	GenList<CM> HKA;//Kitchen appliances
	GenList<CM> HTL;//television 
	GenList<CM> HTD;//Treadmill 跑步机
	
	GenListNode<CM> TD(LIST, NULL); TD.hLink = HTD.GetHead();
	GenListNode<CM> TL(LIST, &TD); TL.hLink = HTL.GetHead();
	GenListNode<CM> KA(LIST, &TL); KA.hLink = HKA.GetHead();
	HEA.GetHead()->tLink = &KA;

	//1.TD的完善
	CM td1("television1", 3999.9, 50);
	CM td2("television2", 4089.9, 4);
	CM td3("television3", 6999.9, 5);
	GenListNode<CM> TD3(ATOM, NULL, td3);
	GenListNode<CM> TD2(ATOM, &TD3, td2);
	GenListNode<CM> TD1(ATOM, &TD2, td1);
	HTD.GetHead()->tLink = &TD1;

	//2.TL的完善
	CM tl1("treadmill1", 4009.9, 100);
	CM tl2("treadmill2", 6999.9, 50);
	CM tl3("treadmill3", 6599.9, 50);
	GenListNode<CM> TL3(ATOM, NULL, tl3);
	GenListNode<CM> TL2(ATOM, &TL3, tl2);
	GenListNode<CM> TL1(ATOM, &TL2, tl1);
	HTL.GetHead()->tLink = &TL1;

	//3.KA的完善
	CM ka1("kitchen appliances1", 409.9, 100);
	CM ka2("kitchen appliances2", 699.9, 200);
	CM ka3("kitchen appliances3", 459.9, 200);
	GenListNode<CM> KA3(ATOM, NULL, ka3);
	GenListNode<CM> KA2(ATOM, &KA3, ka2);
	GenListNode<CM> KA1(ATOM, &KA2, ka1);
	HKA.GetHead()->tLink = &KA1; 

	

	GenList<CM>* HGL=NULL;
	GenListNode<CM>* GLN;
	GenListNode<CM>* A;
	int s1 = 0, s2 = 0, s3 = 0;
	while (1)
	{
		cout << "(Name" << " " << "Price" << " " << "Num)" << endl;
		Supermaket.Show();
		cout << endl;
		cout << "1.插入二级分类" << endl;
		cout << "2.插入商品（先1再2）" << endl;
		cout << "3.删除二级分类" << endl;
		cout << "4.删除商品" << endl;
		cout << "5.进货/出售" << endl;
		cout << "6.各个大类的售出总额" << endl;
		cout << "0.退出程序" << endl;
		int choice; cin >> choice;
		string n1; double n2; int n3; 
		GenListNode<CM>* cur;
		if (choice == 1)
		{
			/*HGL = new GenList<CM>;
			GLN = new GenListNode<CM>(LIST, NULL);
			GLN->hLink = HGL->GetHead();
			GenListNode<CM>* tail = Supermaket.GetHead()->tLink;
			if (tail == NULL)
				Supermaket.GetHead()->tLink = GLN;
			else 
			{
				while (tail->tLink)
				{
					tail = tail->tLink;
				}
				tail->tLink = GLN;
			}*/
			cout << "请输入您想在第n个大类中增加二级分类" << endl;
			int n; cin >> n;
			HGL = new GenList<CM>;
			GLN = new GenListNode<CM>(LIST, NULL);
			GLN->hLink = HGL->GetHead();
			if (n == 1)
			{
				cur=HDN.GetHead()->tLink;
				while (cur->tLink)
				{
					cur = cur->tLink;
				}
				cur->tLink = GLN;
			}
			else if (n == 2)
			{
				cur = HFD.GetHead()->tLink;
				while (cur->tLink)
				{
					cur = cur->tLink;
				}
				cur->tLink = GLN;
			}
			else if (n == 3)
			{
				cur = HEA.GetHead()->tLink;
				while (cur->tLink)
				{
					cur = cur->tLink;
				}
				cur->tLink = GLN;
			}

		}
		else if(choice==2)
		 {
			cout << "请输入您想插入商品的Name Price Num(默认插入新创建的二级分类中)" << endl;
			cin >> n1;
			cin >> n2;
			cin >> n3;
			CM n(n1, n2, n3);
			A = new GenListNode<CM>(ATOM, NULL, n);
			GenListNode<CM>* tail = HGL->GetHead()->tLink;
			if (tail == NULL)
				HGL->GetHead()->tLink = A;
			else
			{
				while (tail->tLink)
				{
					tail = tail->tLink;
				}
				tail->tLink = A;
			}
		}
		else if (choice == 3)
		{
			cout << "输入您想删除第n个大类的第k个二级分类" << endl;
			int n; cin >> n; int k; cin >> k;
			GenListNode<CM>* cur = Supermaket.GetHead()->tLink;		
				for (int i = 1; i < n; i++)
				{
					cur = cur->tLink;
				}
				GenListNode<CM>* p= cur->hLink;
			GenListNode<CM>* ccur=cur->hLink->tLink;
			for (int i = 1; i < k; i++)
			{
				p = ccur;
				ccur = ccur->tLink;
			}
			p->tLink = ccur->tLink;
				
			
		}
		else if (choice == 4)
		{
			cout << "输入您想删除第n个大类的第k个二级分类的第j个商品" << endl;
			int n; cin >> n; int k; cin >> k; int j; cin >> j;
			GenListNode<CM>* cur = Supermaket.GetHead()->tLink;
			for (int i = 1; i < n; i++)
			{
				cur = cur->tLink;
			}
			GenListNode<CM>* ccur = cur->hLink->tLink;
			for (int i = 1; i < k; i++)
			{
				ccur = ccur->tLink;
			}
			GenListNode<CM>* p = ccur->hLink;
			GenListNode<CM>* cccur = ccur->hLink->tLink;
			for (int i = 1; i < j; i++)
			{
				p = cccur;
				cccur = cccur->tLink;
			}
			p->tLink = cccur->tLink;
		}
		else if (choice == 5)
		{
		cout << "输入您想进货第n个大类的第k个二级分类的第j个商品" << endl;
		int n; cin >> n; int k; cin >> k; int j; cin >> j;
		cout << "输入您进货(出售）的数量（进货为正，出售为负）" << endl; int NUM; cin >> NUM;
		GenListNode<CM>* cur = Supermaket.GetHead()->tLink;
		for (int i = 1; i < n; i++)
		{
			cur = cur->tLink;
		}
		GenListNode<CM>* ccur = cur->hLink->tLink;
		for (int i = 1; i < k; i++)
		{
			ccur = ccur->tLink;
		}
		
		GenListNode<CM>* cccur = ccur->hLink->tLink;
		for (int i = 1; i < j; i++)
		{
			cccur = cccur->tLink;
		}
		cccur->atom.num += NUM;
		if (NUM < 0)
		{
			if (n == 1)
				s1 += cccur->atom.price * (-1 * NUM);
			if (n == 2)
				s2 += cccur->atom.price * (-1 * NUM);
			if (n == 3)
				s3 += cccur->atom.price * (-1 * NUM);
		}
        }
		else if (choice == 6)
		{
		cout << "输入您想查询的第n个大类" << endl;
		int n; cin >> n;
		if (n == 1)
			cout << s1 << endl;
		if (n == 2)
			cout << s2 << endl;
		if (n == 3)
			cout << s3 << endl;

		
        }
		else if(choice==0)
		break;
		cout << "按9清理屏幕" << endl;
		int flag; cin >> flag;
		if (flag == 9)
			system("cls");

	}
	return 0;

}