_DWORD *__thiscall ComplexConstructor(_DWORD *this)
{
  ShortComputation_6d60(this, 1);
  *this = &off_5A1200;
  this[199] = &dword_7CE784;
  this[201] = 1;
  this[202] = 0;
  this[203] = 1;
  this[204] = 1;
  this[205] = 241;
  LinkedListInsertWithNodeAllocation(this, (int)&off_5BE704, -1);
  LinkedListInsertWithNodeAllocation(this, (int)aOn, -1);
  SwitchOnActionIDVirtualCall(this);
  return this;
}
