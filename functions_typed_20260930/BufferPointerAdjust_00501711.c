_DWORD *__cdecl sub_501711(int a1, int a2)
{
  _DWORD *result; // eax

  result = *(_DWORD **)(a1 + 20);
  *result += a2;
  result[1] -= a2;
  return result;
}

