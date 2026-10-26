// Function: FUN_0040f550 @ 0040f550
// Size (bytes): 138


void __thiscall FUN_0040f550(int param_1,undefined4 param_2)

{
  int iVar1;
  
  switch(*(undefined4 *)(param_1 + 0x1c)) {
  case 0:
  case 3:
    FUN_00459a40(param_2,param_1 + 0xc);
    *(undefined1 *)(param_1 + 10) = 1;
    return;
  case 1:
  case 4:
    FUN_00459a40(param_2,param_1 + 0xc);
    *(undefined1 *)(param_1 + 10) = 1;
    return;
  case 2:
  case 5:
    FUN_00459a40(param_2,param_1 + 0xc);
    *(undefined1 *)(param_1 + 10) = 1;
    break;
  case 6:
    FUN_004ec080(param_2);
    iVar1 = *(int *)(param_1 + 0x20);
    *(undefined4 *)(param_1 + 0xc) = *(undefined4 *)(iVar1 + 0x34d4);
    *(undefined4 *)(param_1 + 0x10) = *(undefined4 *)(iVar1 + 0x34d8);
    *(undefined4 *)(param_1 + 0x14) = *(undefined4 *)(iVar1 + 0x34dc);
    return;
  }
  return;
}


