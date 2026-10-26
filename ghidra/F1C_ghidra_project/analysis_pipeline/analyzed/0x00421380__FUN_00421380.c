// Function: FUN_00421380 @ 00421380
// Size (bytes): 219


int __fastcall FUN_00421380(int param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  undefined1 *puVar5;
  undefined4 uVar6;
  int local_54;
  undefined1 local_50 [80];
  
  iVar3 = 0;
  local_54 = 0;
  if (param_1 != 0) {
    FUN_004c2850();
    iVar1 = FUN_004c1370();
    if (0 < iVar1) {
      do {
        uVar6 = 0x50;
        puVar5 = local_50;
        iVar1 = iVar3;
        FUN_004c2850(iVar3,puVar5,0x50);
        FUN_004c13a0(iVar1);
        FUN_004c0a20(puVar5,uVar6);
        iVar1 = FUN_00566810();
        if (iVar1 != 0) {
          iVar4 = 0;
          FUN_004c2850();
          iVar1 = FUN_004c11d0();
          if (0 < iVar1) {
            iVar1 = 0xd8;
            do {
              iVar2 = iVar3;
              FUN_004c2850(iVar3);
              iVar2 = FUN_004c13a0(iVar2);
              if (*(int *)(iVar1 + iVar2) == 10) {
                local_54 = local_54 + 1;
              }
              iVar4 = iVar4 + 1;
              iVar1 = iVar1 + 4;
              FUN_004c2850();
              iVar2 = FUN_004c11d0();
            } while (iVar4 < iVar2);
          }
        }
        iVar3 = iVar3 + 1;
        FUN_004c2850();
        iVar1 = FUN_004c1370();
      } while (iVar3 < iVar1);
    }
    return local_54;
  }
  return 0;
}


