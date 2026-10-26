// Function: FUN_0053fd40 @ 0053fd40
// Size (bytes): 395


undefined4 __thiscall
FUN_0053fd40(int *param_1,int *param_2,byte param_3,int param_4,byte param_5,uint param_6)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  int *piVar4;
  int *piVar5;
  int *local_8;
  undefined1 local_4 [4];
  
  piVar5 = param_2;
  FUN_0055c650(local_4,param_2[0xc],0);
  iVar2 = param_4;
  uVar1 = *(uint *)(param_4 + 0x18);
  iVar3 = FUN_0053f720(param_4,*(undefined4 *)(param_4 + 0x2c));
  if (iVar3 != 0) {
    return 0xffffffff;
  }
  if ((param_6 & 0x1000000) == 0) {
    if ((((param_3 & 4) == 0) || (piVar4 = (int *)piVar5[4], piVar4 == (int *)0x0)) &&
       (((param_3 & 8) == 0 || (piVar4 = (int *)piVar5[5], piVar4 == (int *)0x0)))) {
      if (((param_3 & 1) == 0) || (param_2 = (int *)piVar5[2], param_2 == (int *)0x0)) {
        if ((param_3 & 2) == 0) {
          return 0xffffffff;
        }
        param_2 = (int *)piVar5[3];
        if (param_2 == (int *)0x0) {
          return 0xffffffff;
        }
      }
    }
    else {
      iVar3 = (**(code **)(*piVar4 + 0x3c))(piVar4,0,&param_2);
      *param_1 = iVar3;
      if (iVar3 != 0) {
        return 0xffffffff;
      }
    }
    if ((((param_5 & 4) == 0) || (piVar5 = *(int **)(iVar2 + 0x10), piVar5 == (int *)0x0)) &&
       (((param_5 & 8) == 0 || (piVar5 = *(int **)(iVar2 + 0x14), piVar5 == (int *)0x0)))) {
      if (((param_5 & 1) == 0) || (local_8 = *(int **)(iVar2 + 8), local_8 == (int *)0x0)) {
        if ((param_5 & 2) == 0) {
          return 0xffffffff;
        }
        local_8 = *(int **)(iVar2 + 0xc);
        if (local_8 == (int *)0x0) {
          return 0xffffffff;
        }
      }
    }
    else {
      iVar3 = (**(code **)(*piVar5 + 0x3c))(piVar5,0,&local_8);
      *param_1 = iVar3;
      if (iVar3 != 0) {
        return 0xffffffff;
      }
    }
    iVar3 = FUN_0050099c(local_8,0,0,param_2,0,0,4,
                         (-(uint)((uVar1 & 0x800) != 0) & 0xff00ff01) - 0xff01);
    *param_1 = iVar3;
    if (iVar3 != 0) {
      return 0xffffffff;
    }
    if ((param_3 & 0xc) != 0) {
      (**(code **)(*param_2 + 8))(param_2);
    }
    if ((param_5 & 0xc) != 0) {
      (**(code **)(*local_8 + 8))(local_8);
    }
    if (1 < *(int *)(iVar2 + 0x2c)) {
      FUN_00500bc8(*(undefined4 *)(iVar2 + 0x10),0,0xffffffff,5);
    }
  }
  return 0;
}


