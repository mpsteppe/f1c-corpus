// Function: FUN_005932ba @ 005932ba
// Size (bytes): 57


void FUN_005932ba(void)

{
  if ((DAT_008d3ebc == 1) || ((DAT_008d3ebc == 0 && (DAT_005e65b4 == 1)))) {
    FUN_005932f3(0xfc);
    if (DAT_008d41ac != (code *)0x0) {
      (*DAT_008d41ac)();
    }
    FUN_005932f3(0xff);
  }
  return;
}


