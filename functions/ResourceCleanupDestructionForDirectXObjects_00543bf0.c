int __thiscall sub_543BF0(_DWORD *this)
{
  int v2; // edi
  int i; // eax
  int v4; // edi
  int j; // eax
  int v6; // edi
  int k; // eax
  int v9; // edi
  int m; // eax
  int v11; // edi
  int n; // eax
  int v13; // edi
  int ii; // eax
  int v15; // eax
  void *v16; // ebp
  int v17; // edi
  int v18; // ebx
  int v19; // eax
  void *v20; // ebp
  int v21; // edi
  int v22; // ebx
  int v23; // eax
  void *v24; // ebp
  int v25; // edi
  int v26; // ebx
  int v27; // eax
  void *v28; // ebp
  int v29; // edi
  int v30; // ebx
  int v31; // eax
  void *v32; // ebp
  int v33; // edi
  int v34; // ebx
  int v35; // ecx
  int v36; // eax
  void *v37; // ebp
  int v38; // edx
  int v39; // eax
  int v40; // edi
  int v41; // ebx
  int v42; // ecx
  int v43; // eax
  void *v44; // ebp
  int v45; // edx
  int v46; // eax
  int v47; // edi
  int v48; // ebx
  int v49; // ecx
  int v50; // eax
  void *v51; // ebp
  int v52; // edx
  int v53; // eax
  int v54; // edi
  int v55; // ebx
  int v56; // edi
  int jj; // eax

  v2 = this[62];
  if ( v2 )
  {
    for ( i = *(_DWORD *)(v2 + 440); i; i = *(_DWORD *)(v2 + 440) )
    {
      v2 = i;
      SceneGraphTreeDestructor(*(_DWORD *)(i + 436));
    }
    SceneGraphTreeDestructor(v2);
    this[62] = 0;
  }
  v4 = this[64];
  if ( v4 )
  {
    for ( j = *(_DWORD *)(v4 + 260); j; j = *(_DWORD *)(v4 + 260) )
    {
      v4 = j;
      DestroyFree(*(_DWORD *)(j + 256));
    }
    DestroyFree(v4);
    this[64] = 0;
  }
  v6 = this[66];
  if ( v6 )
  {
    for ( k = *(_DWORD *)(v6 + 76); k; k = *(_DWORD *)(v6 + 76) )
    {
      v6 = k;
      F_3DSoundSourceDestructor(*(_DWORD *)(k + 72));
    }
    F_3DSoundSourceDestructor(v6);
    this[66] = 0;
  }
  if ( this[68] && LinkedListWalkWithExitCheck() )
    return -1;
  AudioNetworkStreamCleanup(this);
  v9 = this[72];
  if ( v9 )
  {
    for ( m = *(_DWORD *)(v9 + 108); m; m = *(_DWORD *)(v9 + 108) )
    {
      v9 = m;
      sub_5454A0(*(_DWORD *)(m + 104));
    }
    sub_5454A0(v9);
    this[72] = 0;
  }
  v11 = this[74];
  if ( v11 )
  {
    for ( n = *(_DWORD *)(v11 + 108); n; n = *(_DWORD *)(v11 + 108) )
    {
      v11 = n;
      sub_5454A0(*(_DWORD *)(n + 104));
    }
    sub_5454A0(v11);
    this[74] = 0;
  }
  v13 = this[76];
  if ( v13 )
  {
    for ( ii = *(_DWORD *)(v13 + 108); ii; ii = *(_DWORD *)(v13 + 108) )
    {
      v13 = ii;
      sub_5454A0(*(_DWORD *)(ii + 104));
    }
    sub_5454A0(v13);
    this[76] = 0;
  }
  if ( this[107] )
    ConditionalFreeOfStructField(this);
  v15 = this[110];
  if ( v15 )
  {
    v16 = (void *)(v15 - 4);
    v17 = v15 + 528 * *(_DWORD *)(v15 - 4);
    if ( *(_DWORD *)(v15 - 4) - 1 >= 0 )
    {
      v18 = *(_DWORD *)(v15 - 4);
      do
      {
        v17 -= 528;
        CleanupFunction(v17);
        --v18;
      }
      while ( v18 );
    }
    FreeWrapper_7bcf(v16);
  }
  v19 = this[112];
  if ( v19 )
  {
    v20 = (void *)(v19 - 4);
    v21 = v19 + 528 * *(_DWORD *)(v19 - 4);
    if ( *(_DWORD *)(v19 - 4) - 1 >= 0 )
    {
      v22 = *(_DWORD *)(v19 - 4);
      do
      {
        v21 -= 528;
        CleanupFunction(v21);
        --v22;
      }
      while ( v22 );
    }
    FreeWrapper_7bcf(v20);
  }
  v23 = this[114];
  if ( v23 )
  {
    v24 = (void *)(v23 - 4);
    v25 = v23 + 528 * *(_DWORD *)(v23 - 4);
    if ( *(_DWORD *)(v23 - 4) - 1 >= 0 )
    {
      v26 = *(_DWORD *)(v23 - 4);
      do
      {
        v25 -= 528;
        CleanupFunction(v25);
        --v26;
      }
      while ( v26 );
    }
    FreeWrapper_7bcf(v24);
  }
  v27 = this[116];
  if ( v27 )
  {
    v28 = (void *)(v27 - 4);
    v29 = v27 + 528 * *(_DWORD *)(v27 - 4);
    if ( *(_DWORD *)(v27 - 4) - 1 >= 0 )
    {
      v30 = *(_DWORD *)(v27 - 4);
      do
      {
        v29 -= 528;
        CleanupFunction(v29);
        --v30;
      }
      while ( v30 );
    }
    FreeWrapper_7bcf(v28);
  }
  v31 = this[78];
  if ( v31 )
  {
    v32 = (void *)(v31 - 4);
    v33 = v31 + 56 * *(_DWORD *)(v31 - 4);
    if ( *(_DWORD *)(v31 - 4) - 1 >= 0 )
    {
      v34 = *(_DWORD *)(v31 - 4);
      do
      {
        v33 -= 56;
        EmptyStub_0170();
        --v34;
      }
      while ( v34 );
    }
    FreeWrapper_7bcf(v32);
  }
  v35 = this[84];
  if ( v35 )
  {
    v36 = *(_DWORD *)(v35 - 4);
    v37 = (void *)(v35 - 4);
    v38 = 3 * v36;
    v39 = v36 - 1;
    v40 = v35 + 8 * v38;
    if ( v39 >= 0 )
    {
      v41 = v39 + 1;
      do
      {
        v40 -= 24;
        EmptyStub_0170();
        --v41;
      }
      while ( v41 );
    }
    FreeWrapper_7bcf(v37);
  }
  if ( dword_8B8F2C )
    sub_5593D0();
  v42 = this[80];
  if ( v42 )
  {
    v43 = *(_DWORD *)(v42 - 4);
    v44 = (void *)(v42 - 4);
    v45 = 3 * v43;
    v46 = v43 - 1;
    v47 = v42 + 8 * v45;
    if ( v46 >= 0 )
    {
      v48 = v46 + 1;
      do
      {
        v47 -= 24;
        EmptyStub_0170();
        --v48;
      }
      while ( v48 );
    }
    FreeWrapper_7bcf(v44);
  }
  v49 = this[94];
  if ( v49 )
  {
    v50 = *(_DWORD *)(v49 - 4);
    v51 = (void *)(v49 - 4);
    v52 = 3 * v50;
    v53 = v50 - 1;
    v54 = v49 + 8 * v52;
    if ( v53 >= 0 )
    {
      v55 = v53 + 1;
      do
      {
        v54 -= 24;
        EmptyStub_0170();
        --v55;
      }
      while ( v55 );
    }
    FreeWrapper_7bcf(v51);
  }
  v56 = this[70];
  if ( v56 )
  {
    for ( jj = *(_DWORD *)(v56 + 48); jj; jj = *(_DWORD *)(v56 + 48) )
    {
      v56 = jj;
      DoublyLinkedListNodeRemoval_19e0(*(_DWORD *)(jj + 44));
    }
    DoublyLinkedListNodeRemoval_19e0(v56);
    this[70] = 0;
  }
  return 0;
}
