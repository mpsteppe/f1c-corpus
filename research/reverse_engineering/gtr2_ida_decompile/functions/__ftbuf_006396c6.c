int __cdecl _ftbuf(int a1, int a2)
{
  int result; // eax

  if ( a1 )
  {
    if ( (*(_BYTE *)(a2 + 13) & 0x10) != 0 )
    {
      result = _flush((_DWORD *)a2);
      *(_BYTE *)(a2 + 13) &= 0xEEu;
      *(_DWORD *)(a2 + 24) = 0;
      *(_DWORD *)a2 = 0;
      *(_DWORD *)(a2 + 8) = 0;
    }
  }
  return result;
}
