int __cdecl sub_518828(int a1, unsigned int a2)
{
  unsigned int i; // edi

  for ( i = *(_DWORD *)(a1 + 160); a2 > i; a2 -= i )
    sub_517F58(a1, *(_DWORD *)(a1 + 156), *(_DWORD *)(a1 + 160));
  if ( a2 )
    sub_517F58(a1, *(_DWORD *)(a1 + 156), a2);
  if ( !AnimationStateCheck(a1) )
    return 0;
  if ( ((*(_BYTE *)(a1 + 268) & 0x20) == 0 || (*(_BYTE *)(a1 + 93) & 2) != 0)
    && ((*(_BYTE *)(a1 + 268) & 0x20) != 0 || (*(_BYTE *)(a1 + 93) & 4) == 0) )
  {
    DoubleBufferInit(a1, "CRC error");
  }
  else
  {
    TwoStepDelegation(a1, "CRC error");
  }
  return 1;
}
