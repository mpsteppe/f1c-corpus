int __cdecl sub_58ED70(int a1)
{
  int result; // eax
  int v2; // ecx
  int v3; // edx

  result = 0;
  v2 = 0;
  v3 = *(char *)(a1 + 4);
  if ( v3 > 0 )
  {
    while ( *(_BYTE *)(a1 + v2 + 8) != 0xFE )
    {
      if ( ++v2 >= v3 )
        return result;
    }
    return 1;
  }
  return result;
}
