int __thiscall RacePhasePitEntryTrigger(F1CVehicle *this)
{
  int result; // eax

  result = FuelMultiplierValue(&this->postProcessInput);
  if ( result < 1 )
  {
    result = this->WaypointSetSelector;
    if ( !result && dword_7C56A8 == 5 )
      return RequestPitEntry(this);
  }
  return result;
}

