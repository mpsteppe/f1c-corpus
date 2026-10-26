// Function: FUN_0040a890 @ 0040a890
// Size (bytes): 91


undefined1 __thiscall FUN_0040a890(int param_1,int param_2)

{
  int iVar1;
  int iVar2;
  
  if ((param_2 == 0) ||
     (((((param_2 != *(int *)(param_1 + 0x10) && (param_2 != *(int *)(param_1 + 0x14))) &&
        (param_2 != *(int *)(param_1 + 0x18))) &&
       ((param_2 != *(int *)(param_1 + 0x1c) && (param_2 != *(int *)(param_1 + 0x24))))) &&
      ((param_2 != *(int *)(param_1 + 0x28) &&
       ((param_2 != *(int *)(param_1 + 0x2c) && (param_2 != *(int *)(param_1 + 0x30))))))))) {
    iVar2 = 0;
    if (*(int *)(param_1 + 0x38) < 1) {
      return 0;
    }
    iVar1 = *(int *)(param_1 + 0x20);
    while (iVar1 != param_2) {
      iVar2 = iVar2 + 1;
      iVar1 = iVar1 + 200;
      if (*(int *)(param_1 + 0x38) <= iVar2) {
        return 0;
      }
    }
  }
  return 1;
}


