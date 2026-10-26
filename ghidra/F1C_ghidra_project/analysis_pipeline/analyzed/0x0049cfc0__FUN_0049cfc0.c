// Function: FUN_0049cfc0 @ 0049cfc0
// Size (bytes): 172


void __fastcall FUN_0049cfc0(int param_1)

{
  int iVar1;
  
  if ((*(int *)(param_1 + 0x4c) != 0) &&
     (iVar1 = *(int *)(*(int *)(param_1 + 0x4c) + 0x54), iVar1 != 0)) {
    FUN_0049f530(0,param_1 + 0x60,iVar1);
  }
  if ((*(int *)(param_1 + 0x50) != 0) &&
     (iVar1 = *(int *)(*(int *)(param_1 + 0x50) + 0x54), iVar1 != 0)) {
    FUN_0049f530(1,param_1 + 0xac,iVar1);
  }
  if ((*(int *)(param_1 + 0x54) != 0) &&
     (iVar1 = *(int *)(*(int *)(param_1 + 0x54) + 0x54), iVar1 != 0)) {
    FUN_0049f530(2,param_1 + 0xf8,iVar1);
  }
  if ((*(int *)(param_1 + 0x58) != 0) &&
     (iVar1 = *(int *)(*(int *)(param_1 + 0x58) + 0x54), iVar1 != 0)) {
    FUN_0049f530(3,param_1 + 0x144,iVar1);
  }
  if ((*(int *)(param_1 + 0x5c) != 0) &&
     (iVar1 = *(int *)(*(int *)(param_1 + 0x5c) + 0x54), iVar1 != 0)) {
    FUN_0049f530(4,param_1 + 400,iVar1);
  }
  return;
}


