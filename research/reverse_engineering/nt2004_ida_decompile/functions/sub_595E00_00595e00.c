int __thiscall sub_595E00(_DWORD *this)
{
  _DWORD *v2; // edi
  int i; // eax
  _DWORD *v4; // edi
  int j; // eax
  int v6; // edi
  int k; // eax
  int v9; // edi
  int m; // eax
  int v11; // edi
  int n; // eax
  int v13; // edi
  int ii; // eax
  int v15; // edi
  int jj; // eax
  int v17; // eax
  char *v18; // edi
  int v19; // ebx
  int v20; // eax
  char *v21; // edi
  int v22; // ebx
  int v23; // eax
  char *v24; // edi
  int v25; // ebx
  int v26; // eax
  char *v27; // edi
  int v28; // ebx
  int v29; // eax
  char *v30; // edi
  int v31; // ebx
  int v32; // ecx
  int v33; // eax
  int v34; // edx
  int v35; // eax
  char *v36; // edi
  int v37; // ebx
  _DWORD *v38; // edi
  void *v39; // ebx
  int v40; // ecx
  int v41; // eax
  int v42; // edx
  int v43; // eax
  char *v44; // edi
  int v45; // ebx
  int v46; // ecx
  int v47; // eax
  int v48; // edx
  int v49; // eax
  char *v50; // edi
  int v51; // ebx
  int v52; // edi
  int kk; // eax

  v2 = (_DWORD *)this[63];
  if ( v2 )
  {
    for ( i = v2[158]; i; i = v2[158] )
    {
      v2 = (_DWORD *)i;
      sub_597160(*(void **)(i + 628));
    }
    sub_597160(v2);
    this[63] = 0;
  }
  v4 = (_DWORD *)this[65];
  if ( v4 )
  {
    for ( j = v4[65]; j; j = v4[65] )
    {
      v4 = (_DWORD *)j;
      sub_5954B0(*(_DWORD **)(j + 256));
    }
    sub_5954B0(v4);
    this[65] = 0;
  }
  v6 = this[67];
  if ( v6 )
  {
    for ( k = *(_DWORD *)(v6 + 76); k; k = *(_DWORD *)(v6 + 76) )
    {
      v6 = k;
      sub_5973D0(*(_DWORD *)(k + 72));
    }
    sub_5973D0(v6);
    this[67] = 0;
  }
  if ( this[69] && sub_59A5B0() )
    return -1;
  sub_596D40(this);
  v9 = this[73];
  if ( v9 )
  {
    for ( m = *(_DWORD *)(v9 + 204); m; m = *(_DWORD *)(v9 + 204) )
    {
      v9 = m;
      sub_597700(*(_DWORD *)(m + 200));
    }
    sub_597700(v9);
    this[73] = 0;
  }
  v11 = this[75];
  if ( v11 )
  {
    for ( n = *(_DWORD *)(v11 + 204); n; n = *(_DWORD *)(v11 + 204) )
    {
      v11 = n;
      sub_597700(*(_DWORD *)(n + 200));
    }
    sub_597700(v11);
    this[75] = 0;
  }
  v13 = this[77];
  if ( v13 )
  {
    for ( ii = *(_DWORD *)(v13 + 204); ii; ii = *(_DWORD *)(v13 + 204) )
    {
      v13 = ii;
      sub_597700(*(_DWORD *)(ii + 200));
    }
    sub_597700(v13);
    this[77] = 0;
  }
  v15 = this[79];
  if ( v15 )
  {
    for ( jj = *(_DWORD *)(v15 + 204); jj; jj = *(_DWORD *)(v15 + 204) )
    {
      v15 = jj;
      sub_597700(*(_DWORD *)(jj + 200));
    }
    sub_597700(v15);
    this[77] = 0;
  }
  if ( this[111] )
    sub_5B81A0(this);
  v17 = this[114];
  if ( v17 )
  {
    v18 = (char *)(v17 + 528 * *(_DWORD *)(v17 - 4));
    if ( *(_DWORD *)(v17 - 4) - 1 >= 0 )
    {
      v19 = *(_DWORD *)(v17 - 4);
      do
      {
        v18 -= 528;
        sub_5AEA20(v18);
        --v19;
      }
      while ( v19 );
    }
    sub_5BE8AE();
  }
  v20 = this[116];
  if ( v20 )
  {
    v21 = (char *)(v20 + 528 * *(_DWORD *)(v20 - 4));
    if ( *(_DWORD *)(v20 - 4) - 1 >= 0 )
    {
      v22 = *(_DWORD *)(v20 - 4);
      do
      {
        v21 -= 528;
        sub_5AEA20(v21);
        --v22;
      }
      while ( v22 );
    }
    sub_5BE8AE();
  }
  v23 = this[118];
  if ( v23 )
  {
    v24 = (char *)(v23 + 528 * *(_DWORD *)(v23 - 4));
    if ( *(_DWORD *)(v23 - 4) - 1 >= 0 )
    {
      v25 = *(_DWORD *)(v23 - 4);
      do
      {
        v24 -= 528;
        sub_5AEA20(v24);
        --v25;
      }
      while ( v25 );
    }
    sub_5BE8AE();
  }
  v26 = this[120];
  if ( v26 )
  {
    v27 = (char *)(v26 + 528 * *(_DWORD *)(v26 - 4));
    if ( *(_DWORD *)(v26 - 4) - 1 >= 0 )
    {
      v28 = *(_DWORD *)(v26 - 4);
      do
      {
        v27 -= 528;
        sub_5AEA20(v27);
        --v28;
      }
      while ( v28 );
    }
    sub_5BE8AE();
  }
  v29 = this[81];
  if ( v29 )
  {
    v30 = (char *)(v29 + 56 * *(_DWORD *)(v29 - 4));
    if ( *(_DWORD *)(v29 - 4) - 1 >= 0 )
    {
      v31 = *(_DWORD *)(v29 - 4);
      do
      {
        v30 -= 56;
        nullsub_6(v30);
        --v31;
      }
      while ( v31 );
    }
    sub_5BE8AE();
  }
  v32 = this[87];
  if ( v32 )
  {
    v33 = *(_DWORD *)(v32 - 4);
    v34 = 3 * v33;
    v35 = v33 - 1;
    v36 = (char *)(v32 + 8 * v34);
    if ( v35 >= 0 )
    {
      v37 = v35 + 1;
      do
      {
        v36 -= 24;
        nullsub_6(v36);
        --v37;
      }
      while ( v37 );
    }
    sub_5BE8AE();
  }
  if ( dword_7E8E60 )
    sub_5B1360();
  v38 = (_DWORD *)this[90];
  while ( v38 )
  {
    v39 = v38;
    v38 = (_DWORD *)v38[1];
    nullsub_6(v39);
    sub_5BE8AE();
  }
  v40 = this[83];
  if ( v40 )
  {
    v41 = *(_DWORD *)(v40 - 4);
    v42 = 3 * v41;
    v43 = v41 - 1;
    v44 = (char *)(v40 + 8 * v42);
    if ( v43 >= 0 )
    {
      v45 = v43 + 1;
      do
      {
        v44 -= 24;
        nullsub_6(v44);
        --v45;
      }
      while ( v45 );
    }
    sub_5BE8AE();
  }
  v46 = this[97];
  if ( v46 )
  {
    v47 = *(_DWORD *)(v46 - 4);
    v48 = 3 * v47;
    v49 = v47 - 1;
    v50 = (char *)(v46 + 8 * v48);
    if ( v49 >= 0 )
    {
      v51 = v49 + 1;
      do
      {
        v50 -= 24;
        nullsub_6(v50);
        --v51;
      }
      while ( v51 );
    }
    sub_5BE8AE();
  }
  v52 = this[71];
  if ( v52 )
  {
    for ( kk = *(_DWORD *)(v52 + 48); kk; kk = *(_DWORD *)(v52 + 48) )
    {
      v52 = kk;
      sub_5ADDC0(*(_DWORD *)(kk + 44));
    }
    sub_5ADDC0(v52);
    this[71] = 0;
  }
  return 0;
}
