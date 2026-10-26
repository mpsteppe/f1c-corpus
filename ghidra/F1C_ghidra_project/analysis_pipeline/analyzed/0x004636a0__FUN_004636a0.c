// Function: FUN_004636a0 @ 004636a0
// Size (bytes): 60


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 __fastcall FUN_004636a0(int *param_1)

{
  char cVar1;
  ushort uVar2;
  
  cVar1 = FUN_00461dc0();
  if (cVar1 == '\0') {
    uVar2 = (ushort)(*(float *)(*param_1 + 0x388) < _DAT_0059f124) << 8 |
            (ushort)(*(float *)(*param_1 + 0x388) == _DAT_0059f124) << 0xe;
  }
  else {
    uVar2 = (ushort)(*(float *)(*param_1 + 0x388) < _DAT_0059e8ec) << 8 |
            (ushort)(*(float *)(*param_1 + 0x388) == _DAT_0059e8ec) << 0xe;
  }
  if (uVar2 == 0) {
    return 1;
  }
  return 0;
}


