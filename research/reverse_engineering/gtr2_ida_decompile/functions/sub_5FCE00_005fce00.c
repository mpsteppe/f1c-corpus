void __thiscall sub_5FCE00(_DWORD *this, int a2, int a3, float a4, float a5, float a6, int a7)
{
  _DWORD *v7; // eax
  int v8; // edx

  if ( (*this & 0x200) != 0 && a2 < this[11] )
  {
    v7 = (_DWORD *)(this[13] + 132 * a2);
    if ( (*v7 & 0x100) != 0 )
    {
      if ( (*this & 0x400) != 0 )
      {
        v8 = a3 << 6;
        *(float *)(v8 + v7[32]) = a4;
        *(float *)(v7[32] + v8 + 4) = a5;
        *(float *)(v7[32] + v8 + 8) = a6;
        *(_DWORD *)(v7[32] + v8 + 24) = a7;
      }
      *this |= 0x80000u;
    }
  }
}
