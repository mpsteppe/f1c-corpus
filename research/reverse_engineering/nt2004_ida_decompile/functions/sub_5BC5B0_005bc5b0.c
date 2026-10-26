int __fastcall sub_5BC5B0(int *a1, char a2, _DWORD *a3)
{
  int result; // eax

  *(_BYTE *)*a1 = a2;
  ++*a3;
  result = *a1 + 1;
  *a1 = result;
  return result;
}
