_DWORD *__stdcall sub_6477D3(int a1, int a2)
{
  _DWORD *result; // eax

  result = *(_DWORD **)(a1 + 24);
  *result += a2;
  result[1] -= a2;
  return result;
}
