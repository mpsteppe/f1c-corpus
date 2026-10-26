void __cdecl __noreturn sub_679F05(int a1, int a2)
{
  void (__cdecl *v2)(int, int); // eax

  v2 = *(void (__cdecl **)(int, int))(a1 + 64);
  if ( v2 )
    v2(a1, a2);
  sub_6E0030(a1);
  __debugbreak();
}
