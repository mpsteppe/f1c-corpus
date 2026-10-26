// Function: FUN_0048e5c0 @ 0048e5c0
// Size (bytes): 57


void __fastcall FUN_0048e5c0(int *param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  
  iVar1 = (**(code **)(*param_1 + 0xa0))();
  if (iVar1 == 0) {
    iVar1 = param_1[0x3d];
    iVar4 = param_1[0x3c];
    iVar3 = param_1[0x3b];
    iVar2 = param_1[0x3a];
    FUN_00490920(iVar2,iVar3,iVar4,iVar1);
    FUN_004918d0(iVar2,iVar3,iVar4,iVar1);
  }
  return;
}


