_DWORD *__thiscall ObjectConstructorWithGlobalReferences(_DWORD *this)
{
  ShortComputation_6d60(this, 1);
  *this = &off_5A0840;
  this[199] = &unk_7CF014;
  this[201] = 1;
  this[202] = 0;
  this[203] = 1;
  this[204] = 1;
  this[205] = 408;
  LinkedListInsertWithNodeAllocation(this, (int)&off_5BE704, -1);
  LinkedListInsertWithNodeAllocation(this, (int)aOn, -1);
  return this;
}
