int __thiscall sub_53E3E0(int this)
{
  int result; // eax

  result = *(_DWORD *)(this + 14820);
  if ( result == 1 )
  {
    sub_583170(this + 16, 0, 1);
    result = *(_DWORD *)(this + 16152);
    dword_B6C3D0 = result;
  }
  else if ( !result )
  {
    sub_583170(this + 16, 1, 1);
    *(_BYTE *)(dword_91E084 + 19520) = 0;
    *(_BYTE *)(this + 19472) = 0;
    return sub_429540();
  }
  return result;
}
