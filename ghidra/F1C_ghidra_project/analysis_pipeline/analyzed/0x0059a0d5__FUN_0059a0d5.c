// Function: FUN_0059a0d5 @ 0059a0d5
// Size (bytes): 46


undefined4 __fastcall FUN_0059a0d5(int *param_1)

{
  undefined2 *puVar1;
  int iVar2;
  undefined4 uVar3;
  
  puVar1 = *(undefined2 **)param_1[7];
  if ((puVar1 != (undefined2 *)0x0) && (puVar1 < puVar1 + *(int *)param_1[0xb])) {
    return CONCAT22((short)((uint)puVar1 >> 0x10),*puVar1);
  }
  iVar2 = *param_1;
  uVar3 = (**(code **)(iVar2 + 0x14))();
  uVar3 = (**(code **)(iVar2 + 8))(uVar3);
  return uVar3;
}


