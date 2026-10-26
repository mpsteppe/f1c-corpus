// Function: FUN_00599615 @ 00599615
// Size (bytes): 53


int __thiscall FUN_00599615(int param_1,undefined4 param_2,int param_3)

{
  char cVar1;
  
  cVar1 = FUN_00599560(param_3,1);
  if (cVar1 != '\0') {
    FUN_0058cc00(*(undefined4 *)(param_1 + 4),param_2,param_3);
    *(int *)(param_1 + 8) = param_3;
    *(undefined1 *)(*(int *)(param_1 + 4) + param_3) = 0;
  }
  return param_1;
}


