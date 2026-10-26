void __thiscall CommandQueueResponseHandler(F1CVehicle *this)
{
  if ( dword_7C56A8 == 3 )
  {
    SessionCleanupFlagClear(this);
    *(_DWORD *)&this->gap_4540[4] = 0;
    WrapPlayerCallback(this);
  }
  if ( dword_7C56A4 != 7 && PairArrayLinearSearch(this, 0) )
  {
    *(_DWORD *)&this->gap_4540[4] = 0;
    ParameterValueSetter(this, 18);
    this->driverStatus = 5;
    AISpeedDeltaSetter(this, 1u);
  }
  if ( PairArrayLinearSearch(this, 5) )
  {
    ParameterValueSetter(this, 99999);
    *(_DWORD *)&this->gap_4540[4] = 1;
  }
  if ( PairArrayLinearSearch(this, 4) )
  {
    *(_DWORD *)&this->gap_4414[40] = 1;
    ParameterValueSetter(this, 18);
  }
  if ( PairArrayLinearSearch(this, 14) )
  {
    *(_DWORD *)&this->gap_4540[4] = 0;
    *(_DWORD *)&this->gap_4414[40] = 1;
  }
  if ( dword_7C56A8 == 4 )
  {
    AISpeedDeltaSetter(this, 0);
    ParameterValueSetter(this, 99999);
    *(_DWORD *)&this->gap_4540[4] = 1;
  }
}

