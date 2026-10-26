int __thiscall sub_55D460(int this, float a2, float a3, float a4)
{
  long double v4; // st7
  long double v5; // st7
  int result; // eax

  *(float *)(this + 68) = a2;
  *(float *)(this + 76) = a4;
  *(float *)(this + 72) = a3;
  v4 = sqrt(a2 * a2 + a3 * a3 + a4 * a4);
  if ( v4 != 0.0 )
  {
    v5 = 1.0 / v4;
    *(float *)(this + 68) = a2 * v5;
    *(float *)(this + 72) = a3 * v5;
    *(float *)(this + 76) = v5 * a4;
  }
  DirectXVertexBufferTextureCoordinateSetup(dword_8B78A0, this, *(_DWORD *)(this + 4), 5);
  result = dword_8B8F28;
  *(_DWORD *)(dword_8B8F28 + 236) |= 0x800u;
  return result;
}
