int __thiscall sub_6CB1EB(_DWORD *this, __int64 a2, int a3)
{
  int result; // eax
  int v5; // eax

  result = sub_6CB1D4(this, HIDWORD(a2) | a2);
  if ( result >= 0 )
  {
    if ( a3 )
    {
      result = sub_6CB1D4(this, a3);
      if ( result < 0 )
        return result;
      v5 = this[67] + 4 * this[70];
      *(_BYTE *)(v5 + 3) |= 0x10u;
    }
    return 0;
  }
  return result;
}
