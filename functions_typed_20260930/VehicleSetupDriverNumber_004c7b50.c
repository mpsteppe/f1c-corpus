int __thiscall VehicleSetupDriverNumber(F1CVehicle *this)
{
  int v2; // eax
  int v3; // eax
  char *v4; // ecx
  int result; // eax

  v2 = NamedEntryLookupInFormatList((char ****)&dword_5EA5E8, this->DriverName, (int)this->VehiclePath);
  this->DriverID = v2;
  if ( v2 < 0 )
  {
    v3 = dword_8AC394 + 1060 * this->VehicleRosterIndex;
    if ( v3 )
    {
      v4 = *(char **)v3;
      if ( !*(_DWORD *)v3 )
        v4 = byte_5EA438;
      this->DriverID = NamedEntryLookupInFormatList((char ****)&dword_5EA5E8, (const char *)(v3 + 188), (int)v4);
    }
  }
  result = LinkedListIndexScannerWithValidation(&dword_5EA5E8, (int)&this->CarName[64]);
  *(_DWORD *)this->gap_48A0 = result;
  return result;
}

