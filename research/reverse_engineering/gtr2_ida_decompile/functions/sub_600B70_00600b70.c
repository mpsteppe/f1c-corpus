int __thiscall sub_600B70(float *this, int a2, int a3, int a4, int a5)
{
  float v5; // eax
  int result; // eax

  if ( a2 == 1 )
  {
    v5 = *this;
    this[6] = (double)a3 * 0.0039215689;
    this[7] = (double)a4 * 0.0039215689;
    this[8] = (double)a5 * 0.0039215689;
  }
  else
  {
    if ( a2 == 2 )
    {
      result = *(_DWORD *)this | 0x400;
      *(_DWORD *)this = result;
      this[10] = (double)a3 * 0.0039215689;
      this[11] = (double)a4 * 0.0039215689;
      this[12] = (double)a5 * 0.0039215689;
      return result;
    }
    v5 = *this;
    if ( a2 == 3 )
    {
      result = LODWORD(v5) | 0x400;
      *(_DWORD *)this = result;
      this[14] = (double)a3 * 0.0039215689;
      this[15] = (double)a4 * 0.0039215689;
      this[16] = (double)a5 * 0.0039215689;
      return result;
    }
  }
  result = LODWORD(v5) | 0x400;
  *(_DWORD *)this = result;
  return result;
}
