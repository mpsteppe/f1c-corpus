int __userpurge sub_6D4B60@<eax>(_DWORD *a1@<eax>, char a2)
{
  _BYTE *v3; // eax
  int v4; // eax
  int v5; // edi
  int v6; // ecx
  _BYTE *v7; // eax
  int v9; // edi
  int v10; // eax
  int v11; // eax
  _DWORD *v12; // ecx

  if ( !sub_6D48F0((int)a1, 127, 7) )
    return 0;
  a1[2] = 0;
  a1[3] = 0;
  v3 = (_BYTE *)*a1;
  *v3 = -1;
  *a1 = v3 + 1;
  v4 = a1[1] - 1;
  a1[1] = v4;
  if ( !v4 )
  {
    v5 = *(_DWORD *)(a1[8] + 24);
    if ( !(*(int (__stdcall **)(_DWORD))(v5 + 12))(a1[8]) )
      return 0;
    v6 = *(_DWORD *)(v5 + 4);
    *a1 = *(_DWORD *)v5;
    a1[1] = v6;
  }
  v7 = (_BYTE *)*a1;
  *v7 = a2 - 48;
  *a1 = v7 + 1;
  if ( a1[1]-- == 1 )
  {
    v9 = *(_DWORD *)(a1[8] + 24);
    if ( (*(int (__stdcall **)(_DWORD))(v9 + 12))(a1[8]) )
    {
      v10 = *(_DWORD *)(v9 + 4);
      *a1 = *(_DWORD *)v9;
      a1[1] = v10;
      goto LABEL_8;
    }
    return 0;
  }
LABEL_8:
  v11 = 0;
  if ( *(int *)(a1[8] + 252) > 0 )
  {
    v12 = a1 + 4;
    do
    {
      *v12 = 0;
      ++v11;
      ++v12;
    }
    while ( v11 < *(_DWORD *)(a1[8] + 252) );
  }
  return 1;
}
