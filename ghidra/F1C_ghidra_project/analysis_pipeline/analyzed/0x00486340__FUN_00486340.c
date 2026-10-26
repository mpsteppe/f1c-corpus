// Function: FUN_00486340 @ 00486340
// Size (bytes): 128


void __thiscall FUN_00486340(int param_1,int param_2,char param_3)

{
  undefined4 uVar1;
  int iVar2;
  int extraout_EDX;
  
  *(undefined4 *)(param_2 + 0x40) = *(undefined4 *)(param_1 + 0x40);
  *(undefined4 *)(param_2 + 0x98) = *(undefined4 *)(param_1 + 0x98);
  *(undefined4 *)(param_2 + 0x9c) = *(undefined4 *)(param_1 + 0x9c);
  if (param_3 == '\0') {
    if (*(int *)(param_1 + 0x90) == 0) {
      *(int *)(param_1 + 0x90) = param_2;
    }
    else {
      for (iVar2 = *(int *)(*(int *)(param_1 + 0x90) + 0x8c); iVar2 != 0;
          iVar2 = *(int *)(iVar2 + 0x8c)) {
      }
      FUN_00486330(param_2);
      param_1 = extraout_EDX;
    }
  }
  else {
    uVar1 = *(undefined4 *)(param_1 + 0x90);
    *(int *)(param_1 + 0x90) = param_2;
    *(undefined4 *)(param_2 + 0x8c) = uVar1;
  }
  *(int *)(param_1 + 0x94) = *(int *)(param_1 + 0x94) + 1;
  return;
}


