// Function: FUN_00415780 @ 00415780
// Size (bytes): 378


undefined4 __fastcall FUN_00415780(int *param_1)

{
  int *piVar1;
  int *piVar2;
  int iVar3;
  undefined4 *puVar4;
  undefined4 *puVar5;
  int iVar6;
  int local_c;
  int local_8;
  
  piVar2 = (int *)*param_1;
  while (piVar2 != (int *)0x0) {
    piVar1 = (int *)piVar2[1];
    if (((char)piVar2[2] != '\0') && (*piVar2 != 0)) {
      FUN_00415900(1);
    }
    FUN_00587bcf(piVar2);
    piVar2 = piVar1;
  }
  *param_1 = 0;
  param_1[1] = 0;
  param_1[2] = 0;
  param_1[3] = 0;
  iVar3 = DAT_008ac390;
  if (DAT_008ac390 < 1) {
    return 1;
  }
  local_8 = 0;
  if (0 < DAT_008ac390) {
    local_c = 0;
    do {
      puVar4 = operator_new(0xb0);
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
        FUN_00401000(puVar4 + 0x18,0x14,2,FUN_00415520);
        FUN_00401000(puVar4 + 0x22,0x14,2,FUN_00415520);
        FUN_004149a0();
      }
      FUN_00566650(local_c + 0xbc + DAT_008ac394);
      puVar4[2] = local_8;
      FUN_00414600(0);
      puVar5 = operator_new(0xc);
      if (puVar5 == (undefined4 *)0x0) {
        puVar5 = (undefined4 *)0x0;
      }
      else {
        *puVar5 = puVar4;
        puVar5[1] = 0;
        *(undefined1 *)(puVar5 + 2) = 1;
      }
      if (*param_1 == 0) {
        *param_1 = (int)puVar5;
        param_1[2] = (int)puVar5;
      }
      else {
        *(undefined4 **)(param_1[1] + 4) = puVar5;
      }
      param_1[1] = (int)puVar5;
      local_8 = local_8 + 1;
      local_c = local_c + 0x424;
      param_1[3] = param_1[3] + 1;
    } while (local_8 < iVar3);
  }
  return 0;
}


