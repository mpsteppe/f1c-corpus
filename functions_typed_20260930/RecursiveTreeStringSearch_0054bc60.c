void __thiscall sub_54BC60(int this, const char *a2, _DWORD *a3)
{
  if ( *(_DWORD *)(this + 68) )
    RecursiveTreeStringSearch(a2, a3);
  if ( *(_DWORD *)(this + 76) )
    RecursiveTreeStringSearch(a2, a3);
  if ( !*a3 && !strcmp((const char *)this, a2) )
    *a3 = this;
}

