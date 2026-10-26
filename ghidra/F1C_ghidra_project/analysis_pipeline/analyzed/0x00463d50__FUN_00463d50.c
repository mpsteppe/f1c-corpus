// Function: FUN_00463d50 @ 00463d50
// Size (bytes): 111


char FUN_00463d50(int param_1,undefined4 param_2,undefined4 param_3)

{
  undefined4 uVar1;
  char cVar2;
  
  uVar1 = *(undefined4 *)(&DAT_005f0708 + param_1 * 0x48c0);
  cVar2 = FUN_00500560(param_3,param_1,param_2,uVar1,0);
  if (cVar2 != '\0') {
    FUN_0045e620(param_2);
    FUN_005000e0(param_2,uVar1);
  }
  return cVar2;
}


