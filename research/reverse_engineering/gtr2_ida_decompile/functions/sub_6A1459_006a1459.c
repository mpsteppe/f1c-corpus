int __thiscall sub_6A1459(_DWORD *this)
{
  int v1; // eax
  int result; // eax
  unsigned int v3; // edi
  int v4; // ebx
  _DWORD *i; // eax
  int v6; // edx

  if ( (unsigned __int16)this[50] >= 0x200u )
    return 0;
  v1 = this[64];
  if ( (*(_WORD *)(v1 + 2) & 0xFFF0) == 0 )
    return 0;
  v3 = *(_DWORD *)(v1 + 4);
  v4 = 0;
  if ( !v3 )
    return 0;
  for ( i = *(_DWORD **)(v1 + 8); ; ++i )
  {
    v6 = *(_DWORD *)(this[5] + 4 * *i);
    if ( *(_DWORD *)(v6 + 8) != -1 )
      break;
    if ( ++v4 >= v3 )
      return 0;
  }
  result = sub_6A0B7E(this, *(_DWORD *)(v6 + 8));
  if ( result >= 0 )
    return 0;
  return result;
}
