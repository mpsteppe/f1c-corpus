// Function: FUN_00565f50 @ 00565f50
// Size (bytes): 22


int __fastcall FUN_00565f50(int *param_1)

{
  int *piVar1;
  uint3 uVar2;
  
  piVar1 = *(int **)*param_1;
  ((int *)*param_1)[2] = (int)piVar1;
  uVar2 = (uint3)((uint)piVar1 >> 8);
  if ((piVar1 != (int *)0x0) && (*piVar1 != 0)) {
    return CONCAT31(uVar2,1);
  }
  return (uint)uVar2 << 8;
}


