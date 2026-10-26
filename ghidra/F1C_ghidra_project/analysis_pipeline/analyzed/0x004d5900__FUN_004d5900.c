// Function: FUN_004d5900 @ 004d5900
// Size (bytes): 89


void __thiscall FUN_004d5900(uint param_1,int param_2,uint param_3)

{
  uint local_4;
  
  if (param_2 == 0) {
    param_2 = 3;
  }
  else if (param_2 == 1) {
    param_2 = 1;
  }
  else if (param_2 == 2) {
    param_2 = 2;
  }
  else {
    param_2 = CONCAT31(param_2._1_3_,0xff);
  }
  local_4 = param_1;
  FUN_004d5be0(&param_2,1);
  local_4 = *(uint *)(param_1 + 8) ^ param_3;
  FUN_004d5be0(&local_4,4);
  return;
}


