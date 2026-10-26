// f1c  0x00513bd1  size=40
int __cdecl sub_513BD1(int a1, int a2, int a3)
{
  int (__cdecl *v3)(int, int, int); // eax

  v3 = *(int (__cdecl **)(int, int, int))(a1 + 80);
  if ( v3 )
    return v3(a1, a2, a3);
  else
    return sub_511869(a1, (int)"Call to NULL read function");
}
