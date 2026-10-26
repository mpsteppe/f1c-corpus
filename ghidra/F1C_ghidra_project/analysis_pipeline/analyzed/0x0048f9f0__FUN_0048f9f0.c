// Function: FUN_0048f9f0 @ 0048f9f0
// Size (bytes): 245


void __fastcall FUN_0048f9f0(int param_1)

{
  char *_Source;
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  undefined4 *puVar4;
  char local_40;
  undefined4 local_3f;
  undefined1 local_1;
  
  local_40 = DAT_005ea438;
  puVar4 = &local_3f;
  for (iVar3 = 0xf; iVar3 != 0; iVar3 = iVar3 + -1) {
    *puVar4 = 0;
    puVar4 = puVar4 + 1;
  }
  *(undefined2 *)puVar4 = 0;
  *(undefined1 *)((int)puVar4 + 2) = 0;
  _Source = *(char **)(param_1 + 0xb8);
  if (_Source == (char *)0x0) {
    _Source = &DAT_005ea438;
  }
  _strncpy(&local_40,_Source,0x3f);
  local_1 = 0;
  iVar3 = FUN_005897ca(&local_40,&DAT_005c32d8);
  if (iVar3 != 0) {
    uVar1 = FUN_00587f59(iVar3);
    *(undefined4 *)(param_1 + 0x154) = uVar1;
  }
  iVar3 = FUN_005897ca(0,&DAT_005c32d8);
  if (iVar3 != 0) {
    uVar1 = FUN_00587f59(iVar3);
    *(undefined4 *)(param_1 + 0x150) = uVar1;
  }
  iVar3 = FUN_005897ca(0,&DAT_005c32d8);
  if (iVar3 != 0) {
    iVar2 = FUN_00588410(iVar3,&DAT_005cc21c);
    if (iVar2 == 0) {
      *(undefined4 *)(param_1 + 0xe0) = 0;
    }
    iVar2 = FUN_00588410(iVar3,&DAT_005cc210);
    if (iVar2 == 0) {
      *(undefined4 *)(param_1 + 0xe0) = 1;
    }
    iVar3 = FUN_00588410(iVar3,&DAT_005c36f0);
    if (iVar3 == 0) {
      *(undefined4 *)(param_1 + 0xe0) = 2;
    }
  }
  return;
}


