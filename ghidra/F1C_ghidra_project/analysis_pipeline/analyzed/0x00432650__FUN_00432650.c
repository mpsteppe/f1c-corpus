// Function: FUN_00432650 @ 00432650
// Size (bytes): 78


void __fastcall FUN_00432650(char *param_1)

{
  char cVar1;
  char *pcVar2;
  
  cVar1 = *param_1;
  if (('`' < cVar1) && (cVar1 < '{')) {
    *param_1 = cVar1 + -0x20;
  }
  cVar1 = param_1[1];
  do {
    if (cVar1 == '\0') {
      return;
    }
    pcVar2 = param_1 + 1;
    cVar1 = *param_1;
    if (((cVar1 < 'a') || ('z' < cVar1)) && ((cVar1 < 'A' || ('Z' < cVar1)))) {
      cVar1 = *pcVar2;
      if (('`' < cVar1) && (cVar1 < '{')) {
        cVar1 = cVar1 + -0x20;
LAB_00432693:
        *pcVar2 = cVar1;
      }
    }
    else {
      cVar1 = *pcVar2;
      if (('@' < cVar1) && (cVar1 < '[')) {
        cVar1 = cVar1 + ' ';
        goto LAB_00432693;
      }
    }
    cVar1 = param_1[2];
    param_1 = pcVar2;
  } while( true );
}


