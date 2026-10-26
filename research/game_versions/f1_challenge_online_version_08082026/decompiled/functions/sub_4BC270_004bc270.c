double __thiscall sub_4BC270(_DWORD *this, int a2)
{
  int v2; // edx
  int v3; // eax

  v2 = this[35];
  v3 = a2 - 1;
  if ( v2 && v3 >= 0 && v3 <= this[2] && v3 < this[34] )
    return *(float *)(v2 + 4 * v3);
  else
    return -1.0;
}
