int *__thiscall sub_53AB20(int *this, int a2, int a3)
{
  *this = a2;
  this[1] = CRTFtol(__FYL2X__((double)a2, 0.6931471805599453094) * 1.442695036924675);
  this[3] = OperatorNewNhMallocWrapper(8 * a2 + 16);
  this[5] = 0;
  this[4] = 0;
  CurveSplinePointGenerator(a3);
  return this;
}

