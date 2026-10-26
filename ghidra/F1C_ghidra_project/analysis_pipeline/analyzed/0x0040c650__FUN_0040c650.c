// Function: FUN_0040c650 @ 0040c650
// Size (bytes): 202


void __thiscall FUN_0040c650(int param_1,int param_2)

{
  int iVar1;
  undefined4 uVar2;
  
  if (param_2 == *(int *)((&DAT_007c54f0)[DAT_007c54e4] + 0x4894)) {
    if (*(int *)(param_1 + 0x14) != -1) {
      FUN_0040cde0(*(int *)(param_1 + 0x14),0);
      *(undefined4 *)(param_1 + 0x14) = 0xffffffff;
    }
  }
  else {
    iVar1 = *(int *)(param_1 + 0xc);
    if (((iVar1 == 0) || (iVar1 == 1)) || (iVar1 == 2)) {
      FUN_0040c610();
    }
    else {
      *(undefined4 *)(param_1 + 0x14) = 0xffffffff;
    }
  }
  if ((*(int *)(param_1 + 0xc) == 3) && (*(char *)(DAT_007c54e0 + 0x344c) != '\0')) {
    if (param_2 == *(int *)((&DAT_007c54f0)[DAT_007c54e4] + 0x4894)) {
      uVar2 = 2;
    }
    else {
      uVar2 = 5;
    }
    FUN_0040cde0(uVar2,0);
    *(undefined4 *)(param_1 + 0x14) = 3;
  }
  if ((param_2 != *(int *)((&DAT_007c54f0)[DAT_007c54e4] + 0x4894)) &&
     (((iVar1 = *(int *)(param_1 + 0xc), iVar1 == 0 || (iVar1 == 1)) || (iVar1 == 2)))) {
    FUN_0040c610();
  }
  return;
}


