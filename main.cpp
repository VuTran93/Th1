#include"SinhVien.h"
#include"Lop.h"
#include <sstream>


//nhap thong tin sinh vien tu file
void InputInfoSVFromFile(Lop& l, string filename)
{
	ifstream fi(filename);      //khai bao file can doc
	string temp, tempname, tempid, diem;
	int tempdiem;
	SinhVien* newsv;
	do
	{
		getline(fi, temp);          //doc 1 dong cia file va gan vao bie tam thoi temp
		if (temp.empty())
		{
			break;
		}
		int trr = temp.length() - 1;
		int first = 0, second = 0;
		for (int i = 0; i < temp.length(); ++i)
		{
			if (temp.at(i) == ',' && first == 0)
			{
				first = i + 1;        //lay thu tu cot dau tien
			}
			else if (temp.at(i) == ',' && first != 0)
			{
				second = i;        //lay thu tu cot thu 2
			}
		}
		tempname.assign(temp, 0, first - 1);     //lay ky tu trong chuoi
		tempid.assign(temp, (first), second - first); //lay ky tu trong chuoi
		diem.assign(temp, trr, 1);             //lay ky tu trong chuoi
		stringstream str2um(diem);          //chuyen chuoi thanh int
		str2um >> tempdiem;                 //gan gia tri vua chuyen vao 
		l.AddTail(tempname, tempid, tempdiem);
		l.tangSL();
		//newsv = l.CreateSinhVien(tempname, tempid, 5.0);
		//cout << newsv->GetName() << "va" << newsv->GetID() << endl;
	} while (!fi.eof());
}



int main()
{
	Lop l;
	string filename("Danhsach.csv");
	InputInfoSVFromFile(l, filename);
	char k;
	do
	{
		cout << "\n----nhap 'a' hoac 'b', hoac 'c' hoac 'd', hoac 'e' de xem ket qua or '0' to end!----" << endl;
		cin >> k;
		if (k == 'a')
			l.XuatDanhSach();
		else if (k == 'b')
			l.LietKeDiemCaoNhat();
		else if (k == 'c')
			l.LietKeDiemCaoHon4();
		else if (k == 'd')
			l.TimSinhVien();
		else if (k == 'e')
			l.XoaSinhVienCoMa();
	} while (k!='0');
	return 0;
}