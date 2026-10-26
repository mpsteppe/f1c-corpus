int __cdecl sub_517F58(int a1, int a2, int a3)
{
  int result; // eax

  sub_513BD1(a1, a2, a3);
  result = a1;
  if ( (*(_BYTE *)(a1 + 268) & 0x20) == 0 )
  {
    if ( (*(_BYTE *)(a1 + 93) & 8) != 0 )
      return result;
    goto LABEL_5;
  }
  if ( (*(_DWORD *)(a1 + 92) & 0x300) != 0x300 )
  {
LABEL_5:
    result = sub_51923D(*(_DWORD *)(a1 + 256), a2, a3);
    *(_DWORD *)(a1 + 256) = result;
  }
  return result;
}
