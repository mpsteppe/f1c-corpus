// Function: FUN_00589057 @ 00589057
// Size (bytes): 83


void FUN_00589057(undefined4 param_1,int param_2)

{
  FUN_0058fca0(param_1,param_2);
  if (*(char *)(param_2 + 0x40) != '\0') {
    FUN_00588f66(param_1,2,&DAT_005cc214,param_2 + 0x40);
  }
  if (*(char *)(param_2 + 0x80) != '\0') {
    FUN_00588f66(param_1,2,&DAT_005beb48,param_2 + 0x80);
  }
  return;
}


