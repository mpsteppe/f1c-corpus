// Function: FUN_005016e0 @ 005016e0
// Size (bytes): 27


void FUN_005016e0(int *param_1)

{
  (**(code **)(*param_1 + 8))(param_1);
                    /* WARNING: Subroutine does not return */
  _longjmp((int *)(*param_1 + 0x84),1);
}


