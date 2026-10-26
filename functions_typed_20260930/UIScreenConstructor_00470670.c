_DWORD *__thiscall UIScreenConstructor(_DWORD *this)
{
  ShortComputation_6d60(this, 1);
  *this = &off_5A03C0;
  this[199] = &unk_7D1250;
  this[201] = 1;
  this[202] = 0;
  this[203] = 1;
  this[204] = 1;
  this[205] = 405;
  LinkedListInsertWithNodeAllocation(this, (int)&off_5BE704, -1);
  LinkedListInsertWithNodeAllocation(this, (int)aOn, -1);
  SwitchOnActionIDVirtualCall(this);
  return this;
}

