_DWORD *__thiscall sub_491710(_DWORD *this, int a2)
{
  _DWORD *v3; // eax

  v3 = (_DWORD *)OperatorNewNhMallocWrapper(76);
  if ( v3 )
    *this = sub_490B00(v3, a2);
  else
    *this = 0;
  return this;
}
