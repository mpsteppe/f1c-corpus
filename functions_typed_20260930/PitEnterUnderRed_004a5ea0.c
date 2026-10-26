char __thiscall PitEnterUnderRed(F1CPitMachine *this)
{
  char result; // al
  int *v3; // ecx
  void *vehicle; // [esp-4h] [ebp-8h]

  result = this->pit_entry_latch;
  if ( !result )
  {
    PitStateChangeRequest(this, 2);
    vehicle = this->vehicle;
    this->pit_entry_latch = 1;
    AISessionPhaseChange(dword_5EB978, (int)vehicle);
    sub_4BC240((_DWORD *)this->vehicle + 4109);
    result = dword_8ACFC8 - 2;
    if ( dword_8ACFC8 == 2 )
    {
      result = dword_7CEF84;
      if ( dword_7CEF84 )
      {
        v3 = (int *)((char *)this->vehicle + 16436);
        if ( dword_7C56A4 == 7 )
          DisqualificationHandler(v3, aEnteringPitsUn);
        else
          return sub_4BBA90((float *)v3, aEnteringPitsUn, 1000.0);
      }
    }
  }
  return result;
}

