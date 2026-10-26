// Function: FUN_00565ca0 @ 00565ca0
// Size (bytes): 169


uint __thiscall FUN_00565ca0(int *param_1,undefined4 *param_2,int param_3)

{
  undefined4 *in_EAX;
  undefined4 *puVar1;
  int iVar2;
  undefined4 *puVar3;
  
  if (param_2 != (undefined4 *)0x0) {
    puVar1 = operator_new(0x14c);
    puVar3 = (undefined4 *)0x0;
    if (puVar1 != (undefined4 *)0x0) {
      puVar1[0x51] = 0;
      puVar1[0x52] = 0xffffffff;
      *puVar1 = param_1;
      puVar3 = puVar1;
    }
    puVar1 = puVar3;
    for (iVar2 = 0x50; puVar1 = puVar1 + 1, iVar2 != 0; iVar2 = iVar2 + -1) {
      *puVar1 = *param_2;
      param_2 = param_2 + 1;
    }
    if (param_3 != 0) {
      FUN_00566650(param_3);
    }
    in_EAX = operator_new(0xc);
    if (in_EAX == (undefined4 *)0x0) {
      in_EAX = (undefined4 *)0x0;
    }
    else {
      *in_EAX = puVar3;
      in_EAX[1] = 0;
      *(undefined1 *)(in_EAX + 2) = 1;
    }
    if (*param_1 == 0) {
      *param_1 = (int)in_EAX;
      param_1[2] = (int)in_EAX;
      param_1[1] = (int)in_EAX;
      iVar2 = param_1[3];
      param_1[3] = iVar2 + 1U;
      return iVar2 + 1U & 0xffffff00;
    }
    *(undefined4 **)(param_1[1] + 4) = in_EAX;
    param_1[1] = (int)in_EAX;
    param_1[3] = param_1[3] + 1;
  }
  return (uint)in_EAX & 0xffffff00;
}


