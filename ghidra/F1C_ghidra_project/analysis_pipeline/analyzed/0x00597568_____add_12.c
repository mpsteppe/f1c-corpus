// Function: ___add_12 @ 00597568
// Size (bytes): 94


/* Library Function - Single Match
    ___add_12
   
   Library: Visual Studio 2003 Release */

void ___add_12(undefined4 *param_1,undefined4 *param_2)

{
  int iVar1;
  
  iVar1 = FUN_00597547(*param_1,*param_2,param_1);
  if (iVar1 != 0) {
    iVar1 = FUN_00597547(param_1[1],1,param_1 + 1);
    if (iVar1 != 0) {
      param_1[2] = param_1[2] + 1;
    }
  }
  iVar1 = FUN_00597547(param_1[1],param_2[1],param_1 + 1);
  if (iVar1 != 0) {
    param_1[2] = param_1[2] + 1;
  }
  FUN_00597547(param_1[2],param_2[2],param_1 + 2);
  return;
}


