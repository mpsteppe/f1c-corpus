char __stdcall sub_4FF680(float a1, int a2, int a3, float a4)
{
  int v5; // eax
  int v6; // eax
  int v7; // ecx
  int v8; // edx
  double v9; // st7
  int v10; // eax
  __int16 v11; // ax
  double v12; // st7
  __int16 v13; // ax
  double v14; // st7
  int v15; // ebp
  _BYTE *v16; // eax
  _WORD *v17; // ecx
  float v19; // [esp+10h] [ebp-64h]
  float v20[3]; // [esp+14h] [ebp-60h] BYREF
  float v21[3]; // [esp+20h] [ebp-54h] BYREF
  float v22[3]; // [esp+2Ch] [ebp-48h] BYREF
  float v23[3]; // [esp+38h] [ebp-3Ch] BYREF
  float v24[3]; // [esp+44h] [ebp-30h] BYREF
  _BYTE v25[36]; // [esp+50h] [ebp-24h] BYREF
  int v26; // [esp+78h] [ebp+4h]
  int v27; // [esp+78h] [ebp+4h]
  float v28; // [esp+7Ch] [ebp+8h]

  v28 = a1 - *(float *)(a2 + 4);
  if ( v28 >= -1.25 )
  {
    if ( v28 > 1.25 )
      v28 = 1.25;
  }
  else
  {
    v28 = -1.25;
  }
  v19 = v28 * 0.33399999;
  if ( v19 >= -0.075000003 )
  {
    if ( v19 > 0.075000003 )
      v19 = 0.075000003;
  }
  else
  {
    v19 = -0.075000003;
  }
  *(_DWORD *)a3 = *(_DWORD *)a2;
  v5 = *(_DWORD *)(a2 + 428);
  *(float *)(a3 + 4) = a1;
  *(_DWORD *)(a3 + 428) = v5;
  ShortVectorToFloatWithScale((__int16 *)(a2 + 8), v20);
  ShortToFloatVectorUnpack((__int16 *)(a2 + 8), (int)v24);
  *(float *)(a3 + 8) = (v24[0] * v19 + v20[0]) * v28 + *(float *)(a2 + 8);
  *(float *)(a3 + 12) = (v19 * a4 * -9.81 + v20[1]) * v28 + *(float *)(a2 + 12);
  *(float *)(a3 + 16) = (v24[2] * v19 + v20[2]) * v28 + *(float *)(a2 + 16);
  v6 = *(char *)(a2 + 45);
  v26 = *(__int16 *)(a2 + 46);
  v7 = *(__int16 *)(a2 + 20);
  v8 = *(__int16 *)(a2 + 22);
  v22[0] = (double)*(char *)(a2 + 44) * 0.050000001 * v28 * 0.30000001;
  v9 = (double)v26;
  v27 = v6;
  v10 = *(__int16 *)(a2 + 24);
  v22[1] = v9 * 0.0020000001 * v28 * 0.60000002;
  v22[2] = (double)v27 * 0.050000001 * v28 * 0.30000001;
  v21[0] = (double)v7 * 0.00048828125;
  v21[1] = (double)v8 * 0.00048828125;
  v21[2] = (double)v10 * 0.00048828125;
  EulerToRotationMatrix(v21, v25);
  sub_567120(v22, v23);
  v11 = CRTFtol(v23[0] * 2048.0);
  v12 = v23[1] * 2048.0;
  *(_WORD *)(a3 + 20) = v11;
  v13 = CRTFtol(v12);
  v14 = v23[2] * 2048.0;
  *(_WORD *)(a3 + 22) = v13;
  *(_WORD *)(a3 + 24) = CRTFtol(v14);
  v15 = a2 - a3;
  v16 = (_BYTE *)(a3 + 26);
  v17 = (_WORD *)(a3 + 30);
  do
  {
    *v16 = v16[v15];
    *v17 = *(_WORD *)((char *)v17 + v15);
    ++v17;
    ++v16;
  }
  while ( (int)&v16[-26 - a3] < 4 );
  *(_DWORD *)(a3 + 38) = *(_DWORD *)(a2 + 38);
  *(_DWORD *)(a3 + 42) = *(_DWORD *)(a2 + 42);
  *(_WORD *)(a3 + 46) = *(_WORD *)(a2 + 46);
  *(_DWORD *)(a3 + 48) = *(_DWORD *)(a2 + 48);
  *(_DWORD *)(a3 + 52) = *(_DWORD *)(a2 + 52);
  *(_DWORD *)(a3 + 56) = *(_DWORD *)(a2 + 56);
  return 1;
}

