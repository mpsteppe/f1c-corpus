_DWORD *__thiscall ObjectInitWithVTablePathRegistration(_DWORD *this)
{
  sub_48C070(this, 1);
  *this = &off_5A0780;
  this[199] = 407;
  LinkedListInsertWithNodeAllocation(this, (int)&off_5BE704, -1);
  LinkedListInsertWithNodeAllocation(this, (int)aOn, -1);
  return this;
}

