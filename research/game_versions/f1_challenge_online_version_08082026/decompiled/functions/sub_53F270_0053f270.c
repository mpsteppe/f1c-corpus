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
      sub_540EB0(v3);
      if ( *(_DWORD *)(this + 4416) )
        sub_587BCF(*(LPVOID *)(this + 4416));
      *(_DWORD *)(this + 4416) = 0;
    }
    if ( *(_DWORD *)(this + 4412) )
    {
      sub_540EB0(*(_DWORD *)(this + 4412));
      if ( *(_DWORD *)(this + 4412) )
        sub_587BCF(*(LPVOID *)(this + 4412));
      *(_DWORD *)(this + 4412) = 0;
    }
    if ( *(_DWORD *)(this + 4420) )
    {
      sub_541040(*(_DWORD *)(this + 4420));
      if ( *(_DWORD *)(this + 4420) )
        sub_587BCF(*(LPVOID *)(this + 4420));
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
        sub_540EB0(v4[5]);
        v4[5] = 0;
      }
      v5 = v4[4];
      if ( v5 && *(_DWORD *)(v5 + 84) )
        sub_554D70(v4[4]);
    }
    for ( i = *(_DWORD *)(this + 5504); i; i = *(_DWORD *)(i + 2160) )
    {
      sub_5528B0(i);
      v7 = *(_DWORD *)(i + 2152);
      if ( v7 && *(_DWORD *)(v7 + 84) )
        sub_554D70(*(_DWORD *)(i + 2152));
    }
    if ( a2 )
    {
      sub_544AF0(a2);
      sub_554E10(a2);
      v8 = sub_545F40(a2);
      sub_554CC0(v8);
      *(_DWORD *)(a2 + 236) |= 0x10000u;
    }
    *(_DWORD *)(this + 5032) &= ~0x10000000u;
  }
}
