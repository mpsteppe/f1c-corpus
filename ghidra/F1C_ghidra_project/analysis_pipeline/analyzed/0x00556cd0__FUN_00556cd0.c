// Function: FUN_00556cd0 @ 00556cd0
// Size (bytes): 139


void __thiscall FUN_00556cd0(int param_1,undefined4 param_2,int param_3)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  if (*(int *)(param_1 + 0x44) != 0) {
    FUN_00556cd0(param_2,1);
  }
  if ((*(int *)(param_1 + 0x4c) != 0) && (param_3 != 0)) {
    FUN_00556cd0(param_2,1);
  }
  for (iVar1 = *(int *)(param_1 + 0x204); iVar1 != 0; iVar1 = *(int *)(iVar1 + 0x10)) {
    iVar3 = *(int *)(iVar1 + 0x11c);
    iVar2 = 0;
    if (0 < *(int *)(iVar1 + 0x118)) {
      do {
        *(uint *)(iVar3 + 0x38) = *(uint *)(iVar3 + 0x38) | 0x400;
        FUN_0055d720(param_2,1);
        iVar3 = iVar3 + 0x40;
        iVar2 = iVar2 + 1;
      } while (iVar2 < *(int *)(iVar1 + 0x118));
    }
    *(uint *)(iVar1 + 0x14) = *(uint *)(iVar1 + 0x14) & 0xefffffff;
  }
  return;
}


