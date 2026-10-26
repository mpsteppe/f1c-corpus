double __thiscall sub_426CC0(_DWORD *this, int a2)
{
  double result; // st7
  int v3; // eax

  result = -1.0;
  if ( !a2 )
    return 0.0;
  v3 = this[4309];
  if ( v3 )
    return *(float *)(a2 + 76) - *(float *)(v3 + 76);
  return result;
}
