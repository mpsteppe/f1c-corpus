// Function: FUN_004869e0 @ 004869e0
// Size (bytes): 180


void __thiscall FUN_004869e0(int *param_1,int param_2,int param_3)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  
  iVar1 = param_3;
  iVar3 = param_1[1];
  iVar4 = iVar3 + param_3;
  param_3 = iVar3;
  if (iVar4 <= iVar3) {
    param_3 = iVar4;
  }
  iVar4 = param_1[2];
  if (iVar4 <= iVar4 + iVar1) {
    iVar4 = iVar4 + iVar1;
  }
  iVar3 = param_1[3];
  if (iVar3 + param_2 <= iVar3) {
    iVar3 = iVar3 + param_2;
  }
  iVar2 = param_1[4];
  if (iVar2 <= iVar2 + param_2) {
    iVar2 = iVar2 + param_2;
  }
  FUN_00499050(param_3,iVar4,iVar3,iVar2);
  param_1[1] = param_1[1] + iVar1;
  param_1[4] = param_1[4] + param_2;
  param_1[2] = param_1[2] + iVar1;
  param_1[3] = param_1[3] + param_2;
  (**(code **)(*param_1 + 0x2c))(1);
  for (iVar4 = param_1[0x24]; iVar4 != 0; iVar4 = *(int *)(iVar4 + 0x8c)) {
    FUN_004869e0(param_2,iVar1);
  }
  (**(code **)(*param_1 + 0xa0))();
  return;
}


