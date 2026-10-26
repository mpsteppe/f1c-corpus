char __fastcall sub_568430(int a1, float *a2, int a3, int a4, int a5)
{
  double v7; // st5
  double v8; // st3
  double v9; // st4
  double v10; // st3
  double v11; // st4
  _DWORD *v12; // ecx
  _DWORD *v13; // eax
  int v14; // edx
  int v15; // esi
  float *v17; // eax
  int v18; // [esp+0h] [ebp-74h]
  float v19; // [esp+4h] [ebp-70h]
  int v20; // [esp+8h] [ebp-6Ch] BYREF
  int v21; // [esp+Ch] [ebp-68h]
  float v22; // [esp+10h] [ebp-64h]
  float v23; // [esp+14h] [ebp-60h]
  float v24; // [esp+18h] [ebp-5Ch]
  char v25[4]; // [esp+1Ch] [ebp-58h] BYREF
  char v26[4]; // [esp+20h] [ebp-54h] BYREF
  float v27; // [esp+24h] [ebp-50h] BYREF
  _BYTE v28[4]; // [esp+28h] [ebp-4Ch] BYREF
  _BYTE v29[64]; // [esp+2Ch] [ebp-48h] BYREF
  float *v30; // [esp+6Ch] [ebp-8h]
  float *v31; // [esp+70h] [ebp-4h]
  float retaddr; // [esp+74h] [ebp+0h]

  v21 = (int)a2;
  sub_5E4D90(a1, v25, v26, &v27);
  v7 = -v24 - a2[2];
  v8 = -v23 - a2[1];
  v9 = v7 * v7 + v8 * v8;
  v10 = -v22 - *a2;
  v11 = v9 + v10 * v10;
  v19 = v11;
  if ( v11 > retaddr * retaddr )
    return 0;
  v12 = v29;
  v13 = (_DWORD *)(a1 + 704);
  v14 = 4;
  do
  {
    *(v12 - 1) = *(v13 - 1);
    *v12 = *v13;
    *(_DWORD *)&v28[(_DWORD)v13 - 696 - a1] = v13[1];
    *(_DWORD *)&v29[(_DWORD)v13 - 696 - a1] = v13[2];
    v13 += 4;
    v12 += 4;
    --v14;
  }
  while ( v14 );
  v15 = v18;
  sub_5D7810(v18, v25, v28);
  if ( v27 <= 0.0 )
    return 0;
  sub_5E4E30(v15, &v20);
  *v31 = sqrt(v19);
  v17 = v30;
  *v30 = (float)v20;
  v17[1] = (float)v21;
  v17[2] = 0.0;
  return 1;
}
