void __thiscall sub_4BECA0(_DWORD *this, int a2)
{
  int *v3; // eax
  int v4; // ecx
  int v5; // edi
  int v6; // eax
  int *v7; // eax
  _DWORD **v8; // eax
  _DWORD *v9; // ecx
  int v10; // ebx
  int v11; // edi
  int v12; // ecx
  int v13; // eax
  _DWORD **v14; // eax
  _DWORD **v15; // eax
  _DWORD *v16; // ecx
  int v17; // edi
  int v18; // eax
  _DWORD **v19; // eax

  if ( dword_75CBB0 == 7 )
  {
    switch ( a2 )
    {
      case 1:
        v15 = (_DWORD **)this[46];
        this[48] = v15;
        if ( v15 )
        {
          v16 = *v15;
          if ( *v15 )
          {
            do
            {
              if ( v16[18] != -1 )
              {
                v17 = v16[25];
                if ( v17 )
                {
                  if ( sub_4BD140(v16, this[50]) )
                    sub_59EF50(v17);
                }
              }
              v18 = this[48];
              if ( !v18 )
                break;
              v19 = *(_DWORD ***)(v18 + 4);
              this[48] = v19;
              if ( !v19 )
                break;
              v16 = *v19;
            }
            while ( *v19 );
          }
        }
        break;
      case 2:
        v8 = (_DWORD **)this[46];
        this[48] = v8;
        if ( v8 )
        {
          v9 = *v8;
          if ( *v8 )
          {
            do
            {
              if ( v9[18] != -1 )
              {
                v10 = v9[25];
                if ( v10 )
                {
                  v11 = this[50];
                  if ( sub_4BD140(v9, v11) )
                  {
                    if ( *(_BYTE *)(v12 + 2) || !sub_4BD140((_DWORD *)v12, v11) )
                      sub_59EF60(v10);
                    else
                      sub_59EF50(v10);
                  }
                }
              }
              v13 = this[48];
              if ( !v13 )
                break;
              v14 = *(_DWORD ***)(v13 + 4);
              this[48] = v14;
              if ( !v14 )
                break;
              v9 = *v14;
            }
            while ( *v14 );
          }
        }
        break;
      case 3:
        v3 = (int *)this[46];
        this[48] = v3;
        if ( v3 )
        {
          v4 = *v3;
          if ( *v3 )
          {
            do
            {
              if ( *(_DWORD *)(v4 + 72) != -1 )
              {
                v5 = *(_DWORD *)(v4 + 100);
                if ( v5 )
                {
                  if ( *(_BYTE *)(v4 + 2) && sub_4BD140((_DWORD *)v4, this[50]) )
                    sub_59EF50(v5);
                  else
                    sub_59EF60(v5);
                }
              }
              v6 = this[48];
              if ( !v6 )
                break;
              v7 = *(int **)(v6 + 4);
              this[48] = v7;
              if ( !v7 )
                break;
              v4 = *v7;
            }
            while ( *v7 );
          }
        }
        break;
    }
  }
}
