// Function: FUN_00562890 @ 00562890
// Size (bytes): 94


void __fastcall FUN_00562890(int param_1)

{
  undefined4 uVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 unaff_retaddr;
  undefined4 local_577;
  
  puVar3 = &local_577;
  for (iVar2 = 0x15d; iVar2 != 0; iVar2 = iVar2 + -1) {
    *puVar3 = 0;
    puVar3 = puVar3 + 1;
  }
  uVar1 = *(undefined4 *)(param_1 + 0x100);
  *(undefined2 *)puVar3 = 0;
  *(undefined1 *)((int)puVar3 + 2) = 0;
  (**(code **)(param_1 + 0xd0))(uVar1);
  FUN_00562710(unaff_retaddr,&stack0xfffffa84);
  return;
}


