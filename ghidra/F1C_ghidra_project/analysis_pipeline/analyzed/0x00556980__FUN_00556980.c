// Function: FUN_00556980 @ 00556980
// Size (bytes): 101


void __thiscall FUN_00556980(int param_1,undefined4 param_2)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  
  iVar3 = FUN_0054b570(param_2,0);
  if ((*(byte *)(param_1 + 0x3c) & 4) == 0) {
    for (iVar1 = *(int *)(param_1 + 0x204); iVar1 != 0; iVar1 = *(int *)(iVar1 + 0x10)) {
      uVar2 = *(uint *)(iVar1 + 0x14);
      if (iVar3 != 0) {
        *(uint *)(iVar1 + 0x14) = uVar2 & 0xdfffffd7;
      }
      if ((uVar2 & 0x200000) == 0) {
        if (*(int *)(iVar1 + 0x13c) == 0) {
          FUN_00556b10(param_2,iVar1);
        }
        else {
          FUN_005569f0(param_2,iVar1);
        }
      }
    }
  }
  return;
}


