int __thiscall sub_546430(int this)
{
  int result; // eax

  if ( (*(_BYTE *)(this + 156) & 2) == 0 )
  {
    result = 0;
    *(_DWORD *)(this + 148) = 0;
    *(_DWORD *)(this + 152) = 0;
  }
  return result;
}

