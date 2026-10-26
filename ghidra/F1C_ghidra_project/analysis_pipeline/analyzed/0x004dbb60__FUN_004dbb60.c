// Function: FUN_004dbb60 @ 004dbb60
// Size (bytes): 293


void FUN_004dbb60(int param_1)

{
  undefined1 local_40 [64];
  
  FUN_0049c6d0(local_40,0x40);
  FUN_004d7e40(local_40,param_1 + 0x32,0x2e,0xffff00,2,0,0x3f400000,0x3f800000);
  param_1 = param_1 + 0x145;
  FUN_004dc1a0(param_1,10);
  FUN_0049c310(local_40,0x40);
  FUN_004d7e40(local_40,param_1,0x32,0xffffff,1,2,0x3f800000,0x3f800000);
  FUN_0049c370(local_40,0x40);
  FUN_004d7e40(local_40,param_1,0x32,0xffffff,0,1,0x3f800000,0x3f800000);
  FUN_0049c490(local_40,0x40);
  FUN_004d7e40(local_40,param_1,0x5a,0xffffff,1,2,0x3f800000,0x3f800000);
  FUN_0049c4e0(local_40,0x40);
  FUN_004d7e40(local_40,param_1,0x5a,0xffffff,0,1,0x3f800000,0x3f800000);
  return;
}


