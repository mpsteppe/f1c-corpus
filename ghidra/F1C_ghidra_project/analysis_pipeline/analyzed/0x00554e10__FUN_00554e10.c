// Function: FUN_00554e10 @ 00554e10
// Size (bytes): 125


void __thiscall FUN_00554e10(int param_1,int param_2)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  iVar2 = 0;
  if (0 < *(int *)(param_1 + 0x13b0)) {
    do {
      FUN_00554610(0);
      iVar2 = iVar2 + 1;
    } while (iVar2 < *(int *)(param_1 + 0x13b0));
  }
  if (param_2 != 0) {
    for (iVar2 = *(int *)(*(int *)(param_2 + 0x110) + 0x28); iVar2 != 0;
        iVar2 = *(int *)(iVar2 + 0x5c)) {
      iVar3 = 0;
      iVar1 = iVar2;
      if (0 < *(int *)(iVar2 + 0x4c)) {
        do {
          if ((*(uint *)(*(int *)(iVar2 + 0x54) + 0x18) & 0x80000) == 0) {
            FUN_00554d70(iVar1);
          }
          iVar3 = iVar3 + 1;
          iVar1 = iVar1 + 0x60;
        } while (iVar3 < *(int *)(iVar2 + 0x4c));
      }
    }
  }
  return;
}


