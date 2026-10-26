// Function: FUN_0040cd60 @ 0040cd60
// Size (bytes): 89


undefined4 __fastcall FUN_0040cd60(int param_1)

{
  if (*(int *)(param_1 + 0x18) == *(int *)(param_1 + 8)) {
    switch(*(undefined4 *)(*(int *)(param_1 + 0x18) + 0x34)) {
    case 0:
      *(undefined4 *)(param_1 + 0xc) = 0;
      return *(undefined4 *)(param_1 + 0xc);
    case 1:
      *(undefined4 *)(param_1 + 0xc) = 1;
      return *(undefined4 *)(param_1 + 0xc);
    case 2:
      *(undefined4 *)(param_1 + 0xc) = 2;
      return *(undefined4 *)(param_1 + 0xc);
    case 3:
      *(undefined4 *)(param_1 + 0xc) = 3;
      return *(undefined4 *)(param_1 + 0xc);
    case 4:
      *(undefined4 *)(param_1 + 0xc) = 4;
      return *(undefined4 *)(param_1 + 0xc);
    }
  }
  else {
    *(undefined4 *)(param_1 + 0xc) = 5;
  }
  return *(undefined4 *)(param_1 + 0xc);
}


