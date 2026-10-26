int __thiscall sub_54E270(int this)
{
  double v1; // st7
  double v2; // st6
  double v3; // st5
  double v4; // st4
  int v6; // eax
  double v7; // st3
  double v8; // st2
  int *v9; // ebx
  int v10; // edi
  float *v11; // ecx
  unsigned int v12; // ebp
  float *v13; // edx
  float *v14; // eax
  int v15; // edx
  bool v16; // zf
  _BYTE *v17; // edi
  float *v18; // eax
  int v19; // ebx
  _DWORD *v20; // ecx
  int v21; // edx
  int v22; // eax
  int v23; // edi
  int v24; // eax
  int v25; // ebp
  int v26; // ebx
  int v27; // eax
  int v28; // eax
  int v29; // ecx
  int result; // eax
  int *v31; // ebp
  int v32; // edi
  unsigned int v33; // ebx
  float *v34; // edx
  float *v35; // ecx
  float *v36; // eax
  double v37; // st5
  double v38; // st3
  double v39; // st4
  double v40; // st3
  long double v41; // st4
  int v42; // [esp+10h] [ebp-188h]
  double v43; // [esp+10h] [ebp-188h]
  int v44; // [esp+10h] [ebp-188h]
  float v45; // [esp+10h] [ebp-188h]
  int v46; // [esp+10h] [ebp-188h]
  float v47; // [esp+18h] [ebp-180h] BYREF
  float v48; // [esp+1Ch] [ebp-17Ch]
  float v49; // [esp+20h] [ebp-178h]
  double v50; // [esp+28h] [ebp-170h]
  double v51; // [esp+30h] [ebp-168h]
  double v52; // [esp+38h] [ebp-160h]
  double v53; // [esp+40h] [ebp-158h]
  double v54; // [esp+48h] [ebp-150h]
  double v55; // [esp+50h] [ebp-148h]
  double v56; // [esp+58h] [ebp-140h]
  long double v57; // [esp+60h] [ebp-138h]
  double v58; // [esp+68h] [ebp-130h]
  float v59[16]; // [esp+70h] [ebp-128h] BYREF
  double v60; // [esp+B0h] [ebp-E8h] BYREF
  double v61; // [esp+B8h] [ebp-E0h]
  double v62; // [esp+C0h] [ebp-D8h]
  double v63; // [esp+C8h] [ebp-D0h]
  double v64; // [esp+D0h] [ebp-C8h]
  double v65; // [esp+D8h] [ebp-C0h]
  double v66; // [esp+E0h] [ebp-B8h]
  double v67; // [esp+E8h] [ebp-B0h]
  double v68; // [esp+F0h] [ebp-A8h]
  double v69[9]; // [esp+F8h] [ebp-A0h] BYREF
  long double v70[3]; // [esp+140h] [ebp-58h] BYREF
  _BYTE v71[64]; // [esp+158h] [ebp-40h] BYREF

  v1 = 0.0;
  v2 = 0.0;
  v3 = 0.0;
  v4 = 0.0;
  v6 = *(_DWORD *)(this + 280);
  v7 = 0.0;
  v8 = 0.0;
  LODWORD(v50) = 0;
  v51 = 0.0;
  v52 = 0.0;
  v55 = 0.0;
  if ( v6 > 0 )
  {
    v9 = (int *)(*(_DWORD *)(this + 284) + 8);
    v42 = v6;
    do
    {
      v10 = *v9;
      if ( *v9 > 0 )
      {
        v11 = (float *)v9[1];
        v12 = (unsigned int)&unk_800000 & *(_DWORD *)(this + 20);
        v13 = v11;
        do
        {
          v14 = v13;
          if ( !v12 )
            v14 = v11;
          v13 += 16;
          v11 += 12;
          --v10;
          v3 = v3 + *v14 * *v14;
          v2 = v2 + v14[1] * v14[1];
          v1 = v1 + v14[2] * v14[2];
          v55 = v14[1] * *v14 + v55;
          v52 = *v14 * v14[2] + v52;
          v51 = v14[1] * v14[2] + v51;
          v8 = v8 + *v14;
          v7 = v7 + v14[1];
          v4 = v4 + v14[2];
        }
        while ( v10 );
      }
      v15 = *v9 + LODWORD(v50);
      v9 += 16;
      v16 = v42 == 1;
      LODWORD(v50) = v15;
      --v42;
    }
    while ( !v16 );
  }
  v43 = 1.0 / (double)SLODWORD(v50);
  v50 = v43 * v8;
  v53 = v43 * v7;
  v54 = v43 * v4;
  v52 = v43 * v52 - v54 * v50;
  v51 = v43 * v51 - v54 * v53;
  v65 = v51;
  v60 = v43 * v3 - v50 * v50;
  v61 = v43 * v55 - v53 * v50;
  v62 = v52;
  v63 = v61;
  v64 = v43 * v2 - v53 * v53;
  v66 = v52;
  v67 = v51;
  v68 = v43 * v1 - v54 * v54;
  QRDecomposition(&v60, v70, v69);
  v59[0] = v69[0];
  v59[3] = 0.0;
  v59[7] = 0.0;
  v59[1] = v69[3];
  memset(&v59[11], 0, 16);
  v59[2] = v69[6];
  v59[4] = v69[1];
  v59[15] = 1.0;
  v17 = v71;
  v59[5] = v69[4];
  v18 = v59;
  v19 = 4;
  v59[6] = v69[7];
  v59[8] = v69[2];
  v59[9] = v69[5];
  v59[10] = v69[8];
  do
  {
    v20 = v17;
    v21 = 4;
    do
    {
      *v20 = *(_DWORD *)v18;
      v20 += 4;
      ++v18;
      --v21;
    }
    while ( v21 );
    v17 += 4;
    --v19;
  }
  while ( v19 );
  v22 = *(_DWORD *)(this + 280);
  v23 = 0;
  v51 = 9.99999995904e11;
  v53 = 9.99999995904e11;
  v56 = 9.99999995904e11;
  v52 = -9.99999995904e11;
  v58 = -9.99999995904e11;
  v54 = -9.99999995904e11;
  v57 = 0.0;
  v44 = 0;
  if ( v22 > 0 )
  {
    do
    {
      v24 = *(_DWORD *)(this + 284);
      v25 = 0;
      v26 = 0;
      if ( *(int *)(v24 + v23 + 8) > 0 )
      {
        LODWORD(v50) = 0;
        do
        {
          v27 = *(_DWORD *)(v24 + v23 + 12);
          if ( ((unsigned int)&unk_800000 & *(_DWORD *)(this + 20)) != 0 )
            v28 = v25 + v27;
          else
            v28 = LODWORD(v50) + v27;
          (*(void (__cdecl **)(int, int, float *, _BYTE *))(*(_DWORD *)dword_8B8F24 + 4))(dword_8B8F24, v28, &v47, v71);
          if ( v47 < v56 )
            v56 = v47;
          if ( v47 > v54 )
            v54 = v47;
          if ( v48 < v53 )
            v53 = v48;
          if ( v48 > v58 )
            v58 = v48;
          if ( v49 < v51 )
            v51 = v49;
          if ( v49 > v52 )
            v52 = v49;
          v24 = *(_DWORD *)(this + 284);
          v29 = *(_DWORD *)(v24 + v23 + 8);
          ++v26;
          v25 += 64;
          LODWORD(v50) += 48;
        }
        while ( v26 < v29 );
      }
      v23 += 64;
      ++v44;
    }
    while ( v44 < *(_DWORD *)(this + 280) );
  }
  *(float *)&v55 = v54;
  v47 = *(float *)&v55;
  *(float *)&v50 = v53;
  v48 = *(float *)&v50;
  v45 = v51;
  v49 = v45;
  (*(void (__cdecl **)(int, float *, int, float *))(*(_DWORD *)dword_8B8F24 + 4))(dword_8B8F24, &v47, this + 28, v59);
  *(float *)&v52 = v52;
  v49 = *(float *)&v52;
  v48 = *(float *)&v50;
  v47 = *(float *)&v55;
  (*(void (__cdecl **)(int, float *, int, float *))(*(_DWORD *)dword_8B8F24 + 4))(dword_8B8F24, &v47, this + 40, v59);
  *(float *)&v51 = v56;
  v47 = *(float *)&v51;
  v48 = *(float *)&v50;
  v49 = *(float *)&v52;
  (*(void (__cdecl **)(int, float *, int, float *))(*(_DWORD *)dword_8B8F24 + 4))(dword_8B8F24, &v47, this + 52, v59);
  v49 = v45;
  v47 = *(float *)&v51;
  v48 = *(float *)&v50;
  (*(void (__cdecl **)(int, float *, int, float *))(*(_DWORD *)dword_8B8F24 + 4))(dword_8B8F24, &v47, this + 64, v59);
  *(float *)&v50 = v58;
  v48 = *(float *)&v50;
  v47 = *(float *)&v55;
  v49 = v45;
  (*(void (__cdecl **)(int, float *, int, float *))(*(_DWORD *)dword_8B8F24 + 4))(dword_8B8F24, &v47, this + 76, v59);
  v49 = *(float *)&v52;
  v48 = *(float *)&v50;
  v47 = *(float *)&v55;
  (*(void (__cdecl **)(int, float *, int, float *))(*(_DWORD *)dword_8B8F24 + 4))(dword_8B8F24, &v47, this + 88, v59);
  v49 = *(float *)&v52;
  v48 = *(float *)&v50;
  v47 = *(float *)&v51;
  (*(void (__cdecl **)(int, float *, int, float *))(*(_DWORD *)dword_8B8F24 + 4))(dword_8B8F24, &v47, this + 100, v59);
  v49 = v45;
  v48 = *(float *)&v50;
  v47 = *(float *)&v51;
  (*(void (__cdecl **)(int, float *, int, float *))(*(_DWORD *)dword_8B8F24 + 4))(dword_8B8F24, &v47, this + 112, v59);
  result = *(_DWORD *)(this + 280);
  if ( result > 0 )
  {
    v31 = (int *)(*(_DWORD *)(this + 284) + 8);
    v46 = *(_DWORD *)(this + 280);
    do
    {
      v32 = *v31;
      if ( *v31 > 0 )
      {
        v33 = (unsigned int)&unk_800000 & *(_DWORD *)(this + 20);
        v34 = (float *)v31[1];
        v35 = v34;
        do
        {
          v36 = v35;
          if ( !v33 )
            v36 = v34;
          v37 = *(float *)(this + 228) - v36[2];
          v38 = *(float *)(this + 224) - v36[1];
          v39 = v37 * v37 + v38 * v38;
          v40 = *(float *)(this + 220) - *v36;
          v41 = v39 + v40 * v40;
          if ( v57 <= v41 )
            v57 = v41;
          v35 += 16;
          v34 += 12;
          --v32;
        }
        while ( v32 );
      }
      v31 += 16;
      result = --v46;
    }
    while ( v46 );
  }
  *(float *)(this + 24) = sqrt(v57);
  return result;
}
