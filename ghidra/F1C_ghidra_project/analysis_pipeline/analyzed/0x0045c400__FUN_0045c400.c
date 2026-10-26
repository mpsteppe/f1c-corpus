// Function: FUN_0045c400 @ 0045c400
// Size (bytes): 587


bool FUN_0045c400(int param_1,undefined4 param_2,int param_3,int param_4,undefined4 param_5,
                 int param_6,undefined4 param_7,int param_8,undefined4 param_9,int param_10,
                 undefined4 param_11,int param_12)

{
  char cVar1;
  char cVar2;
  char cVar3;
  char cVar4;
  char cVar5;
  char cVar6;
  char cVar7;
  int unaff_retaddr;
  int in_stack_00001ad4;
  int *in_stack_00003790;
  
  FUN_005881c0();
  FUN_0042e320();
  FUN_004f34e0();
  FUN_004f4270();
  *in_stack_00003790 = 0;
  cVar1 = FUN_00568a60();
  if (cVar1 != '\0') {
    *in_stack_00003790 = *in_stack_00003790 + unaff_retaddr;
  }
  cVar2 = FUN_00568a60();
  if (cVar2 != '\0') {
    *in_stack_00003790 = *in_stack_00003790 + unaff_retaddr;
  }
  *in_stack_00003790 = *in_stack_00003790 + param_3;
  cVar3 = FUN_00568a60();
  if (cVar3 != '\0') {
    *in_stack_00003790 = *in_stack_00003790 + unaff_retaddr;
  }
  cVar4 = FUN_00568a60();
  if (cVar4 != '\0') {
    *in_stack_00003790 = *in_stack_00003790 + unaff_retaddr;
  }
  cVar5 = FUN_00568a60();
  if (cVar5 != '\0') {
    *in_stack_00003790 = *in_stack_00003790 + unaff_retaddr;
  }
  cVar6 = FUN_00568a60();
  if (cVar6 != '\0') {
    *in_stack_00003790 = *in_stack_00003790 + unaff_retaddr;
  }
  cVar7 = FUN_00568a60();
  if (cVar7 != '\0') {
    *in_stack_00003790 = *in_stack_00003790 + unaff_retaddr;
  }
  if (param_12 != 0) {
    FUN_00587bcf();
  }
  if (param_10 != 0) {
    FUN_00587bcf();
  }
  if (param_8 != 0) {
    FUN_00587bcf();
  }
  if (param_6 != 0) {
    FUN_00587bcf();
  }
  if (param_4 != 0) {
    FUN_00587bcf();
  }
  if (param_1 != 0) {
    FUN_00587bcf();
  }
  FUN_0042ddd0();
  if (in_stack_00001ad4 != 0) {
    FUN_00587bcf();
  }
  return cVar7 != '\0' &&
         (cVar6 != '\0' &&
         (cVar5 != '\0' && (cVar4 != '\0' && (cVar3 != '\0' && (cVar2 != '\0' && cVar1 != '\0')))));
}


