// Function: FUN_00598815 @ 00598815
// Size (bytes): 383


undefined4 FUN_00598815(void)

{
  int iVar1;
  undefined4 extraout_ECX;
  int unaff_EBP;
  bool bVar2;
  
  FUN_0058a5d8();
  *(undefined4 *)(unaff_EBP + -0x14) = extraout_ECX;
  *(undefined4 *)(unaff_EBP + -0x10) = 0;
  FUN_0059a54d();
  bVar2 = DAT_005e9ef4 < 0;
  if (bVar2) {
    DAT_005e9ef4 = 1;
  }
  else {
    DAT_005e9ef4 = DAT_005e9ef4 + 1;
  }
  FUN_0059a5e9();
  if (bVar2) {
    *(undefined **)(unaff_EBP + -0x10) = &DAT_008d4370;
    *(undefined4 *)(unaff_EBP + -4) = 0;
    FUN_00598bbc(&PTR_DAT_005e6748);
    *(undefined **)(unaff_EBP + -0x10) = &DAT_008d4248;
    *(undefined4 *)(unaff_EBP + -4) = 1;
    FUN_00598bbc(&DAT_005e6768);
    *(int **)(unaff_EBP + -0x10) = &DAT_008d4330;
    *(undefined4 *)(unaff_EBP + -4) = 2;
    FUN_00598af5(&DAT_008d4370,1,1);
    *(undefined **)(unaff_EBP + -0x10) = &DAT_008d42a0;
    *(undefined4 *)(unaff_EBP + -4) = 3;
    FUN_005989d7(&DAT_008d4248,1,1,1);
    iVar1 = DAT_008d4330;
    *(undefined **)(unaff_EBP + -0x10) = &DAT_008d42d8;
    *(undefined **)(&DAT_008d435c + *(int *)(iVar1 + 4)) = &DAT_008d42a0;
    *(undefined4 *)(unaff_EBP + -4) = 4;
    FUN_00598bbc(&DAT_005e6788);
    *(int **)(unaff_EBP + -0x10) = &DAT_008d43c8;
    *(undefined4 *)(unaff_EBP + -4) = 5;
    FUN_005989d7(&DAT_008d42d8,1,1,1);
    iVar1 = DAT_008d43c8;
    *(int **)(unaff_EBP + -0x10) = &DAT_008d4210;
    *(undefined **)(&DAT_008d43f4 + *(int *)(iVar1 + 4)) = &DAT_008d42a0;
    *(uint *)(&DAT_008d43d4 + *(int *)(DAT_008d43c8 + 4)) =
         *(uint *)(&DAT_008d43d4 + *(int *)(DAT_008d43c8 + 4)) | 2;
    *(undefined4 *)(unaff_EBP + -4) = 6;
    FUN_005989d7(&DAT_008d42d8,1,1,1);
    *(undefined **)(&DAT_008d423c + *(int *)(DAT_008d4210 + 4)) = &DAT_008d42a0;
  }
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return *(undefined4 *)(unaff_EBP + -0x14);
}


