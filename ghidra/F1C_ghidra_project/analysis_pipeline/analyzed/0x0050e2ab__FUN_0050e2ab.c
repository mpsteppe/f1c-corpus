// Function: FUN_0050e2ab @ 0050e2ab
// Size (bytes): 87


undefined4
FUN_0050e2ab(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
            undefined4 param_5,float param_6)

{
  undefined1 local_24 [16];
  undefined1 local_14 [16];
  
  thunk_FUN_0050e174(local_24,param_2,param_5,param_6);
  thunk_FUN_0050e174(local_14,param_3,param_4,param_6);
  param_6 = (1.0 - param_6) * param_6;
  thunk_FUN_0050e174(param_1,local_24,local_14,param_6 + param_6);
  return param_1;
}


