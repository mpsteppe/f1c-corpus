// Function: FUN_004e4e60 @ 004e4e60
// Size (bytes): 218


void __thiscall FUN_004e4e60(int param_1,undefined4 param_2)

{
  float fVar1;
  undefined4 uVar2;
  undefined4 *puVar3;
  int iVar4;
  int iVar5;
  
  iVar4 = *(int *)(param_1 + 0x3498);
  fVar1 = *(float *)(param_1 + 0x3508) * *(float *)(param_1 + 0x3508);
  if (fVar1 <= *(float *)(param_1 + 0x349c)) {
    if (*(float *)(param_1 + 0x349c) <
        *(float *)(param_1 + 0x350c) * *(float *)(param_1 + 0x350c) +
        *(float *)(param_1 + 0x3504) * *(float *)(param_1 + 0x3504) + fVar1) {
      iVar4 = iVar4 + 1;
      *(undefined4 *)(param_1 + 0x34a8) = *(undefined4 *)(param_1 + 0x34a4);
      goto LAB_004e4ed2;
    }
    uVar2 = *(undefined4 *)(param_1 + 0x34a0);
  }
  else {
    uVar2 = *(undefined4 *)(param_1 + 0x34a4);
    iVar4 = iVar4 + 1;
  }
  *(undefined4 *)(param_1 + 0x34a8) = uVar2;
LAB_004e4ed2:
  puVar3 = (undefined4 *)(param_1 + 0x35f0);
  iVar5 = 4;
  do {
    *puVar3 = *(undefined4 *)(param_1 + 0x34a8);
    puVar3 = puVar3 + 0x3e;
    iVar5 = iVar5 + -1;
  } while (iVar5 != 0);
  if (iVar4 < 1) {
    *(undefined4 *)(param_1 + 0x34ac) = param_2;
    return;
  }
  do {
    FUN_004e4f40();
    FUN_004e58d0();
    FUN_004e51a0();
    FUN_004e5470();
    FUN_004e5ae0();
    iVar4 = iVar4 + -1;
  } while (iVar4 != 0);
  *(undefined4 *)(param_1 + 0x34ac) = param_2;
  return;
}


