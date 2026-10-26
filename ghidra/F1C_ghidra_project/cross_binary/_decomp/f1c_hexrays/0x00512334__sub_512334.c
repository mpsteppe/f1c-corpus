// f1c  0x00512334  size=25
int __cdecl sub_512334(int a1)
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
