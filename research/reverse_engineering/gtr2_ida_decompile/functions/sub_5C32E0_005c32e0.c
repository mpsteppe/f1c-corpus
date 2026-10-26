char __thiscall sub_5C32E0(_DWORD *this, float *a2, int a3, float *a4, _DWORD *a5, _DWORD *a6, int *a7)
{
  int v8; // eax
  int v9; // ebx
  int v11; // edi
  int v12; // ebp
  _DWORD *v13; // esi
  double v14; // st4
  char result; // al
  double v16; // st7
  double v17; // st6
  char v18; // [esp+19h] [ebp-C1h]
  float v19; // [esp+1Ah] [ebp-C0h] BYREF
  float v20; // [esp+1Eh] [ebp-BCh]
  float v21; // [esp+22h] [ebp-B8h]
  int v22; // [esp+26h] [ebp-B4h] BYREF
  float v23; // [esp+2Ah] [ebp-B0h]
  float v24; // [esp+2Eh] [ebp-ACh]
  float v25; // [esp+32h] [ebp-A8h]
  int v26; // [esp+36h] [ebp-A4h]
  int v27; // [esp+3Ah] [ebp-A0h]
  float v28; // [esp+3Eh] [ebp-9Ch]
  int v29; // [esp+42h] [ebp-98h]
  float v30; // [esp+46h] [ebp-94h] BYREF
  float v31; // [esp+4Ah] [ebp-90h]
  float v32; // [esp+4Eh] [ebp-8Ch]
  int v33; // [esp+52h] [ebp-88h] BYREF
  float *v34; // [esp+56h] [ebp-84h]
  float v35[16]; // [esp+5Ah] [ebp-80h] BYREF
  float v36[16]; // [esp+9Ah] [ebp-40h] BYREF

  v8 = this[8];
  v9 = this[4];
  v34 = (float *)(a3 + 68);
  qmemcpy(v36, (const void *)(a3 + 68), sizeof(v36));
  v22 = v8;
  sub_5BE470(v36);
  qmemcpy(v35, v36, sizeof(v35));
  v30 = v35[4] * a2[1] + v35[8] * a2[2] + v35[0] * *a2 + v35[12];
  v31 = v35[1] * *a2 + v35[5] * a2[1] + v35[9] * a2[2] + v35[13];
  v32 = v35[6] * a2[1] + v35[10] * a2[2] + v35[2] * *a2 + v35[14];
  v19 = v35[4] * a2[4] + v35[8] * a2[5] + v35[0] * a2[3] + v35[12];
  v20 = v35[1] * a2[3] + v35[5] * a2[4] + v35[9] * a2[5] + v35[13];
  v21 = v35[6] * a2[4] + v35[10] * a2[5] + v35[2] * a2[3] + v35[14];
  v11 = 0;
  v28 = 3.4028235e38;
  v18 = 0;
  v29 = 0;
  v27 = 0;
  v26 = 0;
  sub_5C2770(v35, &v30, &v19);
  v12 = this[11];
  if ( v12 <= 0 )
    return 0;
  v13 = (_DWORD *)(v22 + 4);
  do
  {
    if ( (unsigned __int8)((int (__thiscall *)(float *, int, int, int, float *, int *, int *))loc_5C2C30)(
                            v35,
                            v9 + 12 * *(v13 - 1),
                            v9 + 12 * *v13,
                            v9 + 12 * v13[1],
                            &v19,
                            &v22,
                            &v33) )
    {
      v14 = (v21 - v32) * (v21 - v32) + (v20 - v31) * (v20 - v31) + (v19 - v30) * (v19 - v30);
      if ( v14 < v28 )
      {
        v28 = v14;
        v23 = v19;
        v24 = v20;
        v25 = v21;
        v18 = 1;
        v29 = v11;
        v27 = v22;
        v26 = v33;
      }
    }
    v11 += 3;
    v13 += 3;
  }
  while ( v11 < v12 );
  result = v18;
  if ( v18 )
  {
    if ( a4 )
    {
      v16 = v25 * v34[8] + v24 * v34[4] + v23 * *v34 + v34[12];
      v17 = v25 * v34[9] + v24 * v34[5] + v23 * v34[1] + v34[13];
      v21 = v25 * v34[10] + v24 * v34[6] + v23 * v34[2] + v34[14];
      a4[2] = v21;
      *a4 = v16;
      a4[1] = v17;
    }
    if ( a7 )
      *a7 = v29;
    if ( a5 )
      *a5 = v27;
    if ( a6 )
      *a6 = v26;
  }
  return result;
}
