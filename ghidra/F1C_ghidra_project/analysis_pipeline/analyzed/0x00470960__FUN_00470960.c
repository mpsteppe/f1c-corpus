// Function: FUN_00470960 @ 00470960
// Size (bytes): 99


undefined4 __fastcall FUN_00470960(int param_1)

{
  undefined4 uVar1;
  int iVar2;
  undefined1 local_20 [32];
  
  *(undefined4 *)(param_1 + 0x324) = DAT_007d0410;
  *(undefined4 **)(param_1 + 800) = &DAT_007ceaa4;
  uVar1 = FUN_00487010(DAT_007ceaa4);
  FUN_0058815f(local_20,uVar1);
  FUN_0048b810(local_20);
  iVar2 = (**(code **)(*DAT_007cd8c0 + 0x1c))(0x13);
  if (iVar2 != 0) {
    FUN_00477280(param_1);
  }
  return 0;
}


