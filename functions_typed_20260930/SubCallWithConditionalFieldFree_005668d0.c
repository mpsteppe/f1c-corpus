int __thiscall sub_5668D0(_DWORD *this)
{
  int result; // eax
  void *v3; // esi

  result = ConditionalFileHandleCloseWithFlagDispatch(this);
  v3 = (void *)this[1];
  if ( v3 )
    return FreeWrapper_7bcf(v3);
  return result;
}

