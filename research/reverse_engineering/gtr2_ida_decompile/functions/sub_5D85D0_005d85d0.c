float *__stdcall sub_5D85D0(int a1, float *a2)
{
  int v3; // ecx
  int v4; // ebp
  int v5; // ebx
  int v6; // edx
  int v7; // edi
  float *v8; // edi
  float *result; // eax
  int v10; // ebx
  float v11; // [esp+0h] [ebp-44h]
  float v12; // [esp+4h] [ebp-40h]
  float v13; // [esp+8h] [ebp-3Ch]
  float v14; // [esp+Ch] [ebp-38h]
  float v15; // [esp+Ch] [ebp-38h]
  int v16; // [esp+28h] [ebp-1Ch]
  int v17; // [esp+2Ch] [ebp-18h]
  int v18; // [esp+30h] [ebp-14h]
  float v19; // [esp+38h] [ebp-Ch] BYREF
  int v20; // [esp+3Ch] [ebp-8h]
  _BYTE v21[4]; // [esp+40h] [ebp-4h] BYREF
  int v22; // [esp+48h] [ebp+4h]

  v3 = *(_DWORD *)(a1 + 108);
  v4 = *(_DWORD *)(a1 + 104);
  v5 = *(_DWORD *)(a1 + 120);
  v6 = *(_DWORD *)(a1 + 112);
  v7 = *(_DWORD *)(a1 + 100);
  v22 = *(_DWORD *)(a1 + 116);
  v16 = v3;
  v18 = v7;
  v20 = v5;
  v17 = v6;
  sub_5E4DB0(v21, &v19);
  if ( v5 + (v7 >> 1) == v16 && v22 + (v4 >> 1) == v17 )
  {
    v8 = a2;
    v14 = (double)v18 / (double)v4;
    result = sub_5ABBA9(a2, v19, v14, *(float *)(a1 + 36), *(float *)(a1 + 40));
  }
  else
  {
    v10 = v7 + v5;
    v8 = a2;
    v15 = (float)(v4 + v22);
    v13 = (float)v22;
    v12 = (float)v10;
    v11 = (float)v20;
    result = sub_5ABC3F(a2, v11, v12, v13, v15, *(float *)(a1 + 36), *(float *)(a1 + 40));
  }
  if ( (*(_BYTE *)a1 & 0x10) != 0 )
    *v8 = -*v8;
  return result;
}
