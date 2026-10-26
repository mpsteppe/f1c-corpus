// Function: FUN_0042e1f0 @ 0042e1f0
// Size (bytes): 157


void __thiscall
FUN_0042e1f0(double *param_1,undefined4 param_2,int param_3,undefined4 param_4,double param_5)

{
  double *pdVar1;
  int *piVar2;
  int iVar3;
  undefined4 uVar4;
  int iVar5;
  undefined1 local_8 [8];
  
  if (param_3 != 0) {
    pdVar1 = param_1 + 1;
    iVar3 = FUN_00565aa0(param_3,param_1,pdVar1,local_8,0);
    if (iVar3 != 0) {
      uVar4 = __ftol();
      *(undefined4 *)(param_1 + 2) = uVar4;
      *param_1 = param_5 * *param_1;
      *pdVar1 = param_5 * *pdVar1;
    }
  }
  piVar2 = (int *)((int)param_1 + 0x14);
  iVar3 = FUN_00565760(param_4,piVar2,0,0,0);
  if (iVar3 != 0) {
    iVar3 = *(int *)(param_1 + 2);
    if (0 < iVar3) {
      iVar5 = *piVar2;
      if (iVar5 < 0) {
        *piVar2 = 0;
        return;
      }
      if (iVar3 <= iVar5) {
        iVar5 = iVar3 + -1;
      }
      *piVar2 = iVar5;
      return;
    }
    *piVar2 = 0;
  }
  return;
}


