int __cdecl sub_563F20(__int16 **a1, __int16 **a2)
{
  __int16 *v2; // esi
  int v3; // edi
  int result; // eax

  v2 = *a1;
  v3 = StringComparisonWithConstantDispatch(*a2, *(const char **)(dword_8D46B4 + 128), 0);
  result = StringComparisonWithConstantDispatch(v2, *(const char **)(dword_8D46B4 + 128), 0) - v3;
  if ( !*(_DWORD *)(dword_8D46B4 + 132) )
    return -result;
  return result;
}

