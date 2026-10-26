// Function: FUN_0059b2f0 @ 0059b2f0
// Size (bytes): 145


undefined4 * __thiscall
FUN_0059b2f0(undefined4 *param_1,uint param_2,int param_3,int param_4,int param_5)

{
  undefined4 *puVar1;
  undefined2 *puVar2;
  uint uVar3;
  undefined2 *puVar4;
  int iVar5;
  
  puVar1 = operator_new(param_2);
  uVar3 = param_2 >> 2;
  *param_1 = puVar1;
  param_1[1] = param_2;
  for (; uVar3 != 0; uVar3 = uVar3 - 1) {
    *puVar1 = 0;
    puVar1 = puVar1 + 1;
  }
  for (param_2 = param_2 & 3; param_2 != 0; param_2 = param_2 - 1) {
    *(undefined1 *)puVar1 = 0;
    puVar1 = (undefined4 *)((int)puVar1 + 1);
  }
  puVar2 = operator_new(param_4 * 4);
  if (puVar2 == (undefined2 *)0x0) {
    puVar2 = (undefined2 *)0x0;
  }
  else {
    puVar4 = puVar2;
    iVar5 = param_4;
    if (-1 < param_4 + -1) {
      do {
        puVar4[1] = 0;
        *puVar4 = 0;
        iVar5 = iVar5 + -1;
        puVar4 = puVar4 + 2;
      } while (iVar5 != 0);
    }
  }
  param_1[2] = puVar2;
  param_1[3] = param_4;
  param_1[4] = 0;
  param_1[5] = 0;
  if (param_3 == 0) {
    param_3 = 1;
  }
  param_1[6] = param_3;
  if (param_5 == 0) {
    param_5 = 1;
  }
  param_1[7] = param_5;
  return param_1;
}


