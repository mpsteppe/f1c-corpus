int __thiscall sub_583F50(char *this, float a2)
{
  char *v2; // esi
  int v3; // edi
  HANDLE *v4; // ebp
  char *v5; // edi
  void *v6; // eax
  DWORD v7; // eax
  int *v8; // eax
  bool v9; // zf
  int v10; // ebx
  int v11; // eax
  DWORD v12; // eax
  _DWORD *v13; // esi
  _DWORD *v14; // eax
  int *v15; // eax
  int v16; // eax
  int result; // eax
  int v19; // [esp+4h] [ebp-8h]
  int v20; // [esp+8h] [ebp-4h]
  char *v21; // [esp+10h] [ebp+4h]

  v2 = this;
  v3 = 0;
  v19 = 0;
  v20 = CRTFtol(a2 * 1000.0 + 0.5);
  do
  {
    if ( v3 )
    {
      v4 = (HANDLE *)(v2 + 1348);
      v21 = v2 + 1432;
    }
    else
    {
      v4 = (HANDLE *)(v2 + 1376);
      v21 = v2 + 1404;
    }
    v5 = v21;
    v6 = (void *)*((_DWORD *)v21 + 4);
    if ( !v6 || (v7 = WaitForSingleObject(v6, *((_DWORD *)v21 + 5))) != 0 && v7 != 128 )
      v5 = 0;
    v8 = *(int **)v5;
    v9 = *(_DWORD *)v5 == 0;
    *((_DWORD *)v5 + 2) = *(_DWORD *)v5;
    if ( !v9 )
    {
      v10 = *v8;
      if ( *v8 )
      {
        do
        {
          v11 = *(_DWORD *)(v10 + 76) - v20;
          *(_DWORD *)(v10 + 76) = v11;
          if ( v11 > 0 || (v12 = WaitForSingleObject(v4[4], 1u), v12 == 258) || v12 == -1 )
          {
            v16 = *((_DWORD *)v5 + 2);
            if ( !v16 )
              break;
            v15 = *(int **)(v16 + 4);
            *((_DWORD *)v5 + 2) = v15;
          }
          else
          {
            v13 = *(_DWORD **)v5;
            v14 = 0;
            if ( *(_DWORD *)v5 )
            {
              while ( *v13 != v10 )
              {
                v14 = v13;
                v13 = (_DWORD *)v13[1];
                if ( !v13 )
                  goto LABEL_26;
              }
              if ( v13 == *((_DWORD **)v5 + 2) )
                *((_DWORD *)v5 + 2) = v13[1];
              if ( v14 )
                v14[1] = v13[1];
              else
                *(_DWORD *)v5 = v13[1];
              if ( *((_DWORD **)v5 + 1) == v13 )
                *((_DWORD *)v5 + 1) = v14;
              --*((_DWORD *)v5 + 3);
              ConditionalListNodeCleanup(v13);
              FreeWrapper_7bcf(v13);
            }
LABEL_26:
            LinkedListNodeAppend_6000(v10, 0);
            if ( v4[4] )
              ReleaseMutex(v4[4]);
            v15 = (int *)*((_DWORD *)v5 + 2);
            v2 = this;
          }
          if ( !v15 )
            break;
          v10 = *v15;
        }
        while ( *v15 );
      }
    }
    result = *((_DWORD *)v21 + 4);
    if ( result )
      result = ReleaseMutex(*((HANDLE *)v21 + 4));
    v3 = ++v19;
  }
  while ( v19 < 2 );
  return result;
}
