// Function: FUN_00554c30 @ 00554c30
// Size (bytes): 137


void FUN_00554c30(int param_1)

{
  uint *puVar1;
  int iVar2;
  int iVar3;
  int *piVar4;
  
  for (iVar2 = *(int *)(param_1 + 0x24); iVar2 != 0; iVar2 = *(int *)(iVar2 + 0xc0)) {
    iVar3 = 0;
    if (0 < *(int *)(iVar2 + 0xa4)) {
      piVar4 = (int *)(*(int *)(iVar2 + 0xa8) + 0x8c);
      do {
        if (((*(byte *)(piVar4 + -0x13) & 2) != 0) &&
           (*(int *)(*(int *)(*piVar4 + 0x54) + 0x14) == 0)) {
          puVar1 = (uint *)(*(int *)(*piVar4 + 0x54) + 0x18);
          *puVar1 = *puVar1 & 0xfffffffe;
          puVar1 = (uint *)(*(int *)(*piVar4 + 0x54) + 0x18);
          *puVar1 = *puVar1 | 8;
          FUN_0053f720(*(undefined4 *)(*piVar4 + 0x54),0);
          puVar1 = (uint *)(*(int *)(*piVar4 + 0x54) + 0x18);
          *puVar1 = *puVar1 | 1;
        }
        piVar4 = piVar4 + 0x25;
        iVar3 = iVar3 + 1;
      } while (iVar3 < *(int *)(iVar2 + 0xa4));
    }
  }
  return;
}


