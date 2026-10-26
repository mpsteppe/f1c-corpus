// Function: FUN_0053d750 @ 0053d750
// Strings:  [Error creating DirectDraw primary device]


undefined4 __fastcall FUN_0053d750(undefined4 *param_1)

{
  int *piVar1;
  undefined4 uVar2;
  int iVar3;
  undefined4 *puVar4;
  
  if (param_1[0x43f] != 0) {
    piVar1 = (int *)param_1[0x440];
    if (piVar1 != (int *)0x0) {
      uVar2 = (**(code **)(*piVar1 + 8))(piVar1);
      *param_1 = uVar2;
      param_1[0x440] = 0;
      puVar4 = param_1 + 0x441;
      for (iVar3 = 0xd; iVar3 != 0; iVar3 = iVar3 + -1) {
        *puVar4 = 0;
        puVar4 = puVar4 + 1;
      }
    }
    uVar2 = (**(code **)(*(int *)param_1[0x43f] + 8))((int *)param_1[0x43f]);
    *param_1 = uVar2;
    param_1[0x43f] = 0;
  }
  param_1[2] = 0;
  param_1[1] = 0;
  param_1[0x44e] = 0;
  iVar3 = Direct3DCreate8(0xdc);
  param_1[0x43f] = iVar3;
  if (iVar3 != 0) {
    iVar3 = param_1[0x4f8];
    if (iVar3 == 0) {
      param_1[0x4f7] = 0;
    }
    else if ((iVar3 == 1) || (iVar3 == 2)) {
      param_1[0x4f7] = 1;
    }
    FUN_00540760();
    param_1[0x53c] = 0;
    param_1[0x4fa] = 0;
    param_1[0x4fb] = 0;
    param_1[0x4fc] = 0;
    param_1[0x4fd] = 0;
    param_1[0x4fe] = 0;
    param_1[0x4ff] = 0;
    param_1[0x500] = 0;
    param_1[0x501] = 0;
    param_1[0x546] = 0;
    param_1[0x560] = 0;
    return 0;
  }
  FUN_0053c590(0xffffffff,s_Error_creating_DirectDraw_primar_005dbc30);
  return 0xffffffff;
}


