bool __thiscall sub_5762D0(int this)
{
  int *v2; // ecx
  double v3; // st7
  double v4; // st7
  int v6; // edx
  int v7; // eax
  int v8; // ecx
  int v9; // edi
  float *v10; // ebp
  float *v11; // ebx
  float *v12; // eax
  float v13; // ecx
  float v14; // edx
  float v15; // eax
  float v16; // edx
  float v17; // eax
  double v18; // st7
  double v19; // st7
  double v20; // st7
  double v21; // st7
  int v22; // ebx
  float *v23; // ebp
  float *v24; // eax
  float v25; // ecx
  float v26; // edx
  double v27; // st7
  double v28; // st7
  double v29; // st6
  int v30; // edi
  float *v31; // ebx
  float *v32; // eax
  float v33; // ecx
  float v34; // edx
  float *v35; // eax
  float v36; // ecx
  float v37; // edx
  float *v38; // eax
  float v39; // ecx
  float v40; // edx
  float v41; // [esp+4h] [ebp-48h]
  float v42; // [esp+8h] [ebp-44h]
  float v43; // [esp+8h] [ebp-44h]
  float v44; // [esp+8h] [ebp-44h]
  float *v45; // [esp+Ch] [ebp-40h]
  float *v46; // [esp+10h] [ebp-3Ch]
  float *v47; // [esp+14h] [ebp-38h]
  float *v48; // [esp+18h] [ebp-34h]
  float v49; // [esp+1Ch] [ebp-30h] BYREF
  float v50; // [esp+20h] [ebp-2Ch]
  float v51; // [esp+24h] [ebp-28h]
  float v52; // [esp+28h] [ebp-24h] BYREF
  float v53; // [esp+2Ch] [ebp-20h]
  float v54; // [esp+30h] [ebp-1Ch]
  float v55; // [esp+34h] [ebp-18h]
  float v56; // [esp+38h] [ebp-14h]
  float v57; // [esp+3Ch] [ebp-10h]
  float v58[3]; // [esp+40h] [ebp-Ch] BYREF

  if ( !*(_DWORD *)(this + 14804) )
    return 1;
  v2 = (int *)(this + 15972);
  v45 = (float *)(this + 15972);
  v52 = *(float *)(this + 17492) - *(float *)(this + 15972);
  v3 = *(float *)(this + 17496);
  v55 = v52;
  v53 = v3 - *(float *)(this + 15976);
  v4 = *(float *)(this + 17500);
  v56 = v53;
  v54 = v4 - *(float *)(this + 15980);
  v57 = v54;
  if ( v54 * v54 + v53 * v53 + v52 * v52 < 0.0009 )
    return 0;
  v6 = *v2;
  v7 = *(_DWORD *)(this + 15976);
  v8 = *(_DWORD *)(this + 15980);
  *(_DWORD *)(this + 17492) = v6;
  *(_DWORD *)(this + 17496) = v7;
  *(_DWORD *)(this + 17500) = v8;
  if ( *(float *)(this + 15952) < 0.94999999
    && (*(float *)(this + 15952) < 0.70710677
     || !*(_BYTE *)(this + 3216)
     || !*(_BYTE *)(this + 3512)
     || !*(_BYTE *)(this + 3808)
     || !*(_BYTE *)(this + 4104)) )
  {
    return 1;
  }
  v9 = sub_5761B0(this);
  v10 = *(float **)(v9 + 276);
  v11 = *(float **)(v9 + 272);
  v47 = v10;
  v46 = v11;
  v48 = (float *)(v9 + 4);
  v12 = sub_401290(v45, (float *)(v9 + 4), &v52);
  v13 = *v12;
  v14 = v12[1];
  v15 = v12[2];
  v55 = v13;
  v56 = v14;
  v16 = *(float *)(v9 + 36);
  v57 = v15;
  v17 = *(float *)(v9 + 40);
  v54 = *(float *)(v9 + 44);
  v53 = v17;
  v52 = v16;
  v18 = v54 * v57 + v17 * v56 + v16 * v13;
  v41 = v18;
  if ( v18 < *(float *)(this + 17684) )
  {
    v19 = v10[23] >= (double)v11[23] ? v11[23] : v10[23];
    if ( v19 <= *(float *)(v9 + 92) )
      v20 = v10[23] >= (double)v11[23] ? v11[23] : v10[23];
    else
      v20 = *(float *)(v9 + 92);
    v42 = -v20;
    v21 = v41 - *(float *)(this + 17684);
    if ( v21 < v42 )
    {
      if ( v21 >= v42 - 1.75 )
      {
        v22 = 0;
        v23 = (float *)(this + 17504);
        v43 = v42 - v41 + 0.1;
        while ( 1 )
        {
          sub_407380((float *)(this + 15936), v23, &v49);
          if ( v51 * v54 + v50 * v53 + v49 * v52 < v43 )
            break;
          ++v22;
          v23 += 3;
          if ( v22 >= 13 )
          {
            v24 = sub_401290((float *)(this + 17672), v45, v58);
            v25 = *v24;
            v26 = v24[1];
            v51 = v24[2];
            v50 = v26;
            v49 = v25;
            if ( v51 * v54 + v26 * v53 + v25 * v52 < v43 )
              return 1;
            v10 = v47;
            v11 = v46;
            goto LABEL_27;
          }
        }
      }
      return 1;
    }
  }
LABEL_27:
  if ( -*(float *)(this + 17684) < v41 )
  {
    v27 = v10[24] >= (double)v11[24] ? v11[24] : v10[24];
    if ( v27 <= *(float *)(v9 + 96) )
      v28 = v10[24] >= (double)v11[24] ? v11[24] : v10[24];
    else
      v28 = *(float *)(v9 + 96);
    v29 = v41 + *(float *)(this + 17684);
    if ( v29 > v28 )
    {
      if ( v29 <= v28 + 1.75 )
      {
        v30 = 0;
        v31 = (float *)(this + 17504);
        v44 = v28 - v41 - 0.1;
        while ( 1 )
        {
          sub_407380((float *)(this + 15936), v31, &v49);
          if ( v51 * v54 + v50 * v53 + v49 * v52 > v44 )
            break;
          ++v30;
          v31 += 3;
          if ( v30 >= 13 )
          {
            v32 = sub_401290((float *)(this + 17672), v45, v58);
            v33 = *v32;
            v34 = v32[1];
            v51 = v32[2];
            v50 = v34;
            v49 = v33;
            if ( v51 * v54 + v34 * v53 + v33 * v52 > v44 )
              return 1;
            v11 = v46;
            goto LABEL_46;
          }
        }
      }
      return 1;
    }
  }
LABEL_46:
  v35 = sub_401290(v10 + 1, v48, v58);
  v36 = *v35;
  v37 = v35[1];
  v54 = v35[2];
  v53 = v37;
  v52 = v36;
  if ( v54 * v54 + v37 * v37 + v36 * v36 < v54 * v57 + v37 * v56 + v36 * v55 )
    return 1;
  v38 = sub_401290(v11 + 1, v48, v58);
  v39 = *v38;
  v40 = v38[1];
  v54 = v38[2];
  v53 = v40;
  v52 = v39;
  return v54 * v54 + v40 * v40 + v39 * v39 < v54 * v57 + v40 * v56 + v39 * v55;
}
