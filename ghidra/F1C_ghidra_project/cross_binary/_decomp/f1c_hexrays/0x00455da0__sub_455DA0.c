// f1c  0x00455da0  size=165
_DWORD *__thiscall sub_455DA0(int this)
{
  unsigned int v2; // ecx
  _DWORD *result; // eax

  if ( dword_7C569C != 5 && (unsigned __int8)sub_4D7A50(2, aDDevF119992002_13, 5269) )
    sub_4D7AA0(&unk_8AD25C, aEnteredHwinput_2);
  sub_44F680((float *)(this + 3260), 0, 0, dword_5D6D60, dword_5D6D64);
  sub_44F0A0((_DWORD *)(this + 4));
  if ( dword_7D1FFC )
    sub_44FF50((int *)(this + 5504));
  *(_BYTE *)(this + 9256) = 0;
  v2 = 26;
  result = (_DWORD *)(this + 8088);
  while ( !*result && result[1] == 89 )
  {
    ++v2;
    result += 11;
    if ( v2 > 0x21 )
      return result;
  }
  *(_BYTE *)(this + 9256) = 1;
  return result;
}
