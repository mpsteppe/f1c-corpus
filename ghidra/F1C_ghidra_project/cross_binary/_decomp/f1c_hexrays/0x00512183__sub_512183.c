// f1c  0x00512183  size=43
int __cdecl sub_512183(int a1, int a2, _DWORD *a3)
{
  int result; // eax

  if ( !a1 )
    return 0;
  if ( !a2 )
    return 0;
  result = 2048;
  if ( (*(_DWORD *)(a2 + 8) & 0x800) == 0 || !a3 )
    return 0;
  *a3 = *(unsigned __int8 *)(a2 + 44);
  return result;
}
