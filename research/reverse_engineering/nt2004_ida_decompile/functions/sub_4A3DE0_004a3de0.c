int __thiscall sub_4A3DE0(int this)
{
  int v2; // eax

  v2 = *(_DWORD *)(this + 268);
  *(_DWORD *)this = &off_5E9C98;
  if ( v2 )
    sub_5A9130(v2);
  if ( *(_DWORD *)(this + 292) )
    sub_5BE8AE(*(LPVOID *)(this + 292));
  return sub_49D970((LPVOID *)this);
}
