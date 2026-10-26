char *__thiscall sub_4D3D70(float *this)
{
  char *v2; // edi
  int *v3; // eax
  bool v4; // zf
  int v5; // ebx
  _DWORD *v6; // esi
  _DWORD *v7; // eax
  int v8; // eax
  int *v9; // eax
  char *result; // eax
  int v11; // ecx
  char *v12; // esi
  char *v13; // esi
  int v14; // [esp+10h] [ebp-4h]

  this[15] = dbl_7DA9D0;
  v2 = (char *)(this + 16);
  v14 = 4;
  do
  {
    v3 = *(int **)v2;
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
            while ( *v6 != v5 )
            {
              v7 = v6;
              v6 = (_DWORD *)v6[1];
              if ( !v6 )
                goto LABEL_18;
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
              sub_5BE8AE((LPVOID)*v6);
            sub_5BE8AE(v6);
          }
LABEL_18:
          if ( operator new(0xCu) )
            v8 = sub_4DB610(v5, 0);
          else
            v8 = 0;
          if ( dword_7D5DC0 )
          {
            *(_DWORD *)(v8 + 4) = dword_7D5DC0;
          }
          else
          {
            dword_7D5DC4 = v8;
            dword_7D5DC8 = v8;
          }
          dword_7D5DC0 = v8;
          ++dword_7D5DCC;
          v9 = *(int **)v2;
          v4 = *(_DWORD *)v2 == 0;
          *((_DWORD *)v2 + 2) = *(_DWORD *)v2;
          if ( v4 )
            break;
          v5 = *v9;
        }
        while ( *v9 );
      }
    }
    v2 += 16;
    --v14;
  }
  while ( v14 );
  result = (char *)this + 29;
  v11 = 4;
  do
  {
    v12 = result - 28;
    *(_DWORD *)v12 = 0;
    *((_WORD *)v12 + 2) = 0;
    v12[6] = 0;
    v13 = result;
    result += 7;
    --v11;
    *(_DWORD *)v13 = 0;
    *((_WORD *)v13 + 2) = 0;
    v13[6] = 0;
  }
  while ( v11 );
  *(_BYTE *)this = 1;
  return result;
}
