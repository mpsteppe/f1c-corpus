// Function: FUN_004b0540 @ 004b0540
// Size (bytes): 472


undefined4 __fastcall FUN_004b0540(int param_1)

{
  char cVar1;
  DWORD DVar2;
  char *pcVar3;
  undefined1 *puVar4;
  int iVar5;
  undefined4 *puVar6;
  undefined4 uVar7;
  undefined1 local_21c [28];
  char local_200;
  undefined4 local_1ff;
  
  local_200 = DAT_005ea438;
  puVar6 = &local_1ff;
  for (iVar5 = 0x7f; iVar5 != 0; iVar5 = iVar5 + -1) {
    *puVar6 = 0;
    puVar6 = puVar6 + 1;
  }
  *(undefined2 *)puVar6 = 0;
  *(undefined1 *)((int)puVar6 + 2) = 0;
  FUN_005668b0();
  DVar2 = GetFileAttributesA((LPCSTR)(param_1 + 0x14));
  if ((DVar2 & 1) != 0) {
    *(undefined4 *)(param_1 + 0x114) = 1;
  }
  FUN_00568620(0x200);
  cVar1 = FUN_00566b20(&local_200,1);
  if (cVar1 == '\0') {
    FUN_005668d0();
    return 0xffffffff;
  }
  FUN_00568910(0x200);
  pcVar3 = &local_200;
  do {
    cVar1 = *pcVar3;
    pcVar3[(param_1 + 0x14) - (int)&local_200] = cVar1;
    pcVar3 = pcVar3 + 1;
  } while (cVar1 != '\0');
  if ((DAT_007cb710 & 1) == 0) {
    uVar7 = 1;
  }
  else {
    uVar7 = 2;
  }
  FUN_004ae750(uVar7);
  FUN_004a1d10(local_21c);
  *(uint *)(param_1 + 0x1f00) = (uint)(0 < *(int *)(param_1 + 0x1f00));
  if ((*(char *)(param_1 + 0x2f08) != '\0') && (*(int *)(param_1 + 0x2f8c) < 0x22)) {
    *(undefined4 *)(param_1 + 0x2f8c) = 0x22;
  }
  if ((*(char *)(param_1 + 0x2ed8) != '\0') && (*(int *)(param_1 + 0x2f8c) < 0x21)) {
    *(undefined4 *)(param_1 + 0x2f8c) = 0x21;
  }
  puVar4 = *(undefined1 **)(param_1 + 0x138);
  if (puVar4 == (undefined1 *)0x0) {
    puVar4 = &DAT_005ea438;
  }
  FUN_004c5690(puVar4);
  iVar5 = *(int *)(param_1 + 0x24f8 + *(int *)(param_1 + 0x1f78) * 0x24);
  cVar1 = FUN_0042bc10();
  DAT_005c329c = (uint)(cVar1 != '\0') + iVar5;
  if (DAT_005c329c < 1) {
    DAT_005c329c = 1;
  }
  else if (0x68 < DAT_005c329c) {
    DAT_005c329c = 0x68;
  }
  if (*(int *)(param_1 + 0x1f78) == 5) {
    DAT_005c329c = 0;
  }
  FUN_0042bc80();
  FUN_004b0720();
  FUN_004b0ef0(*(undefined4 *)(param_1 + 0x1f78));
  FUN_00432e70();
  puVar4 = *(undefined1 **)(param_1 + 0x1b4);
  if (puVar4 == (undefined1 *)0x0) {
    puVar4 = &DAT_005ea438;
  }
  FUN_00415730(puVar4);
  FUN_005668d0();
  return 0;
}


