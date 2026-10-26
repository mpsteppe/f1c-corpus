// Function: FUN_004868c0 @ 004868c0
// Size (bytes): 286


undefined4 __thiscall
FUN_004868c0(int param_1,int param_2,char param_3,int param_4,int param_5,int param_6,int param_7)

{
  int *piVar1;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  undefined4 uVar9;
  undefined4 uVar10;
  
  piVar1 = (int *)FUN_00486460(param_2);
  if (param_4 == -50000) {
    param_4 = *(int *)(param_1 + 4);
  }
  if (param_5 == -50000) {
    param_5 = *(int *)(param_1 + 8);
  }
  if (param_6 == -50000) {
    param_6 = *(int *)(param_1 + 0xc);
  }
  if (param_7 == -50000) {
    param_7 = *(int *)(param_1 + 0x10);
  }
  if ((param_7 - param_6 < 1) || (param_5 - param_4 < 1)) {
    uVar2 = 0;
  }
  else {
    uVar2 = 1;
    if (piVar1 != (int *)0x0) {
      param_2 = *piVar1;
      _param_3 = piVar1[2];
      iVar4 = piVar1[1] - param_2;
      iVar3 = piVar1[3] - _param_3;
      if (param_6 < 0) {
        param_2 = param_2 - param_6;
      }
      if (param_4 < 0) {
        _param_3 = _param_3 - param_4;
      }
      if (piVar1[8] != 0) {
        uVar10 = 0;
        uVar9 = 0;
        iVar5 = param_6;
        iVar6 = param_4;
        iVar7 = iVar4;
        iVar8 = iVar3;
        uVar2 = FUN_00495150(param_6,param_4,iVar4,iVar3,0,0);
        FUN_00494a30(*(undefined4 *)(piVar1[8] + 0xc),param_2,_param_3,uVar2,iVar5,iVar6,iVar7,iVar8
                     ,uVar9,uVar10);
      }
      FUN_00490920(param_6,param_4,iVar4,iVar3);
      FUN_00491960(param_6,param_4,iVar4,iVar3);
      return 1;
    }
    if (param_3 != '\0') {
      FUN_00497260(param_4,param_5,param_6,param_7,0xf0f0f,0xaaffaa);
      return 1;
    }
  }
  return uVar2;
}


