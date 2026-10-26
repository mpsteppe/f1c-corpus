int __fastcall sub_5BB890(int a1, int a2)
{
  int v3; // eax
  _DWORD *i; // edx
  int v5; // edx
  int result; // eax

  v3 = 0;
  for ( i = (_DWORD *)(a1 + 216); *i != a2; ++i )
  {
    if ( ++v3 >= 10 )
    {
      v5 = (*(_DWORD *)(a1 + 256) + 1) % 10;
      result = 0;
      *(_DWORD *)(a1 + 256) = v5;
      *(_DWORD *)(a1 + 4 * v5 + 216) = a2;
      return result;
    }
  }
  return 1;
}
