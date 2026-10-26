char __thiscall sub_5D5A50(int this, int a2, int a3, int a4, int a5)
{
  int v5; // eax
  float *v6; // edi
  _DWORD *v7; // edx
  int v8; // ebp
  double v9; // st7
  int v10; // ecx
  int v11; // esi
  float v12; // edx
  int v13; // ebx
  _DWORD *v14; // ebx
  unsigned __int8 *v15; // esi
  unsigned __int16 *v16; // edx
  double v17; // st6
  int v18; // edi
  double v19; // st5
  double v20; // st5
  int v21; // edi
  double v22; // st5
  double v23; // st5
  int v24; // edi
  double v25; // st5
  double v26; // st5
  int v27; // edi
  double v28; // st5
  double v29; // st5
  int v30; // edi
  double v31; // st7
  unsigned __int16 *v32; // esi
  double v33; // st6
  double v34; // st5
  int v35; // edx
  double v36; // st6
  float v38; // [esp+Ch] [ebp-54h]
  float v39; // [esp+10h] [ebp-50h]
  unsigned int v40; // [esp+14h] [ebp-4Ch]
  int v41; // [esp+18h] [ebp-48h]
  float v42; // [esp+24h] [ebp-3Ch]
  int v43; // [esp+28h] [ebp-38h]
  int v44; // [esp+2Ch] [ebp-34h]
  int v45; // [esp+2Ch] [ebp-34h]
  float v46; // [esp+38h] [ebp-28h]
  float v47; // [esp+38h] [ebp-28h]
  float v48; // [esp+38h] [ebp-28h]
  float v49; // [esp+38h] [ebp-28h]
  float v50; // [esp+38h] [ebp-28h]
  float v51; // [esp+3Ch] [ebp-24h]
  float v52; // [esp+3Ch] [ebp-24h]
  float v53; // [esp+3Ch] [ebp-24h]
  float v54; // [esp+3Ch] [ebp-24h]
  float v55; // [esp+3Ch] [ebp-24h]
  float v56; // [esp+50h] [ebp-10h]
  float v57; // [esp+50h] [ebp-10h]
  float v58; // [esp+50h] [ebp-10h]
  float v59; // [esp+50h] [ebp-10h]
  float v60; // [esp+50h] [ebp-10h]
  float v61; // [esp+54h] [ebp-Ch]
  float v62; // [esp+54h] [ebp-Ch]
  float v63; // [esp+54h] [ebp-Ch]
  float v64; // [esp+54h] [ebp-Ch]
  float v65; // [esp+54h] [ebp-Ch]

  v5 = *(_DWORD *)(this + 12);
  v6 = *(float **)(*(_DWORD *)(v5 + 64) + 4 * *(_DWORD *)(this + 16));
  v7 = *(_DWORD **)(this + 4);
  v8 = *((_DWORD *)v6 + 4);
  if ( v8 <= v7[10] )
  {
    v38 = (*(float *)(v5 + 44) - *(float *)(v5 + 40)) * *(float *)(v5 + 36) + *(float *)(v5 + 40);
    if ( -0.0000099999997 > v38 || v38 > 0.0000099999997 )
    {
      *(_BYTE *)(this + 20) = 0;
    }
    else
    {
      LOBYTE(v5) = *(_BYTE *)(this + 20);
      if ( (_BYTE)v5 )
        return v5;
      *(_BYTE *)(this + 20) = 1;
    }
    v5 = v7[4];
    v9 = v6[6];
    v10 = v7[5];
    v11 = *((_DWORD *)v6 + 1);
    v41 = *((_DWORD *)v6 + 2);
    v12 = *v6;
    v39 = v6[5];
    v13 = 0;
    v42 = *v6;
    v44 = v11;
    if ( v8 >= 4 )
    {
      v14 = (_DWORD *)(v41 + 8);
      v15 = (unsigned __int8 *)(v11 + 5);
      v16 = (unsigned __int16 *)(LODWORD(v12) + 10);
      v40 = ((unsigned int)(v8 - 4) >> 2) + 1;
      v17 = (v9 - v39) * 0.000015259022;
      v43 = 4 * v40;
      do
      {
        v18 = 12 * *(v14 - 2);
        v46 = (double)*(v16 - 3) * v17 + v39;
        v51 = ((double)*(v16 - 5) * v17 + v39) * v38;
        v19 = ((double)*(v16 - 4) * v17 + v39) * v38;
        *(float *)(v18 + v5) = v51 + *(float *)(v18 + v5);
        *(float *)(v18 + v5 + 4) = v19 + *(float *)(v18 + v5 + 4);
        *(float *)(v18 + v5 + 8) = v46 * v38 + *(float *)(v18 + v5 + 8);
        v56 = (double)*(v15 - 3) * 0.0078431377 - 1.0;
        v61 = ((double)*(v15 - 5) * 0.0078431377 - 1.0) * v38;
        v20 = ((double)*(v15 - 4) * 0.0078431377 - 1.0) * v38;
        *(float *)(v18 + v10) = v61 + *(float *)(v18 + v10);
        *(float *)(v18 + v10 + 4) = v20 + *(float *)(v18 + v10 + 4);
        *(float *)(v18 + v10 + 8) = v56 * v38 + *(float *)(v18 + v10 + 8);
        v21 = 12 * *(v14 - 1);
        v47 = (double)*v16 * v17 + v39;
        v52 = ((double)*(v16 - 2) * v17 + v39) * v38;
        v22 = ((double)*(v16 - 1) * v17 + v39) * v38;
        *(float *)(v21 + v5) = v52 + *(float *)(v21 + v5);
        *(float *)(v21 + v5 + 4) = v22 + *(float *)(v21 + v5 + 4);
        *(float *)(v21 + v5 + 8) = v47 * v38 + *(float *)(v21 + v5 + 8);
        v57 = (double)*v15 * 0.0078431377 - 1.0;
        v62 = ((double)*(v15 - 2) * 0.0078431377 - 1.0) * v38;
        v23 = ((double)*(v15 - 1) * 0.0078431377 - 1.0) * v38;
        *(float *)(v21 + v10) = v62 + *(float *)(v21 + v10);
        *(float *)(v21 + v10 + 4) = v23 + *(float *)(v21 + v10 + 4);
        *(float *)(v21 + v10 + 8) = v57 * v38 + *(float *)(v21 + v10 + 8);
        v48 = (double)v16[3] * v17 + v39;
        v53 = ((double)v16[1] * v17 + v39) * v38;
        v24 = 12 * *v14;
        v25 = ((double)v16[2] * v17 + v39) * v38;
        *(float *)(v24 + v5) = v53 + *(float *)(v24 + v5);
        *(float *)(v24 + v5 + 4) = v25 + *(float *)(v24 + v5 + 4);
        *(float *)(v24 + v5 + 8) = v48 * v38 + *(float *)(v24 + v5 + 8);
        v58 = (double)v15[3] * 0.0078431377 - 1.0;
        v63 = ((double)v15[1] * 0.0078431377 - 1.0) * v38;
        v26 = ((double)v15[2] * 0.0078431377 - 1.0) * v38;
        *(float *)(v24 + v10) = v63 + *(float *)(v24 + v10);
        *(float *)(v24 + v10 + 4) = v26 + *(float *)(v24 + v10 + 4);
        *(float *)(v24 + v10 + 8) = v58 * v38 + *(float *)(v24 + v10 + 8);
        v27 = 12 * v14[1];
        v49 = (double)v16[6] * v17 + v39;
        v54 = ((double)v16[4] * v17 + v39) * v38;
        v28 = ((double)v16[5] * v17 + v39) * v38;
        *(float *)(v27 + v5) = v54 + *(float *)(v27 + v5);
        *(float *)(v27 + v5 + 4) = v28 + *(float *)(v27 + v5 + 4);
        v14 += 4;
        v16 += 12;
        v15 += 12;
        *(float *)(v27 + v5 + 8) = v49 * v38 + *(float *)(v27 + v5 + 8);
        v59 = (double)*(v15 - 6) * 0.0078431377 - 1.0;
        v64 = ((double)*(v15 - 8) * 0.0078431377 - 1.0) * v38;
        v29 = ((double)*(v15 - 7) * 0.0078431377 - 1.0) * v38;
        *(float *)(v27 + v10) = v64 + *(float *)(v27 + v10);
        *(float *)(v27 + v10 + 4) = v29 + *(float *)(v27 + v10 + 4);
        *(float *)(v27 + v10 + 8) = v59 * v38 + *(float *)(v27 + v10 + 8);
        --v40;
      }
      while ( v40 );
      v12 = v42;
      v13 = v43;
      v11 = v44;
    }
    if ( v13 < v8 )
    {
      v30 = v13 + v11 + 2 * v13 + 2;
      v31 = (v9 - v39) * 0.000015259022;
      v32 = (unsigned __int16 *)(LODWORD(v12) + 6 * v13 + 4);
      do
      {
        v33 = (double)*(v32 - 2);
        v34 = (double)*(v32 - 1);
        v45 = *v32;
        v35 = 12 * *(_DWORD *)(v41 + 4 * v13++);
        v32 += 3;
        v30 += 3;
        v50 = (double)v45 * v31 + v39;
        v55 = (v33 * v31 + v39) * v38;
        *(float *)(v35 + v5) = v55 + *(float *)(v35 + v5);
        *(float *)(v35 + v5 + 4) = (v34 * v31 + v39) * v38 + *(float *)(v35 + v5 + 4);
        *(float *)(v35 + v5 + 8) = v50 * v38 + *(float *)(v35 + v5 + 8);
        v60 = (double)*(unsigned __int8 *)(v30 - 3) * 0.0078431377 - 1.0;
        v65 = ((double)*(unsigned __int8 *)(v30 - 5) * 0.0078431377 - 1.0) * v38;
        v36 = ((double)*(unsigned __int8 *)(v30 - 4) * 0.0078431377 - 1.0) * v38;
        *(float *)(v35 + v10) = v65 + *(float *)(v35 + v10);
        *(float *)(v35 + v10 + 4) = v36 + *(float *)(v35 + v10 + 4);
        *(float *)(v35 + v10 + 8) = v60 * v38 + *(float *)(v35 + v10 + 8);
      }
      while ( v13 < v8 );
    }
  }
  return v5;
}
