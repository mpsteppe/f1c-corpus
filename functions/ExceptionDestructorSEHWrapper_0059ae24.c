int __usercall sub_59AE24@<eax>(int a1@<ebp>)
{
  _DWORD *v1; // ecx
  _DWORD *v2; // esi

  SEHHandlerInit();
  v2 = v1;
  *(_DWORD *)(a1 - 16) = v1;
  *v1 = &std::logic_error::`vftable';
  *(_DWORD *)(a1 - 4) = 0;
  ReferenceCountDecrementWithConditionalFree(v1 + 3, 1);
  *(_DWORD *)(a1 - 4) = -1;
  return MSVCExceptionDestructor(v2);
}
