int __stdcall sub_526AA0(int a1)
{
  int result; // eax

  result = sub_5A97F0(dword_7DA988);
  if ( a1 < result )
  {
    dword_7DA990 = a1;
    result = sub_5A9800(a1);
    dword_7DA98C = result;
  }
  return result;
}
