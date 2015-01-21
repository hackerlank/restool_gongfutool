#include <iostream>
#include <cmath>
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
	//skin.showMaterialInfo();
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
	for(int d = 9; d >= 0; d--)
	{
		for(int i = 1; i < argc; i++)
		{
			Skin skin(argv[i]);
			skin.calc(list, d);
		}
	}

	ofstream fout("out/m.bone");
	for(int i = 0; i < 200; i++)
	{
		if(list[i])
		{
			cout << i << " =================================" << endl;
			list[i]->print();
			
			Vec3f trans, rot, scale;
			list[i]->decompose(trans, rot, scale);
			fout << i << endl;
			fout << fmt(trans.x) << " " << fmt(trans.y) << " " << fmt(trans.z) << endl;
			//fout << fmt(rot.x) << " " << fmt(rot.y) << " " << fmt(rot.z) << endl;
	
			Quaternion q(rot.x, rot.y, rot.z);
			fout << fmt(q.x) << " " << fmt(q.y) << " " << fmt(q.z) << " " << fmt(q.w) << endl;
				
			if(scale.x - 1 > -0.1 && scale.x - 1 < 0.1)
				scale.x = 1;
			if(scale.y - 1 > -0.1 && scale.y - 1 < 0.1)
				scale.y = 1;
			if(scale.z - 1 > -0.1 && scale.z - 1 < 0.1)
				scale.z = 1;
			
			if(scale.x + 1 > -0.1 && scale.x + 1 < 0.1)
				scale.x = -1;
			if(scale.y + 1 > -0.1 && scale.y + 1 < 0.1)
				scale.y = -1;
			if(scale.z + 1 > -0.1 && scale.z + 1 < 0.1)
				scale.z = -1;

			fout << scale.x << " " << scale.y << " " << scale.z << " " << endl;
		}
	}
	fout.close();
}

void genBoneLink(int argc, char* argv[])
{
	if(argc < 1)
		return;

	Skel skel(argv[1]);

	ofstream fout("out/m.link");
	fout << skel.m_info.boneNames.size() << endl;
	for(int i = 0; i < skel.m_info.boneNames.size(); i++)
	{
		fout << skel.m_info.boneNames[i] << endl;
	}

	SkelFrame frame = skel.m_frames[0];
	for(int i = 0; i < frame.boneDatas.size(); i++)
	{
		BoneData dd = frame.boneDatas[i];
		fout << i << " " << dd.parent << " " << dd.children.size();
		for(int j = 0; j < dd.children.size(); j++)
			fout << " " << dd.children[j];
		fout << endl;
	}
	fout.close();
}


 
int main(int argc, char* argv[])
{
	//read_skel("../system/anigirl/rdy1.skel");
	for(int i = 1; i < argc; i ++)
		read_skel(argv[i]);
	
	//read_skin("../system/shizhuang/sz_04.skin");
	//read_skin("../system/avatargirl/ff01_00.skin");
	//for(int i = 1; i < argc; i ++)
	//	read_skin(argv[i]);
	
	//read_smm("res/smm/64212A26.smm");
	//for(int i = 1; i < argc; i ++)
	//	read_smm(argv[i]);
	

	//genBoneInfo(argc, argv);
	//genBoneLink(argc, argv);
	

}

