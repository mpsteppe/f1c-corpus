// Function: FUN_005642b0 @ 005642b0
// Size (bytes): 53


void __fastcall FUN_005642b0(ulong *param_1,char *param_2)

{
  undefined2 uVar1;
  undefined1 *puVar2;
  ulong uVar3;
  
  puVar2 = (undefined1 *)FUN_00589db0(param_2,0x3a);
  if (puVar2 != (undefined1 *)0x0) {
    *puVar2 = 0;
    uVar3 = inet_addr(param_2);
    *param_1 = uVar3;
    uVar1 = FUN_00587f59(puVar2 + 1);
    *(undefined2 *)(param_1 + 1) = uVar1;
  }
  return;
}


