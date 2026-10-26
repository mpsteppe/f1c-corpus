int __stdcall sub_6DB510(int a1, int a2, __int16 *a3, int a4, int a5)
{
  float *v6; // edx
  int v7; // ebx
  float *v8; // eax
  __int16 v9; // si
  double v10; // st7
  double v11; // st7
  double v12; // st6
  double v13; // st5
  double v14; // st7
  double v15; // st6
  double v16; // st5
  int v17; // esi
  double v18; // st5
  double v19; // st4
  double v20; // st3
  double v21; // rt1
  float *v22; // esi
  double v23; // st7
  double v24; // st6
  _BYTE *v25; // edi
  double v26; // st5
  double v27; // st7
  double v28; // st6
  double v29; // st5
  double v30; // st5
  double v31; // st4
  __int64 v32; // rax
  double v33; // st4
  __int64 v34; // rax
  double v35; // st4
  __int64 v36; // rax
  double v37; // st7
  __int64 v38; // rax
  double v39; // st7
  int result; // eax
  char v41; // [esp+Ch] [ebp-11Ch] BYREF
  char v42; // [esp+14h] [ebp-114h] BYREF
  float v43; // [esp+10Ch] [ebp-1Ch]
  float v44; // [esp+110h] [ebp-18h]
  float v45; // [esp+114h] [ebp-14h]
  int v46; // [esp+118h] [ebp-10h]
  float v47; // [esp+11Ch] [ebp-Ch]
  int v48; // [esp+120h] [ebp-8h]
  float v49; // [esp+124h] [ebp-4h]
  float v50; // [esp+130h] [ebp+8h]
  int v51; // [esp+130h] [ebp+8h]
  float v52; // [esp+130h] [ebp+8h]
  float v53; // [esp+130h] [ebp+8h]
  float v54; // [esp+130h] [ebp+8h]
  float v55; // [esp+130h] [ebp+8h]
  float v56; // [esp+134h] [ebp+Ch]
  float v57; // [esp+134h] [ebp+Ch]
  float v58; // [esp+134h] [ebp+Ch]
  float v59; // [esp+134h] [ebp+Ch]
  float v60; // [esp+134h] [ebp+Ch]
  float v61; // [esp+138h] [ebp+10h]
  float v62; // [esp+138h] [ebp+10h]
  float v63; // [esp+138h] [ebp+10h]

  v6 = *(float **)(a2 + 80);
  v7 = *(_DWORD *)(a1 + 328) + 128;
  v8 = (float *)&v41;
  v46 = 8;
  do
  {
    v9 = a3[8];
    if ( v9 || a3[16] || a3[24] || a3[32] || a3[40] || a3[48] || a3[56] )
    {
      v11 = (double)*a3 * *v6;
      v12 = (double)a3[16] * v6[16];
      v13 = (double)a3[32] * v6[32];
      v61 = (double)a3[48] * v6[48];
      v56 = v13 + v11;
      *(float *)&v48 = v11 - v13;
      v50 = v61 + v12;
      v14 = (v12 - v61) * 1.4142135 - v50;
      v15 = v50 + v56;
      v16 = v56 - v50;
      v51 = v9;
      v17 = a3[24];
      v62 = v16;
      v45 = v14 + *(float *)&v48;
      v43 = *(float *)&v48 - v14;
      v18 = (double)v51 * v6[8];
      v19 = (double)v17 * v6[24];
      v20 = (double)a3[40] * v6[40];
      v52 = (double)a3[56] * v6[56];
      v44 = v20 + v19;
      v57 = v52 + v18;
      v21 = v20 - v19;
      v47 = v18 - v52;
      v53 = v57 + v44;
      v49 = (v47 + v21) * 1.847759;
      *(float *)&v48 = v49 - v21 * 2.613126 - v53;
      v58 = (v57 - v44) * 1.4142135 - *(float *)&v48;
      v49 = v47 * 1.0823922 - v49 + v58;
      *v8 = v53 + v15;
      v8[56] = v15 - v53;
      v8[8] = *(float *)&v48 + v45;
      v8[48] = v45 - *(float *)&v48;
      v8[16] = v58 + v43;
      v8[40] = v43 - v58;
      v8[32] = v49 + v62;
      v8[24] = v62 - v49;
    }
    else
    {
      v10 = (double)*a3 * *v6;
      *v8 = v10;
      v8[8] = v10;
      v8[16] = v10;
      v8[24] = v10;
      v8[32] = v10;
      v8[40] = v10;
      v8[48] = v10;
      v8[56] = v10;
    }
    ++v6;
    ++a3;
    ++v8;
    --v46;
  }
  while ( *(float *)&v46 != 0.0 );
  *(float *)&v48 = 0.0;
  v22 = (float *)&v42;
  do
  {
    v23 = v22[2] + *(v22 - 2);
    v24 = *(v22 - 2) - v22[2];
    v25 = (_BYTE *)(a5 + *(_DWORD *)(a4 + 4 * v48));
    v26 = *v22 + v22[4];
    v54 = (*v22 - v22[4]) * 1.4142135 - v26;
    *(float *)&v46 = v26 + v23;
    v63 = v23 - v26;
    v45 = v54 + v24;
    v27 = v24 - v54;
    v28 = v22[3] + v22[1];
    v29 = v22[3] - v22[1];
    v59 = v22[5] + *(v22 - 1);
    v47 = *(v22 - 1) - v22[5];
    v55 = v59 + v28;
    v49 = (v47 + v29) * 1.847759;
    v30 = v49 - v29 * 2.613126 - v55;
    v60 = (v59 - v28) * 1.4142135 - v30;
    v49 = v47 * 1.0823922 - v49 + v60;
    v31 = *(float *)&v46 - v55;
    *v25 = *(_BYTE *)((((int)((__int64)(v55 + *(float *)&v46) + 4) >> 3) & 0x3FF) + v7);
    v32 = (__int64)v31;
    v33 = v45 + v30;
    v25[7] = *(_BYTE *)(((((int)v32 + 4) >> 3) & 0x3FF) + v7);
    v34 = (__int64)v33;
    v35 = v45 - v30;
    v25[1] = *(_BYTE *)(((((int)v34 + 4) >> 3) & 0x3FF) + v7);
    v25[6] = *(_BYTE *)((((int)((__int64)v35 + 4) >> 3) & 0x3FF) + v7);
    v25[2] = *(_BYTE *)((((int)((__int64)(v60 + v27) + 4) >> 3) & 0x3FF) + v7);
    v36 = (__int64)(v27 - v60);
    v37 = v49 + v63;
    v25[5] = *(_BYTE *)(((((int)v36 + 4) >> 3) & 0x3FF) + v7);
    v38 = (__int64)v37;
    v39 = v63 - v49;
    v25[4] = *(_BYTE *)(((((int)v38 + 4) >> 3) & 0x3FF) + v7);
    v25[3] = *(_BYTE *)((((int)((__int64)v39 + 4) >> 3) & 0x3FF) + v7);
    v22 += 8;
    result = ++v48;
  }
  while ( v48 < 8 );
  return result;
}
