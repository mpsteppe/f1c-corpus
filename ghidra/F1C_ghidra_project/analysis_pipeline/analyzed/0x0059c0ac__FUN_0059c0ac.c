// Function: FUN_0059c0ac @ 0059c0ac
// Size (bytes): 123


uint FUN_0059c0ac(uint param_1)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  undefined1 uVar5;
  undefined2 local_8;
  
  uVar4 = param_1;
  if (param_1 < 0x100) {
    if ((*(byte *)((int)&DAT_008d47e0 + param_1 + 1) & 0x20) == 0x20) {
      uVar4 = (uint)(byte)(&DAT_008d46e0)[param_1];
    }
  }
  else {
    uVar5 = (undefined1)param_1;
    uVar2 = param_1 >> 8;
    uVar1 = param_1 >> 8;
    param_1 = CONCAT13(uVar5,CONCAT12((char)uVar1,(undefined2)param_1));
    if (((*(byte *)((int)&DAT_008d47e0 + (uVar2 & 0xff) + 1) & 4) != 0) &&
       (iVar3 = FUN_00591fa1(DAT_008d48e4,0x200,(int)&param_1 + 2,2,&local_8,2,DAT_008d46bc,1),
       iVar3 != 0)) {
      uVar4 = (uint)CONCAT11((undefined1)local_8,local_8._1_1_);
    }
  }
  return uVar4;
}


