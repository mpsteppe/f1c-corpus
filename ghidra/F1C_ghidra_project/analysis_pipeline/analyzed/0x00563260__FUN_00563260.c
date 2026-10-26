// Function: FUN_00563260 @ 00563260
// Size (bytes): 363


int __fastcall
FUN_00563260(int *param_1,char *param_2,undefined4 param_3,int param_4,undefined4 param_5)

{
  int iVar1;
  int iVar2;
  int *piVar3;
  
  inet_addr(param_2);
  iVar1 = FUN_005631a0(param_3);
  if (*param_1 == 0) {
    iVar2 = FUN_00562d20();
    if (iVar2 != 0) {
      return iVar2;
    }
    if (iVar1 == -1) {
      FUN_00563160(param_3,param_5);
    }
    else {
      piVar3 = (int *)FUN_005648b0();
      iVar1 = *piVar3;
      *(undefined4 *)(iVar1 + 8) = param_5;
      *(undefined2 *)(iVar1 + 6) = 9999;
      FUN_00564990();
      FUN_005648c0();
    }
    iVar1 = FUN_00563e70();
    param_1[0x1c] = iVar1 + -1;
    param_1[0x1d] = 0;
    FUN_00562fe0();
    if (param_4 == 0) {
      FUN_00563000();
      return 0;
    }
  }
  else if (iVar1 == -1) {
    FUN_005633d0(param_3,param_1[0x1c],param_5);
    if ((*param_1 == 1) || (*param_1 == 2)) {
      param_1[0x26] = param_1[0x26] + 1;
      return 0;
    }
  }
  else {
    piVar3 = (int *)FUN_005648b0();
    iVar2 = *piVar3;
    if (iVar1 < param_1[0x1c]) {
      *(undefined4 *)(iVar2 + 8) = param_5;
      *(undefined2 *)(iVar2 + 6) = 9999;
      iVar1 = FUN_00563230();
      if (iVar1 != -1) {
        *(undefined4 *)(param_1[2] + 4 + iVar1 * 0x1c) = 0;
      }
      FUN_005648d0(param_1[0x1c]);
      FUN_00564990();
      param_1[0x1c] = param_1[0x1c] + -1;
    }
  }
  return 0;
}


