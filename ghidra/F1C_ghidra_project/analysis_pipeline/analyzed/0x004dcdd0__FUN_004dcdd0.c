// Function: FUN_004dcdd0 @ 004dcdd0
// Size (bytes): 233


void __thiscall
FUN_004dcdd0(int param_1,int param_2,int param_3,undefined4 param_4,undefined4 param_5)

{
  int iVar1;
  
  *(undefined4 *)(param_1 + 0x10) = param_4;
  switch(param_5) {
  case 0:
    *(int *)(param_1 + 8) = param_2;
    *(int *)(param_1 + 0xc) = param_3;
    FUN_004dca80();
    return;
  case 1:
    *(int *)(param_1 + 8) = param_2 - *(int *)(param_1 + 0x14);
    *(int *)(param_1 + 0xc) = param_3;
    FUN_004dca80();
    return;
  case 2:
    *(int *)(param_1 + 8) = param_2 - *(int *)(param_1 + 0x14) / 2;
    *(int *)(param_1 + 0xc) = param_3;
    FUN_004dca80();
    return;
  case 3:
    *(int *)(param_1 + 8) = param_2;
    *(int *)(param_1 + 0xc) = param_3 - *(int *)(param_1 + 0x18);
    FUN_004dca80();
    return;
  case 4:
    iVar1 = *(int *)(param_1 + 0x14);
    goto LAB_004dce62;
  case 5:
    iVar1 = *(int *)(param_1 + 0x14) / 2;
LAB_004dce62:
    *(int *)(param_1 + 8) = param_2 - iVar1;
    *(int *)(param_1 + 0xc) = param_3 - *(int *)(param_1 + 0x18);
    FUN_004dca80();
    return;
  case 6:
    break;
  case 7:
    *(int *)(param_1 + 8) = param_2 - *(int *)(param_1 + 0x14);
    goto LAB_004dcea0;
  case 8:
    param_2 = param_2 - *(int *)(param_1 + 0x14) / 2;
    break;
  default:
    goto switchD_004dcde4_default;
  }
  *(int *)(param_1 + 8) = param_2;
LAB_004dcea0:
  *(int *)(param_1 + 0xc) = param_3 - *(int *)(param_1 + 0x18) / 2;
switchD_004dcde4_default:
  FUN_004dca80();
  return;
}


