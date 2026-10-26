double __thiscall sub_45BE00(float **this, int a2)
{
  float *v2; // esi

  v2 = *this;
  if ( a2 <= FloatArrayThresholdSearch(*this) )
    a2 = FloatArrayThresholdSearch(v2);
  return (double)a2 * 0.035;
}
