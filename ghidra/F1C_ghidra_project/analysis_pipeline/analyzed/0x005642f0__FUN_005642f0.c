// Function: FUN_005642f0 @ 005642f0
// Size (bytes): 133


undefined4 * __fastcall
FUN_005642f0(undefined4 param_1,undefined2 param_2,undefined4 param_3,undefined4 param_4)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  
  puVar1 = _malloc(0x14);
  *puVar1 = param_1;
  *(undefined2 *)(puVar1 + 1) = param_2;
  *(undefined2 *)((int)puVar1 + 6) = 9999;
  puVar1[2] = param_3;
  switch(param_3) {
  case 0:
    uVar2 = 2;
    break;
  case 1:
    uVar2 = 2;
    break;
  case 2:
  case 3:
    uVar2 = 2;
    break;
  default:
    uVar2 = 4;
  }
  uVar2 = FUN_005646d0(uVar2,&LAB_005645f0,&LAB_00564620,0);
  puVar1[3] = uVar2;
  puVar1[4] = param_4;
  return puVar1;
}


