void __usercall sub_5FAE80(_DWORD *a1@<ecx>, int a2@<ebp>)
{
  void **v3; // eax
  void *v4; // ebp
  _DWORD *v5; // esi
  _DWORD *v6; // eax
  void *v7; // ebx
  void **v8; // eax
  void **v9; // esi
  int v10; // ebx
  char *v11; // eax
  char *v12; // edi
  int v13; // [esp-4h] [ebp-10h]

  v3 = (void **)a1[2344];
  a1[2346] = v3;
  if ( v3 )
  {
    v13 = a2;
    v4 = *v3;
    if ( *v3 )
    {
      do
      {
        sub_5FABB0((int)v4);
        v5 = (_DWORD *)a1[2344];
        v6 = 0;
        if ( v5 )
        {
          while ( (void *)*v5 != v4 )
          {
            v6 = v5;
            v5 = (_DWORD *)v5[1];
            if ( !v5 )
              goto LABEL_18;
          }
          if ( v5 == (_DWORD *)a1[2346] )
            a1[2346] = v5[1];
          if ( v6 )
            v6[1] = v5[1];
          else
            a1[2344] = v5[1];
          if ( (_DWORD *)a1[2345] == v5 )
            a1[2345] = v6;
          --a1[2347];
          if ( *((_BYTE *)v5 + 8) )
          {
            v7 = (void *)*v5;
            if ( *v5 )
            {
              sub_5FAB30(v13);
              j__free(v7);
            }
          }
          j__free(v5);
        }
LABEL_18:
        sub_5FAB30(v13);
        j__free(v4);
        v8 = (void **)a1[2344];
        a1[2346] = v8;
        if ( !v8 )
          break;
        v4 = *v8;
      }
      while ( *v8 );
    }
  }
  v9 = (void **)(a1 + 2277);
  v10 = 6;
  do
  {
    v11 = (char *)*v9;
    if ( *v9 )
    {
      v12 = v11 - 4;
      `eh vector destructor iterator'(v11, 4u, *((_DWORD *)v11 - 1), j_nullsub_7);
      j__free(v12);
    }
    *v9 = 0;
    *(v9 - 6) = 0;
    *(v9 - 12) = 0;
    ++v9;
    --v10;
  }
  while ( v10 );
}
