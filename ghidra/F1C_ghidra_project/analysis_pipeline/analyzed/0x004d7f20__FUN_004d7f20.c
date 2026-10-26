// Function: FUN_004d7f20 @ 004d7f20
// Size (bytes): 62


void FUN_004d7f20(undefined4 param_1,int param_2,int *param_3,int param_4)

{
  int iVar1;
  
  iVar1 = FUN_004d7fa0(param_4);
  if (iVar1 != 0) {
    FUN_005531f0(param_1,&param_4,&param_1,0);
    *param_3 = param_2 - param_4 / 2;
  }
  return;
}


