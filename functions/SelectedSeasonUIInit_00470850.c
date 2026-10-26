_DWORD *__thiscall SelectedSeasonUIInit(_DWORD *this)
{
  sub_48C070(this, 1);
  *this = &off_5A0540;
  this[199] = 401;
  LinkedListInsertWithNodeAllocation(this, (int)&off_5BE704, -1);
  LinkedListInsertWithNodeAllocation(this, (int)aNormal_0, -1);
  LinkedListInsertWithNodeAllocation(this, (int)aTimeScaled, -1);
  LinkedListInsertWithNodeAllocation(this, (int)aSelectedSeason, -1);
  SessionSetupScreenSetup(this);
  return this;
}
