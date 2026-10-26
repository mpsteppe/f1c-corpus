int __stdcall sub_59ED70(_DWORD *a1, int a2)
{
  int i; // esi
  int result; // eax

  sub_5FDFB0(a1, 1);
  for ( i = 0; i < 616; i += 308 )
    result = sub_5E5780(i + *a1, 0);
  return result;
}
