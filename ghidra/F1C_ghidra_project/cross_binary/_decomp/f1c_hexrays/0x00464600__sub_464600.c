// f1c  0x00464600  size=102
char __thiscall sub_464600(int *this)
{
  char result; // al
  int v3; // esi

  result = byte_7CE260;
  if ( !byte_7CE260 )
  {
    sub_4B16B0(&unk_7CE498);
    if ( *(_DWORD *)(*this + 16324) )
    {
      sub_463140(this);
      sub_45D500((_BYTE *)(*this + 112528));
    }
    sub_57A910(*(_DWORD *)(*this + 16312));
    v3 = *this;
    result = *(_BYTE *)(v3 + 197);
    if ( result || (result = *(_BYTE *)(v3 + 198)) != 0 )
      byte_7CE25F = 1;
  }
  return result;
}
