// Function: FUN_004b9da0 @ 004b9da0
// Size (bytes): 98


undefined4 __thiscall FUN_004b9da0(int *param_1,undefined4 param_2)

{
  switch(param_2) {
  case 0:
  case 1:
  case 2:
  case 3:
  case 4:
  case 5:
  case 6:
  case 7:
  case 8:
    *(undefined4 *)(*param_1 + 0xf8c) = param_2;
    return 1;
  case 9:
    FUN_004b81a0(0);
    return 1;
  case 10:
    FUN_004b8360();
    return 1;
  case 0xb:
    FUN_004b8480();
    return 1;
  case 0xc:
    FUN_004b84f0();
    return 1;
  case 0xd:
    FUN_004b85d0();
  }
  return 1;
}


