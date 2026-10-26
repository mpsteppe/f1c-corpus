int __thiscall MenuOptionValueDisplay(int this)
{
  int v2; // eax
  _BYTE v4[61]; // [esp+8h] [ebp-40h] BYREF
  __int16 v5; // [esp+45h] [ebp-3h]
  char v6; // [esp+47h] [ebp-1h]

  v4[0] = byte_5EA438[0];
  memset(&v4[1], 0, 0x3Cu);
  v5 = 0;
  v6 = 0;
  v2 = *(_DWORD *)(this + 812);
  if ( v2 == 4 )
    VehicleSetupValueFormatter((int)&byte_7C56C0, *(const char ***)(this + 804));
  else
    SetupValueFormatDispatcher((int)&byte_7C56C0, v2, *(_DWORD *)(this + 808));
  StringFormatWithBufferOverflowCheck(v4, (int)"%s", (const char *)(*(_DWORD *)(this + 800) + 30));
  return StringCompareAndConditionalReplace(v4);
}

