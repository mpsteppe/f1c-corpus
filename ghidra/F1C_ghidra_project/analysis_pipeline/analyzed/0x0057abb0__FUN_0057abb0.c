// Function: FUN_0057abb0 @ 0057abb0
// Size (bytes): 248


undefined4 FUN_0057abb0(void)

{
  void *pvVar1;
  undefined4 *puVar2;
  int iVar3;
  undefined4 *puVar4;
  undefined4 *puVar5;
  undefined4 uVar6;
  char cStack00000034;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puVar5 = _cStack00000034;
  local_4 = 0xffffffff;
  puStack_8 = &LAB_0059c79b;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *_cStack00000034 = 0;
  _cStack00000034 = (undefined4 *)((uint)_cStack00000034 & 0xffffff00);
  pvVar1 = operator_new(4);
  local_4 = 0;
  if (pvVar1 == (void *)0x0) {
    puVar2 = (undefined4 *)0x0;
  }
  else {
    puVar2 = (undefined4 *)FUN_0057a420(&stack0x00000004,&stack0x00000034);
  }
  local_4 = 0xffffffff;
  if ((cStack00000034 == '\0') && (iVar3 = (**(code **)(*(int *)*puVar2 + 0x48))(), iVar3 == 0)) {
    puVar4 = (undefined4 *)FUN_00585cc0();
    (**(code **)*puVar4)();
    FUN_004b0170();
    *puVar5 = puVar2;
    puVar5 = operator_new(0x10);
    if (puVar5 == (undefined4 *)0x0) {
      puVar5 = (undefined4 *)0x0;
    }
    else {
      *puVar5 = puVar2;
      puVar5[1] = 0;
      puVar5[2] = 0;
      *(undefined1 *)(puVar5 + 3) = 1;
    }
    puVar2 = puVar5;
    puVar4 = puVar5;
    if (DAT_008d3bfc != (undefined4 *)0x0) {
      DAT_008d3c00[1] = puVar5;
      puVar5[2] = DAT_008d3c00;
      puVar2 = DAT_008d3bfc;
      puVar4 = DAT_008d3c04;
    }
    DAT_008d3c04 = puVar4;
    DAT_008d3bfc = puVar2;
    DAT_008d3c08 = DAT_008d3c08 + 1;
    uVar6 = 0;
    DAT_008d3c00 = puVar5;
  }
  else {
    uVar6 = 1;
  }
  ExceptionList = local_c;
  return uVar6;
}


