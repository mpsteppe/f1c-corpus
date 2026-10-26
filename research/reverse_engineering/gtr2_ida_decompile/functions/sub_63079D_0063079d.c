void __usercall __noreturn sub_63079D(int a1@<ebp>)
{
  ((void (*)(void))loc_634C58)();
  sub_406300();
  *(_DWORD *)(a1 - 4) = 0;
  sub_4062A0();
  *(_DWORD *)(a1 - 80) = &std::length_error::`vftable';
  sub_63153D(a1 - 80, &_TI3_AVlength_error_std___0);
  __debugbreak();
}
