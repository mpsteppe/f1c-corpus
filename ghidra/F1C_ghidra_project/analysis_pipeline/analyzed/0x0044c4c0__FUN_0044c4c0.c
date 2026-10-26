// Function: FUN_0044c4c0 @ 0044c4c0
// Size (bytes): 141


undefined4 __thiscall FUN_0044c4c0(int param_1,double *param_2)

{
  int iVar1;
  int iVar2;
  
  if ((*(int *)(param_2 + 6) != 0) && (*(char *)(*(int *)(param_2 + 6) + 0x58) == '\0')) {
    iVar2 = FUN_0044a070(param_2);
    if (iVar2 != 0) goto LAB_0044c542;
  }
  *(undefined4 *)(param_2 + 6) = 0;
  iVar2 = (int)ROUND((*param_2 - *(double *)(param_1 + 8)) * *(double *)(param_1 + 0x10));
  iVar1 = (int)ROUND((param_2[2] - *(double *)(param_1 + 0x18)) * *(double *)(param_1 + 0x20));
  if ((((-1 < iVar2) && (iVar2 < 0x20)) && (-1 < iVar1)) &&
     ((iVar1 < 0x20 && (*(int *)(param_1 + 0x28 + (iVar2 * 0x20 + iVar1) * 4) != 0)))) {
    FUN_0044aa30(param_2);
  }
LAB_0044c542:
  return *(undefined4 *)(param_2 + 6);
}


