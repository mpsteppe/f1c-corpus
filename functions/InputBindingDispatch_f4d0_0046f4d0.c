int __thiscall InputBindingDispatch_f4d0(_DWORD **this)
{
  _DWORD *v1; // eax
  char *v2; // eax

  v1 = (_DWORD *)(*(int (__thiscall **)(_DWORD *, int))(*this[16] + 28))(this[16], 44);
  if ( v1 )
  {
    v2 = UIScreenTextAccessor(v1);
    if ( v2 )
      ClearBufferAndInit(v2);
  }
  return 0;
}
