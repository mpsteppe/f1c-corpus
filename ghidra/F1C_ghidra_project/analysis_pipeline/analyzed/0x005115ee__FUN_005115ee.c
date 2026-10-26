// Function: FUN_005115ee @ 005115ee
// Size (bytes): 125


void FUN_005115ee(int param_1)

{
  undefined4 *puVar1;
  int iVar2;
  
  puVar1 = (undefined4 *)(*(code *)**(undefined4 **)(param_1 + 4))(param_1,0,0x5c);
  *(undefined4 **)(param_1 + 400) = puVar1;
  *puVar1 = FUN_005115c4;
  *(undefined1 **)(*(int *)(param_1 + 400) + 4) = &LAB_0051126a;
  *(code **)(*(int *)(param_1 + 400) + 8) = FUN_00511457;
  *(code **)(*(int *)(param_1 + 400) + 0xc) = FUN_00511060;
  iVar2 = 0x10;
  do {
    *(code **)(iVar2 + *(int *)(param_1 + 400)) = FUN_00511060;
    iVar2 = iVar2 + 4;
  } while (iVar2 < 0x50);
  *(code **)(*(int *)(param_1 + 400) + 0x10) = FUN_005105bf;
  *(code **)(*(int *)(param_1 + 400) + 0x48) = FUN_005107fb;
  FUN_005115c4(param_1);
  return;
}


