// Function: FUN_004628a0 @ 004628a0
// Size (bytes): 154


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_004628a0(void)

{
  char cVar1;
  undefined1 local_230 [128];
  undefined1 local_1b0 [432];
  
  FUN_00461550();
  cVar1 = FUN_004630d0(local_230);
  if (cVar1 != '\0') {
    FUN_00463760(0);
    FUN_00461610();
    FUN_00462760(local_230);
    FUN_004b33b0(4,5,0,0,(float)_DAT_008afea0,1);
    FUN_00462250(local_1b0,2,0xffffffff,0xffffffff);
    FUN_004a0dc0();
    return 1;
  }
  return 0;
}


