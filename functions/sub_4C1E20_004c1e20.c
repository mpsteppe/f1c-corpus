LPVOID *__thiscall sub_4C1E20(LPVOID *this, char a2)
{
  PitStopMemoryCleanup(this);
  if ( (a2 & 1) != 0 )
    FreeWrapper_7bcf(this);
  return this;
}
