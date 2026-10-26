double __thiscall sub_52B860(_DWORD *this, int a2)
{
  if ( a2 < 0 || a2 >= this[3] || a2 >= this[51] )
    return -1.0;
  else
    return *(float *)(this[53] + 4 * a2);
}
