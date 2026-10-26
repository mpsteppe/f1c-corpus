// Function: FUN_004c9c00 @ 004c9c00
// Size (bytes): 100


void __fastcall FUN_004c9c00(int *param_1)

{
  int iVar1;
  int *piVar2;
  int iVar3;
  int iVar4;
  
  iVar1 = DAT_005c329c;
  if (0 < DAT_005c329c) {
    piVar2 = param_1;
    iVar4 = DAT_005c329c;
    do {
      *piVar2 = *(int *)(((int)&DAT_007c54f0 - (int)param_1) + (int)piVar2) + 0xc;
      piVar2 = piVar2 + 1;
      iVar4 = iVar4 + -1;
    } while (iVar4 != 0);
  }
  FUN_005890aa(param_1,iVar1,4,&LAB_004c9ba0);
  iVar4 = 0;
  if (0 < iVar1) {
    do {
      iVar3 = iVar4 + 1;
      param_1[iVar4 + 0x68] =
           (int)(*(float *)(param_1[iVar4] + 0x740) + *(float *)(param_1[iVar4] + 0x738));
      iVar4 = iVar3;
    } while (iVar3 < iVar1);
  }
  return;
}


