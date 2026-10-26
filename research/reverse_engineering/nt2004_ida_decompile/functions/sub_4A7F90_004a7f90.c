void __thiscall sub_4A7F90(_DWORD *this)
{
  _DWORD *v1; // esi
  int v2; // eax
  char *v3; // eax
  _DWORD *v4; // eax
  _DWORD *v5; // edi
  int *v6; // ebp
  int v7; // esi
  int *v8; // edi
  bool v9; // zf
  _DWORD *v10; // [esp+8h] [ebp-10h]
  _DWORD *v11; // [esp+Ch] [ebp-Ch]
  _DWORD *v13; // [esp+14h] [ebp-4h]

  v1 = this;
  if ( this[38] )
  {
    v2 = sub_4AEF90();
    if ( v2 )
    {
      v3 = *(char **)(v2 + 36);
      if ( !v3 )
        v3 = &byte_629120;
      v4 = (_DWORD *)sub_4A80A0(v1[67], v3);
      v13 = v4;
      if ( v4 )
      {
        v5 = (_DWORD *)v1[68];
        if ( v5 )
        {
          while ( 1 )
          {
            v11 = v5;
            v10 = (_DWORD *)v5[1];
            if ( *((_BYTE *)v5 + 8) )
            {
              v6 = (int *)*v5;
              if ( *v5 )
              {
                v7 = *v6;
                if ( *v6 )
                {
                  do
                  {
                    v8 = (int *)v7;
                    v9 = *(_BYTE *)(v7 + 8) == 0;
                    v7 = *(_DWORD *)(v7 + 4);
                    if ( !v9 )
                    {
                      if ( *v8 )
                        sub_4A79D0(*v8, 1);
                    }
                    sub_5BE8AE(v8);
                  }
                  while ( v7 );
                  v5 = v11;
                }
                *v6 = 0;
                v6[1] = 0;
                v6[2] = 0;
                v6[3] = 0;
                sub_5BE8AE(v6);
                v1 = this;
              }
            }
            sub_5BE8AE(v5);
            if ( !v10 )
              break;
            v5 = v10;
          }
          v4 = v13;
        }
        v1[68] = 0;
        v1[69] = 0;
        v1[70] = 0;
        v1[71] = 0;
        sub_4A7600(v1, v4, 1, 0, 0);
      }
    }
  }
}
