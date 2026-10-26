int __cdecl sub_552842(_DWORD *a1, float *a2)
{
  int result; // eax
  float v3[64]; // [esp+0h] [ebp-100h] BYREF

  result = sub_550DC0(a2, v3);
  if ( result >= 0 )
  {
    result = sub_552296(a1, v3);
    if ( result >= 0 )
      return 0;
  }
  return result;
}
