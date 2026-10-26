// Function: FUN_0059a5fe @ 0059a5fe
// Strings:  [ios::eofbit set, ios::failbit set, ios::badbit set, ios::badbit set, ios::badbit set]


void FUN_0059a5fe(void)

{
  uint uVar1;
  size_t sVar2;
  int extraout_ECX;
  int unaff_EBP;
  char *_Str;
  
  FUN_0058a5d8();
  uVar1 = *(uint *)(unaff_EBP + 8) & 7;
  *(uint *)(extraout_ECX + 4) = uVar1;
  uVar1 = *(uint *)(extraout_ECX + 8) & uVar1;
  if (uVar1 == 0) {
    ExceptionList = *(void **)(unaff_EBP + -0xc);
    return;
  }
  if (*(char *)(unaff_EBP + 0xc) != '\0') {
                    /* WARNING: Subroutine does not return */
    __CxxThrowException_8(0,0);
  }
  if ((uVar1 & 4) == 0) {
    _Str = "ios::failbit set";
    if ((uVar1 & 2) == 0) {
      _Str = "ios::eofbit set";
    }
  }
  else {
    _Str = "ios::badbit set";
  }
  *(undefined1 *)(unaff_EBP + -0x1c) = *(undefined1 *)(unaff_EBP + 0xf);
  FUN_005993af(0);
  sVar2 = _strlen(_Str);
  FUN_00599615(_Str,sVar2);
  *(undefined4 *)(unaff_EBP + -4) = 0;
  FUN_0059a69a(unaff_EBP + -0x1c);
  *(undefined ***)(unaff_EBP + -0x38) = &PTR_LAB_005b9ce4;
                    /* WARNING: Subroutine does not return */
  __CxxThrowException_8(unaff_EBP + -0x38,&DAT_005bb668);
}


