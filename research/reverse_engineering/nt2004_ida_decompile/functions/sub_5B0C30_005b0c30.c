int __thiscall sub_5B0C30(_DWORD *this, int a2, int a3)
{
  int result; // eax

  result = a2;
  if ( a2 < this[11] )
  {
    result = a2 << 7;
    *(_DWORD *)((a2 << 7) + this[13] + 12) = a3;
  }
  return result;
}
