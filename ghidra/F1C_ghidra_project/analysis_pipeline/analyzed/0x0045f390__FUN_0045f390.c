// Function: FUN_0045f390 @ 0045f390
// Size (bytes): 272


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 __fastcall FUN_0045f390(int param_1)

{
  char cVar1;
  float10 fVar2;
  float local_60;
  float local_5c;
  float local_58;
  undefined1 local_54 [4];
  undefined1 local_50 [80];
  
  if (*(int *)(param_1 + 0x3fc4) == 3) {
    FUN_00568ba0();
    FUN_00568be0();
    FUN_00568c60();
    fVar2 = (float10)DAT_0059e440;
    local_60 = DAT_0059e440;
    local_5c = 0.0;
    do {
      if (fVar2 < (float10)DAT_0059e440 != (fVar2 == (float10)DAT_0059e440)) {
        FUN_0057a5a0();
        local_60 = 4.0;
      }
      cVar1 = FUN_0057a610(&local_58,local_54,local_50);
      if (cVar1 != '\0') {
        FUN_004f9fc0();
        FUN_0042bda0((double)local_58);
        FUN_0042cf10();
        FUN_0045c8b0();
        FUN_004b0170();
        return 1;
      }
      fVar2 = (float10)FUN_00568cf0();
      local_5c = (float)((float10)local_5c + fVar2);
      fVar2 = (float10)local_60 - fVar2;
      local_60 = (float)fVar2;
    } while (local_5c < _DAT_0059f118);
    FUN_004b0170();
  }
  return 0;
}


