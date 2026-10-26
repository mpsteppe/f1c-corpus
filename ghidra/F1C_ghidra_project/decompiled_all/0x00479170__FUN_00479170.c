// Function: FUN_00479170 @ 00479170
// Strings:  [Coordinate, NumCoordinates]


void __thiscall FUN_00479170(int param_1,undefined4 param_2)

{
  byte bVar1;
  undefined4 *puVar2;
  int iVar3;
  undefined4 *puVar4;
  int iVar5;
  int local_324;
  undefined4 local_320;
  undefined4 local_31c [97];
  undefined4 local_198;
  undefined1 local_194;
  undefined4 local_18c;
  undefined4 local_188;
  undefined4 local_184;
  undefined4 local_180 [96];
  
  puVar2 = local_180;
  for (iVar5 = 0x60; iVar5 != 0; iVar5 = iVar5 + -1) {
    *puVar2 = 0;
    puVar2 = puVar2 + 1;
  }
  local_198 = 0;
  local_184 = 0;
  local_18c = 0;
  local_188 = 0;
  local_194 = 1;
  local_324 = 0;
  iVar5 = FUN_00587db0(param_2,&DAT_005be690);
  puVar2 = *(undefined4 **)(param_1 + 0x164);
  while (puVar2 != (undefined4 *)0x0) {
    puVar4 = (undefined4 *)puVar2[1];
    if (*(char *)(puVar2 + 2) != '\0') {
      FUN_00587bcf(*puVar2);
    }
    FUN_00587bcf(puVar2);
    puVar2 = puVar4;
  }
  *(undefined4 *)(param_1 + 0x164) = 0;
  *(undefined4 *)(param_1 + 0x168) = 0;
  *(undefined4 *)(param_1 + 0x16c) = 0;
  *(undefined4 *)(param_1 + 0x170) = 0;
  *(undefined4 *)(param_1 + 0x154) = 0;
  if (iVar5 != 0) {
    bVar1 = *(byte *)(iVar5 + 0xc);
    while ((bVar1 & 0x10) == 0) {
      puVar2 = operator_new(0xc);
      FUN_00587ca0(local_180,0x180,iVar5);
      FUN_00565760(s_NumCoordinates_005c71b0,&local_324,0,0,0);
      if ((0 < local_324) &&
         (iVar3 = FUN_00565760(s_Coordinate_005c71a4,&local_320,local_31c,0,0), iVar3 != 0)) {
        *puVar2 = local_320;
        puVar2[1] = local_31c[0];
        puVar4 = operator_new(0xc);
        if (puVar4 == (undefined4 *)0x0) {
          puVar4 = (undefined4 *)0x0;
        }
        else {
          *puVar4 = puVar2;
          puVar4[1] = 0;
          *(undefined1 *)(puVar4 + 2) = 1;
        }
        if (*(int *)(param_1 + 0x164) == 0) {
          *(undefined4 **)(param_1 + 0x164) = puVar4;
          *(undefined4 **)(param_1 + 0x16c) = puVar4;
        }
        else {
          *(undefined4 **)(*(int *)(param_1 + 0x168) + 4) = puVar4;
        }
        *(undefined4 **)(param_1 + 0x168) = puVar4;
        *(int *)(param_1 + 0x170) = *(int *)(param_1 + 0x170) + 1;
        *(int *)(param_1 + 0x154) = *(int *)(param_1 + 0x154) + 1;
      }
      bVar1 = *(byte *)(iVar5 + 0xc);
    }
    FUN_00587d02(iVar5);
  }
  return;
}


