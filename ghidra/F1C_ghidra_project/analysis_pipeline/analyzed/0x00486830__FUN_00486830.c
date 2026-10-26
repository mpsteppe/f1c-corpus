// Function: FUN_00486830 @ 00486830
// Size (bytes): 143


byte __fastcall FUN_00486830(int *param_1)

{
  char cVar1;
  int unaff_EBX;
  int unaff_EBP;
  int unaff_ESI;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int iStack_14;
  undefined1 local_10 [4];
  undefined1 local_c [4];
  undefined1 local_8 [4];
  undefined1 local_4 [4];
  
  (**(code **)(*param_1 + 8))(local_c,local_4,local_10,local_8);
  iVar2 = unaff_EBX - unaff_ESI;
  iVar3 = iStack_14 - unaff_EBP;
  cVar1 = FUN_00486730();
  if (cVar1 != '\0') {
    iVar4 = unaff_ESI;
    iVar5 = unaff_EBP;
    iVar6 = iVar2;
    iVar7 = iVar3;
    FUN_00490920(unaff_ESI,unaff_EBP,iVar2,iVar3);
    cVar1 = FUN_00491c70(iVar4,iVar5,iVar6,iVar7);
    if (cVar1 == '\0') {
      return 1;
    }
  }
  FUN_00490920(unaff_ESI,unaff_EBP,iVar2,iVar3);
  cVar1 = FUN_00491cb0(unaff_ESI,unaff_EBP,iVar2,iVar3);
  return -(cVar1 != '\0') & 2;
}


