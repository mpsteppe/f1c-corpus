// Function: FUN_0059a728 @ 0059a728
// Size (bytes): 61


void FUN_0059a728(void)

{
  exception *this;
  int unaff_EBP;
  
  FUN_0058a5d8();
  *(exception **)(unaff_EBP + -0x10) = this;
  *(undefined ***)this = &PTR_FUN_005b9d28;
  *(undefined4 *)(unaff_EBP + -4) = 0;
  FUN_005993af(1);
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  exception::~exception(this);
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return;
}


