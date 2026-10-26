int __thiscall sub_5FABB0(int this)
{
  void *v2; // eax
  int *v3; // eax
  int i; // eax
  int v5; // esi
  int v6; // ecx
  void *v7; // ebp
  int *v8; // eax
  int *v9; // eax
  int j; // eax
  int v11; // esi
  int v12; // ecx
  void *v13; // ebp
  int *v14; // eax
  _DWORD **v15; // edi
  int v16; // ebp
  _DWORD *v17; // esi
  void *v18; // eax

  v2 = *(void **)(this + 332);
  *(_BYTE *)(this + 204) = 0;
  *(_DWORD *)(this + 336) = 0;
  *(_BYTE *)(this + 268) = 0;
  if ( v2 )
    j__free(v2);
  *(_DWORD *)(this + 332) = 0;
  v3 = *(int **)(this + 540);
  *(_DWORD *)(this + 548) = v3;
  if ( v3 )
  {
    for ( i = *v3; i; i = *v8 )
    {
      v5 = *(_DWORD *)(this + 540);
      v6 = 0;
      if ( v5 )
      {
        while ( *(_DWORD *)v5 != i )
        {
          v6 = v5;
          v5 = *(_DWORD *)(v5 + 4);
          if ( !v5 )
            goto LABEL_20;
        }
        if ( v5 == *(_DWORD *)(this + 548) )
          *(_DWORD *)(this + 548) = *(_DWORD *)(v5 + 4);
        if ( v6 )
          *(_DWORD *)(v6 + 4) = *(_DWORD *)(v5 + 4);
        else
          *(_DWORD *)(this + 540) = *(_DWORD *)(v5 + 4);
        if ( *(_DWORD *)(this + 544) == v5 )
          *(_DWORD *)(this + 544) = v6;
        --*(_DWORD *)(this + 552);
        if ( *(_BYTE *)(v5 + 8) )
        {
          v7 = *(void **)v5;
          if ( *(_DWORD *)v5 )
          {
            sub_5F77C0(*(char **)v5);
            j__free(v7);
          }
        }
        j__free((void *)v5);
      }
LABEL_20:
      v8 = *(int **)(this + 540);
      *(_DWORD *)(this + 548) = v8;
      if ( !v8 )
        break;
    }
  }
  v9 = *(int **)(this + 556);
  *(_DWORD *)(this + 564) = v9;
  if ( v9 )
  {
    for ( j = *v9; j; j = *v14 )
    {
      v11 = *(_DWORD *)(this + 556);
      v12 = 0;
      if ( v11 )
      {
        while ( *(_DWORD *)v11 != j )
        {
          v12 = v11;
          v11 = *(_DWORD *)(v11 + 4);
          if ( !v11 )
            goto LABEL_39;
        }
        if ( v11 == *(_DWORD *)(this + 564) )
          *(_DWORD *)(this + 564) = *(_DWORD *)(v11 + 4);
        if ( v12 )
          *(_DWORD *)(v12 + 4) = *(_DWORD *)(v11 + 4);
        else
          *(_DWORD *)(this + 556) = *(_DWORD *)(v11 + 4);
        if ( *(_DWORD *)(this + 560) == v11 )
          *(_DWORD *)(this + 560) = v12;
        --*(_DWORD *)(this + 568);
        if ( *(_BYTE *)(v11 + 8) )
        {
          v13 = *(void **)v11;
          if ( *(_DWORD *)v11 )
          {
            sub_5F77C0(*(char **)v11);
            j__free(v13);
          }
        }
        j__free((void *)v11);
      }
LABEL_39:
      v14 = *(int **)(this + 556);
      *(_DWORD *)(this + 564) = v14;
      if ( !v14 )
        break;
    }
  }
  v15 = (_DWORD **)(this + 756);
  v16 = 6;
  do
  {
    v17 = *v15;
    if ( *v15 )
    {
      v18 = (void *)v17[1];
      *v17 = 0;
      if ( v18 )
        j__free(v18);
      j__free(v17);
    }
    ++v15;
    --v16;
  }
  while ( v16 );
  return 0;
}
