// Function: FUN_00434820 @ 00434820
// Size (bytes): 64


undefined4 __fastcall FUN_00434820(undefined1 *param_1)

{
  undefined4 uVar1;
  int iVar2;
  
  FUN_00434860();
  uVar1 = FUN_0040c870();
  *(undefined4 *)(param_1 + 8) = uVar1;
  iVar2 = FUN_004348b0();
  if (iVar2 == 0) {
    FUN_0040cde0(5,1);
    *param_1 = 1;
    return 0;
  }
  return 1;
}


