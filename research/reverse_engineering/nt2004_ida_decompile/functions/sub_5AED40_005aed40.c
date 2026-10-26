int __thiscall sub_5AED40(int this)
{
  if ( *(_DWORD *)(this + 16) )
  {
    fclose(*(FILE **)(this + 16));
    *(_DWORD *)(this + 16) = 0;
  }
  if ( *(_DWORD *)(this + 296) )
  {
    sub_5BE8AE();
    *(_DWORD *)(this + 296) = 0;
  }
  return 0;
}
