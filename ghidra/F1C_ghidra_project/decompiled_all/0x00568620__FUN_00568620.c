// Function: FUN_00568620 @ 00568620
// Strings:  [%c%c%x%x]


int __fastcall FUN_00568620(byte *param_1,char *param_2,int param_3)

{
  byte bVar1;
  char cVar2;
  undefined4 in_EAX;
  int iVar3;
  uint3 uVar4;
  uint uVar5;
  uint uVar6;
  int iVar7;
  byte *pbVar8;
  byte *pbVar9;
  char *pcVar10;
  char *pcVar11;
  byte local_8 [4];
  undefined1 local_4;
  
  uVar4 = (uint3)((uint)in_EAX >> 8);
  if ((param_1 == (byte *)0x0) || (param_2 == (char *)0x0)) {
    return (uint)uVar4 << 8;
  }
  *param_2 = '\0';
  bVar1 = *param_1;
  do {
    if (bVar1 == 0) {
      return CONCAT31(uVar4,1);
    }
    cVar2 = FUN_005687f0();
    if (cVar2 == '\0') {
      cVar2 = FUN_00568750();
      if (cVar2 == '\0') {
        if (*param_1 != 0x2b) goto LAB_005686b1;
        cVar2 = FUN_005685b0();
        if (cVar2 == '\0') {
          local_8[1] = 0;
          local_8[0] = *param_1;
        }
        else {
          local_8[0] = *param_1;
          pbVar8 = param_1 + 2;
          local_8[1] = param_1[1];
          local_4 = 0;
          pbVar9 = param_1 + 3;
          param_1 = param_1 + 3;
          local_8[2] = *pbVar8;
          local_8[3] = *pbVar9;
        }
      }
      else {
        local_8[0] = *param_1;
        local_8[1] = 0;
      }
    }
    else {
LAB_005686b1:
      FUN_0058815f(local_8,s__c_c_x_x_005e5184,0x2b,0x7e,*param_1 >> 4,*param_1 & 0xf);
    }
    uVar5 = 0xffffffff;
    pcVar10 = param_2;
    do {
      if (uVar5 == 0) break;
      uVar5 = uVar5 - 1;
      cVar2 = *pcVar10;
      pcVar10 = pcVar10 + 1;
    } while (cVar2 != '\0');
    uVar6 = 0xffffffff;
    pbVar9 = local_8;
    do {
      if (uVar6 == 0) break;
      uVar6 = uVar6 - 1;
      bVar1 = *pbVar9;
      pbVar9 = pbVar9 + 1;
    } while (bVar1 != 0);
    iVar3 = param_3;
    if ((int)(~uVar5 + (~uVar6 - 2)) < param_3) {
      uVar5 = 0xffffffff;
      iVar3 = 0;
      pbVar9 = local_8;
      do {
        pbVar8 = pbVar9;
        if (uVar5 == 0) break;
        uVar5 = uVar5 - 1;
        pbVar8 = pbVar9 + 1;
        bVar1 = *pbVar9;
        pbVar9 = pbVar8;
      } while (bVar1 != 0);
      uVar5 = ~uVar5;
      iVar7 = -1;
      pcVar10 = param_2;
      do {
        pcVar11 = pcVar10;
        if (iVar7 == 0) break;
        iVar7 = iVar7 + -1;
        pcVar11 = pcVar10 + 1;
        cVar2 = *pcVar10;
        pcVar10 = pcVar11;
      } while (cVar2 != '\0');
      pbVar9 = pbVar8 + -uVar5;
      pbVar8 = (byte *)(pcVar11 + -1);
      for (uVar6 = uVar5 >> 2; uVar6 != 0; uVar6 = uVar6 - 1) {
        *(undefined4 *)pbVar8 = *(undefined4 *)pbVar9;
        pbVar9 = pbVar9 + 4;
        pbVar8 = pbVar8 + 4;
      }
      for (uVar5 = uVar5 & 3; uVar5 != 0; uVar5 = uVar5 - 1) {
        *pbVar8 = *pbVar9;
        pbVar9 = pbVar9 + 1;
        pbVar8 = pbVar8 + 1;
      }
    }
    bVar1 = param_1[1];
    uVar4 = (uint3)((uint)iVar3 >> 8);
    param_1 = param_1 + 1;
  } while( true );
}


