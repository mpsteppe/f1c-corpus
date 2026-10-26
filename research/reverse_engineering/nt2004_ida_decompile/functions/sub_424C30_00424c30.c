double __thiscall sub_424C30(_DWORD *this, int a2)
{
  double result; // st7
  int v3; // eax

  result = -1.0;
  if ( !a2 )
    return 0.0;
  v3 = this[5858];
  if ( v3 )
    return *(float *)(a2 + 120) - *(float *)(v3 + 120);
  return result;
}
