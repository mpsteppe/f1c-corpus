double __thiscall sub_45D2A0(_DWORD *this, int a2)
{
  float *v2; // esi

  v2 = (float *)(*this + 8);
  if ( a2 <= sub_45CE00(v2) )
    a2 = sub_45CE00(v2);
  return (double)a2 * 0.035;
}
