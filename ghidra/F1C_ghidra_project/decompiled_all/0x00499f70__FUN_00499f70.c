// Function: FUN_00499f70 @ 00499f70
// Strings:  [Options Frame Add Error, Could not load "%s"]


undefined4 * __thiscall
FUN_00499f70(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,undefined4 param_5
            ,int param_6,char param_7,char param_8,int param_9)

{
  int iVar1;
  int iVar2;
  void *pvVar3;
  undefined4 *puVar4;
  CHAR local_80 [128];
  
  if (param_6 == 0) {
    return (undefined4 *)0x0;
  }
  iVar2 = FUN_00497ad0(param_6,0);
  if (iVar2 == 0) {
    if (param_8 != '\0') {
      FUN_0058815f(local_80,s_Could_not_load___s__005ccb30,param_6);
      MessageBoxA((HWND)0x0,local_80,s_Options_Frame_Add_Error_005ccb18,0);
    }
    return (undefined4 *)0x0;
  }
  pvVar3 = operator_new(0x34);
  if (pvVar3 == (void *)0x0) {
    puVar4 = (undefined4 *)0x0;
  }
  else {
    puVar4 = (undefined4 *)FUN_00499b10();
  }
  puVar4[1] = param_5;
  puVar4[3] = param_3;
  *puVar4 = param_4;
  puVar4[2] = param_2;
  puVar4[9] = 0;
  puVar4[8] = iVar2;
  if (param_7 != '\0') {
    puVar4[2] = 0;
    *puVar4 = 0;
    puVar4[1] = *(undefined4 *)(*(int *)(iVar2 + 0xc) + 0x1c);
    puVar4[3] = *(undefined4 *)(*(int *)(iVar2 + 0xc) + 0x20);
  }
  if (param_9 != 0) {
    for (iVar2 = *(int *)(param_1 + 8); iVar2 != 0; iVar2 = *(int *)(iVar2 + 0x24)) {
      if (iVar2 == param_9) {
        *(int *)(param_9 + 0x10) = *(int *)(param_9 + 0x10) + 1;
        puVar4[6] = *(undefined4 *)(param_9 + 0x18);
        if (*(int *)(param_9 + 0x28) != 0) {
          iVar2 = *(int *)(param_9 + 0x28);
          while (iVar1 = iVar2, iVar1 != 0) {
            param_9 = iVar1;
            iVar2 = *(int *)(iVar1 + 0x28);
          }
          *(undefined4 **)(param_9 + 0x28) = puVar4;
          return puVar4;
        }
        *(undefined4 **)(param_9 + 0x28) = puVar4;
        return puVar4;
      }
    }
  }
  iVar2 = *(int *)(param_1 + 8);
  if (iVar2 != 0) {
    for (iVar1 = *(int *)(iVar2 + 0x24); iVar1 != 0; iVar1 = *(int *)(iVar1 + 0x24)) {
      iVar2 = iVar1;
    }
    *(undefined4 **)(iVar2 + 0x24) = puVar4;
    *(int *)(param_1 + 0xc) = *(int *)(param_1 + 0xc) + 1;
    return puVar4;
  }
  *(undefined4 **)(param_1 + 8) = puVar4;
  *(int *)(param_1 + 0xc) = *(int *)(param_1 + 0xc) + 1;
  return puVar4;
}


