int __thiscall sub_6AB03D(_DWORD *this, int a2)
{
  int result; // eax

  result = a2;
  if ( *(_DWORD *)(this[64] + 36) == 1 )
    return a2 | 0x40000000;
  return result;
}
