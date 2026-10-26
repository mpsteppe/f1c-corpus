int __thiscall sub_4C9D30(_DWORD *this)
{
  void *v1; // esi
  int result; // eax

  v1 = (void *)this[9];
  if ( v1 )
  {
    RecursiveTreeFree(this[9]);
    return FreeWrapper_7bcf(v1);
  }
  return result;
}

