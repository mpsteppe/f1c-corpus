// Function: FUN_00547920 @ 00547920
// Size (bytes): 464


int __thiscall FUN_00547920(int param_1,char *param_2)

{
  char cVar1;
  byte bVar2;
  int iVar3;
  char *pcVar4;
  byte *pbVar5;
  int iVar6;
  int iVar7;
  char *pcVar8;
  byte *pbVar9;
  byte *pbVar10;
  bool bVar11;
  int local_204;
  byte local_200 [256];
  byte local_100 [256];
  
  local_204 = 0;
  iVar3 = -(int)param_2;
  do {
    cVar1 = *param_2;
    param_2[(int)(local_100 + iVar3)] = cVar1;
    param_2 = param_2 + 1;
  } while (cVar1 != '\0');
  FUN_00589901(local_100);
  iVar3 = FUN_00547af0();
  if (iVar3 != 0) {
    local_204 = 1;
  }
  iVar3 = *(int *)(param_1 + 0x28);
  if (iVar3 == 0) {
    return 0;
  }
  do {
    if (*(int *)(iVar3 + 0x4c) == 1) {
      pcVar4 = (char *)(iVar3 + 4);
      iVar6 = -(int)pcVar4;
      do {
        cVar1 = *pcVar4;
        pcVar4[(int)(local_200 + iVar6)] = cVar1;
        pcVar4 = pcVar4 + 1;
      } while (cVar1 != '\0');
      FUN_00589901(local_200);
      if (local_204 != 0) {
        FUN_00547af0();
      }
      pbVar9 = local_100;
      pbVar5 = local_200;
      do {
        bVar2 = *pbVar5;
        bVar11 = bVar2 < *pbVar9;
        if (bVar2 != *pbVar9) {
LAB_00547a0b:
          iVar6 = (1 - (uint)bVar11) - (uint)(bVar11 != 0);
          goto LAB_00547a10;
        }
        if (bVar2 == 0) break;
        bVar2 = pbVar5[1];
        bVar11 = bVar2 < pbVar9[1];
        if (bVar2 != pbVar9[1]) goto LAB_00547a0b;
        pbVar5 = pbVar5 + 2;
        pbVar9 = pbVar9 + 2;
      } while (bVar2 != 0);
      iVar6 = 0;
LAB_00547a10:
      if (iVar6 == 0) {
        return iVar3;
      }
    }
    else {
      iVar6 = 0;
      if (0 < *(int *)(iVar3 + 0x4c)) {
        pcVar4 = (char *)(iVar3 + 4);
        pbVar5 = local_200 + (-4 - iVar3);
        pcVar8 = pcVar4;
        do {
          do {
            cVar1 = *pcVar4;
            pcVar4[(int)pbVar5] = cVar1;
            pcVar4 = pcVar4 + 1;
          } while (cVar1 != '\0');
          FUN_00589901(local_200);
          if (local_204 != 0) {
            FUN_00547af0();
          }
          pbVar10 = local_100;
          pbVar9 = local_200;
          do {
            bVar2 = *pbVar9;
            bVar11 = bVar2 < *pbVar10;
            if (bVar2 != *pbVar10) {
LAB_00547a99:
              iVar7 = (1 - (uint)bVar11) - (uint)(bVar11 != 0);
              goto LAB_00547a9e;
            }
            if (bVar2 == 0) break;
            bVar2 = pbVar9[1];
            bVar11 = bVar2 < pbVar10[1];
            if (bVar2 != pbVar10[1]) goto LAB_00547a99;
            pbVar9 = pbVar9 + 2;
            pbVar10 = pbVar10 + 2;
          } while (bVar2 != 0);
          iVar7 = 0;
LAB_00547a9e:
          if (iVar7 == 0) {
            return iVar6 * 0x60 + iVar3;
          }
          iVar6 = iVar6 + 1;
          pbVar5 = pbVar5 + -0x60;
          pcVar4 = pcVar8 + 0x60;
          pcVar8 = pcVar4;
        } while (iVar6 < *(int *)(iVar3 + 0x4c));
      }
    }
    iVar3 = *(int *)(iVar3 + 0x5c);
    if (iVar3 == 0) {
      return 0;
    }
  } while( true );
}


