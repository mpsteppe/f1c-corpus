// Function: FUN_00497d20 @ 00497d20
// Size (bytes): 342


undefined4 FUN_00497d20(char *param_1)

{
  char cVar1;
  int iVar2;
  int iVar3;
  undefined1 *puVar4;
  int *piVar5;
  void *pvVar6;
  int unaff_ESI;
  int unaff_EDI;
  undefined4 local_18;
  undefined4 uStack_14;
  undefined4 uStack_10;
  undefined4 uStack_c;
  undefined1 uStack_8;
  
  if (param_1 != (char *)0x0) {
    iVar3 = FUN_00497e80(param_1);
    piVar5 = DAT_008ac4c4;
    if (iVar3 != 0) {
      return 1;
    }
    if (DAT_008ac4c4 != (int *)0x0) {
      puVar4 = DAT_005ec400;
      if (DAT_005ec400 == (undefined1 *)0x0) {
        puVar4 = &DAT_005ea438;
      }
      (**(code **)(*DAT_008ac4c4 + 0x44))(puVar4);
      local_18 = 0;
      uStack_14 = 0xffffffff;
      FUN_00566650(&DAT_005ea438);
      uStack_10 = 0xffffffff;
      uStack_c = 0xffffffff;
      uStack_8 = 0;
      FUN_00566650(param_1);
      uStack_10 = 0;
      uStack_c = 0;
      uStack_8 = 0;
      piVar5 = (int *)(**(code **)(*piVar5 + 0x5c))(&local_18,0,0xf);
      if (piVar5 != (int *)0x0) {
        iVar3 = (**(code **)(*piVar5 + 0x14))();
        if (iVar3 == 0) {
          pvVar6 = operator_new(0x58);
          if (pvVar6 == (void *)0x0) {
            pvVar6 = (void *)0x0;
          }
          else {
            *(undefined4 *)((int)pvVar6 + 0x50) = 0;
            *(undefined4 *)((int)pvVar6 + 0x54) = 0;
          }
          iVar3 = (int)pvVar6 - (int)param_1;
          do {
            cVar1 = *param_1;
            param_1[iVar3] = cVar1;
            param_1 = param_1 + 1;
          } while (cVar1 != '\0');
          *(int **)((int)pvVar6 + 0x50) = piVar5;
          iVar3 = *(int *)(unaff_EDI + 0x10c);
          if (iVar3 == 0) {
            *(void **)(unaff_EDI + 0x10c) = pvVar6;
          }
          else {
            for (iVar2 = *(int *)(iVar3 + 0x54); iVar2 != 0; iVar2 = *(int *)(iVar2 + 0x54)) {
              iVar3 = iVar2;
            }
            *(void **)(iVar3 + 0x54) = pvVar6;
          }
          *(int *)(unaff_EDI + 0x110) = *(int *)(unaff_EDI + 0x110) + 1;
          if (unaff_ESI == 0) {
            return 1;
          }
          FUN_00587bcf(unaff_ESI);
          return 1;
        }
        (**(code **)*piVar5)(1);
      }
      if (unaff_ESI != 0) {
        FUN_00587bcf(unaff_ESI);
      }
    }
  }
  return 0;
}


