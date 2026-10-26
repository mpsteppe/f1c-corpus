int __thiscall sub_5A4E50(char *this, float a2)
{
  char *v2; // esi
  char *v3; // ebx
  HANDLE *v4; // ebp
  void *v5; // eax
  DWORD v6; // eax
  char *v7; // edi
  int *v8; // eax
  bool v9; // zf
  int v10; // ebx
  int v11; // eax
  DWORD v12; // eax
  _DWORD *v13; // esi
  _DWORD *v14; // eax
  void *v15; // ebp
  int *v16; // eax
  int v17; // eax
  int result; // eax
  char *v19; // [esp+0h] [ebp-10h]
  int v20; // [esp+4h] [ebp-Ch]
  int v22; // [esp+Ch] [ebp-4h]
  HANDLE *v23; // [esp+14h] [ebp+4h]

  v2 = this;
  v20 = 0;
  v22 = (unsigned __int64)(a2 * 1000.0 + 0.5);
  do
  {
    if ( v20 )
    {
      v19 = v2 + 1448;
      v23 = (HANDLE *)(v2 + 1364);
      v4 = (HANDLE *)(v2 + 1364);
      v3 = v2 + 1448;
    }
    else
    {
      v3 = v2 + 1420;
      v4 = (HANDLE *)(v2 + 1392);
      v19 = v2 + 1420;
      v23 = (HANDLE *)(v2 + 1392);
    }
    v5 = (void *)*((_DWORD *)v3 + 4);
    if ( v5 && ((v6 = WaitForSingleObject(v5, *((_DWORD *)v3 + 5))) == 0 || v6 == 128) )
      v7 = v3;
    else
      v7 = 0;
    v8 = *(int **)v7;
    v9 = *(_DWORD *)v7 == 0;
    *((_DWORD *)v7 + 2) = *(_DWORD *)v7;
    if ( !v9 )
    {
      v10 = *v8;
      if ( *v8 )
      {
        do
        {
          v11 = *(_DWORD *)(v10 + 76) - v22;
          v9 = *(_DWORD *)(v10 + 76) == v22;
          *(_DWORD *)(v10 + 76) = v11;
          if ( v11 >= 0 && !v9 || (v12 = WaitForSingleObject(v4[4], 1u), v12 == 258) || v12 == -1 )
          {
            v17 = *((_DWORD *)v7 + 2);
            if ( !v17 )
              break;
            v16 = *(int **)(v17 + 4);
            *((_DWORD *)v7 + 2) = v16;
          }
          else
          {
            v13 = *(_DWORD **)v7;
            v14 = 0;
            if ( *(_DWORD *)v7 )
            {
              while ( *v13 != v10 )
              {
                v14 = v13;
                v13 = (_DWORD *)v13[1];
                if ( !v13 )
                  goto LABEL_31;
              }
              if ( v13 == *((_DWORD **)v7 + 2) )
                *((_DWORD *)v7 + 2) = v13[1];
              if ( v14 )
                v14[1] = v13[1];
              else
                *(_DWORD *)v7 = v13[1];
              if ( *((_DWORD **)v7 + 1) == v13 )
                *((_DWORD *)v7 + 1) = v14;
              --*((_DWORD *)v7 + 3);
              if ( *((_BYTE *)v13 + 8) )
              {
                v15 = (void *)*v13;
                if ( *v13 )
                {
                  sub_5A6920((void *)*v13);
                  j__free(v15);
                }
                v4 = v23;
              }
              j__free(v13);
            }
LABEL_31:
            sub_5FDFB0(v10, 0);
            if ( v4[4] )
              ReleaseMutex(v4[4]);
            v16 = (int *)*((_DWORD *)v7 + 2);
            v2 = this;
          }
          if ( !v16 )
            break;
          v10 = *v16;
        }
        while ( *v16 );
      }
      v3 = v19;
    }
    if ( *((_DWORD *)v3 + 4) )
      ReleaseMutex(*((HANDLE *)v3 + 4));
    result = ++v20;
  }
  while ( v20 < 2 );
  return result;
}
