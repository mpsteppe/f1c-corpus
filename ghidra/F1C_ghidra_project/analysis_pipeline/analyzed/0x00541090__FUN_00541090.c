// Function: FUN_00541090 @ 00541090
// Size (bytes): 96


undefined4 __thiscall
FUN_00541090(int *param_1,byte *param_2,undefined4 param_3,int param_4,int param_5)

{
  int *piVar1;
  int iVar2;
  undefined4 uVar3;
  undefined4 local_4;
  
  uVar3 = 0x800;
  local_4 = 0;
  if ((param_2 != (byte *)0x0) && (piVar1 = *(int **)(param_2 + 0x18), piVar1 != (int *)0x0)) {
    if ((*param_2 & 1) != 0) {
      uVar3 = 0x810;
    }
    iVar2 = (**(code **)(*piVar1 + 0x2c))(piVar1,param_4 * 2,param_5 * 2,&local_4,uVar3);
    *param_1 = iVar2;
    if (iVar2 != 0) {
      return 0;
    }
    *(int *)(param_2 + 0xc) = *(int *)(param_2 + 0xc) + 1;
  }
  return local_4;
}


