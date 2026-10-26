// Function: FUN_00423459 @ 00423459
// Size (bytes): 37


void FUN_00423459(void)

{
  HLOCAL unaff_EBX;
  int unaff_EBP;
  HLOCAL unaff_EDI;
  
  if (unaff_EBX != (HLOCAL)0x0) {
    LocalFree(unaff_EBX);
  }
  if (unaff_EDI != (HLOCAL)0x0) {
    LocalFree(unaff_EDI);
  }
  if (*(PSID *)(unaff_EBP + -0x24) != (PSID)0x0) {
    FreeSid(*(PSID *)(unaff_EBP + -0x24));
  }
  return;
}


