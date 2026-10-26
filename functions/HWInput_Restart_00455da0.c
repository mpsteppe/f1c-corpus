_DWORD *__thiscall sub_455DA0(int this)
{
  unsigned int v2; // ecx
  _DWORD *result; // eax

  if ( dword_7C569C != 5 && (unsigned __int8)StringSplitLoop(2, aDDevF119992002_13, 5269) )
    DebugLogWrite(&dword_8AD25C, aEnteredHwinput_2);
  FrustumViewportSetup((float *)(this + 3260), 0, 0, dword_5D6D60, dword_5D6D64);
  BVHTreeNodeArrayInit((_DWORD *)(this + 4));
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
