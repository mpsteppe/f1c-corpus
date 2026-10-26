int __stdcall sub_5ABD97(int a1, _DWORD *a2, float *a3)
{
  int result; // eax
  long double v4; // st7

  result = a1;
  if ( a2 )
  {
    *a2 = *(_DWORD *)a1;
    a2[1] = *(_DWORD *)(a1 + 4);
    a2[2] = *(_DWORD *)(a1 + 8);
  }
  if ( a3 )
  {
    v4 = acos(*(float *)(a1 + 12));
    *a3 = v4 + v4;
  }
  return result;
}
