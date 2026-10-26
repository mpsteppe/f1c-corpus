int __thiscall sub_5D82B0(float *this)
{
  if ( *((_DWORD *)this + 1) != 1065353216
    || *((_DWORD *)this + 6) != 1065353216
    || *((_DWORD *)this + 11) != 1065353216
    || *((_DWORD *)this + 16) != 1065353216
    || this[2] != 0.0
    || this[3] != 0.0
    || this[4] != 0.0
    || this[5] != 0.0
    || this[7] != 0.0
    || this[8] != 0.0
    || this[9] != 0.0
    || this[10] != 0.0
    || this[12] != 0.0
    || this[13] != 0.0
    || this[14] != 0.0
    || this[15] != 0.0 )
  {
    return 0;
  }
  *(_DWORD *)this |= 1u;
  return 1;
}
