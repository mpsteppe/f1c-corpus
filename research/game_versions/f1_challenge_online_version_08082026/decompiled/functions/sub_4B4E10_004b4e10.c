_DWORD *__thiscall sub_4B4E10(char *this)
{
  char *v2; // edi
  int *v3; // eax
  bool v4; // zf
  int v5; // ebx
  _DWORD *v6; // esi
  _DWORD *v7; // eax
  int v8; // eax
  int *v9; // eax
  _DWORD *result; // eax
  int v11; // ecx
  _DWORD *v12; // esi
  _DWORD *v13; // esi
  int v14; // [esp+10h] [ebp-4h]

  *((float *)this + 27) = dbl_8AFEA0;
  v2 = this + 112;
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
              sub_587BCF((LPVOID)*v6);
            sub_587BCF(v6);
          }
LABEL_18:
          if ( sub_587C03(12) )
            v8 = sub_4BAC20(v5, 0);
          else
            v8 = 0;
          if ( dword_8AB700 )
          {
            *(_DWORD *)(v8 + 4) = dword_8AB700;
          }
          else
          {
            dword_8AB704 = v8;
            dword_8AB708 = v8;
          }
          dword_8AB700 = v8;
          ++dword_8AB70C;
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
  result = this + 53;
  v11 = 4;
  do
  {
    v12 = result - 13;
    *v12 = 0;
    v12[1] = 0;
    v12[2] = 0;
    *((_BYTE *)v12 + 12) = 0;
    v13 = result;
    *result = 0;
    result[1] = 0;
    result[2] = 0;
    result = (_DWORD *)((char *)result + 13);
    --v11;
    *((_BYTE *)v13 + 12) = 0;
  }
  while ( v11 );
  *this = 1;
  return result;
}
