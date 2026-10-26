// Function: FUN_004fa640 @ 004fa640
// Strings:  [D:\dev\F1_1999_2002\Source\vidman.cpp, Entered VidMan::Restart()]


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_004fa640(void)

{
  char cVar1;
  undefined4 uVar2;
  
  cVar1 = FUN_004d7a50(2,s_D__dev_F1_1999_2002_Source_vidma_005d6dc4,0x470);
  if (cVar1 != '\0') {
    FUN_004d7aa0(&DAT_008ad25c,s_Entered_VidMan__Restart___005d6eb4);
  }
  FUN_0042d210(0);
  switch(DAT_007c56a4) {
  case 0:
  case 1:
  case 2:
  case 3:
  case 4:
    FUN_0054a200(0x40,0);
    uVar2 = 1;
    break;
  case 5:
    FUN_0054a200(0x40,1);
    uVar2 = 0;
    break;
  case 6:
  case 7:
    FUN_0054a200(0x40,1);
    FUN_0054a200(0x80,1);
    FUN_0054a200(0x100,0);
    if ((((DAT_007c56a4 == 7) && (DAT_008ab6e4 != 2)) && (cVar1 = FUN_00404f10(), cVar1 == '\0')) &&
       ((DAT_007ce254 != '\0' && (cVar1 = FUN_00461db0(), cVar1 == '\0')))) {
      FUN_0042d210(1);
    }
    goto LAB_004fa776;
  default:
    FUN_0054a200(0x40,0);
    FUN_0054a200(0x80,0);
    uVar2 = 0;
    goto LAB_004fa766;
  }
  FUN_0054a200(0x80,uVar2);
  uVar2 = 1;
LAB_004fa766:
  FUN_0054a200(0x100,uVar2);
LAB_004fa776:
  FUN_004f9fc0(0);
  _DAT_008afea8 = 0;
  _DAT_008afeac = 0;
  DAT_008afe84 = 0;
  FUN_004f8f10(DAT_008afcac);
  FUN_004f9f70(0);
  return;
}


