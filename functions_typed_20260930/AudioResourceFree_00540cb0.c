int __thiscall sub_540CB0(_DWORD *this, int a2)
{
  void *v2; // eax
  void *v4; // esi

  if ( this[1271] )
  {
    if ( *(_DWORD *)(a2 + 28) )
      FreeWrapper_7bcf(*(LPVOID *)(a2 + 28));
    v2 = *(void **)(a2 + 36);
    *(_DWORD *)(a2 + 28) = 0;
    *(_DWORD *)(a2 + 44) = 0;
    if ( v2 )
      FreeWrapper_7bcf(v2);
    *(_DWORD *)(a2 + 36) = 0;
    *(_DWORD *)(a2 + 48) = 0;
    return 0;
  }
  else
  {
    ObjectResetWithVirtualRelease(*(_DWORD *)(a2 + 28));
    if ( *(_DWORD *)(a2 + 28) )
      FreeWrapper_7bcf(*(LPVOID *)(a2 + 28));
    DrainingLoopFinalizer(*(_DWORD *)(a2 + 36));
    v4 = *(void **)(a2 + 36);
    if ( v4 )
      FreeWrapper_7bcf(v4);
    return 0;
  }
}

