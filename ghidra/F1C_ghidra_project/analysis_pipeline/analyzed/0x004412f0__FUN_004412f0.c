// Function: FUN_004412f0 @ 004412f0
// Size (bytes): 111


void __fastcall FUN_004412f0(int param_1)

{
  undefined4 *puVar1;
  int iVar2;
  int iVar3;
  undefined4 *puVar4;
  undefined4 *puVar5;
  
  *(undefined4 *)(param_1 + 0x1c5c) = *(undefined4 *)(param_1 + 0x1c64);
  *(undefined4 *)(param_1 + 0x1c60) = *(undefined4 *)(param_1 + 0x1c68);
  *(undefined4 *)(param_1 + 0x1e38) = *(undefined4 *)(param_1 + 0x1e40);
  *(undefined4 *)(param_1 + 0x1e3c) = *(undefined4 *)(param_1 + 0x1e44);
  puVar1 = (undefined4 *)(param_1 + 0x338);
  iVar3 = 4;
  do {
    *puVar1 = puVar1[2];
    puVar1[1] = puVar1[3];
    puVar1[4] = puVar1[6];
    puVar1[5] = puVar1[7];
    puVar4 = puVar1 + 0x16;
    puVar5 = puVar1 + 0xe;
    puVar1 = puVar1 + 0x119;
    iVar3 = iVar3 + -1;
    for (iVar2 = 8; iVar2 != 0; iVar2 = iVar2 + -1) {
      *puVar5 = *puVar4;
      puVar4 = puVar4 + 1;
      puVar5 = puVar5 + 1;
    }
  } while (iVar3 != 0);
  return;
}


