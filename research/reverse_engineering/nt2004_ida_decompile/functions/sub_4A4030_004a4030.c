int __thiscall sub_4A4030(int this)
{
  int v2; // eax

  v2 = *(_DWORD *)(this + 268);
  *(_DWORD *)this = &off_5E9D40;
  if ( v2 )
    sub_5A9130(v2);
  if ( *(_DWORD *)(this + 280) )
    sub_5BE8AE(*(LPVOID *)(this + 280));
  return sub_49C520((LPVOID *)this);
}
