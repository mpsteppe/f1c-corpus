// Function: FUN_0041eda0 @ 0041eda0
// Size (bytes): 346


uint __fastcall FUN_0041eda0(int param_1)

{
  bool bVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  int iVar5;
  int iVar6;
  int *piVar7;
  int local_70;
  int local_68 [26];
  
  iVar2 = FUN_004c2850();
  uVar4 = 0;
  if (iVar2 != 0) {
    iVar6 = 0;
    local_70 = 0;
    FUN_004c2850();
    iVar2 = FUN_004c11d0();
    FUN_004c2850();
    uVar3 = FUN_004c1370();
    uVar4 = uVar3;
    if (param_1 != 0) {
      piVar7 = local_68;
      for (iVar5 = 0x1a; iVar5 != 0; iVar5 = iVar5 + -1) {
        *piVar7 = 0;
        piVar7 = piVar7 + 1;
      }
      FUN_004c2850();
      iVar5 = FUN_004c1390();
      if (param_1 == iVar5) {
        local_70 = 0;
      }
      else if (0 < (int)uVar3) {
        do {
          iVar5 = iVar6;
          FUN_004c2850(iVar6);
          iVar5 = FUN_004c13a0(iVar5);
          if (param_1 == iVar5) {
            local_70 = iVar6 + 1;
          }
          iVar6 = iVar6 + 1;
        } while (iVar6 < (int)uVar3);
      }
      uVar4 = iVar2 - 1;
      iVar2 = 0;
      if (0 < (int)uVar4) {
        do {
          FUN_004c2850();
          FUN_004c1390();
          iVar6 = FUN_0041ed20();
          iVar5 = 0;
          local_68[0] = local_68[0] + iVar6;
          if (0 < (int)uVar3) {
            do {
              iVar6 = iVar5;
              FUN_004c2850(iVar5);
              FUN_004c13a0(iVar6);
              iVar6 = FUN_0041ed20();
              local_68[iVar5 + 1] = local_68[iVar5 + 1] + iVar6;
              iVar5 = iVar5 + 1;
            } while (iVar5 < (int)uVar3);
          }
          iVar6 = 0;
          bVar1 = true;
          if ((int)(uVar3 + 1) < 1) {
LAB_0041eef0:
            return CONCAT31((int3)((uint)iVar6 >> 8),1);
          }
          do {
            if ((iVar6 != local_70) && (local_68[local_70] < local_68[iVar6])) {
              bVar1 = false;
            }
            iVar6 = iVar6 + 1;
          } while (iVar6 < (int)(uVar3 + 1));
          if (bVar1) goto LAB_0041eef0;
          iVar2 = iVar2 + 1;
        } while (iVar2 < (int)uVar4);
      }
    }
  }
  return uVar4 & 0xffffff00;
}


