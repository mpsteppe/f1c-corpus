// Function: FUN_0053c5b0 @ 0053c5b0
// Size (bytes): 31


undefined4 FUN_0053c5b0(undefined4 param_1,int param_2)

{
  char cVar1;
  char *pcVar2;
  
  if (param_2 != 0) {
    pcVar2 = &DAT_008b6ac8;
    do {
      cVar1 = *pcVar2;
      pcVar2[param_2 + -0x8b6ac8] = cVar1;
      pcVar2 = pcVar2 + 1;
    } while (cVar1 != '\0');
  }
  return 0;
}


