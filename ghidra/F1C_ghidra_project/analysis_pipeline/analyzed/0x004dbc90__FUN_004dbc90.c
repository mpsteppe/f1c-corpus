// Function: FUN_004dbc90 @ 004dbc90
// Size (bytes): 334


void FUN_004dbc90(int param_1)

{
  undefined1 local_40 [64];
  
  FUN_0049c6d0(local_40,0x40);
  FUN_004d7e40(local_40,param_1 + 0x32,0x2e,0xffff00,2,0,0x3f400000,0x3f800000);
  FUN_0049bb40(local_40,0x40);
  param_1 = param_1 + 0xf5;
  FUN_004d7e40(local_40,param_1,10,0xffffff,1,2,0x3f800000,0x3f800000);
  FUN_0049bbb0(local_40,0x40);
  FUN_004d7e40(local_40,param_1,10,0xffff00,0,1,0x3f800000,0x3f800000);
  FUN_0049bcd0(local_40,0x40);
  FUN_004d7e40(local_40,param_1,0x32,0xffffff,1,2,0x3f800000,0x3f800000);
  FUN_0049bd40(local_40,0x40);
  FUN_004d7e40(local_40,param_1,0x32,0xffff00,0,1,0x3f800000,0x3f800000);
  FUN_0049c0b0(local_40,0x40);
  FUN_004d7e40(local_40,param_1,0x5a,0xffff00,0,1,0x3f800000,0x3f800000);
  return;
}


