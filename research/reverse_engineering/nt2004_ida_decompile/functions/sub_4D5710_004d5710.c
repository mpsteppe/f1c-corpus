int __thiscall sub_4D5710(_DWORD *this)
{
  _DWORD *v1; // ebp
  char *v2; // edi
  _DWORD **v3; // eax
  bool v4; // zf
  _DWORD *v5; // ebx
  _DWORD *v6; // esi
  _DWORD *v7; // eax
  int v8; // ebp
  _DWORD *v9; // eax
  int v10; // ecx
  int v11; // edx
  _DWORD **v12; // eax
  int result; // eax
  int v15; // [esp+14h] [ebp-4h]

  v1 = this;
  v2 = (char *)(this + 16);
  v15 = 49;
  do
  {
    v3 = *(_DWORD ***)v2;
    v4 = *(_DWORD *)v2 == 0;
    *((_DWORD *)v2 + 2) = *(_DWORD *)v2;
    if ( !v4 )
    {
      v5 = *v3;
      if ( *v3 )
      {
        do
        {
          v6 = *(_DWORD **)v2;
          v7 = 0;
          if ( *(_DWORD *)v2 )
          {
            while ( (_DWORD *)*v6 != v5 )
            {
              v7 = v6;
              v6 = (_DWORD *)v6[1];
              if ( !v6 )
                goto LABEL_20;
            }
            if ( v6 == *((_DWORD **)v2 + 2) )
              *((_DWORD *)v2 + 2) = v6[1];
            if ( v7 )
              v7[1] = v6[1];
            else
              *(_DWORD *)v2 = v6[1];
            if ( *((_DWORD **)v2 + 1) == v6 )
              *((_DWORD *)v2 + 1) = v7;
            --*((_DWORD *)v2 + 3);
            if ( *((_BYTE *)v6 + 8) )
            {
              v8 = *v6;
              if ( *v6 )
              {
                nullsub_6((void *)(v8 + 148));
                sub_5BE8AE((LPVOID)v8);
              }
              v1 = this;
            }
            sub_5BE8AE(v6);
          }
LABEL_20:
          sub_4D3ED0(v5);
          v9 = operator new(0xCu);
          if ( v9 )
          {
            *v9 = v5;
            v9[1] = 0;
            *((_BYTE *)v9 + 8) = 0;
          }
          else
          {
            v9 = 0;
          }
          v10 = v1[4];
          if ( v10 )
          {
            v9[1] = v10;
          }
          else
          {
            v1[5] = v9;
            v1[6] = v9;
          }
          v11 = v1[7] + 1;
          v1[4] = v9;
          v1[7] = v11;
          v12 = *(_DWORD ***)v2;
          v4 = *(_DWORD *)v2 == 0;
          *((_DWORD *)v2 + 2) = *(_DWORD *)v2;
          if ( v4 )
            break;
          v5 = *v12;
        }
        while ( *v12 );
      }
    }
    v2 += 16;
    result = --v15;
  }
  while ( v15 );
  return result;
}
