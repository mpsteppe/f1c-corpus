// Function: FUN_00489d00 @ 00489d00
// Strings:  [Ttgjz]


void __fastcall FUN_00489d00(int *param_1)

{
  int *piVar1;
  undefined1 *puVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  uint uVar6;
  undefined4 local_4;
  
  piVar1 = param_1 + 0x56;
  local_4 = 0;
  *piVar1 = 0;
  if (param_1[0x32] != 0) {
    puVar2 = *(undefined1 **)(param_1[0x32] + 0x40);
    if (puVar2 == (undefined1 *)0x0) {
      puVar2 = &DAT_005ea438;
    }
    FUN_00498560(puVar2);
  }
  FUN_004983b0(s_Ttgjz_005c71cc,&local_4,piVar1,1);
  param_1[0x5b] = 0;
  param_1[0x59] = 0;
  param_1[0x58] = 0;
  param_1[0x57] = 0;
  param_1[0x55] = 0;
  if (*piVar1 < 1) {
    return;
  }
  iVar4 = (param_1[2] - param_1[1]) / 0x28 + 2;
  param_1[0x4e] = (param_1[4] - param_1[3]) / 0x28 + 2;
  iVar3 = (param_1[2] - param_1[1]) + iVar4 * -2;
  param_1[0x5b] = iVar3;
  iVar3 = iVar3 / *piVar1;
  param_1[0x4d] = iVar4;
  uVar6 = param_1[0x25] - iVar3;
  param_1[0x59] = iVar3;
  param_1[0x58] = uVar6;
  param_1[0x58] = ((int)uVar6 < 1) - 1 & uVar6;
  iVar4 = FUN_00486460(3);
  if (iVar4 != 0) {
    param_1[0x57] = *(int *)(iVar4 + 0xc) - *(int *)(iVar4 + 8);
  }
  iVar3 = (**(code **)(*param_1 + 0x24))();
  iVar4 = param_1[0x57];
  iVar5 = (**(code **)(*param_1 + 0x1c))();
  iVar5 = (iVar3 - iVar4) - iVar5;
  param_1[0x55] = iVar5;
  if (iVar5 < 0) {
    param_1[0x55] = 0;
  }
  if (param_1[0x58] < param_1[0x53]) {
    param_1[0x53] = param_1[0x58];
  }
  else {
    if (-1 < param_1[0x53]) goto LAB_00489e51;
    param_1[0x53] = 0;
  }
  FUN_00489e90();
LAB_00489e51:
  if (param_1[0x54] <= param_1[0x55]) {
    if (param_1[0x54] < 0) {
      param_1[0x54] = 0;
      FUN_00489ee0();
    }
    return;
  }
  param_1[0x54] = param_1[0x55];
  FUN_00489ee0();
  return;
}


