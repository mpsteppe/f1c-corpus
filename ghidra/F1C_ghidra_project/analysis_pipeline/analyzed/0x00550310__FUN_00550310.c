// Function: FUN_00550310 @ 00550310
// Size (bytes): 141


void __thiscall FUN_00550310(int param_1,float param_2)

{
  int iVar1;
  int iVar2;
  uint *puVar3;
  float10 fVar4;
  
  for (iVar1 = *(int *)(*(int *)(param_1 + 0x110) + 0x24); iVar1 != 0;
      iVar1 = *(int *)(iVar1 + 0xc0)) {
    if ((*(uint *)(iVar1 + 0x9c) & 0x400) != 0) {
      iVar2 = 0;
      if (0 < *(int *)(iVar1 + 0xa4)) {
        puVar3 = (uint *)(*(int *)(iVar1 + 0xa8) + 0x40);
        do {
          if (1 < (int)puVar3[2]) {
            if ((float)puVar3[7] < (float)puVar3[6]) {
              fVar4 = (float10)param_2 + (float10)(float)puVar3[7];
              *puVar3 = *puVar3 & 0xfffffffb;
            }
            else {
              *puVar3 = *puVar3 | 4;
              fVar4 = (float10)FUN_0058957a();
            }
            puVar3[7] = (uint)(float)fVar4;
          }
          puVar3 = puVar3 + 0x25;
          iVar2 = iVar2 + 1;
        } while (iVar2 < *(int *)(iVar1 + 0xa4));
      }
    }
  }
  return;
}


