int __thiscall sub_5A3180(int this)
{
  bool v2; // zf
  void *v3; // esi

  if ( *(_DWORD *)(this + 24) )
  {
    sub_5BE8AE();
    *(_DWORD *)(this + 24) = 0;
  }
  sub_592310(*(void **)(this + 180));
  v2 = (*(_DWORD *)(this + 100) & 0x20000) == 0;
  *(_DWORD *)(this + 180) = 0;
  if ( !v2 )
  {
    sub_5A7FD0(*(_DWORD *)(this + 16));
    if ( *(_DWORD *)(this + 16) )
      sub_5BE8AE();
    v3 = *(void **)(this + 4280);
    if ( v3 )
    {
      j_nullsub_6(v3);
      sub_5BE8AE();
    }
  }
  return 0;
}
