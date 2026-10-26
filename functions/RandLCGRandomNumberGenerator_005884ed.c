int sub_5884ED()
{
  int v0; // eax
  unsigned int v1; // ecx

  v0 = TLSValueRetrievalWithInit();
  v1 = 214013 * *(_DWORD *)(v0 + 20) + 2531011;
  *(_DWORD *)(v0 + 20) = v1;
  return HIWORD(v1) & 0x7FFF;
}
