_DWORD *__thiscall sub_474440(_DWORD *this)
{
  sub_48C070(this, 1);
  *this = &off_5A3A80;
  this[199] = 395;
  LinkedListInsertWithNodeAllocation(this, (int)&off_5BE704, -1);
  LinkedListInsertWithNodeAllocation(this, (int)&off_5C32A4, -1);
  LinkedListInsertWithNodeAllocation(this, (int)aHigh, -1);
  sub_474510(this);
  return this;
}
