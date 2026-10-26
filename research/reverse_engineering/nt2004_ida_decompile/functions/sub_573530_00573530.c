int __stdcall sub_573530(_DWORD *a1, int a2)
{
  int i; // esi
  int result; // eax

  sub_5735F0(a1, 1);
  for ( i = 0; i < 36992; i += 18496 )
    result = sub_5765C0(i + *a1, 0);
  return result;
}
