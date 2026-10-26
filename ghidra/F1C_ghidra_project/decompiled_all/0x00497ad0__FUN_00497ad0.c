// Function: FUN_00497ad0 @ 00497ad0
// Strings:  [Unable to load surface "%s"]


undefined1 * __thiscall FUN_00497ad0(int param_1,int param_2,char param_3)

{
  int iVar1;
  undefined1 *puVar2;
  int iVar3;
  undefined1 *puVar4;
  
  if (param_2 == 0) {
    return (undefined1 *)0x0;
  }
  puVar2 = (undefined1 *)FUN_00497ba0(param_2);
  if (puVar2 == (undefined1 *)0x0) {
    iVar3 = FUN_00495890(param_2);
    if (iVar3 == 0) {
      if (param_3 == '\0') {
        return (undefined1 *)0x0;
      }
      FUN_0058815f(&DAT_007cde38,s_Unable_to_load_surface___s__005cca5c,param_2);
      FUN_004986d0(&DAT_007cde38);
    }
    iVar1 = *(int *)(param_1 + 0x104);
    puVar4 = operator_new(0x14);
    puVar2 = (undefined1 *)0x0;
    if (puVar4 != (undefined1 *)0x0) {
      *(undefined4 *)(puVar4 + 4) = 0;
      *(undefined4 *)(puVar4 + 8) = 0xffffffff;
      *(undefined4 *)(puVar4 + 0xc) = 0;
      *(undefined4 *)(puVar4 + 0x10) = 0;
      *puVar4 = 1;
      puVar2 = puVar4;
    }
    *(int *)(puVar2 + 0xc) = iVar3;
    FUN_00566650(param_2);
    if (iVar1 == 0) {
      *(undefined1 **)(param_1 + 0x104) = puVar2;
    }
    else {
      for (iVar3 = *(int *)(iVar1 + 0x10); iVar3 != 0; iVar3 = *(int *)(iVar3 + 0x10)) {
        iVar1 = iVar3;
      }
      *(undefined1 **)(iVar1 + 0x10) = puVar2;
    }
    *(int *)(param_1 + 0x108) = *(int *)(param_1 + 0x108) + 1;
  }
  return puVar2;
}


