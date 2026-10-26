// Function: FUN_0042c1a0 @ 0042c1a0
// Strings:  [D:\dev\F1_1999_2002\Source\dynman.cpp, Entered DynMan::Init()]


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0042c1a0(void)

{
  bool bVar1;
  char cVar2;
  int *piVar3;
  int iVar4;
  int extraout_EDX;
  int iVar5;
  undefined1 local_200 [512];
  
  cVar2 = FUN_004d7a50(2,s_D__dev_F1_1999_2002_Source_dynma_005c3334,0x20d);
  if (cVar2 != '\0') {
    FUN_004d7aa0(&DAT_008ad25c,s_Entered_DynMan__Init___005c3374);
  }
  FUN_0040fe50();
  iVar5 = DAT_007d0410;
  iVar4 = 0;
  piVar3 = &DAT_005ef9a0;
  do {
    if (iVar5 != 4) {
      piVar3[0x364] = iVar4 + 1;
    }
    if (*piVar3 == 0) {
      FUN_0042bbd0();
      FUN_0042bc40();
      iVar4 = extraout_EDX;
      break;
    }
    piVar3 = piVar3 + 0x1230;
    iVar4 = iVar4 + 1;
  } while ((int)piVar3 < 0x7c87a0);
  if (iVar4 == 0x68) {
    FUN_0042bbd0();
    FUN_0042bc40();
  }
  if ((((DAT_007c56a4 == 1) || (DAT_007c56a4 == 2)) || (DAT_007c56a4 == 3)) || (DAT_007c56a4 == 4))
  {
    bVar1 = true;
  }
  else {
    bVar1 = false;
  }
  if (DAT_007c5690 == '\0') {
    FUN_004b1520(iVar5,local_200,0x200);
    FUN_004bfd90();
    if ((DAT_007d0410 != 3) || (DAT_007cebc4 == '\0')) {
      FUN_004bff70();
      goto LAB_0042c2b9;
    }
  }
  else if ((iVar5 != 4) || (!bVar1)) goto LAB_0042c2b9;
  FUN_004c01a0();
LAB_0042c2b9:
  FUN_0042bc80();
  FUN_005895a2((double)((float)DAT_005c329c * _DAT_0059e8a4 + _DAT_0059e9d4));
  FUN_004f9480();
  iVar5 = 0;
  if (0 < DAT_005c329c) {
    do {
      FUN_004c6c40();
      iVar5 = iVar5 + 1;
      FUN_004f9480();
    } while (iVar5 < DAT_005c329c);
  }
  FUN_005895a2((double)((float)DAT_005c329c * _DAT_0059e8a4 + _DAT_0059e9d4));
  FUN_004f9480();
  FUN_004326e0();
  if (((-1 < DAT_007c54e4) && (DAT_007c54e4 < 0x68)) &&
     (*(int *)((&DAT_007c54f0)[DAT_007c54e4] + 13000) == 0)) {
    FUN_004336f0(DAT_007c54e4);
  }
  return;
}


