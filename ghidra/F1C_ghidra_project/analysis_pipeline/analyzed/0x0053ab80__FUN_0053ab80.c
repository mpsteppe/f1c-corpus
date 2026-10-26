// Function: FUN_0053ab80 @ 0053ab80
// Size (bytes): 186


void __thiscall FUN_0053ab80(int *param_1,int param_2)

{
  int iVar1;
  int iVar2;
  int iVar3;
  float10 fVar4;
  
  param_1[2] = param_2;
  if ((undefined4 *)param_1[3] != (undefined4 *)0x0) {
    *(undefined4 *)param_1[3] = 0;
    *(undefined4 *)(param_1[3] + 4) = 0;
    iVar3 = 1;
    if (1 < *param_1) {
      do {
        fVar4 = (float10)FUN_005881f0();
        *(float *)(param_1[3] + iVar3 * 8) = (float)fVar4;
        iVar1 = iVar3 * 8;
        iVar2 = param_1[3] + iVar3 * 8;
        iVar3 = iVar3 + 1;
        *(float *)(iVar2 + 4) = *(float *)(param_1[3] + iVar1) - *(float *)(iVar2 + -8);
      } while (iVar3 < *param_1);
    }
    fVar4 = (float10)FUN_005881f0();
    *(float *)(param_1[3] + *param_1 * 8) = (float)fVar4;
    iVar3 = param_1[3] + *param_1 * 8;
    *(float *)(iVar3 + 4) = *(float *)(param_1[3] + *param_1 * 8) - *(float *)(iVar3 + -8);
    *(undefined4 *)(param_1[3] + 8 + *param_1 * 8) = *(undefined4 *)(param_1[3] + *param_1 * 8);
    *(undefined4 *)(param_1[3] + 0xc + *param_1 * 8) = 0;
  }
  return;
}


