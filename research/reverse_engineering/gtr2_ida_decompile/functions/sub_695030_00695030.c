int __thiscall sub_695030(int this, int a2, int a3)
{
  int v3; // esi
  int v5; // eax
  int v6; // esi
  int v7; // eax

  v3 = a3;
  if ( (*(_DWORD *)(a3 + 16) & *(_DWORD *)(a2 + 16)) != 0 )
    sub_694B97(this, this + 32, 3048, "duplicate usages specified");
  if ( *(_DWORD *)(a2 + 20) )
  {
    v5 = *(_DWORD *)(a3 + 20);
    if ( v5 )
    {
      qmemcpy((void *)(this + 32), (const void *)(v5 + 16), 0x20u);
      sub_694A67(this, "syntax error");
      v3 = a3;
    }
  }
  *(_DWORD *)(a2 + 16) |= *(_DWORD *)(v3 + 16);
  if ( *(_DWORD *)(a2 + 20) )
    return 0;
  v6 = *(_DWORD *)(v3 + 20);
  if ( !v6 )
    return 0;
  v7 = sub_67ECC3(v6);
  *(_DWORD *)(a2 + 20) = v7;
  if ( v7 )
    return 0;
  else
    return -2147024882;
}
