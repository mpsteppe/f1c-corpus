int __thiscall sub_540CB0(_DWORD *this, int a2)
{
  void *v2; // eax
  void *v4; // esi

  if ( this[1271] )
  {
    if ( *(_DWORD *)(a2 + 28) )
      sub_587BCF(*(LPVOID *)(a2 + 28));
    v2 = *(void **)(a2 + 36);
    *(_DWORD *)(a2 + 28) = 0;
    *(_DWORD *)(a2 + 44) = 0;
    if ( v2 )
      sub_587BCF(v2);
    *(_DWORD *)(a2 + 36) = 0;
    *(_DWORD *)(a2 + 48) = 0;
    return 0;
  }
  else
  {
    sub_540EB0(*(_DWORD *)(a2 + 28));
    if ( *(_DWORD *)(a2 + 28) )
      sub_587BCF(*(LPVOID *)(a2 + 28));
    sub_541040(*(_DWORD *)(a2 + 36));
    v4 = *(void **)(a2 + 36);
    if ( v4 )
      sub_587BCF(v4);
    return 0;
  }
}
