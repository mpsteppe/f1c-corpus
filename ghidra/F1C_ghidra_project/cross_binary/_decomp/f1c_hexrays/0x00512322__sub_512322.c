// f1c  0x00512322  size=18
int __cdecl sub_512322(int a1)
{
  int result; // eax

  result = a1;
  if ( *(_BYTE *)(a1 + 279) == 16 )
    *(_DWORD *)(a1 + 96) |= 0x10u;
  return result;
}
