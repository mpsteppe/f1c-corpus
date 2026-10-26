// Function: FUN_004d95d0 @ 004d95d0
// Size (bytes): 180


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_004d95d0(int param_1,int param_2,float param_3,float param_4)

{
  int iVar1;
  float fVar2;
  float fVar3;
  bool bVar4;
  bool bVar5;
  int iVar6;
  
  fVar2 = param_4 + _DAT_005acf68;
  bVar4 = false;
  fVar3 = param_3 + _DAT_0059e708;
  iVar6 = 0;
  bVar5 = false;
  param_4 = param_4 - _DAT_0059ec20;
  if (0 < DAT_005c329c) {
    do {
      iVar1 = (&DAT_007c54f0)[iVar6];
      if (param_1 == *(int *)(iVar1 + 0x4060)) {
        FUN_004d9690(iVar1,param_3,fVar2);
        bVar5 = true;
LAB_004d966a:
        if (bVar4) {
          return 0;
        }
      }
      else {
        if (param_2 == *(int *)(iVar1 + 0x4060)) {
          FUN_004d9690(iVar1,fVar3,param_4);
          bVar4 = true;
        }
        if (bVar5) goto LAB_004d966a;
      }
      iVar6 = iVar6 + 1;
    } while (iVar6 < DAT_005c329c);
  }
  return 0;
}


