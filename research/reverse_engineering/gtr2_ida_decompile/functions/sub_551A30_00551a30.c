char __thiscall sub_551A30(float *this)
{
  int v1; // esi

  if ( this[55] + 30.0 > dbl_FB1D18 )
    return 0;
  v1 = 0;
  if ( dword_757C10 <= 0 )
    return 1;
  while ( sub_52C430((int *)(*(&dword_91E088 + v1) + 19272), 0, 0) )
  {
    if ( ++v1 >= dword_757C10 )
      return 1;
  }
  return 0;
}
