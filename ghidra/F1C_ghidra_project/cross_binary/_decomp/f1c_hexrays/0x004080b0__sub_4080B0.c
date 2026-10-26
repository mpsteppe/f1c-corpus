// f1c  0x004080b0  size=58
_DWORD *__thiscall sub_4080B0(_DWORD *this, int a2)
{
  _DWORD **v2; // eax
  _DWORD *result; // eax
  int v4; // eax
  _DWORD **v5; // eax

  v2 = (_DWORD **)this[14];
  this[16] = v2;
  if ( !v2 )
    return 0;
  result = *v2;
  if ( result )
  {
    while ( *result != a2 )
    {
      v4 = this[16];
      if ( v4 )
        this[16] = *(_DWORD *)(v4 + 4);
      v5 = (_DWORD **)this[16];
      if ( !v5 )
        return 0;
      result = *v5;
      if ( !result )
        return result;
    }
  }
  return result;
}
