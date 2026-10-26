// f1c  0x004d8fb0  size=113
int sub_4D8FB0()
{
  int result; // eax

  if ( dword_8AD388 )
  {
    sub_53D130(dword_8AD388);
    dword_8AD388 = 0;
  }
  if ( dword_8AD38C )
  {
    sub_53D130(dword_8AD38C);
    dword_8AD38C = 0;
  }
  if ( dword_8AD390 )
  {
    sub_53D130(dword_8AD390);
    dword_8AD390 = 0;
  }
  result = dword_8AD394;
  if ( dword_8AD394 )
  {
    result = sub_53D130(dword_8AD394);
    dword_8AD394 = 0;
  }
  return result;
}
