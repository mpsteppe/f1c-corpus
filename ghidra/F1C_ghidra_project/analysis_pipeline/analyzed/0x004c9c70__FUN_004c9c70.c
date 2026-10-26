// Function: FUN_004c9c70 @ 004c9c70
// Size (bytes): 153


int __thiscall FUN_004c9c70(int param_1,float param_2,float param_3,int *param_4)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  float *pfVar5;
  
  iVar2 = 0;
  iVar3 = DAT_005c329c;
  if (0 < DAT_005c329c) {
    do {
      iVar1 = iVar3 + iVar2 >> 1;
      iVar4 = iVar1;
      if (*(float *)(param_1 + 0x1a0 + iVar1 * 4) <= param_2 - param_3) {
        iVar2 = iVar1 + 1;
        iVar4 = iVar3;
      }
      iVar3 = iVar4;
    } while (iVar2 < iVar4);
    if (iVar2 < DAT_005c329c) {
      iVar2 = iVar1;
      if (iVar1 < DAT_005c329c) {
        pfVar5 = (float *)(param_1 + 0x1a0 + iVar1 * 4);
        do {
          if (param_2 + param_3 < *pfVar5) break;
          iVar2 = iVar2 + 1;
          pfVar5 = pfVar5 + 1;
        } while (iVar2 < DAT_005c329c);
      }
      *param_4 = iVar2 - iVar1;
      return param_1 + iVar1 * 4;
    }
  }
  *param_4 = 0;
  return 0;
}


