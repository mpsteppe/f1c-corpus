int __stdcall sub_5F1500(unsigned int *a1)
{
  int result; // eax

  result = (int)a1;
  if ( a1 )
  {
    *a1 = *a1 & 0xFFFFE0FF | 0x200;
    return sub_5F5BC0(a1[1]);
  }
  return result;
}
