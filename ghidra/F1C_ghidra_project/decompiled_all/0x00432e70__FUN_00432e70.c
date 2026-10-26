// Function: FUN_00432e70 @ 00432e70
// Strings:  [AutoLoadEntry]


void __fastcall FUN_00432e70(int param_1)

{
  int *piVar1;
  char cVar2;
  int iVar3;
  int *piVar4;
  undefined4 *puVar5;
  undefined1 local_434 [412];
  undefined4 local_298;
  undefined1 local_294;
  undefined4 local_28c;
  undefined4 local_288;
  undefined4 local_284;
  undefined4 local_280 [96];
  undefined1 local_100 [256];
  
  FUN_00432df0(&DAT_007ce498);
  piVar4 = *(int **)(param_1 + 0x1c);
  while (piVar4 != (int *)0x0) {
    piVar1 = (int *)piVar4[1];
    if (((char)piVar4[2] != '\0') && (iVar3 = *piVar4, iVar3 != 0)) {
      FUN_00433090();
      FUN_00587bcf(iVar3);
    }
    FUN_00587bcf(piVar4);
    piVar4 = piVar1;
  }
  *(undefined4 *)(param_1 + 0x1c) = 0;
  *(undefined4 *)(param_1 + 0x20) = 0;
  *(undefined4 *)(param_1 + 0x24) = 0;
  *(undefined4 *)(param_1 + 0x28) = 0;
  iVar3 = FUN_00432cf0(&DAT_007ce498,local_100,0x100);
  if (iVar3 == 0) {
    FUN_005668b0();
    cVar2 = FUN_00566b20(local_100,1);
    if (cVar2 != '\0') {
      puVar5 = local_280;
      for (iVar3 = 0x60; iVar3 != 0; iVar3 = iVar3 + -1) {
        *puVar5 = 0;
        puVar5 = puVar5 + 1;
      }
      local_298 = 0;
      local_284 = 0;
      local_28c = 0;
      local_288 = 0;
      local_294 = 1;
      iVar3 = FUN_00566cc0(local_280,0x180);
      while (iVar3 != 0) {
        iVar3 = FUN_005651b0();
        if (((iVar3 == 0) &&
            (iVar3 = FUN_00588410(local_280,PTR_s_AutoLoadEntry_005c3f88), iVar3 == 0)) &&
           (piVar4 = operator_new(0x1c), piVar4 != (int *)0x0)) {
          *piVar4 = 0;
          piVar4[1] = -1;
          piVar4[2] = 0;
          piVar4[3] = -1;
          piVar4[5] = 0;
          piVar4[6] = -1;
          FUN_00432cc0();
          iVar3 = FUN_00432a70(local_434);
          if (iVar3 == 0) {
            puVar5 = operator_new(0xc);
            if (puVar5 == (undefined4 *)0x0) {
              puVar5 = (undefined4 *)0x0;
            }
            else {
              *puVar5 = piVar4;
              puVar5[1] = 0;
              *(undefined1 *)(puVar5 + 2) = 1;
            }
            if (*(int *)(param_1 + 0x1c) == 0) {
              *(undefined4 **)(param_1 + 0x1c) = puVar5;
              *(undefined4 **)(param_1 + 0x24) = puVar5;
              *(undefined4 **)(param_1 + 0x20) = puVar5;
              *(int *)(param_1 + 0x28) = *(int *)(param_1 + 0x28) + 1;
            }
            else {
              *(undefined4 **)(*(int *)(param_1 + 0x20) + 4) = puVar5;
              *(undefined4 **)(param_1 + 0x20) = puVar5;
              *(int *)(param_1 + 0x28) = *(int *)(param_1 + 0x28) + 1;
            }
          }
          else {
            FUN_00432cc0();
            if (piVar4[5] != 0) {
              FUN_00587bcf(piVar4[5]);
            }
            if (piVar4[2] != 0) {
              FUN_00587bcf(piVar4[2]);
            }
            if (*piVar4 != 0) {
              FUN_00587bcf(*piVar4);
            }
            FUN_00587bcf(piVar4);
          }
        }
        iVar3 = FUN_00566cc0(local_280,0x180);
      }
      FUN_00566b90();
    }
    FUN_005668d0();
  }
  *(undefined1 *)(param_1 + 0x18) = 1;
  return;
}


