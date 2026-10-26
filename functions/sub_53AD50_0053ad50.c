void __thiscall sub_53AD50(void *this)
{
  void *v2; // [esp-4h] [ebp-8h]

  v2 = (void *)*((_DWORD *)this + 4);
  *(_DWORD *)this = off_5B8910;
  FreeWrapper_7bcf(v2);
  FreeWrapper_7bcf(*((LPVOID *)this + 8));
  FreeWrapper_7bcf(*((LPVOID *)this + 12));
  EmptyStub_0170();
}
