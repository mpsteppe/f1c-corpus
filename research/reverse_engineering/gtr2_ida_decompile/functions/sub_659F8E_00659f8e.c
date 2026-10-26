void __thiscall sub_659F8E(_DWORD *this)
{
  void *v1; // esi

  v1 = (void *)this[1];
  if ( v1 )
  {
    sub_659F8E(this[1]);
    j__free(v1);
  }
}
