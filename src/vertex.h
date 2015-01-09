#ifndef __VERTEX_H__
#define __VERTEX_H__

#include "define.h"


//--���еĶ����ʽ�������Position���ڵ�һ��λ��
enum EVertType
{
    EVType_None,
    EVType_PNT,
    EVType_PT2,
    EVType_PD,
    EVType_PNT2,
    EVType_PN,
    EVType_PTp,
    EVType_PTD,
    EVType_PSprite,
    EVType_PtT,
    EVType_PtD,
    EVType_PtT4,
    EVType_PtDT,
    EVType_PtDT2,
    EVType_Water,
    EVType_Trn4,
    EVType_T4,
    EVType_Trn2,
    EVType_T2,
    EVType_PT,
    EVType_PTpD,
    EVType_P,
    EVType_PNDT,
    EVType_PNGT,
    EVType_PNWIT,
    EVType_PNGWIT,
    EVType_NT,

    //~ zrw changed hw_fak
    EVType_HWFAK,            // Ӳ�����ٵ�FAK.
    EVType_HWFAKWithLM,        // Ӳ�����ٵĴ�LightMap��FAK.
    EVType_HWFAKWithBump,    // Ӳ�����ٵ�ʹ�÷�����ͼ��FAK.

    EVType_Num,
};

struct Vert_PNT
{
    vec3 pos;
    vec3 normal;
    vec2 uv;
};

struct Vert_PT2
{
    vec3 pos;
    vec2 uv;
    vec2 uv2;
};

struct Vert_PD
{
    vec3 pos;
    uint32 diffuse;
};

struct Vert_PT
{
    vec3 pos;
    vec2 uv;
}
;
struct Vert_PNT2
{
    vec3 pos;
    vec3 normal;
    vec2 uv;
    vec2 uv2;
};

struct Vert_PN
{
    vec3 pos;
    vec3 normal;
};

const int TRN_MAX_UV_SET=4;
struct Vert_T4
{
    vec2 uv[TRN_MAX_UV_SET];
};

struct Vert_T2
{
    vec2 uv[2];
};

/** ��Ҫ����projector*/
struct Vert_PTp
{
    vec3 pos;
    vec3 uvw;    //uv+͸��У������
};

struct Vert_PTpD
{
    vec3 pos;
    uint32 diffuse;
    vec3 uvw;    //uv+͸��У������
};

struct Vert_PTD//ʹ�ö�����ɫ����ͼ����,��Ҫ����Ч��
{
    vec3 pos;
    uint32 diffuse;
    vec2 uv;
};

struct Vert_PSprite    //point sprite
{
    vec3    pos;
    float   size;
    uint32  diffuse;
};

struct Vert_PtT
{
    vec4 pos;    //����ת����λ��(��Ļ����)
    vec2 uv;
};

struct Vert_PtD
{
    vec4 pos;    //����ת����λ��(��Ļ����)
    uint32    diffuse;
};

struct Vert_PtT4
{
    vec4 pos;
    vec2 uv;
    vec2 uv2;
    vec2 uv3;
    vec2 uv4;
};

struct Vert_PtDT
{
    vec4 pos;
    uint32    diffuse;
    vec2 uv;
};

struct Vert_PtDT2
{
    vec4 pos;
    uint32    diffuse;
    vec2 uv;
    vec2 uv2;
};


struct Vert_P
{
    vec3 pos;
};

struct Vert_PNDT
{
    vec3 pos;
    vec3 normal;
    uint32    diffuse;
    vec2 uv;
};

struct Vert_PNGT
{
    vec3 pos;
    vec3 normal;
    vec3 tangent;
    vec2 uv;
};

struct Vert_PNWIT
{
    vec3 pos;
    vec3 normal;
    vec4 blendWeight;
    uint32    blendIndices;
    vec2 uv;
};

struct Vert_PNGWIT
{
    vec3 pos;
    vec3 normal;
    vec3 tangent;
    vec4 blendWeight;
    uint32    blendIndices;
    vec2 uv;
};

struct Vert_NT
{
    vec3 normal;
    vec2 uv;
};

inline uint32 GetVertSize(EVertType type)
{
    switch(type)
    {
    case EVType_PNT:    return sizeof(Vert_PNT);
    case EVType_PT2:    return sizeof(Vert_PT2);
    case EVType_PD:        return sizeof(Vert_PD);
    case EVType_PNT2:    return sizeof(Vert_PNT2);
    case EVType_PN:        return sizeof(Vert_PN);
    case EVType_PTp:    return sizeof(Vert_PTp);
    case EVType_PTD:    return sizeof(Vert_PTD);
    case EVType_PSprite:    return sizeof(Vert_PSprite);
    case EVType_PtT:    return sizeof(Vert_PtT);
    case EVType_PtD:    return sizeof(Vert_PtD);
    case EVType_PtT4:    return sizeof(Vert_PtT4);
    case EVType_PtDT:    return sizeof(Vert_PtDT);
    case EVType_PtDT2:      return sizeof(Vert_PtDT2);
    case EVType_T4:        return sizeof(Vert_T4);
    case EVType_T2:        return sizeof(Vert_T2);
    case EVType_PT:        return sizeof(Vert_PT);
    case EVType_PTpD:    return sizeof(Vert_PTpD);
    case EVType_P:        return sizeof(Vert_P);
    case EVType_PNDT:    return sizeof(Vert_PNDT);
    case EVType_PNGT:    return sizeof(Vert_PNGT);
    case EVType_PNWIT:    return sizeof(Vert_PNWIT);
    case EVType_PNGWIT:    return sizeof(Vert_PNGWIT);
    case EVType_NT:        return sizeof(Vert_NT);
    }

    return 0;
}


struct FaceEdge
{
    uint16 vert[2];    //��ɴ�Edge�����������Index
    uint16 face[32];   //�����Edge������Face
    FaceEdge()
    {
        memset(this,0xFF,sizeof(FaceEdge));
    }
};
struct FaceTopo
{
    FaceEdge edges[3];
    float    plane[4];
};

#endif //__VERTEX_H__
