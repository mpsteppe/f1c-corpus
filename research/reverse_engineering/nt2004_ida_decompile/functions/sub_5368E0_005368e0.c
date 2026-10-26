int __thiscall sub_5368E0(int this)
{
  int result; // eax

  result = sub_536910();
  if ( !result )
  {
    fflush(*(FILE **)(this + 64));
    return *(_DWORD *)(this + 56) != 1 ? *(_DWORD *)(this + 56) : 0;
  }
  return result;
}
