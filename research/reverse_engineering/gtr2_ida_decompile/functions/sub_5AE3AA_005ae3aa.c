unsigned int __stdcall sub_5AE3AA(
        float *a1,
        int a2,
        unsigned int a3,
        float *a4,
        int a5,
        int a6,
        int a7,
        unsigned int a8)
{
  unsigned int result; // eax
  int v10; // eax
  double v11; // st6
  unsigned int v12; // edx
  double v13; // st5
  float *v14; // eax
  double v15; // st4
  double v16; // st3
  double v17; // st2
  double v18; // st1
  float *v19; // ecx
  double v20; // st0
  unsigned int v21; // edx
  float *v22; // eax
  unsigned int v23; // edx
  float *v24; // edi
  float v25[68]; // [esp+14h] [ebp-1C8h] BYREF
  float v26[10]; // [esp+124h] [ebp-B8h] BYREF
  float v27; // [esp+14Ch] [ebp-90h]
  float v28; // [esp+154h] [ebp-88h]
  float v29; // [esp+15Ch] [ebp-80h]
  float v30; // [esp+160h] [ebp-7Ch]
  int v31; // [esp+164h] [ebp-78h] BYREF
  float v32; // [esp+168h] [ebp-74h] BYREF
  float v33; // [esp+16Ch] [ebp-70h]
  float v34[3]; // [esp+170h] [ebp-6Ch] BYREF
  int v35[3]; // [esp+17Ch] [ebp-60h] BYREF
  int v36[3]; // [esp+188h] [ebp-54h] BYREF
  float v37; // [esp+194h] [ebp-48h]
  float v38; // [esp+198h] [ebp-44h]
  float i; // [esp+19Ch] [ebp-40h]
  int v40[3]; // [esp+1A0h] [ebp-3Ch] BYREF
  int v41; // [esp+1ACh] [ebp-30h] BYREF
  float v42; // [esp+1B0h] [ebp-2Ch]
  float v43; // [esp+1B4h] [ebp-28h]
  int v44[3]; // [esp+1B8h] [ebp-24h] BYREF
  int v45[3]; // [esp+1C4h] [ebp-18h] BYREF
  int v46; // [esp+1D0h] [ebp-Ch] BYREF
  float v47; // [esp+1D4h] [ebp-8h]
  float v48; // [esp+1D8h] [ebp-4h]
  unsigned int v49; // [esp+1E4h] [ebp+8h]
  float v50; // [esp+1F8h] [ebp+1Ch]

  v31 = *(int *)a5;
  v32 = *(float *)(a5 + 4);
  v33 = *(float *)(a5 + 8);
  v41 = *(int *)a6;
  v42 = *(float *)(a6 + 4);
  v43 = *(float *)(a6 + 8);
  v46 = *(int *)a7;
  v47 = *(float *)(a7 + 4);
  v48 = *(float *)(a7 + 8);
  sub_5AE30B((float *)&v41, (float *)&v31, a1, 0.33333334, v34);
  sub_5AE30B((float *)&v46, (float *)&v31, a1, 0.33333334, (float *)v35);
  sub_5AE30B((float *)&v31, (float *)&v41, a1 + 3, 0.33333334, (float *)v36);
  sub_5AE30B((float *)&v31, (float *)&v46, a1 + 6, 0.33333334, (float *)v40);
  sub_5AE30B((float *)&v46, (float *)&v41, a1 + 3, 0.33333334, (float *)v44);
  sub_5AE30B((float *)&v41, (float *)&v46, a1 + 6, 0.33333334, (float *)v45);
  i = *(float *)&v35[2] + v34[2];
  v37 = *(float *)v36 + *(float *)v35 + v34[0];
  v37 = *(float *)v40 + v37;
  v38 = *(float *)&v40[1] + *(float *)&v36[1] + *(float *)&v35[1] + v34[1];
  v38 = *(float *)&v44[1] + v38;
  i = *(float *)&v44[2] + *(float *)&v40[2] + *(float *)&v36[2] + i;
  v37 = *(float *)v45 + *(float *)v44 + v37;
  v38 = *(float *)&v45[1] + v38;
  v37 = v37 * 0.25;
  v38 = v38 * 0.25;
  v30 = v43 + v33;
  v27 = *(float *)&v46 + *(float *)&v41 + *(float *)&v31;
  result = 0;
  v49 = 0;
  v28 = v48 + v30;
  v29 = (v47 + v42 + v32) * 0.166666;
  v30 = v28 * 0.166666;
  v37 = v37 - v27 * 0.166666;
  v38 = v38 - v29;
  for ( i = (*(float *)&v45[2] + i) * 0.25 - v30; v49 < a3; ++v49 )
  {
    v10 = 8 * result;
    v11 = *(float *)(v10 + a2);
    v12 = 0;
    v13 = *(float *)(v10 + a2 + 4);
    v14 = &v32;
    v15 = 1.0 - v11 - v13;
    v26[0] = v13 * v13 * v13;
    v50 = v15 * v13;
    v26[1] = v15 * v13 * v13 * 3.0;
    v26[2] = v13 * v13 * v11 * 3.0;
    v26[3] = v15 * v15 * v13 * 3.0;
    v26[4] = v50 * v11 * 6.0;
    v26[5] = v13 * v11 * v11 * 3.0;
    v26[6] = v15 * v15 * v15;
    v26[7] = v15 * v15 * v11 * 3.0;
    v26[8] = v15 * v11 * v11 * 3.0;
    v26[9] = v11 * v11 * v11;
    v16 = 0.0;
    v17 = 0.0;
    v18 = 0.0;
    do
    {
      v19 = &v26[v12++];
      v16 = v16 + *(v14 - 1) * *v19;
      v20 = *v19 * *v14;
      v14 += 3;
      v17 = v17 + v20;
      v18 = v18 + *(v14 - 2) * *v19;
    }
    while ( v12 < 0xA );
    v21 = a8;
    v25[2] = v18;
    v25[1] = v17;
    v25[0] = v16;
    if ( a8 > 3 )
    {
      v22 = (float *)(a6 + 12);
      v23 = a8 - 3;
      do
      {
        *(float *)((char *)v22 + (_DWORD)v25 - a6) = v11 * *(float *)((char *)v22 + a7 - a6)
                                                   + v13 * *(float *)((char *)v22 + a5 - a6)
                                                   + v15 * *v22;
        ++v22;
        --v23;
      }
      while ( v23 );
      v21 = a8;
    }
    v24 = a4;
    a4 += v21;
    qmemcpy(v24, v25, 4 * v21);
    result = v49 + 1;
  }
  return result;
}
