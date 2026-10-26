_BYTE *__userpurge sub_6D56F0@<eax>(_DWORD *a1@<eax>, char a2)
{
  _BYTE *result; // eax
  _BYTE *v4; // eax
  int v5; // eax
  int v6; // edi
  int v7; // ecx
  int v8; // ecx
  _BYTE *v9; // eax
  int v11; // edi
  int v12; // ecx
  int v13; // ecx
  _DWORD *v14; // ecx
  int v15; // [esp-4h] [ebp-10h]
  int v16; // [esp-4h] [ebp-10h]

  sub_6D5640((int)a1);
  result = (_BYTE *)a1[3];
  if ( !result )
  {
    sub_6D5530((int)a1, 127, 7);
    v4 = (_BYTE *)a1[4];
    *v4 = -1;
    a1[4] = v4 + 1;
    v5 = a1[5] - 1;
    a1[6] = 0;
    a1[7] = 0;
    a1[5] = v5;
    if ( !v5 )
    {
      v6 = *(_DWORD *)(a1[8] + 24);
      if ( !(*(int (__stdcall **)(_DWORD))(v6 + 12))(a1[8]) )
      {
        v7 = *(_DWORD *)a1[8];
        v15 = a1[8];
        *(_DWORD *)(v7 + 20) = 24;
        (*(void (__stdcall **)(int))v7)(v15);
      }
      v8 = *(_DWORD *)(v6 + 4);
      a1[4] = *(_DWORD *)v6;
      a1[5] = v8;
    }
    v9 = (_BYTE *)a1[4];
    *v9 = a2 - 48;
    result = v9 + 1;
    a1[4] = result;
    if ( a1[5]-- == 1 )
    {
      v11 = *(_DWORD *)(a1[8] + 24);
      if ( !(*(int (__stdcall **)(_DWORD))(v11 + 12))(a1[8]) )
      {
        v12 = *(_DWORD *)a1[8];
        v16 = a1[8];
        *(_DWORD *)(v12 + 20) = 24;
        (*(void (__stdcall **)(int))v12)(v16);
      }
      result = *(_BYTE **)(v11 + 4);
      a1[4] = *(_DWORD *)v11;
      a1[5] = result;
    }
  }
  v13 = a1[8];
  if ( *(_DWORD *)(v13 + 324) )
  {
    a1[14] = 0;
    a1[15] = 0;
  }
  else
  {
    result = 0;
    if ( *(int *)(v13 + 252) > 0 )
    {
      v14 = a1 + 9;
      do
      {
        *v14 = 0;
        ++result;
        ++v14;
      }
      while ( (int)result < *(_DWORD *)(a1[8] + 252) );
    }
  }
  return result;
}
