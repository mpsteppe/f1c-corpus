int __stdcall sub_67EA92(_DWORD *a1, float *a2, int a3)
{
  int result; // eax
  float v4[64]; // [esp+0h] [ebp-100h] BYREF

  result = sub_67CCED(a2, v4);
  if ( result >= 0 )
  {
    result = sub_67E443(a1, v4, a3);
    if ( result >= 0 )
      return 0;
  }
  return result;
}
