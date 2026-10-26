// Function: FUN_00599dd9 @ 00599dd9
// Size (bytes): 136


int __thiscall FUN_00599dd9(int *param_1,undefined2 *param_2,undefined4 *param_3)

{
  undefined2 *puVar1;
  short sVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  undefined2 *puVar5;
  int local_8;
  
  local_8 = 0;
  while( true ) {
    while( true ) {
      if ((int)param_3 < 1) {
        return local_8;
      }
      puVar3 = (undefined4 *)param_1[8];
      puVar5 = (undefined2 *)*puVar3;
      if ((puVar5 == (undefined2 *)0x0) ||
         (puVar3 = (undefined4 *)((*(int *)param_1[0xc] << 1) >> 1), (int)puVar3 < 1)) break;
      puVar1 = param_2;
      puVar4 = puVar3;
      if ((int)param_3 < (int)puVar3) {
        puVar3 = param_3;
        puVar4 = param_3;
      }
      for (; puVar3 != (undefined4 *)0x0; puVar3 = (undefined4 *)((int)puVar3 + -1)) {
        *puVar5 = *puVar1;
        puVar5 = puVar5 + 1;
        puVar1 = puVar1 + 1;
      }
      local_8 = local_8 + (int)puVar4;
      param_3 = (undefined4 *)((int)param_3 - (int)puVar4);
      param_2 = param_2 + (int)puVar4;
      FUN_0059a428(puVar4);
    }
    sVar2 = (**(code **)(*param_1 + 4))(CONCAT22((short)((uint)puVar3 >> 0x10),*param_2));
    if (sVar2 == -1) break;
    param_2 = param_2 + 1;
    local_8 = local_8 + 1;
    param_3 = (undefined4 *)((int)param_3 + -1);
  }
  return local_8;
}


