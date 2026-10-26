// Function: FUN_0041f220 @ 0041f220
// Size (bytes): 288


int __fastcall FUN_0041f220(int param_1,int param_2)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  undefined1 *puVar6;
  undefined4 uVar7;
  undefined1 local_50 [80];
  
  FUN_004c2850();
  iVar1 = FUN_004c1370();
  iVar4 = 0;
  if (param_1 == 0) {
    return -1;
  }
  if (param_2 != -1) {
    iVar5 = 0;
    if (0 < param_2) {
      do {
        uVar7 = 0x50;
        puVar6 = local_50;
        FUN_004c2850(puVar6,0x50);
        FUN_004c1390();
        FUN_004c0a20(puVar6,uVar7);
        iVar2 = FUN_00566810();
        if (iVar2 != 0) {
          FUN_004c2850();
          FUN_004c1390();
          iVar2 = FUN_0041ed20();
          iVar4 = iVar4 + iVar2;
        }
        iVar2 = 0;
        if (0 < iVar1) {
          do {
            uVar7 = 0x50;
            puVar6 = local_50;
            iVar3 = iVar2;
            FUN_004c2850(iVar2,puVar6,0x50);
            FUN_004c13a0(iVar3);
            FUN_004c0a20(puVar6,uVar7);
            iVar3 = FUN_00566810();
            if (iVar3 != 0) {
              iVar3 = iVar2;
              FUN_004c2850(iVar2);
              FUN_004c13a0(iVar3);
              iVar3 = FUN_0041ed20();
              iVar4 = iVar4 + iVar3;
            }
            iVar2 = iVar2 + 1;
          } while (iVar2 < iVar1);
        }
        iVar5 = iVar5 + 1;
      } while (iVar5 < param_2);
    }
    return iVar4;
  }
  FUN_004c2850(param_1);
  iVar1 = FUN_004c13c0(param_1);
  return iVar1;
}


