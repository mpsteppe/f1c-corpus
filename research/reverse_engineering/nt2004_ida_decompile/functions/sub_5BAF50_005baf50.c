_DWORD *__fastcall sub_5BAF50(int a1, char a2, _DWORD *a3)
{
  _DWORD *result; // eax
  int v4; // edx

  result = a3;
  *(_BYTE *)a1 = a2;
  v4 = *a3;
  *(_DWORD *)(a1 + 2048) = 5;
  *(_DWORD *)(a1 + 1) = v4;
  return result;
}
