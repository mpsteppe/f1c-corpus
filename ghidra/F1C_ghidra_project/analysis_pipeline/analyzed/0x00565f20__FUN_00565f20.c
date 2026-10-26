// Function: FUN_00565f20 @ 00565f20
// Size (bytes): 33


int __fastcall FUN_00565f20(int *param_1)

{
  int iVar1;
  int *piVar2;
  uint3 uVar3;
  
  iVar1 = *param_1;
  if (*(int *)(iVar1 + 8) != 0) {
    *(undefined4 *)(iVar1 + 8) = *(undefined4 *)(*(int *)(iVar1 + 8) + 4);
  }
  piVar2 = *(int **)(iVar1 + 8);
  uVar3 = (uint3)((uint)piVar2 >> 8);
  if ((piVar2 != (int *)0x0) && (*piVar2 != 0)) {
    return CONCAT31(uVar3,1);
  }
  return (uint)uVar3 << 8;
}


