int *__thiscall sub_452780(int *this)
{
  int *v2; // ecx

  v2 = this + 1;
  *v2 = 89;
  v2[1] = 0;
  v2[2] = 0;
  v2[3] = 0;
  v2[4] = 0;
  v2[5] = 0;
  *this = 0;
  SwapAndReinit(v2, 89, 0);
  this[7] = 0;
  this[8] = 0;
  this[9] = 0;
  this[10] = 0;
  return this;
}
