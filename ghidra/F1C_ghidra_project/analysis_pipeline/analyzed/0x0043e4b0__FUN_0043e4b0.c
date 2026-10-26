// Function: FUN_0043e4b0 @ 0043e4b0
// Size (bytes): 284


void __thiscall FUN_0043e4b0(int param_1,double *param_2,undefined4 param_3)

{
  int iVar1;
  undefined4 *puVar2;
  int iVar3;
  double local_80;
  double local_78;
  double local_70;
  double local_58;
  double local_50;
  double local_48;
  double local_40;
  double local_38;
  double local_30;
  double local_28;
  double local_20;
  double local_18;
  double local_10;
  
  iVar1 = FUN_00567740();
  FUN_0056bd40(param_3);
  local_58 = local_10 * *(double *)(param_1 + 0x160c) +
             local_18 * *(double *)(param_1 + 0x1604) + local_20 * *(double *)(param_1 + 0x15fc);
  local_80 = *param_2 -
             (local_40 * *(double *)(param_1 + 0x160c) +
             local_48 * *(double *)(param_1 + 0x1604) + local_50 * *(double *)(param_1 + 0x15fc));
  local_78 = param_2[1] -
             (local_28 * *(double *)(param_1 + 0x160c) +
             local_30 * *(double *)(param_1 + 0x1604) + local_38 * *(double *)(param_1 + 0x15fc));
  local_70 = param_2[2] - local_58;
  FUN_0056f100(*(undefined4 *)(param_1 + 0x15f0),&local_80,param_3,0);
  *(undefined4 *)(param_1 + 0xb4) = 0;
  puVar2 = (undefined4 *)(param_1 + 0x3a8);
  iVar3 = 4;
  do {
    puVar2[-8] = 0xffffffff;
    puVar2[-7] = 0xffefffff;
    *puVar2 = 0xffffffff;
    puVar2[1] = 0xffefffff;
    puVar2 = puVar2 + 0x119;
    iVar3 = iVar3 + -1;
  } while (iVar3 != 0);
  if (iVar1 != 0x200) {
    FUN_00567780();
  }
  return;
}


