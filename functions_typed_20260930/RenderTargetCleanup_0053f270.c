void __thiscall sub_53F270(int this, int a2)
{
  int v3; // eax
  _DWORD *v4; // edi
  int v5; // eax
  int i; // edi
  int v7; // eax
  int v8; // eax

  if ( (*(_DWORD *)(this + 5032) & 0x10000000) != 0 )
  {
    v3 = *(_DWORD *)(this + 4416);
    if ( v3 )
    {
      ObjectResetWithVirtualRelease(v3);
      if ( *(_DWORD *)(this + 4416) )
        FreeWrapper_7bcf(*(LPVOID *)(this + 4416));
      *(_DWORD *)(this + 4416) = 0;
    }
    if ( *(_DWORD *)(this + 4412) )
    {
      ObjectResetWithVirtualRelease(*(_DWORD *)(this + 4412));
      if ( *(_DWORD *)(this + 4412) )
        FreeWrapper_7bcf(*(LPVOID *)(this + 4412));
      *(_DWORD *)(this + 4412) = 0;
    }
    if ( *(_DWORD *)(this + 4420) )
    {
      DrainingLoopFinalizer(*(_DWORD *)(this + 4420));
      if ( *(_DWORD *)(this + 4420) )
        FreeWrapper_7bcf(*(LPVOID *)(this + 4420));
      *(_DWORD *)(this + 4420) = 0;
    }
    v4 = *(_DWORD **)(this + 5400);
    *(_DWORD *)(this + 5024) = 1;
    *(_DWORD *)(this + 5360) = 0;
    *(_DWORD *)(this + 5364) = 0;
    *(_DWORD *)(this + 5368) = 0;
    *(_DWORD *)(this + 5372) = 0;
    *(_DWORD *)(this + 5376) = 0;
    for ( *(_DWORD *)(this + 5380) = 0; v4; v4 = (_DWORD *)v4[8] )
    {
      if ( v4[5] )
      {
        ObjectResetWithVirtualRelease(v4[5]);
        v4[5] = 0;
      }
      v5 = v4[4];
      if ( v5 && *(_DWORD *)(v5 + 84) )
        UICleanupIterator(v4[4]);
    }
    for ( i = *(_DWORD *)(this + 5504); i; i = *(_DWORD *)(i + 2160) )
    {
      ConditionalFreeByFlag_28b0(i);
      v7 = *(_DWORD *)(i + 2152);
      if ( v7 && *(_DWORD *)(v7 + 84) )
        UICleanupIterator(*(_DWORD *)(i + 2152));
    }
    if ( a2 )
    {
      AudioNetworkStreamCleanup(a2);
      D3DResourceListCleanup(a2);
      v8 = ValueGetter(a2);
      D3DResourceRelease(v8);
      *(_DWORD *)(a2 + 236) |= 0x10000u;
    }
    *(_DWORD *)(this + 5032) &= ~0x10000000u;
  }
}

