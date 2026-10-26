int __stdcall sub_67A055(int a1, int a2, int a3)
{
  int result; // eax

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
    result = sub_6B731E(*(_DWORD *)(a1 + 256), a2, a3);
    *(_DWORD *)(a1 + 256) = result;
  }
  return result;
}
