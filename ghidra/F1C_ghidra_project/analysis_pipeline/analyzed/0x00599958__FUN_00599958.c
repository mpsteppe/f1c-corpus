// Function: FUN_00599958 @ 00599958
// Size (bytes): 385


undefined4 FUN_00599958(void)

{
  int iVar1;
  undefined4 extraout_ECX;
  int unaff_EBP;
  bool bVar2;
  
  FUN_0058a5d8();
  *(undefined4 *)(unaff_EBP + -0x14) = extraout_ECX;
  *(undefined4 *)(unaff_EBP + -0x10) = 0;
  FUN_0059a54d();
  bVar2 = DAT_005ea04c < 0;
  if (bVar2) {
    DAT_005ea04c = 1;
  }
  else {
    DAT_005ea04c = DAT_005ea04c + 1;
  }
  FUN_0059a5e9();
  if (bVar2) {
    *(undefined **)(unaff_EBP + -0x10) = &DAT_008d4510;
    *(undefined4 *)(unaff_EBP + -4) = 0;
    FUN_00599cb7(&PTR_DAT_005e6748);
    *(undefined **)(unaff_EBP + -0x10) = &DAT_008d44b8;
    *(undefined4 *)(unaff_EBP + -4) = 1;
    FUN_00599cb7(&DAT_005e6768);
    *(undefined **)(unaff_EBP + -0x10) = &DAT_008d45a0;
    *(undefined4 *)(unaff_EBP + -4) = 2;
    FUN_00599cb7(&DAT_005e6788);
    *(int **)(unaff_EBP + -0x10) = &DAT_008d4478;
    *(undefined4 *)(unaff_EBP + -4) = 3;
    FUN_00599bf0(&DAT_008d4510,1,1);
    *(undefined **)(unaff_EBP + -0x10) = &DAT_008d4568;
    *(undefined4 *)(unaff_EBP + -4) = 4;
    FUN_00599b1c(&DAT_008d44b8,1,1,1);
    *(undefined **)(&DAT_008d44a4 + *(int *)(DAT_008d4478 + 4)) = &DAT_008d4568;
    *(int **)(unaff_EBP + -0x10) = &DAT_008d4400;
    *(undefined4 *)(unaff_EBP + -4) = 5;
    FUN_00599b1c(&DAT_008d45a0,1,1,1);
    iVar1 = DAT_008d4400;
    *(int **)(unaff_EBP + -0x10) = &DAT_008d4440;
    *(undefined **)(&DAT_008d442c + *(int *)(iVar1 + 4)) = &DAT_008d4568;
    *(uint *)(&DAT_008d440c + *(int *)(DAT_008d4400 + 4)) =
         *(uint *)(&DAT_008d440c + *(int *)(DAT_008d4400 + 4)) | 2;
    *(undefined4 *)(unaff_EBP + -4) = 6;
    FUN_00599b1c(&DAT_008d45a0,1,1,1);
    *(undefined **)(&DAT_008d446c + *(int *)(DAT_008d4440 + 4)) = &DAT_008d4568;
  }
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return *(undefined4 *)(unaff_EBP + -0x14);
}


