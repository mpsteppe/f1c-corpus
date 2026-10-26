_DWORD *__thiscall sub_40D980(_DWORD *this)
{
  ConstraintSolverParamInit(this + 5);
  StructZeroInit_7a00(this + 19);
  this[1] = &dword_5EA510;
  this[2] = &flt_5EA618;
  this[3] = &dword_5EB978;
  this[4] = &unk_5EC6D0;
  *this = 0;
  F_9PointerArrayCleanup(this + 19);
  this[33] = 0;
  this[34] = 0;
  this[38] = 0;
  this[39] = 0;
  this[35] = 0;
  this[36] = 0;
  *((_BYTE *)this + 160) = 124;
  this[37] = -1;
  return this;
}
