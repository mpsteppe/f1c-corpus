// Function: FUN_0047b9c0 @ 0047b9c0
// Size (bytes): 281


void __thiscall FUN_0047b9c0(int param_1,int param_2)

{
  char cVar1;
  int iVar2;
  undefined1 *puVar3;
  uint uVar4;
  int iVar5;
  char *pcVar6;
  int iVar7;
  char *local_10;
  undefined4 local_8;
  undefined1 local_4 [4];
  
  local_10 = (char *)**(undefined4 **)(param_1 + 0xe0);
  if (local_10 == (char *)0x0) {
    local_10 = &DAT_005ea438;
  }
  uVar4 = 0xffffffff;
  pcVar6 = local_10;
  do {
    if (uVar4 == 0) break;
    uVar4 = uVar4 - 1;
    cVar1 = *pcVar6;
    pcVar6 = pcVar6 + 1;
  } while (cVar1 != '\0');
  iVar5 = 0;
  iVar7 = 0;
  while (((iVar2 = FUN_0047b730(iVar7), iVar7 != iVar2 && (iVar2 <= *(int *)(param_1 + 0xe4))) &&
         ((~uVar4 - 1 != iVar2 || (local_10[iVar2 + -1] == -1))))) {
    iVar5 = iVar5 + 1;
    iVar7 = iVar2;
  }
  if (*(int *)(param_1 + 200) != 0) {
    puVar3 = *(undefined1 **)(*(int *)(param_1 + 200) + 0x40);
    if (puVar3 == (undefined1 *)0x0) {
      puVar3 = &DAT_005ea438;
    }
    FUN_00498560(puVar3);
  }
  cVar1 = local_10[*(int *)(param_1 + 0xe4)];
  local_10[*(int *)(param_1 + 0xe4)] = '\0';
  FUN_004983b0(local_10 + iVar7,&local_8,local_4,1);
  local_10[*(int *)(param_1 + 0xe4)] = cVar1;
  param_2 = param_2 + iVar5;
  if (param_2 < 0) {
    param_2 = 0;
  }
  if (param_2 < iVar5) {
    iVar5 = 0;
    FUN_0047b730(0);
    iVar7 = 0;
  }
  for (; iVar2 = FUN_0047b730(iVar7), iVar5 < param_2; iVar5 = iVar5 + 1) {
    if (local_10[iVar2] == '\0') goto LAB_0047bac9;
    iVar7 = iVar2;
  }
  iVar2 = FUN_0047b910(local_8,iVar7,iVar2);
LAB_0047bac9:
  *(int *)(param_1 + 0xe4) = iVar2;
  return;
}


