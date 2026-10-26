// Function: FUN_00498fe0 @ 00498fe0
// Size (bytes): 101


undefined4 __fastcall FUN_00498fe0(int *param_1)

{
  char cVar1;
  int iVar2;
  int *piVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  
  if (param_1[0x18] != 0) {
    cVar1 = (**(code **)(*param_1 + 0x28))();
    if (cVar1 != '\0') {
      iVar6 = param_1[1];
      iVar5 = param_1[3];
      iVar4 = param_1[2] - iVar6;
      iVar2 = param_1[4] - iVar5;
      FUN_00490920(iVar5,iVar6,iVar2,iVar4);
      FUN_004918d0(iVar5,iVar6,iVar2,iVar4);
    }
    FUN_004993d0();
    piVar3 = (int *)param_1[0x13];
    while (piVar3 != (int *)0x0) {
      (**(code **)(*piVar3 + 0x44))();
      piVar3 = (int *)FUN_00486320();
    }
    (**(code **)(*param_1 + 0x2c))(0);
  }
  return 0;
}


