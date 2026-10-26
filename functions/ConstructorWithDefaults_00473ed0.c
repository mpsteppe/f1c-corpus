_DWORD *__thiscall ConstructorWithDefaults(_DWORD *this)
{
  ShortComputation_6d60(this, 1);
  *this = &off_5A3300;
  this[199] = &unk_7CFD10;
  this[201] = 1;
  this[202] = 0;
  this[203] = 1;
  this[204] = 1;
  this[205] = 385;
  LinkedListInsertWithNodeAllocation(this, (int)&off_5C32A4, -1);
  LinkedListInsertWithNodeAllocation(this, (int)aHigh, -1);
  SwitchOnActionIDVirtualCall(this);
  return this;
}
