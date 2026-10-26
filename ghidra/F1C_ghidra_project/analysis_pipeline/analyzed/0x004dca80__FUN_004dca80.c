// Function: FUN_004dca80 @ 004dca80
// Size (bytes): 235


void __fastcall FUN_004dca80(int *param_1)

{
  if (*param_1 != 0) {
    FUN_00553650(0,(float)param_1[2],(float)param_1[3],(float)param_1[4],0,0,param_1[7]);
    FUN_00553650(1,(float)param_1[2],(float)(param_1[3] + param_1[6]),(float)param_1[4],0,param_1[9]
                 ,param_1[7]);
    FUN_00553650(2,(float)(param_1[2] + param_1[5]),(float)(param_1[3] + param_1[6]),
                 (float)param_1[4],param_1[8],param_1[9],param_1[7]);
    FUN_00553650(3,(float)(param_1[2] + param_1[5]),(float)param_1[3],(float)param_1[4],param_1[8],0
                 ,param_1[7]);
  }
  return;
}


