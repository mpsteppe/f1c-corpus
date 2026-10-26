int __thiscall sub_62AAB0(int this)
{
  if ( !this )
    return -2;
  if ( *(_BYTE *)(this + 92) == 119 && !sub_62A910(this, 4) )
  {
    sub_62AA40(*(_DWORD *)(this + 76), *(FILE **)(this + 64));
    sub_62AA40(*(_DWORD *)(this + 8), *(FILE **)(this + 64));
  }
  return sub_62A7B0(this);
}
