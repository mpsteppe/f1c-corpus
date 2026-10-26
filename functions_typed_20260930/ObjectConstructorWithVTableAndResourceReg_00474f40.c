_DWORD *__thiscall ObjectConstructorWithVTableAndResourceReg(_DWORD *this)
{
  sub_48C070(this, 1);
  *this = &off_5A4200;
  LinkedListInsertWithNodeAllocation(this, (int)&unk_5C6E18, -1);
  LinkedListInsertWithNodeAllocation(this, (int)&off_5C6E14, -1);
  return this;
}

