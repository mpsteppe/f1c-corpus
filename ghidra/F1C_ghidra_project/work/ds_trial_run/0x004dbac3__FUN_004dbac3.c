// Function: FUN_004dbac3 @ 004dbac3
// Size (bytes): 153


void FUN_004dbac3(undefined4 param_1,undefined1 param_2,undefined4 param_3,undefined4 param_4,
                 int param_5,undefined4 param_6)

{
  undefined4 uVar1;
  char in_AL;
  char cVar2;
  int iVar3;
  int unaff_ESI;
  
  if (in_AL != '\0') {
    param_2 = 0x3e;
    unaff_ESI = 1;
  }
  cVar2 = FUN_0049bb20();
  if (cVar2 != '\0') {
    (&param_2)[unaff_ESI] = 0x41;
    unaff_ESI = unaff_ESI + 1;
  }
  cVar2 = FUN_0049ba90();
  if (cVar2 != '\0') {
    (&param_2)[unaff_ESI] = 0x66;
    unaff_ESI = unaff_ESI + 1;
  }
  cVar2 = FUN_0049bab0();
  if (cVar2 != '\0') {
    (&param_2)[unaff_ESI] = 0x3f;
    unaff_ESI = unaff_ESI + 1;
  }
  if (DAT_007c56a8 == 8) {
    (&param_2)[unaff_ESI] = 0x42;
    unaff_ESI = unaff_ESI + 1;
  }
  uVar1 = param_6;
  if (0 < unaff_ESI) {
    iVar3 = param_5 + 5;
    (&param_2)[unaff_ESI] = 0;
    FUN_004d7e40(&param_2,iVar3,uVar1,0xffffff,0,3,DAT_005acf48,DAT_005acf4c);
  }
  return;
}


