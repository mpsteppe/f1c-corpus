char __thiscall sub_438CC0(int this)
{
  int i; // edi
  char result; // al

  *(_BYTE *)(this + 114) = dword_7CE6F4;
  *(_BYTE *)(this + 115) = dword_7CE73C;
  *(_BYTE *)(this + 116) = dword_7CE7F0;
  *(_BYTE *)(this + 117) = dword_7CE8A4;
  *(_BYTE *)(this + 118) = dword_7CE850;
  *(_BYTE *)(this + 119) = dword_7CE784;
  *(_BYTE *)(this + 120) = dword_7CE7CC;
  *(_BYTE *)(this + 121) = dword_7CE6AC;
  *(_BYTE *)(this + 122) = dword_7CE718;
  *(_BYTE *)(this + 123) = dword_7CE760;
  *(_BYTE *)(this + 124) = dword_7CE7A8;
  if ( byte_7CE874 )
    *(_DWORD *)(this + 128) = 2 * (byte_7CE88C != 0) + 1;
  else
    *(_DWORD *)(this + 128) = byte_7CE88C != 0 ? 2 : 0;
  for ( i = 0; i < 11; ++i )
  {
    if ( !(unsigned __int8)BitmaskStateTest(i) )
      *(_BYTE *)(this + i + 114) = 0;
  }
  if ( *(_BYTE *)(this + 116) || *(_BYTE *)(this + 122) )
    *(_BYTE *)(this + 115) = 2;
  result = *(_BYTE *)(this + 117);
  if ( result )
    *(_BYTE *)(this + 118) = 1;
  *(double *)(this + 156) = flt_7CE934 * 0.95;
  return result;
}
