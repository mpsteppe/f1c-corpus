unsigned int __thiscall sub_5EC2A0(unsigned int *this, int a2)
{
  unsigned int result; // eax
  float *v3; // esi
  int v4; // edi

  result = *this;
  if ( (BYTE1(*this) & 0x80u) == 0 )
  {
    if ( a2 )
    {
      *this = result | 0x8000;
      v3 = (float *)(this + 6);
      v4 = 8;
      do
      {
        result = (unsigned int)sub_5D7810(v3, v3 + 24, (float *)(a2 + 4));
        v3 += 3;
        --v4;
      }
      while ( v4 );
    }
    else
    {
      return off_16C97E0(0);
    }
  }
  return result;
}
