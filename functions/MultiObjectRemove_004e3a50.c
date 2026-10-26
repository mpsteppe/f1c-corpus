int __thiscall sub_4E3A50(float *this, float a2)
{
  int result; // eax
  int v4; // esi
  float *v5; // edi

  result = *((_DWORD *)this + 746);
  v4 = 0;
  if ( result > 0 )
  {
    v5 = this + 747;
    do
    {
      sub_4DF110(v5, a2, -1);
      result = *((_DWORD *)this + 746);
      ++v4;
      v5 += 187;
    }
    while ( v4 < result );
  }
  return result;
}
