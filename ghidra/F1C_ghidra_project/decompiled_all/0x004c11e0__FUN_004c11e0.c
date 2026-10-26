// Function: FUN_004c11e0 @ 004c11e0
// Strings:  [RaceLaps, RaceTime, QualifyLaps, SceneOrder, QualifyTime]


int __thiscall FUN_004c11e0(int param_1,int param_2)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = FUN_00568210(s_SceneOrder_005d28b4);
  if (iVar1 != 0) {
    iVar1 = thunk_FUN_0059d6a9(param_2);
    if (iVar1 != 0) {
      uVar2 = FUN_00499e20();
      iVar1 = FUN_004c5840(uVar2);
      if (iVar1 != 0) {
        uVar2 = FUN_00499e20();
        FUN_004c55b0(uVar2);
        iVar1 = DAT_008ac48c * 0x18c + DAT_008ac490;
        FUN_00566650(iVar1 + 0x104);
        FUN_00566650(iVar1 + 4);
        iVar1 = FUN_005679c0(s_QualifyLaps_005d231c);
        if (iVar1 == 0) {
          *(undefined4 *)(param_1 + 0xb130) = 0xffffffff;
        }
        else {
          uVar2 = FUN_00567970();
          uVar2 = FUN_00587ece(uVar2);
          *(undefined4 *)(param_1 + 0xb130) = uVar2;
        }
        iVar1 = FUN_005679c0(s_QualifyTime_005d28c0);
        if (iVar1 == 0) {
          *(undefined4 *)(param_1 + 0xb134) = 0xffffffff;
        }
        else {
          uVar2 = FUN_00567970();
          uVar2 = FUN_00587ece(uVar2);
          *(undefined4 *)(param_1 + 0xb134) = uVar2;
        }
        iVar1 = FUN_005679c0(s_RaceLaps_005c7444);
        if (iVar1 == 0) {
          *(undefined4 *)(param_1 + 0xb138) = 0xffffffff;
        }
        else {
          uVar2 = FUN_00567970();
          uVar2 = FUN_00587ece(uVar2);
          *(undefined4 *)(param_1 + 0xb138) = uVar2;
        }
        iVar1 = FUN_005679c0(s_RaceTime_005d2310);
        if (iVar1 == 0) {
          *(undefined4 *)(param_1 + 0xb13c) = 0xffffffff;
        }
        else {
          uVar2 = FUN_00567970();
          uVar2 = FUN_00587ece(uVar2);
          *(undefined4 *)(param_1 + 0xb13c) = uVar2;
        }
        if (param_2 < *(int *)(param_1 + 0xb148)) {
          *(undefined4 *)(param_1 + 0xb140) = *(undefined4 *)(param_1 + 0xaf84 + param_2 * 4);
          return param_1 + 0xb120;
        }
        *(undefined4 *)(param_1 + 0xb140) = 0xffffffff;
        return param_1 + 0xb120;
      }
    }
  }
  return 0;
}


