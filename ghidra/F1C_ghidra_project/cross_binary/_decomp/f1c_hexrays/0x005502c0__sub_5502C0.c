// f1c  0x005502c0  size=55
int __thiscall sub_5502C0(int this)
{
  _DWORD *v2; // ecx
  void *v3; // edi

  v2 = *(_DWORD **)(this + 84);
  if ( v2 )
  {
    sub_542E50(v2);
    v3 = *(void **)(this + 84);
    if ( v3 )
    {
      j_nullsub_3(*(_DWORD *)(this + 84));
      sub_587BCF(v3);
    }
    *(_DWORD *)(this + 84) = 0;
  }
  *(_BYTE *)(this + 4) = 0;
  return 0;
}
