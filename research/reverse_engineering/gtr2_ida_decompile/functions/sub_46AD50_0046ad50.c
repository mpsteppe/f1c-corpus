char __thiscall sub_46AD50(int this)
{
  char result; // al

  CNet::ClearServerList(*(CNet **)(this + 4));
  result = dword_B73240 - 1;
  if ( dword_B73240 != 1 )
    result = CNet::QueryLAN(
               *(CNet **)(this + 4),
               (unsigned __int16)dword_B73400,
               (unsigned __int16)(dword_B73400 + 99),
               *(_BYTE *)(this + 27));
  byte_B6CBA0 = 1;
  return result;
}
