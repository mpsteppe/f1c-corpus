// Function: FUN_0042eaa0 @ 0042eaa0
// Size (bytes): 180


void __thiscall FUN_0042eaa0(undefined1 *param_1,int param_2,int param_3,int param_4)

{
  undefined1 *puVar1;
  int iVar2;
  int iVar3;
  
  iVar3 = (param_2 * 0xb + param_3) * 0x40;
  iVar2 = *(int *)(param_1 + iVar3 + 0xc4);
  puVar1 = param_1 + iVar3 + 0xb0;
  if (param_4 < 1) {
    *(undefined4 *)(puVar1 + 0x14) = 0;
  }
  else if (param_4 < *(int *)(puVar1 + 0x10)) {
    *(int *)(puVar1 + 0x14) = param_4;
  }
  else {
    *(int *)(puVar1 + 0x14) = *(int *)(puVar1 + 0x10) + -1;
  }
  if (param_1[0x19a5] != '\0') {
    FUN_0042e530(param_2,param_3);
    if (param_2 == 0) {
      iVar3 = 1;
    }
    else {
      iVar3 = 0;
      if (param_2 != 1) {
        iVar3 = (param_2 == 2) + 2;
      }
    }
    FUN_0042e470(puVar1,param_1 + (iVar3 * 0xb + param_3) * 0x40 + 0xb0);
  }
  FUN_0042e530(param_2,param_3);
  if (*(int *)(puVar1 + 0x14) != iVar2) {
    param_1[0x19a4] = 1;
    *param_1 = 1;
  }
  return;
}


