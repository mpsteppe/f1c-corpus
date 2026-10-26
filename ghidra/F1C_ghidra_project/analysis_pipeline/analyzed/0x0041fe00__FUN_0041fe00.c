// Function: FUN_0041fe00 @ 0041fe00
// Size (bytes): 261


int __fastcall FUN_0041fe00(undefined1 *param_1)

{
  int iVar1;
  int iVar2;
  undefined1 *puVar3;
  undefined1 *puVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  undefined4 uVar8;
  undefined1 local_50 [80];
  
  iVar5 = 0;
  iVar1 = FUN_004c2990();
  if ((iVar1 != 0) && (iVar1 = iVar1 + -1, -1 < iVar1)) {
    iVar7 = iVar1 * 4 + 0xd8;
    do {
      FUN_004c2850();
      iVar2 = FUN_004c1390();
      if (*(int *)(iVar7 + iVar2) == 10) {
        FUN_004c2850();
        FUN_004c1390();
        puVar3 = (undefined1 *)FUN_004c0a80();
        puVar4 = param_1;
      }
      else {
        iVar6 = 0;
        FUN_004c2850();
        iVar2 = FUN_004c1370();
        if (iVar2 < 1) {
          return iVar5;
        }
        while( true ) {
          uVar8 = 0x50;
          puVar4 = local_50;
          iVar2 = iVar6;
          FUN_004c2850(iVar6,puVar4,0x50);
          FUN_004c13a0(iVar2);
          FUN_004c0a20(puVar4,uVar8);
          iVar2 = iVar6;
          FUN_004c2850(iVar6);
          iVar2 = FUN_004c13a0(iVar2);
          if (*(int *)(iVar7 + iVar2) == 10) break;
          iVar6 = iVar6 + 1;
          FUN_004c2850();
          iVar2 = FUN_004c1370();
          if (iVar2 <= iVar6) {
            return iVar5;
          }
        }
        puVar4 = local_50;
        puVar3 = param_1;
      }
      iVar2 = FUN_00588410(puVar4,puVar3);
      if (iVar2 != 0) {
        return iVar5;
      }
      iVar5 = iVar5 + 1;
      iVar1 = iVar1 + -1;
      iVar7 = iVar7 + -4;
    } while (-1 < iVar1);
  }
  return iVar5;
}


