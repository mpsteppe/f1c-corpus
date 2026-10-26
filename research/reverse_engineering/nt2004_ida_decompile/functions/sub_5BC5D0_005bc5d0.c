int __fastcall sub_5BC5D0(int *a1, int a2, _DWORD *a3)
{
  int result; // eax

  *(_DWORD *)*a1 = a2;
  *a3 += 4;
  result = *a1 + 4;
  *a1 = result;
  return result;
}
