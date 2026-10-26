char __fastcall sub_5060A0(int a1, float *a2, int a3, float *a4, float a5)
{
  double v6; // st6
  double v7; // st5
  double v8; // st3
  _BYTE v10[4]; // [esp+8h] [ebp-6Ch] BYREF
  int v11; // [esp+Ch] [ebp-68h] BYREF
  float v12; // [esp+10h] [ebp-64h]
  int v13; // [esp+14h] [ebp-60h] BYREF
  int v14; // [esp+18h] [ebp-5Ch]
  float v15; // [esp+1Ch] [ebp-58h] BYREF
  float v16; // [esp+20h] [ebp-54h] BYREF
  float v17; // [esp+24h] [ebp-50h] BYREF
  _BYTE v18[8]; // [esp+28h] [ebp-4Ch] BYREF
  float v19; // [esp+30h] [ebp-44h]
  _BYTE v20[64]; // [esp+34h] [ebp-40h] BYREF

  sub_593DE0(&v15, &v16, &v17);
  v6 = -v16 - a2[1];
  v7 = -v17 - a2[2];
  v8 = -v15 - *a2;
  v12 = v7 * v7 + v6 * v6 + v8 * v8;
  if ( a5 > 0.0 && a5 * a5 < v12 )
    return 0;
  sub_593D70(v20);
  (*(void (__cdecl **)(int, float *, _BYTE *, _BYTE *))(*(_DWORD *)dword_7E8E58 + 4))(dword_7E8E58, a2, v18, v20);
  if ( v19 <= 0.0 )
    return 0;
  sub_593F70(a2, &v13);
  v11 = 0;
  sub_593E60(v10, v10, v10, &v11);
  v14 = v11 - v14;
  *a4 = sqrt(v12);
  *(float *)a3 = (float)v13;
  *(float *)(a3 + 4) = (float)v14;
  *(_DWORD *)(a3 + 8) = 0;
  return 1;
}
