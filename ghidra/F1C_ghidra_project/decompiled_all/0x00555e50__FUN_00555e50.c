// Function: FUN_00555e50 @ 00555e50
// Strings:  [%s - 0x%X, %s - 0x%X, Could not set display mode, Could not set display mode]


undefined4 __fastcall FUN_00555e50(int *param_1)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 uStack_12c;
  undefined4 uStack_128;
  int *piStack_124;
  int *piStack_120;
  undefined4 uStack_11c;
  undefined4 uStack_118;
  undefined4 uStack_114;
  undefined4 uStack_110;
  undefined4 uStack_3c;
  int iStack_1c;
  
  uVar2 = 0;
  uStack_110 = 0;
  uStack_114 = 0;
  piStack_120 = (int *)param_1[0x440];
  uStack_118 = 0;
  uStack_11c = 0;
  piStack_124 = (int *)0x555e6d;
  iVar1 = (**(code **)(*piStack_120 + 0x3c))();
  *param_1 = iVar1;
  if (iVar1 != -0x7789f798) {
    return 0;
  }
  piStack_124 = (int *)param_1[0x440];
  uStack_128 = 0x555e86;
  iVar1 = (**(code **)(*piStack_124 + 0xc))();
  *param_1 = iVar1;
  if (iVar1 != -0x7789f797) {
    return 0;
  }
  uStack_128 = 0;
  uStack_12c = 0;
  iVar1 = (**(code **)(*(int *)param_1[0x440] + 0x7c))((int *)param_1[0x440]);
  *param_1 = iVar1;
  FUN_0053f6e0(param_1[0x54b]);
  FUN_0053f270(iStack_1c);
  iVar1 = (**(code **)(*(int *)param_1[0x440] + 0x38))((int *)param_1[0x440],param_1 + 0x441);
  *param_1 = iVar1;
  if (iVar1 == 0) {
    iVar1 = (**(code **)(*(int *)param_1[0x440] + 0x40))
                      ((int *)param_1[0x440],0,0,param_1[0x54a] + 0xc);
    *param_1 = iVar1;
    iVar1 = (**(code **)(**(int **)(param_1[0x54a] + 0xc) + 8))(*(int **)(param_1[0x54a] + 0xc));
    *param_1 = iVar1;
    switch(param_1[0x445]) {
    case 2:
      uVar2 = 0x20;
      break;
    case 3:
      uVar2 = 0x100;
      break;
    case 4:
      uVar2 = 0x40;
      break;
    case 0x10:
      uVar2 = 0x100000;
    }
    iVar1 = FUN_0053f3f0(uStack_3c,param_1[0x54a],param_1[0x54b],uVar2);
    *param_1 = iVar1;
    iVar1 = (**(code **)(*(int *)param_1[0x440] + 0x7c))
                      ((int *)param_1[0x440],*(undefined4 *)(param_1[0x54a] + 0xc),
                       *(undefined4 *)(param_1[0x54b] + 0xc));
    *param_1 = iVar1;
    FUN_0053eb70(iStack_1c);
    if (iStack_1c != 0) {
      FUN_005458d0(2);
    }
    return 0xfffffffe;
  }
  if (iVar1 == -0x7789f798) {
    iVar1 = (**(code **)(*(int *)param_1[0x440] + 0xc))((int *)param_1[0x440]);
    *param_1 = iVar1;
    if (iVar1 != -0x7789f797) goto LAB_00555f1f;
    iVar1 = -0x7789f797;
  }
  FUN_0058815f(&uStack_12c,s__s___0x_X_005dbce4,s_Could_not_set_display_mode_005dbcf0,iVar1);
LAB_00555f1f:
  FUN_0053c590(0xffffffff,&uStack_12c);
  return 0xffffffff;
}


