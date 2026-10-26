double __thiscall sub_5C68E0(_DWORD *this)
{
  double result; // st7
  int v2; // edi
  int v3; // ebp
  int v4; // edx
  unsigned int v5; // ebx
  int *v6; // eax
  int v7; // esi
  int v8; // eax
  bool v9; // c0
  int v10; // esi
  int *v11; // eax
  int v12; // esi
  int v13; // eax
  bool v14; // c0
  int v15; // esi
  int *v16; // eax
  int v17; // esi
  int v18; // eax
  bool v19; // c0
  int v20; // esi
  int *v21; // eax
  int v22; // esi
  int v23; // eax
  bool v24; // c0
  int v25; // esi
  int **v26; // esi
  int v27; // edi
  int *v28; // eax
  int v29; // edx
  int v30; // eax
  bool v31; // c0
  int v32; // edx
  int v33; // ebx
  int v34; // ebp
  int v35; // edx
  unsigned int v36; // edi
  int *v37; // eax
  int v38; // esi
  int v39; // eax
  bool v40; // c0
  int v41; // esi
  int *v42; // eax
  int v43; // esi
  int v44; // eax
  bool v45; // c0
  int v46; // esi
  int *v47; // eax
  int v48; // esi
  int v49; // eax
  bool v50; // c0
  int v51; // esi
  int *v52; // eax
  int v53; // esi
  int v54; // eax
  bool v55; // c0
  int v56; // esi
  int **v57; // edx
  int v58; // esi
  int *v59; // eax
  int v60; // ecx
  int v61; // eax
  bool v62; // c0
  int v63; // ecx

  result = 0.0;
  v2 = this[9];
  v3 = 0;
  if ( v2 >= 4 )
  {
    v4 = this[11] + 8;
    v5 = ((unsigned int)(v2 - 4) >> 2) + 1;
    v3 = 4 * v5;
    do
    {
      v6 = *(int **)(v4 - 8);
      if ( v6 )
      {
        v7 = *v6;
        if ( *v6 > 0 )
        {
          v8 = v6[2];
          v9 = result < *(float *)(v8 + 8 * v7 - 4);
          v10 = v8 + 8 * v7 - 8;
          if ( v9 )
            result = *(float *)(v10 + 4);
        }
      }
      v11 = *(int **)(v4 - 4);
      if ( v11 )
      {
        v12 = *v11;
        if ( *v11 > 0 )
        {
          v13 = v11[2];
          v14 = result < *(float *)(v13 + 8 * v12 - 4);
          v15 = v13 + 8 * v12 - 8;
          if ( v14 )
            result = *(float *)(v15 + 4);
        }
      }
      v16 = *(int **)v4;
      if ( *(_DWORD *)v4 )
      {
        v17 = *v16;
        if ( *v16 > 0 )
        {
          v18 = v16[2];
          v19 = result < *(float *)(v18 + 8 * v17 - 4);
          v20 = v18 + 8 * v17 - 8;
          if ( v19 )
            result = *(float *)(v20 + 4);
        }
      }
      v21 = *(int **)(v4 + 4);
      if ( v21 )
      {
        v22 = *v21;
        if ( *v21 > 0 )
        {
          v23 = v21[2];
          v24 = result < *(float *)(v23 + 8 * v22 - 4);
          v25 = v23 + 8 * v22 - 8;
          if ( v24 )
            result = *(float *)(v25 + 4);
        }
      }
      v4 += 16;
      --v5;
    }
    while ( v5 );
  }
  if ( v3 < v2 )
  {
    v26 = (int **)(this[11] + 4 * v3);
    v27 = v2 - v3;
    do
    {
      v28 = *v26;
      if ( *v26 )
      {
        v29 = *v28;
        if ( *v28 > 0 )
        {
          v30 = v28[2];
          v31 = result < *(float *)(v30 + 8 * v29 - 4);
          v32 = v30 + 8 * v29 - 8;
          if ( v31 )
            result = *(float *)(v32 + 4);
        }
      }
      ++v26;
      --v27;
    }
    while ( v27 );
  }
  v33 = this[6];
  v34 = 0;
  if ( v33 >= 4 )
  {
    v35 = this[8] + 8;
    v36 = ((unsigned int)(v33 - 4) >> 2) + 1;
    v34 = 4 * v36;
    do
    {
      v37 = *(int **)(v35 - 8);
      if ( v37 )
      {
        v38 = *v37;
        if ( *v37 > 0 )
        {
          v39 = v37[2];
          v40 = result < *(float *)(v39 + 8 * v38 - 4);
          v41 = v39 + 8 * v38 - 8;
          if ( v40 )
            result = *(float *)(v41 + 4);
        }
      }
      v42 = *(int **)(v35 - 4);
      if ( v42 )
      {
        v43 = *v42;
        if ( *v42 > 0 )
        {
          v44 = v42[2];
          v45 = result < *(float *)(v44 + 8 * v43 - 4);
          v46 = v44 + 8 * v43 - 8;
          if ( v45 )
            result = *(float *)(v46 + 4);
        }
      }
      v47 = *(int **)v35;
      if ( *(_DWORD *)v35 )
      {
        v48 = *v47;
        if ( *v47 > 0 )
        {
          v49 = v47[2];
          v50 = result < *(float *)(v49 + 8 * v48 - 4);
          v51 = v49 + 8 * v48 - 8;
          if ( v50 )
            result = *(float *)(v51 + 4);
        }
      }
      v52 = *(int **)(v35 + 4);
      if ( v52 )
      {
        v53 = *v52;
        if ( *v52 > 0 )
        {
          v54 = v52[2];
          v55 = result < *(float *)(v54 + 8 * v53 - 4);
          v56 = v54 + 8 * v53 - 8;
          if ( v55 )
            result = *(float *)(v56 + 4);
        }
      }
      v35 += 16;
      --v36;
    }
    while ( v36 );
  }
  if ( v34 < v33 )
  {
    v57 = (int **)(this[8] + 4 * v34);
    v58 = v33 - v34;
    do
    {
      v59 = *v57;
      if ( *v57 )
      {
        v60 = *v59;
        if ( *v59 > 0 )
        {
          v61 = v59[2];
          v62 = result < *(float *)(v61 + 8 * v60 - 4);
          v63 = v61 + 8 * v60 - 8;
          if ( v62 )
            result = *(float *)(v63 + 4);
        }
      }
      ++v57;
      --v58;
    }
    while ( v58 );
  }
  return result;
}
