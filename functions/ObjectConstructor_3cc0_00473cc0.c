_DWORD *__thiscall ObjectConstructor_3cc0(_DWORD *this)
{
  ShortComputation_6d60(this, 1);
  *this = &off_5A3000;
  this[199] = &dword_7CF638;
  this[201] = 1;
  this[202] = 0;
  this[203] = 1;
  this[204] = 1;
  this[205] = 381;
  LinkedListInsertWithNodeAllocation(this, (int)&off_5BE704, -1);
  LinkedListInsertWithNodeAllocation(this, (int)aOn, -1);
  SwitchOnActionIDVirtualCall(this);
  return this;
}
