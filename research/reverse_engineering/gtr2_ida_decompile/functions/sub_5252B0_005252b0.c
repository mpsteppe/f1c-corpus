_DWORD *__thiscall sub_5252B0(char *this)
{
  char *v2; // edi
  int *v3; // eax
  bool v4; // zf
  int v5; // ebx
  _DWORD *v6; // esi
  _DWORD *v7; // eax
  int *v8; // eax
  _DWORD *result; // eax
  int v10; // ecx
  _DWORD *v11; // esi
  _DWORD *v12; // esi
  int v13; // [esp+Ch] [ebp-4h]

  *((float *)this + 29) = dbl_FB1D18;
  v2 = this + 120;
  v13 = 4;
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
              j__free((void *)*v6);
            j__free(v6);
          }
LABEL_18:
          sub_5E5780(v5, 0);
          v8 = *(int **)v2;
          v4 = *(_DWORD *)v2 == 0;
          *((_DWORD *)v2 + 2) = *(_DWORD *)v2;
          if ( v4 )
            break;
          v5 = *v8;
        }
        while ( *v8 );
      }
    }
    v2 += 16;
    --v13;
  }
  while ( v13 );
  result = this + 57;
  v10 = 4;
  do
  {
    v11 = result - 14;
    *v11 = 0;
    v11[1] = 0;
    v11[2] = 0;
    *((_WORD *)v11 + 6) = 0;
    v12 = result;
    *result = 0;
    result[1] = 0;
    result[2] = 0;
    result = (_DWORD *)((char *)result + 14);
    --v10;
    *((_WORD *)v12 + 6) = 0;
  }
  while ( v10 );
  *this = 1;
  return result;
}
