// Function: FUN_0040ca30 @ 0040ca30
// Size (bytes): 688


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __fastcall FUN_0040ca30(int param_1)

{
  float fVar1;
  int *piVar2;
  int iVar3;
  int iVar4;
  float10 extraout_ST0;
  float local_34;
  float local_30;
  float local_2c;
  float local_28;
  float local_24;
  float local_20;
  float local_1c;
  float local_18;
  float local_14;
  float local_10;
  undefined1 local_c [4];
  undefined1 local_8 [4];
  undefined1 local_4 [4];
  
  FUN_0040c7a0();
  iVar4 = 0;
  iVar3 = 0;
  FUN_0040c910();
  if (*(char *)(param_1 + 0x2d) == '\0') {
    *(undefined1 *)(param_1 + 0x2d) = 1;
    FUN_00409890(0);
  }
  FUN_00542460(&local_18,&local_14,&local_10);
  local_24 = -local_18;
  local_20 = -local_14;
  local_1c = -local_10;
  local_18 = local_24;
  local_14 = local_20;
  local_10 = local_1c;
  FUN_004d8860(0);
  if (*(char *)(param_1 + 0x25) == '\0') {
    *(undefined4 *)(param_1 + 0x28) = 0;
    if (*(char *)(param_1 + 0x2e) == '\0') {
      iVar3 = FUN_0040be70();
    }
    else {
      iVar3 = FUN_0040c070();
    }
    FUN_0040c5b0();
    if (iVar3 == 1) {
      if (0 < DAT_005c329c) {
        do {
          FUN_004f0d20();
          iVar4 = iVar4 + 1;
        } while (iVar4 < DAT_005c329c);
      }
      (**(code **)(**(int **)(param_1 + 8) + 0x10))();
    }
    (**(code **)(**(int **)(param_1 + 8) + 0xc))();
  }
  else {
    *(undefined1 *)(param_1 + 0x25) = 0;
  }
  piVar2 = DAT_008ac4c4;
  if (DAT_008ac4c4 != (int *)0x0) {
    FUN_00542420(&local_24,&local_20,&local_1c,local_c,local_8,local_4);
    local_30 = -local_24;
    local_2c = -local_20;
    local_28 = -local_1c;
    local_24 = local_30;
    local_20 = local_2c;
    local_1c = local_28;
    if (iVar3 == 0) {
      if (*(int **)(param_1 + 8) == *(int **)(param_1 + 0x18)) {
        local_30 = *(float *)(DAT_007c54e0 + 0x58);
        local_2c = *(float *)(DAT_007c54e0 + 0x5c);
        local_28 = *(float *)(DAT_007c54e0 + 0x60);
      }
      else {
        iVar3 = (**(code **)(**(int **)(param_1 + 8) + 0x18))();
        if (iVar3 != 0) {
          local_30 = *(float *)(iVar3 + 0x24);
          local_2c = *(float *)(iVar3 + 0x28);
          local_28 = *(float *)(iVar3 + 0x2c);
          (**(code **)(*piVar2 + 0x20))(&local_24,local_c,&local_30);
        }
      }
      if (DAT_007c56ac == '\0') {
        local_34 = DAT_007cfe4c;
      }
      iVar3 = FUN_0040c870();
      fVar1 = DAT_0059e440;
      if (iVar3 != 0) {
        fVar1 = *(float *)(iVar3 + 0x5c);
      }
      FUN_0053d450((float)((float10)fVar1 + extraout_ST0));
      (**(code **)(*piVar2 + 0x20))(&local_28,&local_10,&local_34);
      return;
    }
    (**(code **)(*piVar2 + 0x1c))(&local_24,local_c);
    if (DAT_008acebc != 0) {
      FUN_004ccdc0(&local_20,&local_2c);
    }
  }
  return;
}


