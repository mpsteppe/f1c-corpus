// Function: FUN_0048b7e0 @ 0048b7e0
// Size (bytes): 43


uint __thiscall FUN_0048b7e0(int *param_1,int param_2,uint param_3)

{
  uint in_EAX;
  
  if ((param_2 != 0) && (in_EAX = param_3, 0 < (int)param_3)) {
    param_1[0xbe] = param_3;
    param_1[0xbc] = param_2;
    in_EAX = (**(code **)(*param_1 + 0xa8))(1);
  }
  return in_EAX & 0xffffff00;
}


