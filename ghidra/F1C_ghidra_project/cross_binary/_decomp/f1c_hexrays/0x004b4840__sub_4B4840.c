// f1c  0x004b4840  size=158
_DWORD *__thiscall sub_4B4840(char *this, int a2, int a3, _BYTE *a4)
{
  int v5; // ebx
  int v6; // edi
  _DWORD **v7; // eax
  char *v8; // ecx
  _DWORD *result; // eax
  int v10; // eax
  _DWORD **v11; // eax

  v5 = (int)&this[13 * a2 + a3 / 8];
  if ( ((*(char *)(v5 + 1) >> (a3 % 8)) & 1) == 0 )
    return 0;
  v6 = 16 * (a2 + 7);
  v7 = *(_DWORD ***)&this[v6];
  v8 = &this[v6];
  *(_DWORD *)&this[v6 + 8] = v7;
  if ( !v7 )
    return 0;
  result = *v7;
  if ( !result )
    return 0;
  while ( (unsigned __int8)*result != a3 )
  {
    v10 = *((_DWORD *)v8 + 2);
    if ( v10 )
      *((_DWORD *)v8 + 2) = *(_DWORD *)(v10 + 4);
    v11 = (_DWORD **)*((_DWORD *)v8 + 2);
    if ( v11 )
    {
      result = *v11;
      if ( result )
        continue;
    }
    return 0;
  }
  *a4 = (*(char *)(v5 + 53) >> (a3 % 8)) & 1;
  return result;
}
