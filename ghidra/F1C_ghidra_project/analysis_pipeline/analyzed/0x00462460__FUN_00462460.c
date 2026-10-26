// Function: FUN_00462460 @ 00462460
// Size (bytes): 124


undefined4 __thiscall FUN_00462460(int *param_1,int param_2,undefined4 *param_3,undefined4 *param_4)

{
  undefined1 uVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  undefined4 *puVar7;
  undefined4 *puVar8;
  
  iVar3 = *param_1;
  iVar2 = 0;
  uVar1 = 0;
  if (0 < *(int *)(iVar3 + 0x3e14)) {
    iVar5 = 0;
    iVar6 = 0x3c74;
    do {
      if (*(char *)(iVar5 + 0x410 + iVar3) == param_2) {
        puVar7 = (undefined4 *)(iVar5 + 0x394 + iVar3);
        puVar8 = param_3;
        for (iVar4 = 0x23; iVar4 != 0; iVar4 = iVar4 + -1) {
          *puVar8 = *puVar7;
          puVar7 = puVar7 + 1;
          puVar8 = puVar8 + 1;
        }
        *param_4 = *(undefined4 *)(*param_1 + iVar6);
        uVar1 = 1;
      }
      iVar3 = *param_1;
      iVar2 = iVar2 + 1;
      iVar6 = iVar6 + 4;
      iVar5 = iVar5 + 0x8c;
    } while (iVar2 < *(int *)(iVar3 + 0x3e14));
    return CONCAT31((int3)((uint)iVar2 >> 8),uVar1);
  }
  return 0;
}


