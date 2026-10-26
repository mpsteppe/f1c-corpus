// Function: FUN_00496380 @ 00496380
// Strings:  [Gametitle.bmp, pmbeltite.mag]


void FUN_00496380(void)

{
  char cVar1;
  
  if ((DAT_007d0398 != 0) && (cVar1 = FUN_004f9d60(s_pmbeltite_mag_005cca00,0,0), cVar1 == '\x01'))
  {
    return;
  }
  FUN_004f9d60(s_Gametitle_bmp_005cc9f0,0,0);
  return;
}


