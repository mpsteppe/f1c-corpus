int __thiscall sub_4E3890(float *this)
{
  int result; // eax
  int v3; // edi
  float *v4; // esi

  result = *((_DWORD *)this + 746);
  v3 = 0;
  if ( result > 0 )
  {
    v4 = this + 747;
    do
    {
      sub_4DF110(v4, 0.0, -1);
      v4[6] = 0.0;
      result = *((_DWORD *)this + 746);
      ++v3;
      v4 += 187;
    }
    while ( v3 < result );
  }
  return result;
}

