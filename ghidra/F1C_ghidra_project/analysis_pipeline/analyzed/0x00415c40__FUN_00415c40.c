// Function: FUN_00415c40 @ 00415c40
// Size (bytes): 334


undefined4 __fastcall FUN_00415c40(int param_1)

{
  int *piVar1;
  int *piVar2;
  int iVar3;
  undefined4 *puVar4;
  undefined4 *puVar5;
  int iVar6;
  int local_c;
  int local_8;
  
  piVar2 = *(int **)(param_1 + 0x20);
  while (piVar2 != (int *)0x0) {
    piVar1 = (int *)piVar2[1];
    if (((char)piVar2[2] != '\0') && (*piVar2 != 0)) {
      FUN_00418cf0(1);
    }
    FUN_00587bcf(piVar2);
    piVar2 = piVar1;
  }
  *(undefined4 *)(param_1 + 0x20) = 0;
  *(undefined4 *)(param_1 + 0x24) = 0;
  *(undefined4 *)(param_1 + 0x28) = 0;
  *(undefined4 *)(param_1 + 0x2c) = 0;
  iVar3 = DAT_008ac488;
  if (DAT_008ac488 < 1) {
    return 1;
  }
  local_8 = 0;
  if (0 < DAT_008ac488) {
    local_c = 0;
    do {
      puVar4 = operator_new(0x5c);
      if (puVar4 == (undefined4 *)0x0) {
        puVar4 = (undefined4 *)0x0;
      }
      else {
        *puVar4 = 0;
        puVar4[1] = 0xffffffff;
        iVar6 = 2;
        do {
          FUN_00415520();
          iVar6 = iVar6 + -1;
        } while (iVar6 != 0);
        iVar6 = 2;
        do {
          FUN_00415520();
          iVar6 = iVar6 + -1;
        } while (iVar6 != 0);
        FUN_00414fe0();
      }
      FUN_00566650(local_c + 0x104 + DAT_008ac490);
      puVar4[2] = local_8;
      FUN_00414e60();
      puVar5 = operator_new(0xc);
      if (puVar5 == (undefined4 *)0x0) {
        puVar5 = (undefined4 *)0x0;
      }
      else {
        *puVar5 = puVar4;
        puVar5[1] = 0;
        *(undefined1 *)(puVar5 + 2) = 1;
      }
      if (*(int *)(param_1 + 0x20) == 0) {
        *(undefined4 **)(param_1 + 0x20) = puVar5;
        *(undefined4 **)(param_1 + 0x28) = puVar5;
      }
      else {
        *(undefined4 **)(*(int *)(param_1 + 0x24) + 4) = puVar5;
      }
      *(undefined4 **)(param_1 + 0x24) = puVar5;
      local_8 = local_8 + 1;
      local_c = local_c + 0x18c;
      *(int *)(param_1 + 0x2c) = *(int *)(param_1 + 0x2c) + 1;
    } while (local_8 < iVar3);
  }
  return 0;
}


