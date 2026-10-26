int __thiscall LinkedListVirtualDispatch(_DWORD *this)
{
  _DWORD *i; // esi

  for ( i = (_DWORD *)this[17]; i; i = (_DWORD *)i[35] )
    (*(void (__thiscall **)(_DWORD *))(*i + 164))(i);
  return 0;
}

