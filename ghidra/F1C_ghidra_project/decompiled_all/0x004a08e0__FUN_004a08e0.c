// Function: FUN_004a08e0 @ 004a08e0
// Strings:  [winconstructors.bik]


undefined4 FUN_004a08e0(void)

{
  int iVar1;
  undefined1 *puVar2;
  undefined1 local_180 [128];
  undefined1 local_100 [256];
  
  iVar1 = FUN_004c2760();
  if (iVar1 == 3) {
    iVar1 = FUN_004c2850();
    if (iVar1 != 0) {
      iVar1 = FUN_004c1390();
      if (iVar1 != 0) {
        FUN_004c0a20(local_180,0x80);
        iVar1 = FUN_004c1450(local_180);
        if ((iVar1 == 1) && (DAT_007d032c == 1)) {
          puVar2 = DAT_005ec418;
          if (DAT_005ec418 == (undefined1 *)0x0) {
            puVar2 = &DAT_005ea438;
          }
          FUN_0058815f(local_100,&DAT_005be860,puVar2,s_winconstructors_bik_005cd018);
          FUN_004f9b70(local_100,1);
        }
      }
    }
  }
  FUN_0041e320();
  return 0;
}


