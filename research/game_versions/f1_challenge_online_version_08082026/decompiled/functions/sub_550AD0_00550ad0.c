int __thiscall sub_550AD0(float *this, int a2, int a3)
{
  float *v3; // ebx
  _DWORD *v4; // ebp
  int v5; // edx
  int v6; // eax
  char v7; // cl
  int v8; // eax
  int v9; // esi
  float *v11; // edi
  int v12; // esi
  _DWORD *v13; // eax
  int v14; // esi
  _DWORD *v15; // edi
  int v16; // esi
  int v17; // eax
  int v18; // ebp
  int v19; // esi
  _DWORD *v20; // eax
  int v21; // esi
  _DWORD *v22; // edx
  _DWORD *v23; // ecx
  int v24; // esi
  int v25; // ecx
  int v26; // edi
  int v27; // eax
  int v28; // edi
  int *v29; // esi
  _DWORD *v30; // ebx
  int v31; // eax
  int v32; // esi
  bool v33; // cc
  int v34; // esi
  int v35; // eax
  _DWORD *v36; // eax
  int v37; // esi
  _DWORD *v38; // ebp
  int v39; // esi
  int v40; // ecx
  int *v41; // esi
  int *v42; // edi
  int v43; // ebp
  int v44; // eax
  _DWORD *v45; // eax
  int v46; // ebp
  int v47; // ebp
  void *v48; // ecx
  unsigned int v49; // edx
  int v50; // eax
  int v51; // ecx
  double v52; // st7
  int v53; // edi
  int v54; // [esp+10h] [ebp-14h]
  _DWORD *v55; // [esp+10h] [ebp-14h]
  int v56; // [esp+10h] [ebp-14h]
  int v58; // [esp+14h] [ebp-10h]
  _DWORD *v59; // [esp+1Ch] [ebp-8h]
  int v60; // [esp+28h] [ebp+4h]
  _DWORD *v61; // [esp+28h] [ebp+4h]
  int v62; // [esp+28h] [ebp+4h]
  int v63; // [esp+2Ch] [ebp+8h]

  v3 = this;
  v4 = 0;
  if ( a3
    && (v5 = *(_DWORD *)(a3 + 296),
        v6 = *(_DWORD *)(a3 + 292) << 8,
        v7 = *(_BYTE *)(v6 + v5),
        v8 = v5 + v6,
        (v7 & 0x10) != 0) )
  {
    v9 = *(_DWORD *)(v8 + 12);
    dword_8B8F30 = sub_587C03(*(_DWORD *)(v8 + 8));
    dword_8B8F34 = sub_587C03(v9);
    if ( sub_58803F(dword_8B8F34, 1, v9, a2) != v9 )
    {
      sub_587BCF((LPVOID)dword_8B8F30);
      sub_587BCF((LPVOID)dword_8B8F34);
      return -1;
    }
    sub_59B260(dword_8B8F34, v9);
  }
  else
  {
    v26 = sub_58ACE6(a2);
    sub_587F64(a2, 0, 2);
    v63 = sub_58ACE6(a2) - v26;
    sub_587F64(a2, v26, 0);
    dword_8B8F30 = sub_587C03(v63);
    if ( sub_58803F(dword_8B8F30, 1, v63, a2) != v63 )
    {
      sub_587BCF((LPVOID)dword_8B8F30);
      return -1;
    }
  }
  dword_8B8F3C = 0;
  sub_54A5C0(v3 + 7, dword_8B8F30, 0x10u);
  sub_54A5C0(v3, dword_8B8F30, 4u);
  v11 = v3 + 1;
  sub_54A5C0(v3 + 1, dword_8B8F30, 4u);
  sub_54A5C0(v3 + 2, dword_8B8F30, 4u);
  v3[1] = 1.0 / v3[1];
  sub_589901((LPCSTR)v3 + 28);
  if ( (*(_DWORD *)v3 & 2) != 0 )
  {
    sub_54A5C0(v3 + 5, dword_8B8F30, 4u);
    v12 = *((_DWORD *)v3 + 5);
    v13 = (_DWORD *)sub_587C03(12 * v12 + 4);
    if ( v13 )
    {
      *v13 = v12;
      v14 = v12 - 1;
      v4 = v13 + 1;
      v15 = v13 + 1;
      if ( v14 >= 0 )
      {
        v16 = v14 + 1;
        do
        {
          sub_5593B0(v15);
          v15 += 3;
          --v16;
        }
        while ( v16 );
      }
    }
    v17 = *((_DWORD *)v3 + 5);
    *((_DWORD *)v3 + 6) = v4;
    v60 = 0;
    if ( v17 > 0 )
    {
      v54 = 0;
      do
      {
        v18 = v54 + *((_DWORD *)v3 + 6);
        sub_54A5C0((void *)(v18 + 4), dword_8B8F30, 4u);
        v19 = *(_DWORD *)(v18 + 4);
        v20 = (_DWORD *)sub_587C03(8 * v19 + 4);
        if ( v20 )
        {
          *v20 = v19;
          v21 = v19 - 1;
          v22 = v20 + 1;
          v23 = v20 + 1;
          if ( v21 >= 0 )
          {
            v24 = v21 + 1;
            do
            {
              sub_550800(v23);
              v23 = (_DWORD *)(v25 + 8);
              --v24;
            }
            while ( v24 );
          }
        }
        else
        {
          v22 = 0;
        }
        v27 = *(_DWORD *)(v18 + 4);
        v28 = 0;
        *(_DWORD *)(v18 + 8) = v22;
        if ( v27 > 0 )
        {
          do
          {
            v29 = (int *)(*(_DWORD *)(v18 + 8) + 8 * v28);
            sub_54A5C0(v29, dword_8B8F30, 4u);
            v30 = v29 + 1;
            v31 = sub_587C03(36 * *v29);
            v32 = *v29;
            *v30 = v31;
            sub_54A5C0(v30, dword_8B8F30, 36 * v32);
            ++v28;
          }
          while ( v28 < *(_DWORD *)(v18 + 4) );
          v3 = this;
        }
        v33 = ++v60 < *((_DWORD *)v3 + 5);
        v54 += 12;
      }
      while ( v33 );
    }
  }
  else if ( (*(_DWORD *)v3 & 1) != 0 )
  {
    sub_54A5C0(v3 + 3, dword_8B8F30, 4u);
    v34 = *((_DWORD *)v3 + 3);
    v35 = sub_587C03(44 * v34 + 4);
    if ( v35 )
    {
      v36 = (_DWORD *)(v35 + 4);
      *(v36 - 1) = v34;
      v37 = v34 - 1;
      v61 = v36;
      v38 = v36;
      if ( v37 >= 0 )
      {
        v39 = v37 + 1;
        do
        {
          sub_5507E0(v38);
          v38 += 11;
          --v39;
        }
        while ( v39 );
        v36 = v61;
      }
    }
    else
    {
      v36 = 0;
    }
    v40 = *((_DWORD *)v3 + 3);
    *((_DWORD *)v3 + 4) = v36;
    v62 = 0;
    if ( v40 > 0 )
    {
      v58 = 0;
      do
      {
        v41 = (int *)(v58 + *((_DWORD *)v3 + 4));
        sub_54A5C0(v41, dword_8B8F30, 0x20u);
        sub_54A5C0(v41 + 8, dword_8B8F30, 4u);
        v42 = v41 + 9;
        sub_54A5C0(v41 + 9, dword_8B8F30, 4u);
        v43 = v41[9];
        v44 = sub_587C03(32 * v43 + 4);
        if ( v44 )
        {
          v45 = (_DWORD *)(v44 + 4);
          *(v45 - 1) = v43;
          v46 = v43 - 1;
          v59 = v45;
          v55 = v45;
          if ( v46 >= 0 )
          {
            v47 = v46 + 1;
            do
            {
              sub_5507A0(v55);
              --v47;
              v55 += 8;
            }
            while ( v47 );
            v45 = v59;
          }
          v48 = v45;
        }
        else
        {
          v48 = 0;
        }
        v49 = 32 * *v42;
        v41[10] = (int)v48;
        sub_54A5C0(v48, dword_8B8F30, v49);
        v50 = 0;
        v56 = 0;
        if ( *v42 > 0 )
        {
          v51 = 0;
          do
          {
            ++v50;
            v51 += 32;
            v52 = (double)v56 * v3[1];
            v56 = v50;
            *(float *)(v51 + v41[10] - 32) = v52;
          }
          while ( v50 < *v42 );
        }
        v53 = *v42;
        if ( v53 > *((_DWORD *)v3 + 5) )
          *((_DWORD *)v3 + 5) = v53;
        v33 = ++v62 < *((_DWORD *)v3 + 3);
        v58 += 44;
      }
      while ( v33 );
      v11 = v3 + 1;
    }
    v3[2] = (double)*((int *)v3 + 5) * *v11;
  }
  if ( dword_8B8F30 )
    sub_587BCF((LPVOID)dword_8B8F30);
  if ( dword_8B8F34 )
    sub_587BCF((LPVOID)dword_8B8F34);
  return 0;
}
