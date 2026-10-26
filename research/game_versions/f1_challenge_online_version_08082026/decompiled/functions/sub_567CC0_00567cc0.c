int __stdcall sub_567CC0(_DWORD *a1)
{
  int result; // eax

  if ( a1 )
  {
    sub_567CC0(a1[1]);
    sub_567CC0(a1[2]);
    sub_567CC0(a1[3]);
    sub_567940((int)a1);
    return sub_587BCF(a1);
  }
  return result;
}
