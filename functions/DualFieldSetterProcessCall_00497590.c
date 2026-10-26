int __thiscall sub_497590(void *this, int a2, int a3, int a4)
{
  *(_DWORD *)(a2 + 64) = this;
  *(_DWORD *)(a2 + 152) = a3;
  return ObjectRegistration(a2);
}
