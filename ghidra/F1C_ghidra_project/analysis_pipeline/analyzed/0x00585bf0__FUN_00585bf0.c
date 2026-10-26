// Function: FUN_00585bf0 @ 00585bf0
// Size (bytes): 196


undefined4 __fastcall FUN_00585bf0(int *param_1)

{
  char cVar1;
  undefined4 uVar2;
  int *piVar3;
  undefined4 uVar4;
  int iVar5;
  undefined4 uStack_14;
  undefined4 uStack_10;
  int iStack_c;
  int iStack_8;
  int iStack_4;
  
  (**(code **)(*param_1 + 200))();
  uVar2 = (**(code **)(*param_1 + 0x1c))();
  iStack_4 = (**(code **)(*param_1 + 0xa4))();
  iStack_c = 0;
  if (0 < iStack_4) {
    do {
      iVar5 = iStack_c;
      cVar1 = (**(code **)(*param_1 + 0xac))(iStack_c,uVar2);
      if (cVar1 != '\0') {
        uStack_10 = 0;
        uStack_14 = 0;
        FUN_005871c0(&uStack_10,&uStack_14);
        piVar3 = (int *)FUN_00585cc0();
        iStack_8 = *piVar3;
        uVar4 = FUN_00587220(uStack_10,uStack_14);
        uVar4 = FUN_005871f0(uVar4);
        iVar5 = iStack_c;
        (**(code **)(iStack_8 + 0x34))(iStack_c,uVar4);
        FUN_004b0170();
      }
      iStack_c = iVar5 + 1;
    } while (iStack_c < iStack_4);
  }
  (**(code **)(*param_1 + 0x20))(uVar2);
  (**(code **)(*param_1 + 0xcc))();
  return 1;
}


