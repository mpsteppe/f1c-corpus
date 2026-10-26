// Function: FUN_004652d0 @ 004652d0
// Size (bytes): 38


void __thiscall FUN_004652d0(int *param_1,int param_2)

{
  char *pcVar1;
  
  pcVar1 = (char *)(param_2 * 0x230 + 0xf8 + *param_1);
  if (*pcVar1 == '\0') {
    *pcVar1 = '\x01';
    *(int *)(*param_1 + 0xe40c) = *(int *)(*param_1 + 0xe40c) + 1;
  }
  return;
}


