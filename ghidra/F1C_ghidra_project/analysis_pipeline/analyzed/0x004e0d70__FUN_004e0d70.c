// Function: FUN_004e0d70 @ 004e0d70
// Size (bytes): 50


void FUN_004e0d70(int *param_1)

{
  if ((*param_1 != 0) && ((char)param_1[0x10] != '\0')) {
    FUN_0054baa0(*param_1);
    *(undefined1 *)(param_1 + 0x10) = 0;
    FUN_0054c030(1,1,1,0);
  }
  return;
}


