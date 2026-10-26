char __fastcall sub_4DC960(int a1, float *a2, int a3, float *a4, float a5)
{
  double v6; // st5
  double v7; // st3
  double v8; // st4
  double v9; // st3
  double v10; // st4
  _BYTE v12[4]; // [esp+8h] [ebp-6Ch] BYREF
  int v13; // [esp+Ch] [ebp-68h] BYREF
  float v14; // [esp+10h] [ebp-64h]
  int v15; // [esp+14h] [ebp-60h] BYREF
  int v16; // [esp+18h] [ebp-5Ch]
  float v17; // [esp+1Ch] [ebp-58h] BYREF
  float v18; // [esp+20h] [ebp-54h] BYREF
  float v19; // [esp+24h] [ebp-50h] BYREF
  _BYTE v20[8]; // [esp+28h] [ebp-4Ch] BYREF
  float v21; // [esp+30h] [ebp-44h]
  _BYTE v22[64]; // [esp+34h] [ebp-40h] BYREF

  TripleFieldGetter_2460(&v17, &v18, &v19);
  v6 = -v19 - a2[2];
  v7 = -v18 - a2[1];
  v8 = v6 * v6 + v7 * v7;
  v9 = -v17 - *a2;
  v10 = v8 + v9 * v9;
  v14 = v10;
  if ( v10 > a5 * a5 )
    return 0;
  StructFieldArrayCopy(v22);
  (*(void (__cdecl **)(int, float *, _BYTE *, _BYTE *))(*(_DWORD *)dword_8B8F24 + 4))(dword_8B8F24, a2, v20, v22);
  if ( v21 <= 0.0 )
    return 0;
  ViewportPositionClamping(a2, &v15);
  v13 = 0;
  sub_5424E0(v12, v12, v12, &v13);
  v16 = v13 - v16;
  *a4 = sqrt(v14);
  *(float *)a3 = (float)v15;
  *(float *)(a3 + 4) = (float)v16;
  *(_DWORD *)(a3 + 8) = 0;
  return 1;
}
