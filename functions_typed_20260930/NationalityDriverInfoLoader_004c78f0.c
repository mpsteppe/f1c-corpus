int __thiscall NationalityDriverInfoLoader(F1CVehicle *this, int a2)
{
  int v2; // esi
  _DWORD *v4; // eax
  _DWORD *v5; // eax
  char *v6; // eax
  int result; // eax
  const char *v8; // ecx

  v2 = dword_8AC394 + 1060 * a2;
  SetDriverName((char *)this, v2 + 188);
  sub_587DD0(&this->numberOfLaps, byte_5EA438, 0x17u);
  this->gap_4664[19] = 0;
  v4 = (_DWORD *)AudioChannelStop(dword_8AD3B4, this->DriverName);
  if ( v4 )
  {
    v5 = StringKeyedLinkedListSearch(v4, (int)aNationality);
    if ( v5 )
    {
      v6 = DataEntryAccessor(v5);
      sub_587DD0(&this->numberOfLaps, v6, 0x17u);
      this->gap_4664[19] = 0;
    }
  }
  sub_587DD0(this->CarName, (char *)(v2 + 252), 0x3Fu);
  this->CarName[63] = 0;
  sub_587DD0(&this->CarName[64], (char *)(v2 + 124), 0x3Fu);
  this->CarName[127] = 0;
  result = ShortStringSet(this, v2 + 116);
  v8 = *(const char **)v2;
  if ( !*(_DWORD *)v2 )
    v8 = byte_5EA438;
  strcpy(this->VehiclePath, v8);
  this->VehicleRosterIndex = a2;
  return result;
}

