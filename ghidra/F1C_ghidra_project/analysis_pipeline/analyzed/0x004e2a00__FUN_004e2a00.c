// Function: FUN_004e2a00 @ 004e2a00
// Size (bytes): 95


void FUN_004e2a00(int param_1,float param_2,char param_3)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  do {
    iVar1 = FUN_0054c210();
    iVar3 = 0;
    if (0 < iVar1) {
      do {
        iVar2 = FUN_0054c230(iVar3);
        iVar3 = iVar3 + 1;
        *(float *)(iVar2 + 0xf4) = param_2 * *(float *)(iVar2 + 0xf4);
        *(float *)(iVar2 + 0xf8) = param_2 * *(float *)(iVar2 + 0xf8);
      } while (iVar3 < iVar1);
    }
  } while ((param_3 != '\0') && (param_1 = *(int *)(param_1 + 0x4c), param_1 != 0));
  return;
}


