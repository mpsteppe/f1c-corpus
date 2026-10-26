// Function: FUN_00498d90 @ 00498d90
// Size (bytes): 91


void __fastcall FUN_00498d90(undefined4 *param_1)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  
  iVar1 = param_1[0x12];
  *param_1 = &PTR_FUN_005ac9e8;
  while (iVar1 != 0) {
    iVar1 = *(int *)(iVar1 + 0x48);
    if ((undefined4 *)param_1[0x12] != (undefined4 *)0x0) {
      (*(code *)**(undefined4 **)param_1[0x12])(1);
    }
    param_1[0x12] = iVar1;
  }
  puVar3 = (undefined4 *)FUN_00498f60();
  while (puVar2 = puVar3, puVar2 != (undefined4 *)0x0) {
    puVar3 = (undefined4 *)FUN_00486320();
    if (puVar2 != (undefined4 *)0x0) {
      (**(code **)*puVar2)(1);
    }
  }
  FUN_0049a990();
  return;
}


