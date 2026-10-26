int __stdcall sub_4F9160(int a1)
{
  int result; // eax

  result = SimpleFieldGetter_bfc0(dword_8AFE64);
  if ( a1 < result )
  {
    dword_8AFE6C = a1;
    result = BoundedArrayAccessor_bfd0(a1);
    dword_8AFE68 = result;
  }
  return result;
}
