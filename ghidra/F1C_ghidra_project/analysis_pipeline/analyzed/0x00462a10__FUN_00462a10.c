// Function: FUN_00462a10 @ 00462a10
// Size (bytes): 493


void __fastcall FUN_00462a10(int *param_1)

{
  int iVar1;
  char cVar2;
  int *piVar3;
  undefined4 *puVar4;
  undefined4 *puVar5;
  int extraout_EDX;
  int iVar6;
  int iVar7;
  int local_20;
  int local_1c;
  int local_18;
  undefined4 *local_10;
  undefined4 *local_c;
  
  local_10 = (undefined4 *)0x0;
  local_c = (undefined4 *)0x0;
  local_18 = 0;
  if (0 < *(int *)(*param_1 + 0x3e14)) {
    local_1c = 0;
    local_20 = 0x3c74;
    do {
      cVar2 = FUN_00461530(2);
      if (cVar2 == '\0') {
        iVar7 = -1;
      }
      else {
        iVar7 = (int)*(char *)(local_1c + 0x410 + extraout_EDX);
      }
      iVar1 = *(int *)(local_20 + extraout_EDX);
      if (iVar7 < 0) {
        iVar6 = -1;
      }
      else {
        iVar6 = (&DAT_005f0730)[iVar7 * 0x1230];
      }
      piVar3 = operator_new(0xc);
      puVar5 = local_10;
      puVar4 = local_c;
      if (piVar3 != (int *)0x0) {
        *piVar3 = iVar7;
        piVar3[1] = iVar1;
        piVar3[2] = iVar6;
        puVar4 = operator_new(0xc);
        if (puVar4 == (undefined4 *)0x0) {
          puVar4 = (undefined4 *)0x0;
        }
        else {
          *puVar4 = piVar3;
          puVar4[1] = 0;
          *(undefined1 *)(puVar4 + 2) = 1;
        }
        puVar5 = puVar4;
        if (local_10 != (undefined4 *)0x0) {
          local_c[1] = puVar4;
          puVar5 = local_10;
        }
      }
      local_c = puVar4;
      local_10 = puVar5;
      local_1c = local_1c + 0x8c;
      local_18 = local_18 + 1;
      local_20 = local_20 + 4;
    } while (local_18 < *(int *)(*param_1 + 0x3e14));
  }
  puVar5 = (undefined4 *)FUN_004647d0(local_10);
  if (puVar5 != (undefined4 *)0x0) {
    for (iVar7 = puVar5[1]; iVar7 != 0; iVar7 = *(int *)(iVar7 + 4)) {
    }
  }
  iVar7 = 0;
  piVar3 = &DAT_005f0730;
  do {
    iVar7 = iVar7 + 1;
    *piVar3 = iVar7;
    piVar3 = piVar3 + 0x1230;
  } while ((int)piVar3 < 0x7c9530);
  if (puVar5 == (undefined4 *)0x0) {
    piVar3 = (int *)0x0;
  }
  else {
    piVar3 = (int *)*puVar5;
  }
  iVar7 = 1;
  puVar4 = puVar5;
  while (piVar3 != (int *)0x0) {
    *(int *)(*param_1 + 0x3fd6 + iVar7 * 4) = piVar3[1];
    if (-1 < *piVar3) {
      (&DAT_005f0730)[*piVar3 * 0x1230] = iVar7;
    }
    iVar7 = iVar7 + 1;
    if ((puVar4 == (undefined4 *)0x0) ||
       (puVar4 = (undefined4 *)puVar4[1], puVar4 == (undefined4 *)0x0)) break;
    piVar3 = (int *)*puVar4;
  }
  *(char *)(*param_1 + 0x3fd9) = (char)iVar7 + -1;
  while (puVar5 != (undefined4 *)0x0) {
    puVar4 = (undefined4 *)puVar5[1];
    if (*(char *)(puVar5 + 2) != '\0') {
      FUN_00587bcf(*puVar5);
    }
    FUN_00587bcf(puVar5);
    puVar5 = puVar4;
  }
  return;
}


