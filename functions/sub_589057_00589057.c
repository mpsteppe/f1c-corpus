int __cdecl sub_589057(int a1, int a2)
{
  int result; // eax

  sub_58FCA0(a1);
  if ( *(_BYTE *)(a2 + 64) )
    BatchFunctionCallOverVarargs(a1, 2);
  result = a2 + 128;
  if ( *(_BYTE *)(a2 + 128) )
    return BatchFunctionCallOverVarargs(a1, 2);
  return result;
}
