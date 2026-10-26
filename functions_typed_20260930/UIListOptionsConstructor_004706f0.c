_DWORD *__thiscall UIListOptionsConstructor(_DWORD *this)
{
  sub_48C070(this, 1);
  *this = &off_5A0480;
  this[199] = 406;
  LinkedListInsertWithNodeAllocation(this, (int)&off_5BE704, -1);
  RaceModeScreenSetup(this);
  return this;
}

