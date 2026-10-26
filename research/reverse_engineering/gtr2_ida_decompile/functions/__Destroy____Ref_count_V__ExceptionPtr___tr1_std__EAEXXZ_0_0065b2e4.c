void __thiscall std::tr1::_Ref_count<__ExceptionPtr>::_Destroy(_DWORD *this)
{
  void *v1; // esi

  v1 = (void *)this[3];
  if ( v1 )
  {
    std::tr1::_Ref_count<__ExceptionPtr>::_Destroy(this[3]);
    j__free(v1);
  }
}
