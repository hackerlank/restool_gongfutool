#include "util.h"

float fmt(float n)
{
	if(abs(n) < 0.001)
		return 0;
	return n;
}

const unsigned long globe_Crc32Table[256]={
0x00000000,0x04c11db7,0x09823b6e,0x0d4326d9,0x130476dc,0x17c56b6b,0x1a864db2,0x1e475005,
0x2608edb8,0x22c9f00f,0x2f8ad6d6,0x2b4bcb61,0x350c9b64,0x31cd86d3,0x3c8ea00a,0x384fbdbd,
0x4c11db70,0x48d0c6c7,0x4593e01e,0x4152fda9,0x5f15adac,0x5bd4b01b,0x569796c2,0x52568b75,
0x6a1936c8,0x6ed82b7f,0x639b0da6,0x675a1011,0x791d4014,0x7ddc5da3,0x709f7b7a,0x745e66cd,
0x9823b6e0,0x9ce2ab57,0x91a18d8e,0x95609039,0x8b27c03c,0x8fe6dd8b,0x82a5fb52,0x8664e6e5,
0xbe2b5b58,0xbaea46ef,0xb7a96036,0xb3687d81,0xad2f2d84,0xa9ee3033,0xa4ad16ea,0xa06c0b5d,
0xd4326d90,0xd0f37027,0xddb056fe,0xd9714b49,0xc7361b4c,0xc3f706fb,0xceb42022,0xca753d95,
0xf23a8028,0xf6fb9d9f,0xfbb8bb46,0xff79a6f1,0xe13ef6f4,0xe5ffeb43,0xe8bccd9a,0xec7dd02d,
0x34867077,0x30476dc0,0x3d044b19,0x39c556ae,0x278206ab,0x23431b1c,0x2e003dc5,0x2ac12072,
0x128e9dcf,0x164f8078,0x1b0ca6a1,0x1fcdbb16,0x018aeb13,0x054bf6a4,0x0808d07d,0x0cc9cdca,
0x7897ab07,0x7c56b6b0,0x71159069,0x75d48dde,0x6b93dddb,0x6f52c06c,0x6211e6b5,0x66d0fb02,
0x5e9f46bf,0x5a5e5b08,0x571d7dd1,0x53dc6066,0x4d9b3063,0x495a2dd4,0x44190b0d,0x40d816ba,
0xaca5c697,0xa864db20,0xa527fdf9,0xa1e6e04e,0xbfa1b04b,0xbb60adfc,0xb6238b25,0xb2e29692,
0x8aad2b2f,0x8e6c3698,0x832f1041,0x87ee0df6,0x99a95df3,0x9d684044,0x902b669d,0x94ea7b2a,
0xe0b41de7,0xe4750050,0xe9362689,0xedf73b3e,0xf3b06b3b,0xf771768c,0xfa325055,0xfef34de2,
0xc6bcf05f,0xc27dede8,0xcf3ecb31,0xcbffd686,0xd5b88683,0xd1799b34,0xdc3abded,0xd8fba05a,
0x690ce0ee,0x6dcdfd59,0x608edb80,0x644fc637,0x7a089632,0x7ec98b85,0x738aad5c,0x774bb0eb,
0x4f040d56,0x4bc510e1,0x46863638,0x42472b8f,0x5c007b8a,0x58c1663d,0x558240e4,0x51435d53,
0x251d3b9e,0x21dc2629,0x2c9f00f0,0x285e1d47,0x36194d42,0x32d850f5,0x3f9b762c,0x3b5a6b9b,
0x0315d626,0x07d4cb91,0x0a97ed48,0x0e56f0ff,0x1011a0fa,0x14d0bd4d,0x19939b94,0x1d528623,
0xf12f560e,0xf5ee4bb9,0xf8ad6d60,0xfc6c70d7,0xe22b20d2,0xe6ea3d65,0xeba91bbc,0xef68060b,
0xd727bbb6,0xd3e6a601,0xdea580d8,0xda649d6f,0xc423cd6a,0xc0e2d0dd,0xcda1f604,0xc960ebb3,
0xbd3e8d7e,0xb9ff90c9,0xb4bcb610,0xb07daba7,0xae3afba2,0xaafbe615,0xa7b8c0cc,0xa379dd7b,
0x9b3660c6,0x9ff77d71,0x92b45ba8,0x9675461f,0x8832161a,0x8cf30bad,0x81b02d74,0x857130c3,
0x5d8a9099,0x594b8d2e,0x5408abf7,0x50c9b640,0x4e8ee645,0x4a4ffbf2,0x470cdd2b,0x43cdc09c,
0x7b827d21,0x7f436096,0x7200464f,0x76c15bf8,0x68860bfd,0x6c47164a,0x61043093,0x65c52d24,
0x119b4be9,0x155a565e,0x18197087,0x1cd86d30,0x029f3d35,0x065e2082,0x0b1d065b,0x0fdc1bec,
0x3793a651,0x3352bbe6,0x3e119d3f,0x3ad08088,0x2497d08d,0x2056cd3a,0x2d15ebe3,0x29d4f654,
0xc5a92679,0xc1683bce,0xcc2b1d17,0xc8ea00a0,0xd6ad50a5,0xd26c4d12,0xdf2f6bcb,0xdbee767c,
0xe3a1cbc1,0xe760d676,0xea23f0af,0xeee2ed18,0xf0a5bd1d,0xf464a0aa,0xf9278673,0xfde69bc4,
0x89b8fd09,0x8d79e0be,0x803ac667,0x84fbdbd0,0x9abc8bd5,0x9e7d9662,0x933eb0bb,0x97ffad0c,
0xafb010b1,0xab710d06,0xa6322bdf,0xa2f33668,0xbcb4666d,0xb8757bda,0xb5365d03,0xb1f740b4
};



