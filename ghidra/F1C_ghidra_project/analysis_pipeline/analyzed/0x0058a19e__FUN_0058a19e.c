// Function: FUN_0058a19e @ 0058a19e
// Size (bytes): 253


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0058a19e(void)

{
  DWORD DVar1;
  int iVar2;
  undefined4 uVar3;
  uint uVar4;
  HMODULE pHVar5;
  undefined4 uVar6;
  _STARTUPINFOA local_60;
  undefined1 *local_1c;
  undefined4 *local_18;
  void *pvStack_14;
  undefined1 *puStack_10;
  undefined *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &DAT_005b8c88;
  puStack_10 = &LAB_0058895c;
  pvStack_14 = ExceptionList;
  local_1c = &stack0xffffff88;
  ExceptionList = &pvStack_14;
  DVar1 = GetVersion();
  _DAT_008d3e80 = DVar1 >> 8 & 0xff;
  _DAT_008d3e7c = DVar1 & 0xff;
  _DAT_008d3e78 = _DAT_008d3e7c * 0x100 + _DAT_008d3e80;
  _DAT_008d3e74 = DVar1 >> 0x10;
  iVar2 = FUN_0059325d(1);
  if (iVar2 == 0) {
    FUN_0058a2cb(0x1c);
  }
  iVar2 = FUN_0058e060();
  if (iVar2 == 0) {
    FUN_0058a2cb(0x10);
  }
  local_8 = 0;
  FUN_00592f2c();
  DAT_008d5a44 = GetCommandLineA();
  DAT_008d3eb4 = FUN_00592dfa();
  FUN_00592bad();
  FUN_00592af4();
  FUN_00589c77();
  local_60.dwFlags = 0;
  GetStartupInfoA(&local_60);
  uVar3 = FUN_00592a9c();
  if ((local_60.dwFlags & 1) == 0) {
    uVar4 = 10;
  }
  else {
    uVar4 = (uint)local_60.wShowWindow;
  }
  uVar6 = 0;
  pHVar5 = GetModuleHandleA((LPCSTR)0x0);
  uVar3 = FUN_0045b200(pHVar5,uVar6,uVar3,uVar4);
  FUN_00589ca4(uVar3);
  FUN_00592924(*(undefined4 *)*local_18,local_18);
  return;
}


