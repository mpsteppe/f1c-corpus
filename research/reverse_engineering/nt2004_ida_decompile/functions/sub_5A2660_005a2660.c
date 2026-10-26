int __thiscall sub_5A2660(int this)
{
  _DWORD *v2; // ecx

  v2 = *(_DWORD **)(this + 16);
  if ( v2 )
  {
    sub_59FA90(v2);
    if ( *(_DWORD *)(this + 16) )
    {
      j_nullsub_6(*(void **)(this + 16));
      sub_5BE8AE();
    }
    *(_DWORD *)(this + 16) = 0;
  }
  *(_BYTE *)(this + 20) = 0;
  return 0;
}
