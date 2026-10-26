// Function: FUN_004dbf90 @ 004dbf90
// Size (bytes): 283


void FUN_004dbf90(int param_1)

{
  undefined1 local_40 [64];
  
  FUN_0049c670(local_40,0x40);
  FUN_004d7e40(local_40,param_1 + 0xd7,0x2e,0xffff00,2,0,0x3f400000,0x3f800000);
  FUN_0049bde0(local_40,0x40);
  param_1 = param_1 + 0xf;
  FUN_004d7e40(local_40,param_1,10,0xffffff,1,2,0x3f800000,0x3f800000);
  FUN_0049be50(local_40,0x40);
  FUN_004d7e40(local_40,param_1,10,0xffff00,0,1,0x3f800000,0x3f800000);
  FUN_0049c700(local_40,0x40);
  FUN_004d7e40(local_40,param_1,0x5a,0xffffff,1,2,0x3f800000,0x3f800000);
  FUN_0049c770(local_40,0x40);
  FUN_004d7e40(local_40,param_1,0x5a,0xffff00,0,1,0x3f800000,0x3f800000);
  return;
}


