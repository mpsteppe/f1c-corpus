// Function: FUN_004881f0 @ 004881f0
// Size (bytes): 273


undefined4 __thiscall FUN_004881f0(int *param_1,int *param_2,int *param_3,int *param_4,int *param_5)

{
  int iVar1;
  int iVar2;
  int *piVar3;
  undefined4 uVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  int iVar10;
  undefined4 uVar11;
  undefined4 uVar12;
  
  piVar3 = (int *)(**(code **)(*param_1 + 0xa8))();
  if (piVar3 == (int *)0x0) {
    iVar1 = param_1[3];
    iVar2 = param_1[1];
    iVar6 = param_1[4] - iVar1;
    iVar5 = param_1[2] - iVar2;
    if ((0 < iVar6) && (0 < iVar5)) {
      uVar11 = 0x10101;
      iVar7 = iVar1;
      iVar8 = iVar2;
      iVar9 = iVar6;
      iVar10 = iVar5;
      uVar4 = FUN_00495150(iVar1,iVar2,iVar6,iVar5,0x10101);
      FUN_00494bf0(uVar4,iVar7,iVar8,iVar9,iVar10,uVar11);
    }
    *param_2 = iVar2;
    *param_3 = iVar5 + iVar2;
    *param_4 = iVar1;
    *param_5 = iVar6 + iVar1;
  }
  else {
    iVar1 = param_1[3];
    iVar2 = param_1[1];
    iVar5 = piVar3[1] - *piVar3;
    iVar6 = piVar3[3] - piVar3[2];
    if (((0 < iVar5) && (0 < iVar6)) && (*(int *)(piVar3[8] + 0xc) != 0)) {
      uVar12 = 0;
      uVar11 = 0;
      iVar7 = iVar1;
      iVar8 = iVar2;
      iVar9 = iVar5;
      iVar10 = iVar6;
      uVar4 = FUN_00495150(iVar1,iVar2,iVar5,iVar6,0,0);
      FUN_00494a30(*(undefined4 *)(piVar3[8] + 0xc),*piVar3,piVar3[2],uVar4,iVar7,iVar8,iVar9,iVar10
                   ,uVar11,uVar12);
      FUN_0049aa70(iVar5,iVar6);
      *param_2 = iVar2;
      *param_3 = iVar6 + iVar2;
      *param_4 = iVar1;
      *param_5 = iVar5 + iVar1;
    }
  }
  (**(code **)(*param_1 + 0x2c))(0);
  return 0;
}


