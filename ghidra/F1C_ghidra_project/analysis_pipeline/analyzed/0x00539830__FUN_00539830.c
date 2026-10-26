// Function: FUN_00539830 @ 00539830
// Size (bytes): 64


void __fastcall
FUN_00539830(undefined4 param_1,undefined1 param_2,undefined4 param_3,undefined4 param_4,int param_5
            )

{
  undefined4 *puVar1;
  undefined1 unaff_BL;
  undefined4 unaff_retaddr;
  
  puVar1 = (undefined4 *)(**(code **)(param_5 + 0x20))(0x1a);
  if (puVar1 != (undefined4 *)0x0) {
    *(undefined1 *)(puVar1 + 4) = unaff_BL;
    *puVar1 = 0;
    *(undefined1 *)((int)puVar1 + 0x11) = param_2;
    *(undefined4 *)((int)puVar1 + 0x12) = unaff_retaddr;
    *(undefined4 *)((int)puVar1 + 0x16) = param_3;
  }
  return;
}


