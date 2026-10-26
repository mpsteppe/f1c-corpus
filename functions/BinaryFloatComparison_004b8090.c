bool __stdcall sub_4B8090(float a1)
{
  char v2[8]; // [esp+8h] [ebp-8h] BYREF

  ConditionalAllocInitDispatch(LODWORD(a1));
  strcpy(v2, "xxxx");
  a1 = -1.0;
  FileWriteWithBackendDispatch(v2, 4);
  FileWriteWithBackendDispatch(&a1, 4);
  return !strcmp(v2, off_5D2434) && a1 == flt_5D2438;
}
