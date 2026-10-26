// Function: FUN_0053cfe0 @ 0053cfe0
// Size (bytes): 324


undefined4 FUN_0053cfe0(int *param_1,char *param_2,undefined4 param_3)

{
  byte bVar1;
  char cVar2;
  char *pcVar3;
  byte *pbVar4;
  void *pvVar5;
  int iVar6;
  uint uVar7;
  int iVar8;
  byte *pbVar9;
  bool bVar10;
  byte local_100 [256];
  
  pcVar3 = param_2;
  do {
    cVar2 = *pcVar3;
    pcVar3[(int)(local_100 + -(int)param_2)] = cVar2;
    pcVar3 = pcVar3 + 1;
  } while (cVar2 != '\0');
  FUN_00589901(local_100);
  uVar7 = 0xffffffff;
  pbVar4 = local_100;
  do {
    if (uVar7 == 0) break;
    uVar7 = uVar7 - 1;
    bVar1 = *pbVar4;
    pbVar4 = pbVar4 + 1;
  } while (bVar1 != 0);
  iVar8 = ~uVar7 - 2;
  do {
    iVar6 = DAT_008b8e20;
    if (iVar8 < 1) {
joined_r0x0053d04a:
      do {
        if (iVar6 == 0) {
          pvVar5 = operator_new(0x874);
          if (pvVar5 == (void *)0x0) {
            iVar8 = 0;
          }
          else {
            iVar8 = FUN_005523e0();
          }
          iVar6 = FUN_00552470(param_2,param_3);
          if (iVar6 == 0) {
            FUN_0053d340(iVar8);
            if (param_1 != (int *)0x0) {
              *param_1 = iVar8;
            }
            return 0;
          }
          if (iVar8 != 0) {
            FUN_00557470();
            FUN_00587bcf(iVar8);
          }
          return 0xffffffff;
        }
        pbVar9 = local_100;
        pbVar4 = (byte *)(iVar6 + 0x14);
        do {
          bVar1 = *pbVar4;
          bVar10 = bVar1 < *pbVar9;
          if (bVar1 != *pbVar9) {
LAB_0053d07b:
            iVar8 = (1 - (uint)bVar10) - (uint)(bVar10 != 0);
            goto LAB_0053d080;
          }
          if (bVar1 == 0) break;
          bVar1 = pbVar4[1];
          bVar10 = bVar1 < pbVar9[1];
          if (bVar1 != pbVar9[1]) goto LAB_0053d07b;
          pbVar4 = pbVar4 + 2;
          pbVar9 = pbVar9 + 2;
        } while (bVar1 != 0);
        iVar8 = 0;
LAB_0053d080:
        if (iVar8 == 0) {
          if (param_1 == (int *)0x0) {
            return 0;
          }
          *param_1 = iVar6;
          return 0;
        }
        iVar6 = *(int *)(iVar6 + 0x870);
      } while( true );
    }
    if (local_100[iVar8] == 0x2e) {
      local_100[iVar8] = 0;
      goto joined_r0x0053d04a;
    }
    iVar8 = iVar8 + -1;
  } while( true );
}


