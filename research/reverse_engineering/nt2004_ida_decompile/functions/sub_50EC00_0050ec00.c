int __thiscall sub_50EC00(float *this)
{
  int result; // eax
  int v3; // edi
  float *v4; // esi

  result = *((_DWORD *)this + 867);
  v3 = 0;
  if ( result > 0 )
  {
    v4 = this + 868;
    do
    {
      sub_508D20(v4, 0.0, -1);
      v4[6] = 0.0;
      result = *((_DWORD *)this + 867);
      ++v3;
      v4 += 187;
    }
    while ( v3 < result );
  }
  return result;
}
