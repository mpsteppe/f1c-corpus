// Function: FUN_00494690 @ 00494690
// Size (bytes): 614


void FUN_00494690(void)

{
  float fVar1;
  float fVar2;
  void *pvVar3;
  int iVar4;
  
  pvVar3 = operator_new(0x60);
  if (pvVar3 == (void *)0x0) {
    DAT_007cde04 = 0;
  }
  else {
    DAT_007cde04 = FUN_0054fe10();
  }
  FUN_0054fec0(&DAT_005cc9d8,0x100,0x100,0,4);
  DAT_007cde08 = *(undefined4 *)(DAT_007cde04 + 0x54);
  FUN_00553980(&DAT_007cde0c,2,DAT_007cde04,0x30,0x40);
  pvVar3 = operator_new(0x60);
  if (pvVar3 == (void *)0x0) {
    DAT_007cde10 = 0;
  }
  else {
    DAT_007cde10 = FUN_0054fe10();
  }
  FUN_0054fec0(&DAT_005cc9d0,0x400,0x400,0,4);
  DAT_007cde14 = *(undefined4 *)(DAT_007cde10 + 0x54);
  iVar4 = FUN_00553980(&DAT_007cde18,2,DAT_007cde10,0x10,0x40);
  if (iVar4 == 0) {
    fVar1 = (float)DAT_005d6d60;
    fVar2 = (float)DAT_005d6d64;
    FUN_00553650(0,0,0,0x3f800000,0,0,0xffffff);
    FUN_00553650(1,0,fVar2,0x3f800000,0,0x3f160000,0xffffff);
    FUN_00553650(2,fVar1,fVar2,0x3f800000,0x3f480000,0x3f160000,0xffffff);
    FUN_00553650(3,fVar1,0,0x3f800000,0x3f480000,0,0xffffff);
  }
  pvVar3 = operator_new(0x60);
  if (pvVar3 == (void *)0x0) {
    DAT_007cde1c = 0;
  }
  else {
    DAT_007cde1c = FUN_0054fe10();
  }
  FUN_0054fec0(&DAT_005cc9c8,0x200,0x200,0,4);
  DAT_007cde20 = *(undefined4 *)(DAT_007cde1c + 0x54);
  iVar4 = FUN_00553980(&DAT_007cde24,2,DAT_007cde1c,0x10,0x40);
  if (iVar4 == 0) {
    fVar1 = (float)DAT_005d6d60;
    fVar2 = (float)DAT_005d6d64;
    FUN_00553650(0,0,0,0x3f800000,0,0,0xffffff);
    FUN_00553650(1,0,fVar2,0x3f800000,0,0x3f160000,0xffffff);
    FUN_00553650(2,fVar1,fVar2,0x3f800000,0x3f480000,0x3f160000,0xffffff);
    FUN_00553650(3,fVar1,0,0x3f800000,0x3f480000,0,0xffffff);
  }
  return;
}


