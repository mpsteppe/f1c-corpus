int __thiscall sub_4B3A60(_DWORD *this)
{
  int v2; // ecx
  const char *v3; // eax
  int result; // eax
  int v5; // [esp+0h] [ebp-6Ch]
  char String1[24]; // [esp+Ch] [ebp-60h] BYREF
  char Buffer[69]; // [esp+24h] [ebp-48h] BYREF
  __int16 v8; // [esp+69h] [ebp-3h]
  char v9; // [esp+6Bh] [ebp-1h]

  this[153] = 0;
  sub_4D0AC0(v5);
  memset(&Buffer[8], 0, 61);
  v2 = this[12];
  v8 = 0;
  this[139] = 0;
  this[140] = 0;
  v9 = 0;
  v3 = (const char *)sub_4DEE50(v2);
  sub_41D810(String1, 0x1Fu, "[%s]", v3);
  if ( !_stricmp(String1, "[(null)]") )
    sub_41D810(String1, 0x1Fu, "[MAIN_SIMULATION]");
  sub_4A50E0();
  result = this[153];
  if ( result < 1 )
  {
    result = sub_4A50E0();
    if ( (int)this[153] < 1 )
    {
      sub_41D810(Buffer, 0x3Fu, "No Help available");
      return sub_4D93B0(Buffer, 0, 0, 0, 0, 0, -1, -1, -1, -1);
    }
  }
  return result;
}
