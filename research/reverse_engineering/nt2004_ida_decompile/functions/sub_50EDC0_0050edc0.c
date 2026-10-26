int __thiscall sub_50EDC0(float *this, float a2)
{
  int result; // eax
  int v4; // esi
  float *v5; // edi

  result = *((_DWORD *)this + 867);
  v4 = 0;
  if ( result > 0 )
  {
    v5 = this + 868;
    do
    {
      sub_508D20(v5, a2, -1);
      result = *((_DWORD *)this + 867);
      ++v4;
      v5 += 187;
    }
    while ( v4 < result );
  }
  return result;
}
