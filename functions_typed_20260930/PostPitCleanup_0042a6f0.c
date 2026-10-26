char __thiscall PostPitCleanup(F1CVehicle *this)
{
  char result; // al

  SentinelSlotFill(&this->gap_3D80[692]);
  result = this->gap_4578[12];
  if ( !result )
    ++*(_DWORD *)&this->gap_45D4[12];
  if ( dword_7C56A4 == 7 )
    this->timeOfNextExit = 0.0;
  *(float *)&this->gap_4454[40] = dbl_8AFEA0 + 4.0;
  return result;
}

