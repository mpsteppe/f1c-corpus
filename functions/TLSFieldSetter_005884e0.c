int __cdecl sub_5884E0(int a1)
{
  int result; // eax

  result = TLSValueRetrievalWithInit();
  *(_DWORD *)(result + 20) = a1;
  return result;
}
