int __thiscall sub_4A2770(int this, char a2, int a3, const char *a4, int a5, int a6)
{
  int result; // eax

  *(_BYTE *)(this + 2) = a2;
  *(_DWORD *)(this + 72) = a3;
  result = sub_4A2010((__int16 *)this, a4, a5, a6, 0);
  if ( *(_DWORD *)(this + 100) )
  {
    if ( *(_BYTE *)(this + 2) )
      return sub_54C030(1, 1, 0, 0);
    else
      return sub_54C030(0, 0, 0, 0);
  }
  return result;
}
