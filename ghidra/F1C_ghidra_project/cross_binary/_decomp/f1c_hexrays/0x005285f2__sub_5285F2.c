// f1c  0x005285f2  size=993
char __cdecl sub_5285F2(int a1, int a2, __int16 *a3, int a4, int a5)
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
  double v27; // st4
  double v28; // st3
  double v29; // st1
  char result; // al
  bool v31; // cc
  char v32; // [esp+Ch] [ebp-118h] BYREF
  char v33; // [esp+14h] [ebp-110h] BYREF
  int v34; // [esp+10Ch] [ebp-18h]
  float v35; // [esp+110h] [ebp-14h]
  int v36; // [esp+114h] [ebp-10h]
  float v37; // [esp+118h] [ebp-Ch]
  float v38; // [esp+11Ch] [ebp-8h]
  float v39; // [esp+120h] [ebp-4h]
  float v40; // [esp+12Ch] [ebp+8h]
  float v41; // [esp+12Ch] [ebp+8h]
  float v42; // [esp+130h] [ebp+Ch]
  float v43; // [esp+130h] [ebp+Ch]
  float v44; // [esp+130h] [ebp+Ch]
  float v45; // [esp+130h] [ebp+Ch]
  float v46; // [esp+130h] [ebp+Ch]
  int v47; // [esp+134h] [ebp+10h]
  float v48; // [esp+134h] [ebp+10h]
  float v49; // [esp+134h] [ebp+10h]

  v36 = *(_DWORD *)(a1 + 284) + 128;
  v6 = *(float **)(a2 + 80);
  v7 = (float *)&v32;
  v34 = 8;
  do
  {
    v8 = a3[56];
    v9 = a3[48];
    v10 = (double)*a3 * *v6;
    if ( (unsigned __int16)v8 | (unsigned __int16)(v9 | a3[40] | a3[32] | a3[24] | a3[16] | a3[8]) )
    {
      v40 = v6[16] * (double)a3[16];
      v47 = v9;
      v11 = a3[8];
      v12 = v6[32] * (double)a3[32];
      v48 = v6[48] * (double)v47;
      v42 = v12 + v10;
      v13 = v10 - v12;
      v14 = v48 + v40;
      v15 = (v40 - v48) * 1.4142135 - v14;
      v35 = v14 + v42;
      v49 = v42 - v14;
      v41 = v15 + v13;
      v16 = v13 - v15;
      v17 = v6[8] * (double)v11;
      v18 = v6[24] * (double)a3[24];
      v19 = v6[40] * (double)a3[40];
      LODWORD(v37) = v8;
      v43 = v19;
      v20 = v6[56] * (double)v8;
      v38 = v43 + v18;
      v44 = v43 - v18;
      v39 = v20 + v17;
      v21 = v17 - v20;
      v22 = v39 + v38;
      v37 = (v21 + v44) * 1.847759;
      v23 = v37 - v44 * 2.613126 - v22;
      v24 = (v39 - v38) * 1.4142135 - v23;
      v39 = v24;
      v38 = v21 * 1.0823922 - v37 + v24;
      *v7 = v22 + v35;
      v7[56] = v35 - v22;
      v7[8] = v41 + v23;
      v7[48] = v41 - v23;
      v7[16] = v39 + v16;
      v7[40] = v16 - v39;
      v7[32] = v38 + v49;
      v7[24] = v49 - v38;
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
    --v34;
  }
  while ( *(float *)&v34 != 0.0 );
  v37 = 0.0;
  v25 = (float *)&v33;
  do
  {
    v26 = (_BYTE *)(a5 + *(_DWORD *)(a4 + 4 * LODWORD(v37)));
    v45 = v25[2] + *(v25 - 2);
    v35 = *v25 + v25[4] + v45;
    v27 = v25[3] + v25[1];
    v38 = v27;
    v46 = v25[3] - v25[1];
    v39 = v25[5] + *(v25 - 1);
    *(float *)&v34 = *(v25 - 1) - v25[5];
    v28 = (*(float *)&v34 + v46) * 1.847759;
    v29 = (v39 - v38) * 1.4142135 - (v28 - v46 * 2.613126 - (v27 + v39));
    v39 = v29;
    v38 = *(float *)&v34 * 1.0823922 - v28 + v29;
    *v26 = *(_BYTE *)((((sub_587BDC(1.4142135) + 4) >> 3) & 0x3FF) + v36);
    v26[7] = *(_BYTE *)((((sub_587BDC(1.4142135) + 4) >> 3) & 0x3FF) + v36);
    v26[1] = *(_BYTE *)((((sub_587BDC(1.4142135) + 4) >> 3) & 0x3FF) + v36);
    v26[6] = *(_BYTE *)((((sub_587BDC(1.4142135) + 4) >> 3) & 0x3FF) + v36);
    v26[2] = *(_BYTE *)((((sub_587BDC(1.4142135) + 4) >> 3) & 0x3FF) + v36);
    v26[5] = *(_BYTE *)((((sub_587BDC(1.4142135) + 4) >> 3) & 0x3FF) + v36);
    v26[4] = *(_BYTE *)((((sub_587BDC(1.4142135) + 4) >> 3) & 0x3FF) + v36);
    result = *(_BYTE *)((((sub_587BDC(1.4142135) + 4) >> 3) & 0x3FF) + v36);
    v25 += 8;
    v31 = ++LODWORD(v37) < 8;
    v26[3] = result;
  }
  while ( v31 );
  return result;
}
