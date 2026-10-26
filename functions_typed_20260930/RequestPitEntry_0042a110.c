int __thiscall RequestPitEntry(F1CVehicle *this)
{
  int result; // eax

  if ( dword_7C56A4 == 7 )
  {
    result = dword_8ACF8C - 1;
    if ( this->lapNumber != dword_8ACF8C - 1 )
    {
      result = TeammatePitStatusLookup((F1CPitMachine *)this->gap_32CC);
      if ( !result || result == 4 || this->FinishState == 1 )
      {
        PitEnterCalledState((F1CPitMachine *)this->gap_32CC);
        return SetCallToBox(this, 1u);
      }
    }
  }
  else
  {
    PitEnterCalledState((F1CPitMachine *)this->gap_32CC);
    return SetCallToBox(this, 1u);
  }
  return result;
}

