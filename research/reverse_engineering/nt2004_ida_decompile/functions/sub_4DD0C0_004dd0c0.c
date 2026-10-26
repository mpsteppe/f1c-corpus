double __thiscall sub_4DD0C0(_DWORD *this, int a2)
{
  if ( a2 < 0 || a2 >= this[3] )
    return -1.0;
  else
    return *(float *)(this[41] + 4 * a2);
}
