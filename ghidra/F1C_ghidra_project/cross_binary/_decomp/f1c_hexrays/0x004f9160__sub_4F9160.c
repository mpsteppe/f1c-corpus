// f1c  0x004f9160  size=45
int __stdcall sub_4F9160(int a1)
{
  int result; // eax

  result = sub_55BFC0(dword_8AFE64);
  if ( a1 < result )
  {
    dword_8AFE6C = a1;
    result = sub_55BFD0(a1);
    dword_8AFE68 = result;
  }
  return result;
}
