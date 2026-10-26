int __thiscall sub_4E0CD0(_DWORD *this)
{
  _DWORD *i; // esi

  for ( ; (unsigned __int8)sub_4DF840(); this = (_DWORD *)sub_4DF700() )
    ;
  for ( i = (_DWORD *)this[13]; i; i = (_DWORD *)i[35] )
    (*(void (__thiscall **)(_DWORD *))(*i + 156))(i);
  return 0;
}
