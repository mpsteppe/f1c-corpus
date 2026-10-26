int __userpurge sub_59AD49@<eax>(int a1@<ebp>, int a2)
{
  char *v2; // eax

  SEHHandlerInit();
  *(_BYTE *)(a1 - 32) = *(_BYTE *)(a1 - 13);
  ReferenceCountDecrementWithConditionalFree((_DWORD *)(a1 - 32), 0);
  v2 = Strlen("string too long");
  BufferWriteWithNullTerminate((_DWORD *)(a1 - 32), "string too long", (unsigned int)v2);
  *(_DWORD *)(a1 - 4) = 0;
  CExceptionInitHandler_ada3(a1 - 32);
  *(_DWORD *)(a1 - 60) = &std::length_error::`vftable';
  CxxThrowException8(a1 - 60, &_TI3_AVlength_error_std__);
  return CExceptionInitHandler_ada3(a2);
}

