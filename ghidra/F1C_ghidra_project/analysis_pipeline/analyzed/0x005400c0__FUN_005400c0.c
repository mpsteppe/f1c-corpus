// Function: FUN_005400c0 @ 005400c0
// Size (bytes): 136


undefined4 __thiscall FUN_005400c0(int *param_1,int param_2,undefined4 param_3,uint param_4)

{
  int *piVar1;
  int iVar2;
  undefined4 uVar3;
  uint uVar4;
  undefined1 local_8 [8];
  
  uVar3 = 0;
  uVar4 = param_4;
  if (param_4 == 0) {
    uVar4 = *(uint *)(param_2 + 0x18);
  }
  if ((param_4 & 0x100) != 0) {
    uVar3 = 0x10;
  }
  if ((uVar4 & 1) == 0) {
    if ((uVar4 & 2) != 0) {
      piVar1 = *(int **)(param_2 + 0xc);
      goto LAB_005400f6;
    }
  }
  else {
    piVar1 = *(int **)(param_2 + 8);
LAB_005400f6:
    if (piVar1 != (int *)0x0) {
      iVar2 = (**(code **)(*piVar1 + 0x24))(piVar1,local_8);
      goto LAB_00540108;
    }
  }
  if ((uVar4 & 4) == 0) {
    return 0;
  }
  iVar2 = (**(code **)(**(int **)(param_2 + 0x10) + 0x40))
                    (*(int **)(param_2 + 0x10),param_3,local_8);
LAB_00540108:
  *param_1 = iVar2;
  if (iVar2 != 0) {
    return 0;
  }
  *(undefined4 *)(param_2 + 0x28) = 0;
  return uVar3;
}


