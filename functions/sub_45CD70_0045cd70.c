bool __thiscall sub_45CD70(_DWORD *this)
{
  bool result; // al
  int v3; // eax

  if ( *(_BYTE *)this )
    return 1;
  v3 = 0;
  dword_8D4680 = 0;
  dword_8D4684 = 0;
  dword_8D4688 = 0;
  dword_8D468C = 0;
  do
  {
    *((_BYTE *)&dword_8D4680 + v3) = byte_59F0C4[v3] ^ 0x3E;
    ++v3;
  }
  while ( v3 < 6 );
  result = sub_561BF0(
             this[1],
             off_5C5B68,
             (int)&dword_8D4680,
             (int)DebugFloatFormatString,
             (int)SceneTextureApply,
             (int)BooleanParameterFormatDispatch,
             (int)NetworkScorePingDisplay,
             0) == 0;
  *(_BYTE *)this = result;
  return result;
}
