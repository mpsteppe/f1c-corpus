double __thiscall sub_4DD090(_DWORD *this, int a2)
{
  if ( a2 - 1 < 0 || a2 - 1 > this[3] )
    return -1.0;
  else
    return *(float *)(this[40] + 4 * a2 - 4);
}
