_DWORD *__thiscall Constructor(_DWORD *this)
{
  sub_48C070(this, 1);
  *this = &off_5A2DC0;
  this[200] = &byte_7D0474;
  this[199] = 278;
  LinkedListInsertWithNodeAllocation(this, (int)&off_5C7084, -1);
  LinkedListInsertWithNodeAllocation(this, (int)&off_5C7080, -1);
  return this;
}

