// Function: FUN_0059abcd @ 0059abcd
// Size (bytes): 114


undefined4 * FUN_0059abcd(void)

{
  undefined1 uVar1;
  size_t sVar2;
  undefined4 *extraout_ECX;
  int unaff_EBP;
  
  FUN_0058a5d8();
  *(undefined4 **)(unaff_EBP + -0x10) = extraout_ECX;
  extraout_ECX[1] = 1;
  *extraout_ECX = &PTR_LAB_005b9d54;
  *(undefined1 *)(extraout_ECX + 5) = *(undefined1 *)(unaff_EBP + 8);
  uVar1 = *(undefined1 *)(unaff_EBP + 0xb);
  extraout_ECX[2] = 0;
  extraout_ECX[3] = 0;
  extraout_ECX[4] = 0;
  *(undefined1 *)(extraout_ECX + 6) = uVar1;
  *(undefined4 *)(unaff_EBP + -4) = 0;
  FUN_005993af(0);
  sVar2 = _strlen((char *)&DAT_005c406c);
  FUN_00599615(&DAT_005c406c,sVar2);
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  *extraout_ECX = &PTR_FUN_005b9d4c;
  return extraout_ECX;
}


