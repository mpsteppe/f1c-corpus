// Function: FUN_00455b30 @ 00455b30
// Size (bytes): 158


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

ushort FUN_00455b30(UINT param_1)

{
  byte bVar1;
  BOOL BVar2;
  UINT uVirtKey;
  
  if ((DAT_007ccc04 & 1) == 0) {
    DAT_007ccc04 = DAT_007ccc04 | 1;
    DAT_007ca508 = GetKeyboardLayout(0);
  }
  _DAT_007ccbc0 = 0;
  _DAT_007ccfc0 = 0;
  BVar2 = GetKeyboardState(&DAT_007ccab0);
  if (BVar2 == 0) {
    return 0;
  }
  if (param_1 == 0x8039) {
    param_1 = 0x39;
  }
  uVirtKey = MapVirtualKeyExA(param_1,1,DAT_007ca508);
  ToAsciiEx(uVirtKey,param_1,&DAT_007ccab0,(LPWORD)&DAT_007ccfc0,0,DAT_007ca508);
  bVar1 = FUN_00455580();
  _DAT_007ccbc0 = (ushort)bVar1;
  return (ushort)bVar1;
}


