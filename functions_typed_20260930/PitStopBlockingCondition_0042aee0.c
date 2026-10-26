int __thiscall PitStopBlockingCondition(F1CVehicle *this)
{
  if ( dword_7C56A4 != 7 )
    return *(_DWORD *)&this->gap_4594[16 * *(_DWORD *)&this->gap_45D4[12] + 8] & 8;
  return this->lapNumber >= dword_8ACF8C
      || dword_7C56A8 == 8
      || this->gap_39A8[82]
      || *(_DWORD *)(LODWORD(this->postProcessInput) + 3352) && !*(_BYTE *)(LODWORD(this->postProcessInput) + 3416);
}

