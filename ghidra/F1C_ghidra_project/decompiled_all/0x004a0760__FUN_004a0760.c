// Function: FUN_004a0760 @ 004a0760
// Strings:  [windrivers.bik, winRace.bik]


undefined4 FUN_004a0760(void)

{
  char cVar1;
  undefined1 *puVar2;
  int iVar3;
  int iVar4;
  undefined1 auStack_100 [256];
  
  if (DAT_005eb10c != (int *)0x0) {
    (**(code **)(*DAT_005eb10c + 0xc))();
  }
  FUN_004186a0();
  FUN_004b17b0();
  cVar1 = FUN_0042bc10();
  if (((cVar1 != '\0') && (*(int *)(DAT_007c54e8 + 0x4060) == 1)) && (DAT_007d032c == 1)) {
    puVar2 = DAT_005ec418;
    if (DAT_005ec418 == (undefined1 *)0x0) {
      puVar2 = &DAT_005ea438;
    }
    FUN_0058815f(auStack_100,&DAT_005be860,puVar2,s_winRace_bik_005cd00c);
    FUN_004f9b70(auStack_100,1);
  }
  iVar3 = FUN_004c2850();
  if (iVar3 != 0) {
    FUN_004c15a0();
    iVar3 = FUN_004c2760();
    if (iVar3 == 3) {
      iVar3 = FUN_004c1390();
      if ((iVar3 != 0) && (*(int *)(iVar3 + 0x19c) == 0)) {
        FUN_004c2c10();
        if (DAT_007d032c == 1) {
          puVar2 = DAT_005ec418;
          if (DAT_005ec418 == (undefined1 *)0x0) {
            puVar2 = &DAT_005ea438;
          }
          FUN_0058815f(auStack_100,&DAT_005be860,puVar2,s_windrivers_bik_005ccffc);
          FUN_004f9b70(auStack_100,1);
        }
      }
    }
    else {
      FUN_004c2a80();
      FUN_004c2810();
    }
  }
  iVar3 = (**(code **)(*DAT_007cd8c0 + 0x1c))(0x28);
  iVar4 = (**(code **)(*DAT_007cd8c0 + 0x1c))(0x2a);
  if (iVar3 != 0) {
    FUN_0047c360(1);
  }
  if (iVar4 != 0) {
    FUN_0047c360(0);
  }
  FUN_0041daf0();
  DAT_005cc9e8 = 3;
  return 0;
}


