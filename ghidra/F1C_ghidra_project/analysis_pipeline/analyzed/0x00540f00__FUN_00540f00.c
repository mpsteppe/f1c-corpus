// Function: FUN_00540f00 @ 00540f00
// Size (bytes): 144


undefined4 __thiscall FUN_00540f00(int *param_1,uint *param_2,byte param_3,int param_4,int param_5)

{
  int *piVar1;
  int iVar2;
  uint uVar3;
  undefined4 local_4;
  
  uVar3 = 0x800;
  local_4 = 0;
  if (param_2 == (uint *)0x0) {
    return 0;
  }
  piVar1 = (int *)param_2[8];
  if (piVar1 == (int *)0x0) {
    return 0;
  }
  if ((*param_2 & 1) != 0) {
    uVar3 = 0x810;
  }
  if ((*param_2 & 0x20) == 0) goto LAB_00540f56;
  iVar2 = param_1[0x4f8];
  if (iVar2 != 0) {
    if ((iVar2 < 1) || (2 < iVar2)) goto LAB_00540f56;
    if ((param_3 & 0x40) == 0) {
      uVar3 = uVar3 | 0x1000;
      goto LAB_00540f56;
    }
  }
  uVar3 = uVar3 | 0x2000;
LAB_00540f56:
  iVar2 = (**(code **)(*piVar1 + 0x2c))
                    (piVar1,param_2[2] * param_4,param_2[2] * param_5,&local_4,uVar3);
  *param_1 = iVar2;
  if (iVar2 == 0) {
    param_2[5] = param_2[5] + 1;
    return local_4;
  }
  return 0;
}


