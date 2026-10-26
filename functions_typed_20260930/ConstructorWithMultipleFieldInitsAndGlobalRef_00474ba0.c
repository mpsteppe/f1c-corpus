_DWORD *__thiscall ConstructorWithMultipleFieldInitsAndGlobalRef(_DWORD *this)
{
  ShortComputation_6d60(this, 1);
  *this = &off_5A3FC0;
  this[199] = &dword_7D0038;
  this[202] = 0;
  this[201] = 1;
  this[203] = 1;
  this[204] = 1;
  LinkedListInsertWithNodeAllocation(this, (int)&off_5BE704, -1);
  LinkedListInsertWithNodeAllocation(this, (int)aOn, -1);
  this[205] = 438;
  return this;
}