bool Util::mkdir(const char *path)
{  

	char DirName[256];  
	strcpy(DirName, path);  

	for(int t = 0; t < strlen(DirName); t++)
	{
		if(DirName[t] == '\\')
			DirName[t] = '/';
	}


	int len = strlen(DirName);  
	
	if(DirName[len-1] != '/')
		strcat(DirName,   "/");  

	len = strlen(DirName);  

	for(int i = 1; i<len; i++)  
	{  
		if(DirName[i]=='/')  
		{  
			DirName[i] = 0;  
			if(access(DirName, 0) != 0)  
			{  
				if(::mkdir(DirName, 0755) == -1)  
				{   
					cout << "[Util]mkdir failed: " << DirName << endl;
					return false;   
				}
			}
			DirName[i] = '/';  
		} 
	} 
	
	return true;  
}  

void Util::fname(const char* path, char* name)
{
	int i;
	for(i = strlen(path); i > 0; i--)
	{
		if(path[i] == '/' || path[i] == '\\')
		{
			break;
		}
	}
	strcpy(name, path+i+1);  
}

void Util::fpath(const char* path, char* dir)
{
	strcpy(dir, path);  
	for(int i = strlen(dir); i > 0; i--)
	{
		if(dir[i] == '/' || dir[i] == '\\')
		{
			dir[i] = '\0';
			break;
		}
	}
}

void Util::fcopy(const char* path, const char* dest, bool delflag)
{
	char p[256];
	Util::fpath(path, p);
	Util::mkdir(p);
	Util::fpath(dest, p);
	Util::mkdir(p);

	strcpy(p, dest);  
	for(int t = 0; t < strlen(p); t++)
	{
		if(p[t] == '\\')
			p[t] = '/';
	}
	cout <<"[OP]copy " << path << " -> " << p << endl;

	ifstream in(path, ios::in|ios::binary);
	if(in.is_open())
	{
	    ofstream out(p, ios::out|ios::binary);

	    out << in.rdbuf();
	    out.close();
	    in.close();

		if(delflag)
	    	::remove(path);
	}
}

const char* Util::guess(const char *data)
{
	//MAGIC
	//AKK-SKEL-SKIN
	//SMM-SCN-NAV-GMB
	//DDS->DDS
	//BMP->BM
	//JPG->0xd8ff
	static const char *TagList[11] = {"SKEL", "SKIN", "AKK", "QTD", "SMM", "SCN", "NAV", "GMB", "TRN", "DDS", "BM"};
	static const char *ExtList[11] = {".skel", ".skin", ".fak", ".qtd", ".smm", ".scn", ".nav", ".gmb", ".trn", ".dds", ".bmp"};

	for(int i = 0; i < 11; i ++)
	{
		bool flag = true;
		const char *tag = TagList[i];
		for(int j = 0; j < strlen(tag); j ++)
		{
			if(data[j] != tag[j])
			{
				flag = false;
				break;
		    }
		}

		if(flag)
			return ExtList[i];

	}

	if(data[0] == (char)0xff && data[1] == (char)0xd8)
		return ".jpg";

	if(data[0] == (char)0x00 && data[1] == (char)0x00)
		return ".tga";

	return "";
}

//-----------------------------------------------------------------------------
// 计算32位CRC,比一般算法快速很多
//-----------------------------------------------------------------------------
uint32 Util::crc32(const char* pData, int nByteCount)
{
	if( nByteCount <= 0 )
		return 0;

	uint32 unResult = *pData++ << 24;
	if( --nByteCount > 0 )
	{
		unResult |= *pData++ << 16;
		if( --nByteCount > 0 )
		{
			unResult |= *pData++ << 8;
			if( --nByteCount > 0 ) unResult |= *pData++;
		}
	}
	unResult = ~ unResult;
	while( --nByteCount > 0 )
	{
		unResult = (unResult << 8 | *pData) ^ globe_Crc32Table[unResult >> 24];
		pData++;
	}

	return ~unResult;
}



