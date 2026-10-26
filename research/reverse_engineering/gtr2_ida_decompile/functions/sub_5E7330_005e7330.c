_DWORD *__thiscall sub_5E7330(void **this)
{
  void *v2; // edi
  _DWORD *v3; // eax
  _DWORD *result; // eax

  v2 = this[29];
  if ( v2 )
  {
    nullsub_7(this[29]);
    j__free(v2);
  }
  this[29] = 0;
  v3 = operator new(0x88u);
  if ( v3 )
  {
    result = sub_5E70C0(v3);
    this[29] = result;
  }
  else
  {
    result = 0;
    this[29] = 0;
  }
  return result;
}
