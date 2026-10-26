double __thiscall sub_45A5D0(_DWORD *this, int a2)
{
  _DWORD *v3; // ecx

  v3 = (_DWORD *)*this;
  if ( a2 < 0 || a2 >= v3[1] )
    return 0.0;
  else
    return *(float *)(28 * a2 + *v3 + 24);
}
