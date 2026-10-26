// Function: FUN_0044ee10 @ 0044ee10
// Size (bytes): 427


int __thiscall FUN_0044ee10(int *param_1,undefined4 param_2,undefined4 param_3,int param_4)

{
  undefined1 *puVar1;
  int *piVar2;
  int iVar3;
  int iVar4;
  int *piVar5;
  undefined4 *unaff_EBX;
  int *unaff_EDI;
  int *piStack_64;
  undefined1 *puStack_60;
  int iStack_5c;
  int *piStack_58;
  undefined4 *puStack_54;
  undefined *puStack_50;
  int *piStack_4c;
  int *piStack_48;
  undefined *puStack_44;
  undefined1 *puStack_40;
  undefined4 uStack_3c;
  int *piStack_38;
  undefined4 uStack_34;
  undefined1 *puStack_30;
  int iStack_2c;
  undefined4 uStack_28;
  undefined1 auStack_8 [8];
  
  piVar2 = param_1 + 0xdf;
  piVar5 = param_1 + 0x11f;
  do {
    *(undefined1 *)(piVar2 + -0x40) = 1;
    *(undefined1 *)piVar2 = 0;
    *piVar5 = 0;
    piVar5 = piVar5 + 1;
    piVar2 = (int *)((int)piVar2 + 1);
  } while ((int)((-0x37c - (int)param_1) + (int)piVar2) < 0x100);
  uStack_28 = 1;
  iStack_2c = 0x13;
  puStack_30 = &LAB_0044ed10;
  param_1[799] = -0x41000000;
  param_1[800] = -0x42333333;
  *param_1 = param_4;
  uStack_34 = 0x13;
  piStack_38 = DAT_007ca590;
  uStack_3c = 0x44ee7f;
  iVar3 = (**(code **)(*DAT_007ca590 + 0x10))();
  if ((iVar3 == 0) && (param_1[0x9e] == 0x13)) {
    uStack_3c = 0;
    puStack_40 = auStack_8;
    puStack_44 = &DAT_005ad3f0;
    piStack_48 = DAT_007ca590;
    piStack_4c = (int *)0x44eeab;
    iVar3 = (**(code **)(*DAT_007ca590 + 0xc))();
    if (iVar3 == 0) {
      piVar2 = param_1 + 1;
      *piVar2 = 0;
      puStack_50 = &DAT_005ad490;
      piStack_58 = (int *)0x44eec7;
      puStack_54 = unaff_EBX;
      piStack_4c = piVar2;
      iVar3 = (**(code **)*unaff_EBX)();
      if ((iVar3 == 0) && (*piVar2 != 0)) {
        iStack_5c = 0x44eee2;
        piStack_58 = unaff_EDI;
        (**(code **)(*unaff_EDI + 8))();
        iVar3 = iStack_2c;
        puVar1 = puStack_30;
        piStack_64 = (int *)*piVar2;
        uStack_28 = 0;
        iStack_5c = (uint)(iStack_2c != 0) * 4 + 0x16;
        puStack_60 = puStack_30;
        iVar4 = (**(code **)(*piStack_64 + 0x34))();
        if ((iVar4 != 0) &&
           (iVar3 = (**(code **)(*(int *)*piVar2 + 0x34))
                              ((int *)*piVar2,puVar1,(iVar3 == 0) * '\x04' + '\x16'), iVar3 != 0)) {
          return -1;
        }
        param_1[0x93] = 0x2c;
        iVar3 = (**(code **)(*(int *)*piVar2 + 0xc))((int *)*piVar2,param_1 + 0x93);
        if ((iVar3 == 0) &&
           (iVar3 = (**(code **)(*(int *)*piVar2 + 0x2c))((int *)*piVar2,&DAT_005b0e84), iVar3 == 0)
           ) {
          if (*param_1 == 1) {
            iStack_5c = 0;
            piStack_58 = (int *)0x0;
            piStack_64 = (int *)0x14;
            puStack_60 = (undefined1 *)0x10;
            puStack_54 = (undefined4 *)0x400;
            iVar3 = (**(code **)(*(int *)*piVar2 + 0x18))((int *)*piVar2,1,&piStack_64);
            if (iVar3 != 0) {
              return -1;
            }
          }
          iVar3 = (**(code **)(*(int *)*piVar2 + 0x1c))((int *)*piVar2);
          return -(uint)(iVar3 != 0);
        }
      }
      else {
        *piVar2 = 0;
      }
    }
  }
  return -1;
}


