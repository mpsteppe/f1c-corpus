int __stdcall sub_67B443(int a1)
{
  int result; // eax

  result = a1;
  if ( *(_BYTE *)(a1 + 279) == 16 )
    *(_DWORD *)(a1 + 96) |= 0x10u;
  return result;
}
