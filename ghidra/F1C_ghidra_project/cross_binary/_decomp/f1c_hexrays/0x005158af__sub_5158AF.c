// f1c  0x005158af  size=52
int __cdecl sub_5158AF(_DWORD *a1, float *a2)
{
  int result; // eax
  float v3[64]; // [esp+0h] [ebp-100h] BYREF

  result = sub_513E2D(a2, v3);
  if ( result >= 0 )
  {
    result = sub_515303(a1, v3);
    if ( result >= 0 )
      return 0;
  }
  return result;
}
