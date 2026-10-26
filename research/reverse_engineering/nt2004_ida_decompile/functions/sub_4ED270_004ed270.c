void __thiscall sub_4ED270(_DWORD *this)
{
  int v2; // ecx
  int *v3; // eax
  int v4; // ecx
  int v5; // eax
  int v6; // esi
  _DWORD *v7; // eax
  int v8; // edx
  int v9; // ecx
  void *v10; // edi
  int v11; // eax
  int *v12; // ecx
  int v13; // ecx
  int v14; // eax
  int *v15; // eax

  v2 = this[24];
  if ( v2 )
  {
    v3 = *(int **)(v2 + 68);
    *(_DWORD *)(v2 + 76) = v3;
    if ( v3 )
    {
      v4 = *v3;
      while ( v4 )
      {
        v5 = this[24];
        if ( *(_DWORD *)(v4 + 8) == 3 )
        {
          v6 = *(_DWORD *)(v5 + 68);
          v7 = (_DWORD *)(v5 + 68);
          v8 = 0;
          if ( v6 )
          {
            while ( *(_DWORD *)v6 != v4 )
            {
              v8 = v6;
              v6 = *(_DWORD *)(v6 + 4);
              if ( !v6 )
                goto LABEL_20;
            }
            if ( v6 == v7[2] )
              v7[2] = *(_DWORD *)(v6 + 4);
            v9 = *(_DWORD *)(v6 + 4);
            if ( v8 )
              *(_DWORD *)(v8 + 4) = v9;
            else
              *v7 = v9;
            if ( v7[1] == v6 )
              v7[1] = v8;
            --v7[3];
            if ( *(_BYTE *)(v6 + 8) )
            {
              v10 = *(void **)v6;
              if ( *(_DWORD *)v6 )
              {
                sub_4ECA40(*(void **)v6);
                sub_5BE8AE(v10);
              }
            }
            sub_5BE8AE((LPVOID)v6);
          }
LABEL_20:
          v11 = this[24];
          v12 = *(int **)(v11 + 68);
          *(_DWORD *)(v11 + 76) = v12;
          if ( !v12 )
            return;
          v4 = *v12;
        }
        else
        {
          v13 = *(_DWORD *)(v5 + 76);
          v14 = v5 + 68;
          if ( v13 )
            *(_DWORD *)(v14 + 8) = *(_DWORD *)(v13 + 4);
          v15 = *(int **)(v14 + 8);
          if ( !v15 )
            return;
          v4 = *v15;
        }
      }
    }
  }
}
