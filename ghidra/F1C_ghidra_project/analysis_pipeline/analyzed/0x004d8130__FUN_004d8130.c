// Function: FUN_004d8130 @ 004d8130
// Size (bytes): 230


void FUN_004d8130(float param_1,char param_2)

{
  char cVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  uint uVar5;
  char cVar6;
  char *pcVar7;
  char *pcVar8;
  char *pcVar9;
  char local_28 [8];
  char local_20 [32];
  
  cVar6 = DAT_005d4a60;
  if (param_2 == '\0') {
    cVar6 = DAT_005d4a61;
  }
  iVar2 = 0;
  do {
    cVar1 = (&DAT_005ea438)[iVar2];
    local_20[iVar2] = cVar1;
    iVar2 = iVar2 + 1;
  } while (cVar1 != '\0');
  iVar2 = 0;
  if (0 < DAT_005d4a64) {
    do {
      FUN_0058815f(local_28,&DAT_005ccef0,iVar2 + cVar6);
      uVar3 = 0xffffffff;
      pcVar7 = local_28;
      do {
        pcVar9 = pcVar7;
        if (uVar3 == 0) break;
        uVar3 = uVar3 - 1;
        pcVar9 = pcVar7 + 1;
        cVar1 = *pcVar7;
        pcVar7 = pcVar9;
      } while (cVar1 != '\0');
      uVar3 = ~uVar3;
      iVar4 = -1;
      pcVar7 = local_20;
      do {
        pcVar8 = pcVar7;
        if (iVar4 == 0) break;
        iVar4 = iVar4 + -1;
        pcVar8 = pcVar7 + 1;
        cVar1 = *pcVar7;
        pcVar7 = pcVar8;
      } while (cVar1 != '\0');
      pcVar7 = pcVar9 + -uVar3;
      pcVar9 = pcVar8 + -1;
      for (uVar5 = uVar3 >> 2; uVar5 != 0; uVar5 = uVar5 - 1) {
        *(undefined4 *)pcVar9 = *(undefined4 *)pcVar7;
        pcVar7 = pcVar7 + 4;
        pcVar9 = pcVar9 + 4;
      }
      iVar2 = iVar2 + 1;
      for (uVar3 = uVar3 & 3; uVar3 != 0; uVar3 = uVar3 - 1) {
        *pcVar9 = *pcVar7;
        pcVar7 = pcVar7 + 1;
        pcVar9 = pcVar9 + 1;
      }
    } while (iVar2 < DAT_005d4a64);
  }
  if (param_1 < DAT_0059e440 != (param_1 == DAT_0059e440)) {
    param_1 = 0.001;
  }
  FUN_004d7e40(local_20,0x280,0x3ce,0xffffff,2,3,0x3f800000,param_1);
  return;
}


