// Function: FUN_0050afe2 @ 0050afe2
// Size (bytes): 498


undefined4 * __thiscall FUN_0050afe2(undefined4 *param_1,int param_2)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  undefined4 uVar4;
  
  uVar4 = 1;
  FUN_00507496(param_2,0,1);
  *param_1 = &PTR_FUN_005adb90;
  if (*(int *)(param_2 + 0x18) == 1) {
    param_1[0x41e] = 0;
  }
  else if (*(int *)(param_2 + 0x18) == 2) {
    param_1[0x41e] = 1;
  }
  else {
    param_1[0x41e] = 3;
  }
  if (*(int *)(param_2 + 0x1c) == 1) {
    param_1[0x41f] = 0;
  }
  else if (*(int *)(param_2 + 0x1c) == 2) {
    param_1[0x41f] = 1;
  }
  else {
    param_1[0x41f] = 3;
  }
  if ((param_1[0x41e] == 3) && (param_1[0x41f] == 3)) {
    uVar4 = 0;
  }
  param_1[0x41d] = uVar4;
  iVar1 = param_1[1];
  if (iVar1 == 0x31545844) {
    param_1[0x420] = 8;
    param_1[0x422] = &LAB_005152eb;
    param_1[0x421] = FUN_00514fee;
  }
  else if (iVar1 == 0x32545844) {
    param_1[0x420] = 0x10;
    param_1[0x422] = FUN_005158af;
    param_1[0x421] = &LAB_00515869;
  }
  else if (iVar1 == 0x33545844) {
    param_1[0x420] = 0x10;
    param_1[0x422] = FUN_00515303;
    param_1[0x421] = FUN_0051512c;
  }
  else if (iVar1 == 0x34545844) {
    param_1[0x420] = 0x10;
    param_1[0x422] = FUN_005158e3;
    param_1[0x421] = &LAB_0051588c;
  }
  else if (iVar1 == 0x35545844) {
    param_1[0x420] = 0x10;
    param_1[0x422] = FUN_00515417;
    param_1[0x421] = FUN_005151af;
  }
  param_1[0x42c] = 0xffffffff;
  param_1[0x42d] = 0xffffffff;
  param_1[0x427] = param_1[0x410];
  uVar2 = param_1[0x40e] + 3 & 0xfffffffc;
  param_1[0x425] = uVar2;
  uVar3 = param_1[0x40f] + 3 & 0xfffffffc;
  param_1[0x426] = uVar3;
  param_1[0x429] = uVar2 - (param_1[0x40c] & 0xfffffffc) >> 2;
  param_1[0x428] = param_1[0x411];
  param_1[0x423] = param_1[0x40c] & 0xfffffffc;
  param_1[0x42e] = 0;
  param_1[0x42f] = 0;
  param_1[0x430] = 0;
  param_1[0x424] = param_1[0x40d] & 0xfffffffc;
  param_1[0x42a] = uVar3 - (param_1[0x40d] & 0xfffffffc) >> 2;
  param_1[0x42b] = param_1[0x411] - param_1[0x410];
  return param_1;
}


