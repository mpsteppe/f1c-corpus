int __usercall sub_59AF68@<eax>(int a1@<ebp>)
{
  char *v1; // eax

  SEHHandlerInit();
  *(_BYTE *)(a1 - 32) = *(_BYTE *)(a1 - 13);
  ReferenceCountDecrementWithConditionalFree((_DWORD *)(a1 - 32), 0);
  v1 = Strlen("invalid string position");
  BufferWriteWithNullTerminate((_DWORD *)(a1 - 32), "invalid string position", (unsigned int)v1);
  *(_DWORD *)(a1 - 4) = 0;
  CExceptionInitHandler_ada3(a1, a1 - 32);
  *(_DWORD *)(a1 - 60) = &std::out_of_range::`vftable';
  CxxThrowException8(a1 - 60, &_TI3_AVout_of_range_std__);
  return ExceptionObjectDestructorWithSEH();
}

