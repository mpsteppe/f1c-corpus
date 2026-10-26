void __cdecl __noreturn sub_53E4E5(int a1)
{
  (*(void (__cdecl **)(int))(*(_DWORD *)a1 + 8))(a1);
  longjmp((int *)(*(_DWORD *)a1 + 132), 1);
}
