_DWORD *__thiscall ShortComputation_1970(_DWORD *this)
{
  ShortComputation_6d60(this, 1);
  *this = &off_5A1440;
  this[199] = &dword_7CE7F0;
  this[201] = 2;
  this[202] = 0;
  this[203] = 1;
  this[204] = 1;
  this[205] = 244;
  LinkedListInsertWithNodeAllocation(this, (int)&off_5BE704, -1);
  LinkedListInsertWithNodeAllocation(this, (int)&off_5C32A4, -1);
  LinkedListInsertWithNodeAllocation(this, (int)aHigh, -1);
  SwitchOnActionIDVirtualCall(this);
  return this;
}

