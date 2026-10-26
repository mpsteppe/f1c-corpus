// Function: FUN_00556e70 @ 00556e70
// Size (bytes): 578


void __thiscall FUN_00556e70(int param_1,int param_2)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  
  if ((*(byte *)(param_1 + 0x80) & 8) != 0) {
    FUN_005572b0();
    if (*(code **)(param_1 + 0x1a4) != (code *)0x0) {
      (**(code **)(param_1 + 0x1a4))();
    }
    FUN_00541a70();
    FUN_00541b70(0xe);
    for (iVar3 = *(int *)(param_2 + 0x108); iVar3 != 0; iVar3 = *(int *)(iVar3 + 0x4c)) {
      if ((*(byte *)(iVar3 + 0x3c) & 2) == 0) {
        FUN_00556930(param_1);
      }
    }
    uVar2 = *(uint *)(param_2 + 0xec) & 0x3000;
    if (uVar2 == 0x1000) {
      iVar3 = FUN_0054a340(param_1);
      if (iVar3 == 0) {
        iVar3 = *(int *)(param_2 + 0x100);
        *(undefined4 *)(param_2 + 0x1a4) = 0;
        for (; iVar3 != 0; iVar3 = *(int *)(iVar3 + 0x104)) {
          if ((*(byte *)(iVar3 + 4) & 0x40) == 0) {
            FUN_00549fb0(param_1);
            if ((*(byte *)(iVar3 + 4) & 4) != 0) {
              FUN_0054a0a0(param_1);
            }
            if (((*(byte *)(iVar3 + 4) & 5) != 0) || ((*(uint *)(param_1 + 0x80) & 0x800) != 0)) {
              for (iVar1 = *(int *)(iVar3 + 0xec); iVar1 != 0; iVar1 = *(int *)(iVar1 + 0x4c)) {
                if ((*(byte *)(iVar1 + 0x3c) & 2) == 0) {
                  FUN_00556930(param_1);
                }
              }
            }
          }
        }
      }
      else {
        for (iVar1 = *(int *)(iVar3 + 0xec); iVar1 != 0; iVar1 = *(int *)(iVar1 + 0x4c)) {
          if ((*(byte *)(iVar1 + 0x3c) & 2) == 0) {
            FUN_00556930(param_1);
          }
        }
        for (iVar3 = *(int *)(iVar3 + 0xf8); iVar3 != 0; iVar3 = *(int *)(iVar3 + 0x14)) {
          iVar1 = *(int *)(iVar3 + 0x10);
          FUN_00549fb0(param_1);
          if ((*(byte *)(iVar1 + 4) & 4) != 0) {
            FUN_0054a0a0(param_1);
          }
          if ((*(byte *)(iVar1 + 4) & 5) != 0) {
            for (iVar1 = *(int *)(iVar1 + 0xec); iVar1 != 0; iVar1 = *(int *)(iVar1 + 0x4c)) {
              if ((*(byte *)(iVar1 + 0x3c) & 2) == 0) {
                FUN_00556930(param_1);
              }
            }
          }
        }
      }
    }
    else if (uVar2 == 0x2000) {
      for (iVar3 = *(int *)(param_2 + 0x100); iVar3 != 0; iVar3 = *(int *)(iVar3 + 0x104)) {
        if ((*(byte *)(iVar3 + 4) & 0x40) == 0) {
          FUN_00549fb0(param_1);
          if ((*(byte *)(iVar3 + 4) & 4) != 0) {
            FUN_0054a0a0(param_1);
          }
          if (((*(byte *)(iVar3 + 4) & 5) != 0) || ((*(uint *)(param_1 + 0x80) & 0x800) != 0)) {
            for (iVar1 = *(int *)(iVar3 + 0xec); iVar1 != 0; iVar1 = *(int *)(iVar1 + 0x4c)) {
              if ((*(byte *)(iVar1 + 0x3c) & 2) == 0) {
                FUN_00556930(param_1);
              }
            }
          }
        }
      }
    }
    FUN_005550e0(param_2,param_1);
    if ((*(byte *)(param_1 + 0x80) & 0x20) != 0) {
      for (iVar3 = *(int *)(param_2 + 0x148); iVar3 != 0; iVar3 = *(int *)(iVar3 + 0x68)) {
        FUN_00558e70(param_2,param_1);
      }
    }
  }
  if (*(int *)(param_1 + 0x1b0) != 0) {
    FUN_00556e70(param_2);
    FUN_00541b70(0xe);
  }
  return;
}