void Util::transSkin(const char* dest)
{

	mkdir(dest);

	ifstream ff("res/skinlist");

	char path[256];
	char tex[256];
	int  n;
	while(true)
	{
		ff >> path >> n;
		if(ff.eof())
			break;

		cout << path << "  "<< n << endl;
		for(int i = 0; i < n; i ++)
		{
			ff >> tex;

			int m = 0;
			while(tex[m])  
			{
	  			tex[m] = tolower(tex[m]);  
				m++;
			}

			char dir[256];
			Util::fpath(tex, dir);
			int pcrc = Util::crc32(dir, strlen(dir));

			int crc = Util::crc32(tex, strlen(tex));
			char srcPath[256];
			sprintf(srcPath, "../gameres/system.cpk/%X/%X.tga", pcrc, crc);
			char dstPath[256];
			strcpy(dstPath, dest);
			strcat(dstPath, tex);
			for(int m = 0; m < strlen(dstPath); m ++)
				if(dstPath[m] == '\\')
					dstPath[m] = '/';

			
			Util::fcopy(srcPath, dstPath, false);


			tex[m-3] = 'd';
			tex[m-2] = 'd';
			tex[m-1] = 's';

			crc = Util::crc32(tex, strlen(tex));

			sprintf(srcPath, "../gameres/system.cpk/%X/%X.tga", pcrc, crc);
			tex[m-3] = 't';
			tex[m-2] = 'g';
			tex[m-1] = 'a';


			strcpy(dstPath, dest);
			strcat(dstPath, tex);
			for(int m = 0; m < strlen(dstPath); m ++)
				if(dstPath[m] == '\\')
					dstPath[m] = '/';


			Util::fcopy(srcPath, dstPath, false);
		}

		char skinPath[256];
		strcpy(skinPath, dest);
		strcat(skinPath, tex);

		if(n > 1)
		{
			for(int t = strlen(skinPath); t > 0; t--)
			{
				if(skinPath[t] == '.')
					skinPath[t] = '\0';

				if(skinPath[t] == '_')
				{
					skinPath[t] = '\0';
					break;
				}

			}
			strcat(skinPath, ".skin");
		}
		else
		{
			int t = strlen(skinPath);
			skinPath[t-3] = 's';
			skinPath[t-2] = 'k';
			skinPath[t-1] = 'i';
			skinPath[t] = 'n';
			skinPath[t+1] = '\0';
		}
		Util::fcopy(path, skinPath, false);

	}

}


void Util::transSkel(const char* dest)
{

	mkdir(dest);

	ifstream ff("res/skellist");

	char path[256];
	int  n;
	while(true)
	{
		ff >> path >> n;
		//cout << path << endl;
		if(ff.eof())
			break;

		char name[256] = {0};
		char last[32] = {0};
		char temp[32] = {0};
		for(int i = 0; i < n; i ++)
		{
			ff >> temp;
			if(strcmp(temp, last) != 0)
			{
				if(i > 0)
					strcat(name, "_");
				strcat(name, temp);
				strcpy(last, temp);
			}
		}


		char tdir[32] = {0};
		int d1 = 0;
		int d2 = 0;
		for(int i = strlen(path); i > 0; i--)
		{
			if(path[i] == '/')
			{
				if(d1 == 0)
					d1 = i;
				else
				{
					d2 = i;
					break;
				}

			}
		}
		strncpy(tdir, path + d2 + 1, d1 - d2);

		char skelPath[256];
		strcpy(skelPath, dest);
		strcat(skelPath, tdir);
		strcat(skelPath, name);
		strcat(skelPath, ".skel");
		cout << "copy skel file: " << skelPath << endl;
		Util::fcopy(path, skelPath, false);
	}

}


