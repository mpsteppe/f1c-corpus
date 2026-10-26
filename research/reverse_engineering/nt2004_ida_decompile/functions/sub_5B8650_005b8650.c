int __thiscall sub_5B8650(int this)
{
  void *v2; // ecx

  v2 = *(void **)(this + 16);
  if ( v2 )
  {
    nullsub_6(v2);
    if ( *(_DWORD *)(this + 16) )
    {
      j_nullsub_6(*(void **)(this + 16));
      sub_5BE8AE();
    }
    *(_DWORD *)(this + 16) = 0;
  }
  if ( *(_DWORD *)(this + 32) )
  {
    j_nullsub_6(*(void **)(this + 32));
    sub_5BE8AE();
    *(_DWORD *)(this + 32) = 0;
  }
  if ( *(_DWORD *)(this + 36) )
  {
    sub_5B8200(*(_DWORD **)(this + 36));
    sub_5BE8AE();
    *(_DWORD *)(this + 36) = 0;
  }
  return sub_5B8770(this);
}
