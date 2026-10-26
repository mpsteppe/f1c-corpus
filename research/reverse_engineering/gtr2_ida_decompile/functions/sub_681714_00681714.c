int __stdcall sub_681714(int a1)
{
  int result; // eax

  result = a1;
  if ( a1 )
  {
    *(_DWORD *)(a1 + 120) = dword_FB9E50;
    dword_FB9E50 = a1;
  }
  return result;
}
