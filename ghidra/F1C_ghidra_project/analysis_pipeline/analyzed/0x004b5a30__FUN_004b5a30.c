// Function: FUN_004b5a30 @ 004b5a30
// Size (bytes): 432


void __fastcall FUN_004b5a30(int param_1)

{
  int iVar1;
  undefined4 *puVar2;
  int local_4;
  
  FUN_004b6130();
  FUN_004b5e50();
  FUN_004b5f60();
  if (*(int *)(param_1 + 0xf94) != 0) {
    FUN_00587bcf(*(int *)(param_1 + 0xf94));
  }
  FUN_004b52a0();
  FUN_004ba9f0();
  FUN_004ba9f0();
  FUN_004bb4f0();
  FUN_004b0170();
  FUN_004b0170();
  if (*(int *)(param_1 + 0x72c) != 0) {
    FUN_00587bcf(*(int *)(param_1 + 0x72c));
  }
  if (*(int *)(param_1 + 0x724) != 0) {
    FUN_00587bcf(*(int *)(param_1 + 0x724));
  }
  FUN_004bb400();
  if (*(int *)(param_1 + 0x70c) != 0) {
    FUN_00587bcf(*(int *)(param_1 + 0x70c));
  }
  if (*(int *)(param_1 + 0x704) != 0) {
    FUN_00587bcf(*(int *)(param_1 + 0x704));
  }
  FUN_005668d0();
  iVar1 = *(int *)(param_1 + 0x6d4);
  while (iVar1 != 0) {
    iVar1 = *(int *)(iVar1 + 4);
    FUN_004646f0(1);
  }
  *(undefined4 *)(param_1 + 0x6d4) = 0;
  *(undefined4 *)(param_1 + 0x6d8) = 0;
  *(undefined4 *)(param_1 + 0x6dc) = 0;
  *(undefined4 *)(param_1 + 0x6e0) = 0;
  iVar1 = *(int *)(param_1 + 0x6c0);
  while (iVar1 != 0) {
    iVar1 = *(int *)(iVar1 + 4);
    FUN_004ba900(1);
  }
  *(undefined4 *)(param_1 + 0x6c0) = 0;
  *(undefined4 *)(param_1 + 0x6c4) = 0;
  *(undefined4 *)(param_1 + 0x6c8) = 0;
  *(undefined4 *)(param_1 + 0x6cc) = 0;
  local_4 = 0x68;
  puVar2 = (undefined4 *)(param_1 + 0x6c0);
  do {
    iVar1 = puVar2[-4];
    while (iVar1 != 0) {
      iVar1 = *(int *)(iVar1 + 4);
      FUN_004ba8c0(1);
    }
    local_4 = local_4 + -1;
    puVar2[-4] = 0;
    puVar2[-3] = 0;
    puVar2[-2] = 0;
    puVar2[-1] = 0;
    puVar2 = puVar2 + -4;
  } while (local_4 != 0);
  FUN_0049af30();
  FUN_0049af30();
  FUN_004bb650();
  FUN_004baeb0();
  FUN_004baeb0();
  FUN_004bb5a0();
  return;
}


