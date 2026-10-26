// Function: FUN_0045c3d0 @ 0045c3d0
// Size (bytes): 45


undefined4 __thiscall FUN_0045c3d0(int param_1,undefined4 param_2,undefined4 *param_3)

{
  char cVar1;
  
  cVar1 = FUN_00568a60(*(undefined1 *)(param_1 + 1),param_3);
  if (cVar1 != '\0') {
    return 1;
  }
  *param_3 = 0;
  return 0;
}


