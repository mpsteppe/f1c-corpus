char __cdecl sub_565D42(int a1, int a2, __int16 *a3, int a4, int a5)
{
  float *v6; // ecx
  float *v7; // eax
  __int16 v8; // si
  __int16 v9; // di
  double v10; // st5
  int v11; // edi
  double v12; // st4
  double v13; // st5
  double v14; // st4
  double v15; // st3
  double v16; // st5
  double v17; // st4
  double v18; // st3
  double v19; // st2
  double v20; // st2
  double v21; // st4
  double v22; // st3
  double v23; // st2
  double v24; // st1
  float *v25; // esi
  _BYTE *v26; // edi
  double v27; // st5
  double v28; // st4
  double v29; // st3
  double v30; // st5
  double v31; // st4
  double v32; // st4
  double v33; // st3
  double v34; // st2
  double v35; // st1
  double v36; // st3
  double v37; // st4
  double v38; // st5
  __int64 v39; // rax
  double v40; // st5
  __int64 v41; // rax
  double v42; // st5
  char result; // al
  bool v44; // cc
  char v45; // [esp+Ch] [ebp-118h] BYREF
  char v46; // [esp+14h] [ebp-110h] BYREF
  int v47; // [esp+10Ch] [ebp-18h]
  float v48; // [esp+110h] [ebp-14h]
  int v49; // [esp+114h] [ebp-10h]
  float v50; // [esp+118h] [ebp-Ch]
  float v51; // [esp+11Ch] [ebp-8h]
  float v52; // [esp+120h] [ebp-4h]
  float v53; // [esp+12Ch] [ebp+8h]
  float v54; // [esp+12Ch] [ebp+8h]
  float v55; // [esp+12Ch] [ebp+8h]
  float v56; // [esp+130h] [ebp+Ch]
  float v57; // [esp+130h] [ebp+Ch]
  float v58; // [esp+130h] [ebp+Ch]
  float v59; // [esp+130h] [ebp+Ch]
  float v60; // [esp+130h] [ebp+Ch]
  float v61; // [esp+130h] [ebp+Ch]
  int v62; // [esp+134h] [ebp+10h]
  float v63; // [esp+134h] [ebp+10h]
  float v64; // [esp+134h] [ebp+10h]
  float v65; // [esp+134h] [ebp+10h]

  v49 = *(_DWORD *)(a1 + 284) + 128;
  v6 = *(float **)(a2 + 80);
  v7 = (float *)&v45;
  v47 = 8;
  do
  {
    v8 = a3[56];
    v9 = a3[48];
    v10 = (double)*a3 * *v6;
    if ( (unsigned __int16)v8 | (unsigned __int16)(v9 | a3[40] | a3[32] | a3[24] | a3[16] | a3[8]) )
    {
      v53 = v6[16] * (double)a3[16];
      v62 = v9;
      v11 = a3[8];
      v12 = v6[32] * (double)a3[32];
      v63 = v6[48] * (double)v62;
      v56 = v12 + v10;
      v13 = v10 - v12;
      v14 = v63 + v53;
      v15 = (v53 - v63) * 1.4142135 - v14;
      v48 = v14 + v56;
      v64 = v56 - v14;
      v54 = v15 + v13;
      v16 = v13 - v15;
      v17 = v6[8] * (double)v11;
      v18 = v6[24] * (double)a3[24];
      v19 = v6[40] * (double)a3[40];
      LODWORD(v50) = v8;
      v57 = v19;
      v20 = v6[56] * (double)v8;
      v51 = v57 + v18;
      v58 = v57 - v18;
      v52 = v20 + v17;
      v21 = v17 - v20;
      v22 = v52 + v51;
      v50 = (v21 + v58) * 1.847759;
      v23 = v50 - v58 * 2.613126 - v22;
      v24 = (v52 - v51) * 1.4142135 - v23;
      v52 = v24;
      v51 = v21 * 1.0823922 - v50 + v24;
      *v7 = v22 + v48;
      v7[56] = v48 - v22;
      v7[8] = v54 + v23;
      v7[48] = v54 - v23;
      v7[16] = v52 + v16;
      v7[40] = v16 - v52;
      v7[32] = v51 + v64;
      v7[24] = v64 - v51;
    }
    else
    {
      *v7 = v10;
      v7[8] = v10;
      v7[16] = v10;
      v7[24] = v10;
      v7[32] = v10;
      v7[40] = v10;
      v7[48] = v10;
      v7[56] = v10;
    }
    ++v6;
    ++a3;
    ++v7;
    --v47;
  }
  while ( *(float *)&v47 != 0.0 );
  v50 = 0.0;
  v25 = (float *)&v46;
  do
  {
    v26 = (_BYTE *)(a5 + *(_DWORD *)(a4 + 4 * LODWORD(v50)));
    v59 = v25[2] + *(v25 - 2);
    v27 = *(v25 - 2) - v25[2];
    v28 = *v25 + v25[4];
    v29 = (*v25 - v25[4]) * 1.4142135 - v28;
    v48 = v28 + v59;
    v65 = v59 - v28;
    v55 = v29 + v27;
    v30 = v27 - v29;
    v31 = v25[3] + v25[1];
    v51 = v31;
    v60 = v25[3] - v25[1];
    v52 = v25[5] + *(v25 - 1);
    *(float *)&v47 = *(v25 - 1) - v25[5];
    v32 = v31 + v52;
    v33 = (*(float *)&v47 + v60) * 1.847759;
    v34 = v33 - v60 * 2.613126 - v32;
    v61 = v34;
    v35 = (v52 - v51) * 1.4142135 - v34;
    v52 = v35;
    v51 = *(float *)&v47 * 1.0823922 - v33 + v35;
    v36 = v48 - v32;
    *v26 = *(_BYTE *)((((int)((__int64)(v48 + v32) + 4) >> 3) & 0x3FF) + v49);
    v26[7] = *(_BYTE *)((((int)((__int64)v36 + 4) >> 3) & 0x3FF) + v49);
    v26[1] = *(_BYTE *)((((int)((__int64)(v61 + v55) + 4) >> 3) & 0x3FF) + v49);
    v37 = v52 + v30;
    v26[6] = *(_BYTE *)((((int)((__int64)(v55 - v61) + 4) >> 3) & 0x3FF) + v49);
    v38 = v30 - v52;
    v26[2] = *(_BYTE *)((((int)((__int64)v37 + 4) >> 3) & 0x3FF) + v49);
    v39 = (__int64)v38;
    v40 = v51 + v65;
    v26[5] = *(_BYTE *)(((((int)v39 + 4) >> 3) & 0x3FF) + v49);
    v41 = (__int64)v40;
    v42 = v65 - v51;
    v26[4] = *(_BYTE *)(((((int)v41 + 4) >> 3) & 0x3FF) + v49);
    result = *(_BYTE *)((((int)((__int64)v42 + 4) >> 3) & 0x3FF) + v49);
    v25 += 8;
    v44 = ++LODWORD(v50) < 8;
    v26[3] = result;
  }
  while ( v44 );
  return result;
}
