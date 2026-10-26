// Function: FUN_00590440 @ 00590440
// Size (bytes): 31


undefined4 FUN_00590440(short param_1)

{
  short *psVar1;
  
  psVar1 = &DAT_005e7204;
  do {
    if (param_1 == *psVar1) {
      return 0;
    }
    psVar1 = psVar1 + 1;
  } while ((int)psVar1 < 0x5e7218);
  return 1;
}


