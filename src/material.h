#ifndef __MATERIAL_H__
#define __MATERIAL_H__

#include "define.h"

enum EMapChannel
{
    EMap_Diffuse=0,
    EMap_Lighting,
    EMap_Specular,
    EMap_Bump,
    EMap_Max
};

#pragma pack(4)
typedef struct _Material
{
    int  id;
    vec4 diffuse;
    vec4 ambient;
    vec4 specular;
    vec4 emissive;
    float power;

    bool bTwoSide;
    bool bOpcityMap;
    uint8 opcityVal;

    char map[EMap_Max][256];

    bool bMultiPass;

    //~ zrw added UV ����.
    float fUSpeed;        
    float fVSpeed;
    float fRot;
    uint32 dwFluidColor;
    bool bFluidFlash;
    bool bAddMode;

    // �������Է����еĲ�ϣ����˸.
    bool bGlowStatic;
    
    uint8 reserve[13];        //~ zrw�ֽڶ�������Ŀռ�.
} Material;
#pragma pack()

#endif
