void __thiscall sub_59E8F0(int this, const char *a2, _DWORD *a3)
{
  if ( *(_DWORD *)(this + 68) )
    sub_59E8F0(a2, a3);
  if ( *(_DWORD *)(this + 76) )
    sub_59E8F0(a2, a3);
  if ( !*a3 && !strcmp((const char *)this, a2) )
    *a3 = this;
}
