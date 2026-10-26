// Function: FUN_0046c750 @ 0046c750
// Size (bytes): 86


undefined4 FUN_0046c750(char param_1,int param_2)

{
  undefined4 uVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  undefined4 *puVar5;
  
  puVar3 = &DAT_007cd2b8;
  if (param_1 == '\0') {
    puVar3 = &DAT_007cd470;
  }
  uVar1 = puVar3[param_2];
  if (param_2 < 0x67) {
    puVar4 = puVar3 + param_2 + 1;
    puVar5 = puVar3 + param_2;
    for (iVar2 = 0x67 - param_2; iVar2 != 0; iVar2 = iVar2 + -1) {
      *puVar5 = *puVar4;
      puVar4 = puVar4 + 1;
      puVar5 = puVar5 + 1;
    }
    puVar3[(0x67 - param_2) + param_2] = 0xffffffff;
    return uVar1;
  }
  puVar3[param_2] = 0xffffffff;
  return uVar1;
}


