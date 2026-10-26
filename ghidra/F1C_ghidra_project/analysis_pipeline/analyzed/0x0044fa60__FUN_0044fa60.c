// Function: FUN_0044fa60 @ 0044fa60
// Size (bytes): 333


undefined4 __fastcall FUN_0044fa60(int param_1)

{
  int *piVar1;
  undefined4 *puVar2;
  undefined4 uVar3;
  int iVar4;
  undefined4 uStack_54;
  int *piStack_50;
  undefined *puStack_4c;
  int *piStack_48;
  int *piStack_44;
  undefined4 *puStack_40;
  undefined *puStack_3c;
  int *piStack_38;
  int *piStack_34;
  undefined1 *puStack_30;
  undefined1 *puStack_2c;
  undefined4 *puStack_28;
  undefined1 local_18 [24];
  
  puVar2 = (undefined4 *)(param_1 + 0x2f8);
  iVar4 = 8;
  do {
    puVar2[-0xb6] = 0x3d4ccccd;
    *puVar2 = 0x3f800000;
    puVar2 = puVar2 + 1;
    iVar4 = iVar4 + -1;
  } while (iVar4 != 0);
  if (*(int *)(param_1 + 0x2f4) != 0x14) {
    puStack_28 = (undefined4 *)0x1;
    puStack_2c = (undefined1 *)0x14;
    puStack_30 = &LAB_0044ed10;
    piStack_34 = (int *)0x4;
    DAT_007cb310 = 0;
    piStack_38 = DAT_007ca590;
    puStack_3c = (undefined *)0x44fab3;
    iVar4 = (**(code **)(*DAT_007ca590 + 0x10))();
    if (iVar4 != 0) {
      return 0xffffffff;
    }
    if (*(int *)(param_1 + 0x2f4) != 0x14) {
      return 0xffffffff;
    }
  }
  puStack_28 = (undefined4 *)0x0;
  puStack_2c = local_18;
  puStack_30 = (undefined1 *)(param_1 + 0x88);
  piStack_34 = DAT_007ca590;
  piStack_38 = (int *)0x44fae0;
  iVar4 = (**(code **)(*DAT_007ca590 + 0xc))();
  if (iVar4 == 0) {
    piVar1 = (int *)(param_1 + 0x80);
    puStack_3c = &DAT_005ad490;
    *piVar1 = 0;
    puStack_40 = puStack_28;
    piStack_44 = (int *)0x44faff;
    piStack_38 = piVar1;
    iVar4 = (**(code **)*puStack_28)();
    if ((iVar4 == 0) && (*piVar1 != 0)) {
      piStack_44 = piStack_34;
      piStack_48 = (int *)0x44fb19;
      (**(code **)(*piStack_34 + 8))();
      piStack_48 = (int *)*piVar1;
      puStack_4c = (undefined *)0x44fb21;
      (**(code **)(*piStack_48 + 0x20))();
      piStack_50 = (int *)*piVar1;
      puStack_4c = &DAT_005b108c;
      uStack_54 = 0x44fb2e;
      iVar4 = (**(code **)(*piStack_50 + 0x2c))();
      if (iVar4 == 0) {
        uStack_54 = 9;
        iVar4 = (**(code **)(*(int *)*piVar1 + 0x34))((int *)*piVar1,puStack_28);
        if (iVar4 == 0) {
          *(undefined4 *)(param_1 + 0x2c8) = 0x2c;
          iVar4 = (**(code **)(*(int *)*piVar1 + 0xc))
                            ((int *)*piVar1,(undefined4 *)(param_1 + 0x2c8));
          if (iVar4 == 0) {
            piStack_50 = (int *)0x10;
            uStack_54 = 0x14;
            puStack_4c = (undefined *)0x0;
            piStack_48 = (int *)0x0;
            piStack_44 = (int *)0x0;
            (**(code **)(*(int *)*piVar1 + 0x18))((int *)*piVar1,5,&uStack_54);
            (**(code **)(*(int *)*piVar1 + 0x1c))((int *)*piVar1);
            uVar3 = FUN_0044f8f0();
            return uVar3;
          }
        }
      }
    }
  }
  return 0xffffffff;
}


