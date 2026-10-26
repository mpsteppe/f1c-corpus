int __stdcall sub_67CBAE(int a1, int a2, int a3)
{
  int (__cdecl *v3)(int, int, int); // eax

  v3 = *(int (__cdecl **)(int, int, int))(a1 + 80);
  if ( !v3 )
    sub_679F05(a1, (int)"Call to NULL read function");
  return v3(a1, a2, a3);
}
