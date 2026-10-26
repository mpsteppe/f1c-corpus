int __thiscall sub_406150(int this)
{
  sub_4062E0();
  if ( *(_DWORD *)(this + 12) )
  {
    fclose(*(FILE **)(this + 12));
    *(_DWORD *)(this + 12) = 0;
  }
  if ( *(_DWORD *)(this + 24) )
    sub_5BE8AE(*(LPVOID *)(this + 24));
  return sub_4060F0((_DWORD *)this);
}
