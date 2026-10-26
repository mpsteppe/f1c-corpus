// Function: FUN_0048d6b0 @ 0048d6b0
// Size (bytes): 57


undefined4 __fastcall FUN_0048d6b0(int *param_1)

{
  int iVar1;
  undefined1 *puVar2;
  
  iVar1 = FUN_00495790();
  param_1[0x3b] = iVar1;
  if (iVar1 != 0) {
    puVar2 = *(undefined1 **)(iVar1 + 0xc0);
    if (puVar2 == (undefined1 *)0x0) {
      puVar2 = &DAT_005ea438;
    }
    FUN_00488b40(puVar2);
    (**(code **)(*param_1 + 0x2c))(1);
  }
  return 0;
}


