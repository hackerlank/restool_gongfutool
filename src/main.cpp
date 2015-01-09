#include <iostream>
#include "util.h"
#include "skel.h"
#include "skin.h"
#include "smm.h"

using namespace std;


void read_skel(const char *filename)
{
	Skel skel(filename);
	//skel.showHeadInfo();
	skel.save();
}

void read_skin(const char *filename)
{
	Skin skin(filename);
	skin.showHeadInfo();
	skin.showMaterialInfo();
	skin.save();
}

void read_smm(const char *filename)
{
	Smm smm(filename);
	smm.showHeadInfo();
	smm.showMaterialInfo();
}
	
void genBoneInfo(int argc, char* argv[])
{
	Matrix4f * list[200] = {0};
	for(int i = 1; i < argc; i ++)
	{
		Skin skin(argv[i]);
		skin.calc(list);
	}

	ofstream fout("res/m.bone");
	for(int i = 0; i < 200; i++)
	{
		if(list[i])
		{
			cout << i << " =================================" << endl;
			list[i]->print();
			
			Vec3f trans, rot, scale;
			list[i]->decompose(trans, rot, scale);
			fout << i << endl;
			fout << trans.x << " " << trans.y << " " << trans.z << endl;
			fout << rot.x << " " << rot.y << " " << rot.z << endl;
			fout << scale.x << " " << scale.y << " " << scale.z << endl;
		}
	}
	fout.close();
}


 
int main(int argc, char* argv[])
{
	//read_skel("../system/anigirl/rdy1.skel");
	//for(int i = 1; i < argc; i ++)
	//	read_skel(argv[i]);
	
	//read_skin("../system/avatargirl/ff01_00.skin");
	//for(int i = 1; i < argc; i ++)
	//	read_skin(argv[i]);
	
	//read_smm("res/smm/64212A26.smm");
	//for(int i = 1; i < argc; i ++)
	//	read_smm(argv[i]);
	

	genBoneInfo(argc, argv);
	


/*----------------------------------
	Matrix4f m1;
	m1.c[0][0] = -3.14993;
	m1.c[0][1] = 161.426;
	m1.c[0][2] = 14.1951;
	m1.c[0][3] = 1;
	m1.c[1][0] = -3.67676;
	m1.c[1][1] = 159.506;
	m1.c[1][2] = 11.7278;
	m1.c[1][3] = 1;
	m1.c[2][0] = -1.6561;
	m1.c[2][1] = 160.763;
	m1.c[2][2] = 10.5656;
	m1.c[2][3] = 1;
	m1.c[3][0] = -1.04695;
	m1.c[3][1] = 161.82;
	m1.c[3][2] = 9.5102;
	m1.c[3][3] = 1;
	

	Matrix4f m2;
	m2.c[0][0] = 3.72407;
	m2.c[0][1] = -3.14992;
	m2.c[0][2] = 1.42379;
	m2.c[0][3] = 1;
	m2.c[1][0] = 2.93437;
	m2.c[1][1] = -3.67676;
	m2.c[1][2] = -1.60075;
	m2.c[1][3] = 1;
	m2.c[2][0] = 1.2474;
	m2.c[2][1] = -1.6561;
	m2.c[2][2] = -1.31099;
	m2.c[2][3] = 1;
	m2.c[3][0] = -0.233055;
	m2.c[3][1] = -1.04695;
	m2.c[3][2] = -1.11483;
	m2.c[3][3] = 1;
	
	m2.print();
	

	Matrix4f r1 = m2 * m1.inverted();
	r1.print();

	Matrix4f m3;
	m3.c[0][0] = -3.14993;
	m3.c[0][1] = 161.426;
	m3.c[0][2] = 14.1951;
	m3.c[0][3] = 1;
	m3.c[1][0] = -3.67676;
	m3.c[1][1] = 159.506;
	m3.c[1][2] = 11.7278;
	m3.c[1][3] = 1;
	m3.c[2][0] = -1.04695;
	m3.c[2][1] = 161.82;
	m3.c[2][2] = 9.5102;
	m3.c[2][3] = 1;
	m3.c[3][0] = -3.67788;
	m3.c[3][1] = 158.447;
	m3.c[3][2] = 17.4254;
	m3.c[3][3] = 1;
	

	Matrix4f m4;
	m4.c[0][0] = 3.72407;
	m4.c[0][1] = -3.14992;
	m4.c[0][2] = 1.42379;
	m4.c[0][3] = 1;
	m4.c[1][0] = 2.93437;
	m4.c[1][1] = -3.67676;
	m4.c[1][2] = -1.60075;
	m4.c[1][3] = 1;
	m4.c[2][0] = -0.233055;
	m4.c[2][1] = -1.04695;
	m4.c[2][2] = -1.11483;
	m4.c[2][3] = 1;
	m4.c[3][0] = 8.10023;
	m4.c[3][1] = -3.67787;
	m4.c[3][2] = 1.02591;
	m4.c[3][3] = 1;
	

	Matrix4f r2 = m4 * m3.inverted();
	r2.print();

	Vec3f trans, rot, scale;
	r1.decompose(trans, rot, scale);
	cout << "trans\t" << trans.x << " " << trans.y << " " << trans.z << endl;
	cout << "rot\t" << rot.x << " " << rot.y << " " << rot.z << endl;
	cout << "scale\t" << scale.x << " " << scale.y << " " << scale.z << endl;



//---------------------------------------*/

}
