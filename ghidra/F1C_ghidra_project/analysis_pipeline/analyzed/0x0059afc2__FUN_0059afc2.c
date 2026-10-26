// Function: FUN_0059afc2 @ 0059afc2
// Size (bytes): 61


void FUN_0059afc2(void)

{
  exception *this;
  int unaff_EBP;
  undefined4 *unaff_FS_OFFSET;
  
  FUN_0058a5d8();
  *(exception **)(unaff_EBP + -0x10) = this;
  *(undefined ***)this = &PTR_FUN_005b9d7c;
  *(undefined4 *)(unaff_EBP + -4) = 0;
  FUN_005993af(1);
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  exception::~exception(this);
  *unaff_FS_OFFSET = *(undefined4 *)(unaff_EBP + -0xc);
  return;
}


