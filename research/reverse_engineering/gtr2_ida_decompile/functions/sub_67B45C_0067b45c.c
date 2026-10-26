int __stdcall sub_67B45C(int a1)
{
  int result; // eax

  result = a1;
  if ( *(_BYTE *)(a1 + 279) < 8u )
  {
    *(_DWORD *)(a1 + 96) |= 4u;
    *(_BYTE *)(a1 + 280) = 8;
  }
  return result;
}
