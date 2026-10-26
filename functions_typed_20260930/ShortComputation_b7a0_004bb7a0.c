_DWORD *__thiscall ShortComputation_b7a0(_DWORD *this)
{
  _DWORD *v2; // eax
  int v3; // edx

  v2 = this + 16;
  v3 = 4;
  do
  {
    *v2 = 0;
    v2[1] = 0;
    v2 += 2;
    --v3;
  }
  while ( v3 );
  *this = 0;
  this[35] = 0;
  this[36] = 0;
  this[37] = 0;
  this[12] = 0;
  this[41] = 0;
  this[1] = -1;
  this[9] = -1;
  this[10] = -1082130432;
  this[11] = -1;
  StructResetReinitializer((int)this);
  return this;
}

