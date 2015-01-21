#ifndef __SKIN_H__
#define __SKIN_H__

#include <cmath>
#include "define.h"
#include "vertex.h"
#include "material.h"
#include "utMath.h"


#pragma pack(4)
typedef struct _SkinHead
{
    uint32      Lable;  // 类型标志
    uint8       Version;// 版本

	uint8		vertType;

	uint32 		vertNum;
    uint32 		vertOffset;  

	uint32 		meshNum;
    uint32 		meshOffset;  
	
	uint32 		mtlNum;
    uint32 		mtlOffset;  

	vec3		max;
	vec3		min;

	uint32		reserve[64];
	
} SkinHead;



typedef struct _MeshTri
{
	uint16 index[3];
} MeshTri;

typedef struct _SkinMesh
{
	uint16 baseIndex;
	int mtlId;
	uint16 vertNum;

	vec3 max;
	vec3 min;

	vector<MeshTri> baseFaces;

	int lodNum;
	vector<MeshTri> lodFaces[4];
} SkinMesh;  

typedef struct _SkinBone
{
	int	  boneId;
	float weight;
	vec3  offset;
} SkinBone;

typedef struct _SkinVert
{
	vec3	pos;
	vec3	normal;
	vec2	uv;

	vector<SkinBone> bones;
} SkinVert;

#pragma pack()


class Skin
{
public:
	Skin(const char* filename);
	~Skin();

	void showHeadInfo();
	void showMaterialInfo();

	SkinVert readSkinVert(int i);
	SkinMesh readSkinMesh(int i);
	Material readMaterial(int i);

	void save();
	void calc(Matrix4f * omList[200], int d);
public:
	char 	 m_path[255];
	ifstream m_file;

	SkinHead m_head;

	vector<SkinVert> m_vertList;
	vector<SkinMesh> m_meshList;
	vector<Material> m_mtlList;
};



#endif //__SKIN_H__

