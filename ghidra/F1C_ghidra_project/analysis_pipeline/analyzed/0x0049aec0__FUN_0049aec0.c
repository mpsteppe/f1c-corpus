// Function: FUN_0049aec0 @ 0049aec0
// Size (bytes): 112


undefined4 __thiscall
FUN_0049aec0(undefined4 *param_1,int param_2,undefined2 *param_3,undefined2 *param_4)

{
  undefined2 uVar1;
  undefined2 *puVar2;
  
  if ((param_2 < 0) || ((int)param_1[3] <= param_2)) {
    param_1[2] = 0;
  }
  else {
    param_1[2] = *param_1;
    while ((0 < param_2 && (param_1[2] != 0))) {
      param_2 = param_2 + -1;
      param_1[2] = *(undefined4 *)(param_1[2] + 4);
    }
  }
  if (((undefined4 *)param_1[2] != (undefined4 *)0x0) &&
     (puVar2 = *(undefined2 **)param_1[2], puVar2 != (undefined2 *)0x0)) {
    *param_3 = *puVar2;
    uVar1 = puVar2[1];
    *param_4 = uVar1;
    return CONCAT31((uint3)(byte)((ushort)uVar1 >> 8),1);
  }
  *param_3 = 0;
  *param_4 = 0;
  return 0;
}


