int __thiscall sub_460470(_DWORD *this)
{
  int v1; // eax
  int result; // eax
  float v3; // [esp+0h] [ebp-1C0h]
  _BYTE v4[432]; // [esp+10h] [ebp-1B0h] BYREF

  v1 = this[4081];
  if ( v1 > 0 && v1 <= 2 )
    return NetComm_SetSelfAsReady(-1);
  v3 = dbl_8AFEA0;
  ProgressBarEventEncode(4, 3, 0, 0, LODWORD(v3), 1);
  result = TextureCreationWrapper(v4, 2, -1, -1);
  if ( dword_7C569C != 5 )
  {
    result = StringSplitLoop(1, aDDevF119992002_1, 4371);
    if ( (_BYTE)result )
      return DebugLogWrite(&dword_8AD25C, aSendingServerO);
  }
  return result;
}
