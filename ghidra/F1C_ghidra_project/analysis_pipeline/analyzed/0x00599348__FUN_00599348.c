// Function: FUN_00599348 @ 00599348
// Size (bytes): 103


int __thiscall FUN_00599348(int param_1,uint param_2,uint param_3)

{
  char cVar1;
  uint uVar2;
  int iVar3;
  
  if (*(uint *)(param_1 + 8) < param_2) {
    FUN_0059af68();
  }
  FUN_005995e5();
  uVar2 = *(int *)(param_1 + 8) - param_2;
  if (uVar2 < param_3) {
    param_3 = uVar2;
  }
  if (param_3 != 0) {
    iVar3 = *(int *)(param_1 + 4) + param_2;
    FUN_0058b130(iVar3,iVar3 + param_3,uVar2 - param_3);
    iVar3 = *(int *)(param_1 + 8) - param_3;
    cVar1 = FUN_00599560(iVar3,0);
    if (cVar1 != '\0') {
      *(int *)(param_1 + 8) = iVar3;
      *(undefined1 *)(iVar3 + *(int *)(param_1 + 4)) = 0;
    }
  }
  return param_1;
}


