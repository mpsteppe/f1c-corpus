void __thiscall sub_659FC9(_DWORD *this)
{
  void *v1; // esi

  v1 = (void *)this[10];
  if ( v1 )
  {
    sub_659FC9(this[10]);
    j__free(v1);
  }
}
