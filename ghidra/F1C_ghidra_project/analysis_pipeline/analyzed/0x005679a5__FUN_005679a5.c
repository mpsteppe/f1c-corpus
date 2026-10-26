// Function: FUN_005679a5 @ 005679a5
// Size (bytes): 21


void FUN_005679a5(int param_1)

{
  int in_EAX;
  bool in_ZF;
  
  if (!in_ZF) {
    do {
      if (param_1 < 1) {
        return;
      }
      in_EAX = *(int *)(in_EAX + 4);
      param_1 = param_1 + -1;
    } while (in_EAX != 0);
  }
  return;
}


