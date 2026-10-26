// Function: FUN_00594a5e @ 00594a5e
// Size (bytes): 86


void FUN_00594a5e(undefined **param_1)

{
  VirtualFree(param_1[4],0,0x8000);
  if ((undefined **)PTR_LOOP_005e9988 == param_1) {
    PTR_LOOP_005e9988 = param_1[1];
  }
  if (param_1 != &PTR_LOOP_005e7968) {
    *(undefined **)param_1[1] = *param_1;
    *(undefined **)(*param_1 + 4) = param_1[1];
    HeapFree(DAT_008d4904,0,param_1);
    return;
  }
  DAT_005e7978 = 0xffffffff;
  return;
}


