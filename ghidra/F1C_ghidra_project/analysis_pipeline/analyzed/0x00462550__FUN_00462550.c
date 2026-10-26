// Function: FUN_00462550 @ 00462550
// Size (bytes): 519


undefined1 __thiscall FUN_00462550(int *param_1,char *param_2)

{
  char cVar1;
  int iVar2;
  int iVar3;
  char *_Dest;
  undefined4 *puVar4;
  uint uVar5;
  char *pcVar6;
  char *pcVar7;
  undefined1 uVar8;
  undefined4 *puVar9;
  undefined4 auStackY_50 [9];
  undefined4 uStackY_2c;
  
  iVar3 = FUN_0057a880();
  _strncpy((char *)(iVar3 + 8),param_2,0x1f);
  *(undefined1 *)(iVar3 + 0x27) = 0;
  *(undefined1 *)(iVar3 + 0x28) = 1;
  if (*(int *)(*param_1 + 0x1ac) < 1) {
    *(char *)(iVar3 + 0x2b) = DAT_007d0fc4;
    param_2[0x66] = DAT_007d0fc4;
  }
  else {
    *(char *)(iVar3 + 0x2b) = (char)*(int *)(*param_1 + 0x1ac);
    param_2[0x66] = *(char *)(*param_1 + 0x1ac);
  }
  FUN_0057a200();
  puVar4 = (undefined4 *)(*param_1 + 0x34);
  for (iVar3 = 0x20; iVar3 != 0; iVar3 = iVar3 + -1) {
    *puVar4 = *(undefined4 *)param_2;
    param_2 = param_2 + 4;
    puVar4 = puVar4 + 1;
  }
  FUN_00463710();
  puVar4 = &DAT_007cd270;
  puVar9 = auStackY_50;
  for (iVar3 = 0xc; iVar3 != 0; iVar3 = iVar3 + -1) {
    *puVar9 = *puVar4;
    puVar4 = puVar4 + 1;
    puVar9 = puVar9 + 1;
  }
  iVar3 = FUN_0057a4f0();
  if (iVar3 == 0) {
    iVar3 = FUN_004615f0();
    if (iVar3 == 0) {
      *(undefined4 *)(*param_1 + 0x3fc4) = 2;
    }
    else {
      *(undefined4 *)(*param_1 + 0x3fc4) = 1;
    }
    FUN_0045e590();
    iVar3 = *param_1;
    iVar2 = *(int *)(iVar3 + 0x3fc8);
    while (iVar2 != 0) {
      pcVar7 = (char *)(iVar2 + 8);
      iVar2 = *(int *)(iVar2 + 4);
      if (*pcVar7 != '\0') {
        FUN_00587bcf();
      }
      FUN_00587bcf();
    }
    *(undefined4 *)(iVar3 + 0x3fc8) = 0;
    *(undefined4 *)(iVar3 + 0x3fcc) = 0;
    *(undefined4 *)(iVar3 + 0x3fd0) = 0;
    *(undefined4 *)(iVar3 + 0x3fd4) = 0;
    iVar3 = FUN_00461cd0();
    if (iVar3 != 1) {
      _Dest = operator_new(0x80);
      pcVar7 = DAT_007ce64c;
      if (DAT_007ce64c == (char *)0x0) {
        pcVar7 = &DAT_005ea438;
      }
      uVar5 = 0xffffffff;
      pcVar6 = pcVar7;
      do {
        if (uVar5 == 0) break;
        uVar5 = uVar5 - 1;
        cVar1 = *pcVar6;
        pcVar6 = pcVar6 + 1;
      } while (cVar1 != '\0');
      for (pcVar6 = pcVar7 + (~uVar5 - 1); pcVar7 < pcVar6; pcVar6 = pcVar6 + -1) {
        if (*pcVar6 == '\\') {
          pcVar6 = pcVar6 + 1;
          break;
        }
      }
      _strncpy(_Dest,pcVar6,0x7f);
      _Dest[0x7f] = '\0';
      iVar3 = *param_1;
      uStackY_2c = 0x4626f2;
      puVar4 = operator_new(0xc);
      if (puVar4 == (undefined4 *)0x0) {
        puVar4 = (undefined4 *)0x0;
      }
      else {
        *puVar4 = _Dest;
        puVar4[1] = 0;
        *(undefined1 *)(puVar4 + 2) = 1;
      }
      if (*(int *)(iVar3 + 0x3fc8) == 0) {
        *(int *)(iVar3 + 0x3fc8) = (int)puVar4;
        *(undefined4 **)(iVar3 + 0x3fd0) = puVar4;
      }
      else {
        *(undefined4 **)(*(int *)(iVar3 + 0x3fcc) + 4) = puVar4;
      }
      *(undefined4 **)(iVar3 + 0x3fcc) = puVar4;
      *(int *)(iVar3 + 0x3fd4) = *(int *)(iVar3 + 0x3fd4) + 1;
    }
    FUN_0045c240();
    uVar8 = 1;
  }
  else {
    uVar8 = 0;
  }
  FUN_0057a8b0();
  return uVar8;
}


