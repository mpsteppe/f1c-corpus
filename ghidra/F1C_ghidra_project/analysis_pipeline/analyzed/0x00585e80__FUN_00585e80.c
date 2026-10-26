// Function: FUN_00585e80 @ 00585e80
// Size (bytes): 31


void FUN_00585e80(uint param_1,uint *param_2,char *param_3)

{
  *param_2 = param_1 >> 3;
  *param_3 = '\x01' << ((byte)param_1 & 7);
  return;
}


