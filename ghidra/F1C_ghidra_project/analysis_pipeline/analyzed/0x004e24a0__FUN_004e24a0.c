// Function: FUN_004e24a0 @ 004e24a0
// Size (bytes): 156


void __thiscall FUN_004e24a0(int param_1,int param_2,float param_3,undefined4 param_4,float param_5)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  
  param_3 = param_3 - *(float *)(param_1 + 0x4c);
  param_2 = param_2 * 0x128;
  *(float *)(param_2 + 0x14c + param_1) = param_3;
  *(float *)(param_2 + 400 + param_1) = param_3;
  param_5 = param_5 + *(float *)(param_2 + 0x1cc + param_1);
  param_1 = param_2 + 0xd4 + param_1;
  *(undefined4 *)(param_1 + 0xfc) = param_4;
  if (param_5 != *(float *)(param_1 + 200)) {
    *(float *)(param_1 + 200) = param_5;
    FUN_005670d0(param_5,*(undefined4 *)(param_1 + 0xcc));
  }
  puVar2 = (undefined4 *)(param_1 + 0xd0);
  puVar3 = (undefined4 *)(param_1 + 0x8c);
  for (iVar1 = 9; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar3 = *puVar2;
    puVar2 = puVar2 + 1;
    puVar3 = puVar3 + 1;
  }
  FUN_00567340(param_4,param_1 + 0x80);
  return;
}


