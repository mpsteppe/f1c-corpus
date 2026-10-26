// f1c  0x00414140  size=18
int __stdcall sub_414140(int a1)
{
  int result; // eax

  result = *(_DWORD *)(a1 + 8);
  if ( result > 0 )
    *(_DWORD *)(a1 + 8) = --result;
  return result;
}
