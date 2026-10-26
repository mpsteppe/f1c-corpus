int __stdcall sub_58A5F7(int a1, int a2, int a3, int (__thiscall *a4)(int))
{
  int result; // eax
  int i; // [esp+30h] [ebp+8h]

  result = a3 * a2;
  for ( i = a3 * a2 + a1; --a3 >= 0; result = a4(i) )
    i -= a2;
  return result;
}

