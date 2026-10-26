// Function: FUN_004b86e0 @ 004b86e0
// Size (bytes): 166


void __thiscall FUN_004b86e0(int param_1,float param_2)

{
  undefined4 uVar1;
  
  *(undefined4 *)(param_1 + 0xf3c) = *(undefined4 *)(param_1 + 0xf38);
  *(float *)(param_1 + 0xf38) = param_2;
  if (*(char *)(param_1 + 0xf81) != '\0') {
    if (param_2 <= *(float *)(param_1 + 0xf34)) {
      if (param_2 < *(float *)(param_1 + 0xf30)) {
        *(undefined4 *)(param_1 + 0xf38) = *(undefined4 *)(param_1 + 0xf30);
        return;
      }
    }
    else {
      *(undefined4 *)(param_1 + 0xf38) = *(undefined4 *)(param_1 + 0xf34);
    }
    return;
  }
  do {
    if (param_2 <= *(float *)(param_1 + 0xf34)) {
      if (*(float *)(param_1 + 0xf30) <= param_2) {
        return;
      }
      param_2 = (*(float *)(param_1 + 0xf34) - *(float *)(param_1 + 0xf30)) + param_2;
    }
    else {
      param_2 = param_2 - (*(float *)(param_1 + 0xf34) - *(float *)(param_1 + 0xf30));
    }
    uVar1 = *(undefined4 *)(param_1 + 0xf38);
    *(float *)(param_1 + 0xf38) = param_2;
    *(undefined4 *)(param_1 + 0xf3c) = uVar1;
  } while( true );
}


