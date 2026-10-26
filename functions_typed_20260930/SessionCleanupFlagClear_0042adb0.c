char __thiscall SessionCleanupFlagClear(F1CVehicle *this)
{
  char result; // al

  result = this->RetiredFlag;
  if ( !result )
  {
    *(_DWORD *)&this->gap_4414[16] = 0;
    LOBYTE(this->AIControlFlag) = 1;
  }
  return result;
}

