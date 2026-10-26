// Function: FUN_00432bf0 @ 00432bf0
// Strings:  [Track, Session, Classes, AutoLoadEntry]


undefined4 __thiscall FUN_00432bf0(undefined4 *param_1,int *param_2)

{
  undefined4 uVar1;
  undefined1 *puVar2;
  
  uVar1 = 1;
  if ((param_2 != (int *)0x0) && (*param_2 != 0)) {
    FUN_00566c30(param_2,&DAT_005c4064,PTR_s_AutoLoadEntry_005c3f88);
    FUN_00566c30(param_2,&DAT_005c4060);
    puVar2 = (undefined1 *)*param_1;
    if (puVar2 == (undefined1 *)0x0) {
      puVar2 = &DAT_005ea438;
    }
    FUN_00566c30(param_2,s__s___s__005c4054,PTR_s_Track_005c3f8c,puVar2);
    puVar2 = (undefined1 *)param_1[2];
    if (puVar2 == (undefined1 *)0x0) {
      puVar2 = &DAT_005ea438;
    }
    FUN_00566c30(param_2,s__s___s__005c4054,PTR_s_Classes_005c3f90,puVar2);
    FUN_00566c30(param_2,s__s__d_005c4048,PTR_s_Session_005c3f94,param_1[4]);
    puVar2 = (undefined1 *)param_1[5];
    if (puVar2 == (undefined1 *)0x0) {
      puVar2 = &DAT_005ea438;
    }
    FUN_00566c30(param_2,s__s___s__005c4054,PTR_DAT_005c3f98,puVar2);
    FUN_00566c30(param_2,&DAT_005c4044);
    uVar1 = 0;
  }
  return uVar1;
}


