// Function: FUN_005808d0 @ 005808d0
// Strings:  [%s%s%s, TCPReq, <<HPWsock>> ]


undefined4 __thiscall FUN_005808d0(int *param_1,undefined4 param_2,undefined4 param_3)

{
  undefined4 uVar1;
  char cVar2;
  u_short uVar3;
  u_long uVar4;
  int iVar5;
  DWORD DVar6;
  int *piVar7;
  uint uVar8;
  char *pcVar9;
  undefined4 local_80;
  undefined2 uStack_7c;
  u_short uStack_7a;
  undefined2 uStack_78;
  undefined2 uStack_76;
  char acStack_74 [4];
  char acStack_70 [4];
  sockaddr sStack_6c;
  sockaddr sStack_5c;
  char acStack_4c [64];
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  puStack_8 = &LAB_0059caa8;
  pvStack_c = ExceptionList;
  local_80 = 1;
  ExceptionList = &pvStack_c;
  (**(code **)(*param_1 + 0x48))();
  FUN_00584ff0(param_3);
  uStack_7c = 2;
  uVar4 = htonl(0);
  uStack_78 = (undefined2)uVar4;
  uStack_76 = (undefined2)(uVar4 >> 0x10);
  uStack_7a = htons(0);
  cVar2 = FUN_0057ca10(param_2,&uStack_7c);
  if (cVar2 != '\0') {
    FUN_00585680();
    iVar5 = FUN_0057c7b0(param_1[0x24f],(short)param_1[0x244]);
    if (iVar5 < 1) {
      local_80 = 1;
    }
    else {
      acStack_4c[0] = '\0';
      uStack_4 = 0;
      FUN_0058815f(acStack_4c,s__s_s_s_005c6784,PTR_DAT_005e537c,PTR_DAT_005e5384,param_1 + 0x246);
      uVar8 = 0xffffffff;
      pcVar9 = acStack_4c;
      do {
        if (uVar8 == 0) break;
        uVar8 = uVar8 - 1;
        cVar2 = *pcVar9;
        pcVar9 = pcVar9 + 1;
      } while (cVar2 != '\0');
      uVar1._2_1_ = (undefined1)uStack_76;
      uVar1._3_1_ = uStack_76._1_1_;
      uVar1._0_1_ = (undefined1)uStack_78;
      uVar1._1_1_ = uStack_78._1_1_;
      sStack_5c._0_4_ = CONCAT22(uStack_7a,uStack_7c);
      uVar3 = htons(uStack_7a);
      sStack_5c.sa_data[1] = (char)(uVar3 >> 8);
      sStack_5c.sa_data[0] = (char)uVar3;
      sStack_6c.sa_family = sStack_5c.sa_family;
      sStack_6c.sa_data[0] = (char)uVar3;
      sStack_6c.sa_data[1] = sStack_5c.sa_data[1];
      sStack_6c.sa_data[10] = acStack_70[0];
      sStack_6c.sa_data[0xb] = acStack_70[1];
      sStack_6c.sa_data[0xc] = acStack_70[2];
      sStack_6c.sa_data[0xd] = acStack_70[3];
      sStack_6c.sa_data[6] = acStack_74[0];
      sStack_6c.sa_data[7] = acStack_74[1];
      sStack_6c.sa_data[8] = acStack_74[2];
      sStack_6c.sa_data[9] = acStack_74[3];
      sStack_6c.sa_data._2_4_ = uVar1;
      iVar5 = sendto(param_1[0x24f],acStack_4c,~uVar8 - 1,0,&sStack_6c,0x10);
      if (~uVar8 - 1 == iVar5) {
        FUN_00585cd0(1);
        piVar7 = param_1 + 0x171;
        if (((HANDLE)param_1[0x186] == (HANDLE)0x0) ||
           ((DVar6 = WaitForSingleObject((HANDLE)param_1[0x186],param_1[0x187]), DVar6 != 0 &&
            (DVar6 != 0x80)))) {
          piVar7 = (int *)0x0;
        }
        *piVar7 = 0;
        *(undefined1 *)(piVar7 + 1) = 0;
        if ((HANDLE)param_1[0x186] != (HANDLE)0x0) {
          ReleaseMutex((HANDLE)param_1[0x186]);
        }
        local_80 = 0;
      }
    }
  }
  ExceptionList = pvStack_c;
  return local_80;
}


