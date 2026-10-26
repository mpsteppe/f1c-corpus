// Function: FUN_00516883 @ 00516883
// Size (bytes): 180


void FUN_00516883(int *param_1)

{
  undefined4 uVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  int iVar4;
  
  param_1[1] = 0;
  uVar1 = FUN_0058fb7e(param_1);
  puVar2 = (undefined4 *)FUN_00519346(param_1,0x50);
  if (puVar2 == (undefined4 *)0x0) {
    FUN_00587b96(param_1);
    *(undefined4 *)(*param_1 + 0x14) = 0x35;
    *(undefined4 *)(*param_1 + 0x18) = 0;
    (**(code **)*param_1)(param_1);
  }
  else {
    *puVar2 = FUN_00515f23;
    puVar2[1] = FUN_0051601f;
    puVar2[2] = FUN_005160ad;
    puVar2[3] = FUN_0051613f;
    puVar2[4] = FUN_005161dd;
    puVar2[5] = FUN_0051623e;
    puVar2[6] = FUN_0051629f;
    puVar2[7] = FUN_00516531;
    puVar2[8] = FUN_0051664f;
    puVar2[9] = FUN_00516772;
    puVar2[10] = FUN_00516853;
    puVar2[0xb] = uVar1;
    puVar3 = puVar2 + 0xf;
    iVar4 = 2;
    do {
      puVar3[-2] = 0;
      *puVar3 = 0;
      puVar3 = puVar3 + -1;
      iVar4 = iVar4 + -1;
    } while (iVar4 != 0);
    puVar2[0x10] = 0;
    puVar2[0x11] = 0;
    puVar2[0x12] = 0x50;
    param_1[1] = (int)puVar2;
  }
  return;
}


