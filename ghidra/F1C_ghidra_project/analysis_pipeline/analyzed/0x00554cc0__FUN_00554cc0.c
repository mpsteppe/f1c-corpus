// Function: FUN_00554cc0 @ 00554cc0
// Size (bytes): 175


void FUN_00554cc0(int param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int *piVar4;
  
  for (iVar1 = *(int *)(param_1 + 0x24); iVar1 != 0; iVar1 = *(int *)(iVar1 + 0xc0)) {
    iVar3 = 0;
    if (0 < *(int *)(iVar1 + 0xa4)) {
      piVar4 = (int *)(*(int *)(iVar1 + 0xa8) + 0x8c);
      do {
        if ((*(byte *)(piVar4 + -0x13) & 2) != 0) {
          iVar2 = *(int *)(*(int *)(*piVar4 + 0x54) + 4);
          if (iVar2 != 0) {
            FUN_0053f6e0(iVar2);
            iVar2 = *(int *)(*(int *)(*piVar4 + 0x54) + 4);
            if (iVar2 != 0) {
              FUN_00557470();
              FUN_00587bcf(iVar2);
            }
            *(undefined4 *)(*(int *)(*piVar4 + 0x54) + 4) = 0;
          }
          FUN_00554d70(*piVar4);
        }
        piVar4 = piVar4 + 0x25;
        iVar3 = iVar3 + 1;
      } while (iVar3 < *(int *)(iVar1 + 0xa4));
    }
  }
  return;
}


