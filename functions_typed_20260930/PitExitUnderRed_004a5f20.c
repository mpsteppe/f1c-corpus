char __thiscall PitExitUnderRed(F1CPitMachine *this)
{
  char result; // al
  char *v3; // eax
  int *v4; // ecx
  _DWORD *v5; // ecx

  result = this->pit_entry_latch;
  if ( result )
  {
    PitStateChangeRequest(this, 0);
    v3 = (char *)this->vehicle + 16436;
    this->pit_entry_latch = 0;
    ++*((_DWORD *)v3 + 14);
    AIFormationLap(this->vehicle);
    result = dword_8ACFD4 - 2;
    if ( dword_8ACFD4 == 2 )
    {
      result = dword_7CEF84;
      if ( dword_7CEF84 )
      {
        v4 = (int *)((char *)this->vehicle + 16436);
        if ( dword_7C56A4 == 7 )
          DisqualificationHandler(v4, aExitingPitsUnd);
        else
          result = sub_4BBA90((float *)v4, aExitingPitsUnd, 1000.0);
      }
    }
  }
  v5 = *(_DWORD **)&this->gap_008[12];
  if ( v5 )
    return ShortComputation_3fe0(v5);
  return result;
}

