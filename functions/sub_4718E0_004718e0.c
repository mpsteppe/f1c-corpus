_DWORD *__thiscall sub_4718E0(_DWORD *this)
{
  ShortComputation_6d60(this, 1);
  *this = &off_5A1380;
  this[199] = &dword_7CE760;
  this[201] = 2;
  this[202] = 0;
  this[203] = 1;
  this[204] = 1;
  this[205] = 243;
  LinkedListInsertWithNodeAllocation(this, (int)&off_5BE704, -1);
  LinkedListInsertWithNodeAllocation(this, (int)&off_5C32A4, -1);
  LinkedListInsertWithNodeAllocation(this, (int)aHigh, -1);
  SwitchOnActionIDVirtualCall(this);
  return this;
}
