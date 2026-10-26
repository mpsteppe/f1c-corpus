// Function: FUN_00560230 @ 00560230
// Size (bytes): 269


undefined4 __thiscall FUN_00560230(int param_1,char *param_2)

{
  char cVar1;
  byte bVar2;
  char *pcVar3;
  byte *pbVar4;
  int iVar5;
  int iVar6;
  byte *pbVar7;
  byte *pbVar8;
  int iVar9;
  bool bVar10;
  byte local_100 [256];
  
  pcVar3 = param_2;
  do {
    cVar1 = *pcVar3;
    pcVar3[(int)(local_100 + -(int)param_2)] = cVar1;
    pcVar3 = pcVar3 + 1;
  } while (cVar1 != '\0');
  pcVar3 = _strrchr(param_2,0x5c);
  if (pcVar3 != (char *)0x0) {
    pcVar3 = _strrchr(param_2,0x5c);
    pcVar3 = pcVar3 + 1;
    iVar9 = -(int)pcVar3;
    do {
      cVar1 = *pcVar3;
      pcVar3[(int)(local_100 + iVar9)] = cVar1;
      pcVar3 = pcVar3 + 1;
    } while (cVar1 != '\0');
  }
  FUN_00589901(local_100);
  iVar9 = 0;
  if (0 < *(int *)(param_1 + 0x118)) {
    iVar6 = *(int *)(param_1 + 0x128);
    pbVar7 = (byte *)(iVar6 + 0x14);
    do {
      pbVar4 = local_100;
      pbVar8 = pbVar7;
      do {
        bVar2 = *pbVar4;
        bVar10 = bVar2 < *pbVar8;
        if (bVar2 != *pbVar8) {
LAB_005602da:
          iVar5 = (1 - (uint)bVar10) - (uint)(bVar10 != 0);
          goto LAB_005602df;
        }
        if (bVar2 == 0) break;
        bVar2 = pbVar4[1];
        bVar10 = bVar2 < pbVar8[1];
        if (bVar2 != pbVar8[1]) goto LAB_005602da;
        pbVar4 = pbVar4 + 2;
        pbVar8 = pbVar8 + 2;
      } while (bVar2 != 0);
      iVar5 = 0;
LAB_005602df:
      if (iVar5 == 0) {
        *(int *)(param_1 + 0x124) = iVar9;
        FUN_00587f64(*(undefined4 *)(param_1 + 0x10),*(int *)(iVar6 + 4) + *(int *)(param_1 + 0x11c)
                     ,0);
        return 0;
      }
      iVar9 = iVar9 + 1;
      iVar6 = iVar6 + 0x100;
      pbVar7 = pbVar7 + 0x100;
    } while (iVar9 < *(int *)(param_1 + 0x118));
  }
  return 0xfffffffe;
}