void Util::transSmm(const char* dest)
{

	mkdir(dest);

	ifstream ff("res/smmlist");

	char path[256];
	char tex[256];
	int  n;
	while(true)
	{
		ff >> path >> n;
		if(ff.eof())
			break;

		cout << path << "  "<< n << endl;
		char dir[256];
		int pcrc;
		int crc;
		for(int i = 0; i < n; i ++)
		{
			ff >> tex;

			int m = 0;
			while(tex[m])  
			{
	  			tex[m] = tolower(tex[m]);  
				m++;
			}
			cout << tex << endl;

			Util::fpath(tex, dir);
			pcrc = Util::crc32(dir, strlen(dir));
			crc = Util::crc32(tex, strlen(tex));
			char srcPath[256];
			sprintf(srcPath, "../gameres/system.cpk/%X/%X.tga", pcrc, crc);
			char dstPath[256];
			strcpy(dstPath, dest);
			strcat(dstPath, tex);
			Util::fcopy(srcPath, dstPath, false);


			tex[m-3] = 'd';
			tex[m-2] = 'd';
			tex[m-1] = 's';

			crc = Util::crc32(tex, strlen(tex));

			sprintf(srcPath, "../gameres/system.cpk/%X/%X.tga", pcrc, crc);
			tex[m-3] = 't';
			tex[m-2] = 'g';
			tex[m-1] = 'a';


			strcpy(dstPath, dest);
			strcat(dstPath, tex);

			Util::fcopy(srcPath, dstPath, false);
		}

		int dirLen = strlen(dir);
		const char *tagList = "cdngbjqzs";
		for(int i = 0; i < 99; i++)
		{
			for(int j = 0; j < strlen(tagList); j++)
			{
				dir[dirLen] = '\\';
				dir[dirLen + 1] = tagList[j];
				dir[dirLen + 2] = 48 + i/10;
				dir[dirLen + 3] = 48 + i%10;
				dir[dirLen + 4] = '.';
				dir[dirLen + 5] = 'f';
				dir[dirLen + 6] = 's';
				dir[dirLen + 7] = 'm';
				dir[dirLen + 8] = '\0';

				char crcPath[256];
				crc = Util::crc32(dir, strlen(dir));
				sprintf(crcPath, "../gameres/system.cpk/%X/%X.smm", pcrc, crc);
				if(strcmp(path, crcPath) == 0)
				{
					strcpy(tex, dir);
					i = 100;
					break;
				}
			}
		}

		char smmPath[256];
		strcpy(smmPath, dest);
		strcat(smmPath, tex);

		for(int t = strlen(smmPath); t > 0; t--)
			if(smmPath[t] == '\\')
				smmPath[t] = '/';


		for(int t = strlen(smmPath); t > 0; t--)
		{
			if(smmPath[t] == '.')
				smmPath[t] = '\0';

			if(smmPath[t] == '_')
			{
				smmPath[t] = '\0';
				break;
			}

		}

		strcat(smmPath, ".smm");
		Util::fcopy(path, smmPath, false);
	}

}


void Util::transFak(const char* dest)
{

	mkdir(dest);

	ifstream ff("res/faklist");

	char path[256];
	char tex[256];
	int  n;
	while(true)
	{
		ff >> path >> n;
		if(ff.eof())
			break;

		cout << path << "  "<< n << endl;
		ff.getline(tex, 256);
		for(int i = 0; i < n; i ++)
		{
			ff.getline(tex, 256);
			cout << tex << endl;

			int m = 0;
			while(tex[m])  
			{
	  			tex[m] = tolower(tex[m]);  
				m++;
			}

			char dir[256];
			Util::fpath(tex, dir);
			int pcrc = Util::crc32(dir, strlen(dir));

			int crc = Util::crc32(tex, strlen(tex));
			char srcPath[256];
			sprintf(srcPath, "../gameres/system.cpk/%X/%X.tga", pcrc, crc);
			char dstPath[256];
			strcpy(dstPath, dest);
			strcat(dstPath, tex);
			for(int m = 0; m < strlen(dstPath); m ++)
				if(dstPath[m] == '\\')
					dstPath[m] = '/';

			
			Util::fcopy(srcPath, dstPath, false);


			tex[m-3] = 'd';
			tex[m-2] = 'd';
			tex[m-1] = 's';

			crc = Util::crc32(tex, strlen(tex));

			sprintf(srcPath, "../gameres/system.cpk/%X/%X.tga", pcrc, crc);
			tex[m-3] = 't';
			tex[m-2] = 'g';
			tex[m-1] = 'a';


			strcpy(dstPath, dest);
			strcat(dstPath, tex);
			for(int m = 0; m < strlen(dstPath); m ++)
				if(dstPath[m] == '\\')
					dstPath[m] = '/';


			Util::fcopy(srcPath, dstPath, false);
		}

		char fakPath[256];
		strcpy(fakPath, dest);
		strcat(fakPath, tex);

		if(n > 1)
		{
			for(int t = strlen(fakPath); t > 0; t--)
			{
				if(fakPath[t] == '.')
					fakPath[t] = '\0';

				if(fakPath[t] == '_')
				{
					fakPath[t] = '\0';
					break;
				}

			}
			strcat(fakPath, ".fak");
		}
		else
		{
			int t = strlen(fakPath);
			fakPath[t-3] = 'f';
			fakPath[t-2] = 'a';
			fakPath[t-1] = 'k';
			fakPath[t] = '\0';
		}
		Util::fcopy(path, fakPath, false);

	}

}


