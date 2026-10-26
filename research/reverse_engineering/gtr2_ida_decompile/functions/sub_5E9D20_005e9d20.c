int __userpurge sub_5E9D20@<eax>(_DWORD *a1@<ecx>, __int32 a2@<ebx>, int a3@<ebp>, char a4)
{
  int *v5; // eax
  int v6; // ebp
  int v7; // esi
  int v8; // eax
  int v9; // eax
  void *v10; // ebp
  int *v11; // eax
  int *v12; // eax
  int **v13; // esi
  int i; // eax
  int *v15; // eax
  bool v16; // zf
  int v18; // [esp-4h] [ebp-Ch]

  v5 = (int *)a1[9];
  a1[11] = v5;
  if ( v5 )
  {
    v18 = a3;
    v6 = *v5;
    if ( *v5 )
    {
      while ( 1 )
      {
        if ( a4 )
        {
          sub_5E9AE0();
          v7 = a1[9];
          v8 = 0;
          if ( v7 )
          {
            while ( *(_DWORD *)v7 != v6 )
            {
              v8 = v7;
              v7 = *(_DWORD *)(v7 + 4);
              if ( !v7 )
                goto LABEL_32;
            }
            if ( v7 == a1[11] )
              a1[11] = *(_DWORD *)(v7 + 4);
            if ( v8 )
              *(_DWORD *)(v8 + 4) = *(_DWORD *)(v7 + 4);
            else
              a1[9] = *(_DWORD *)(v7 + 4);
            if ( a1[10] == v7 )
              a1[10] = v8;
            --a1[12];
LABEL_28:
            if ( *(_BYTE *)(v7 + 8) )
            {
              v10 = *(void **)v7;
              if ( *(_DWORD *)v7 )
              {
                sub_5E8CD0(*(void **)v7, a2, v18);
                j__free(v10);
              }
            }
            j__free((void *)v7);
          }
        }
        else
        {
          v7 = a1[9];
          v9 = 0;
          if ( v7 )
          {
            while ( *(_DWORD *)v7 != v6 )
            {
              v9 = v7;
              v7 = *(_DWORD *)(v7 + 4);
              if ( !v7 )
                goto LABEL_32;
            }
            if ( v7 == a1[11] )
              a1[11] = *(_DWORD *)(v7 + 4);
            if ( v9 )
              *(_DWORD *)(v9 + 4) = *(_DWORD *)(v7 + 4);
            else
              a1[9] = *(_DWORD *)(v7 + 4);
            if ( a1[10] == v7 )
              a1[10] = v9;
            --a1[12];
            *(_BYTE *)(v7 + 8) = 0;
            goto LABEL_28;
          }
        }
LABEL_32:
        v11 = (int *)a1[9];
        a1[11] = v11;
        if ( v11 )
        {
          v6 = *v11;
          if ( *v11 )
            continue;
        }
        break;
      }
    }
  }
  v12 = (int *)a1[13];
  v13 = (int **)(a1 + 13);
  a1[15] = v12;
  if ( v12 )
  {
    for ( i = *v12; i; i = *v15 )
    {
      sub_5E9A60(a1 + 13, i, a4);
      v15 = *v13;
      v16 = *v13 == 0;
      a1[15] = a1[13];
      if ( v16 )
        break;
    }
  }
  return 0;
}
