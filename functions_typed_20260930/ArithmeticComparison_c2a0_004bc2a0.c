double __thiscall sub_4BC2A0(_DWORD *this, int a2)
{
  if ( a2 < 0 || a2 >= this[2] || a2 >= this[34] )
    return -1.0;
  else
    return *(float *)(this[36] + 4 * a2);
}

