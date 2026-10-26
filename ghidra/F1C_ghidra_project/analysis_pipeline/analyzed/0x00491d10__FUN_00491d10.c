// Function: FUN_00491d10 @ 00491d10
// Size (bytes): 31


undefined4 __fastcall FUN_00491d10(int *param_1)

{
  int iVar1;
  
  iVar1 = *param_1;
  if (*(int *)(iVar1 + 0x24) != 0) {
    *(undefined4 *)(iVar1 + 0x24) = *(undefined4 *)(*(int *)(iVar1 + 0x24) + 4);
  }
  if (*(undefined4 **)(iVar1 + 0x24) != (undefined4 *)0x0) {
    return **(undefined4 **)(iVar1 + 0x24);
  }
  return 0;
}


