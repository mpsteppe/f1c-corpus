int __stdcall sub_6811B3(int a1)
{
  int result; // eax

  result = a1;
  if ( a1 )
  {
    *(_DWORD *)(a1 + 112) = dword_FB9E48;
    dword_FB9E48 = a1;
  }
  return result;
}
