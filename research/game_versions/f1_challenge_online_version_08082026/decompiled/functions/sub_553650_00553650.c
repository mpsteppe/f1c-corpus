int __thiscall sub_553650(_DWORD *this, int a2, float a3, float a4, float a5, float a6, float a7, int a8)
{
  int v9; // eax

  if ( a2 <= 15 )
  {
    if ( (*(_BYTE *)this & 2) != 0 )
    {
      if ( a2 > this[1] - 1 )
        this[1] = a2 + 1;
      v9 = 28 * a2;
      *(float *)(v9 + this[6]) = flt_8B8CF0 * (double)dword_8B8DD4 + flt_8B8CF4 * a3;
      *(float *)(v9 + this[6] + 4) = a4;
      *(float *)(v9 + this[6] + 8) = a5;
      *(_DWORD *)(v9 + this[6] + 12) = 1065353216;
      *(float *)(v9 + this[6] + 20) = a6;
      *(float *)(v9 + this[6] + 24) = a7;
      *(_DWORD *)(v9 + this[6] + 16) = a8;
      *this |= 0x8000u;
      return 0;
    }
    else
    {
      sub_53C590(-1, aWrongVertexFor);
      return -1;
    }
  }
  else
  {
    sub_53C590(-1, aTooManyVertice);
    return -1;
  }
}
