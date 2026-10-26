int __thiscall VehicleDriverInfoClear(F1CVehicle *this)
{
  int result; // eax

  result = 0;
  this->DriverName[0] = 0;
  LOBYTE(this->numberOfLaps) = 0;
  this->CarName[0] = 0;
  this->CarName[64] = 0;
  this->CarName[128] = 0;
  this->CarName[144] = 0;
  *(_DWORD *)&this->CarName[152] = -1;
  this->VehiclePath[0] = 0;
  this->SaveFilePath[0] = 0;
  this->VehicleRosterIndex = -1;
  this->DriverID = -1;
  *(_DWORD *)this->gap_48A0 = -1;
  this->PitTeamIndex = -1;
  *(_DWORD *)this->gap_48A8 = -1;
  *(_DWORD *)&this->gap_48A8[4] = 0;
  *(_WORD *)&this->gap_48A8[8] = 0;
  *(_DWORD *)&this->gap_48A8[12] = -8388609;
  *(_DWORD *)&this->gap_48A8[16] = 0;
  *(_DWORD *)&this->gap_48A8[20] = 11;
  return result;
}

