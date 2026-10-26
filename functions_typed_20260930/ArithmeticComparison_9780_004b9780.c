_DWORD *__thiscall sub_4B9780(_DWORD *this)
{
  _DWORD *v2; // eax

  v2 = (_DWORD *)OperatorNewNhMallocWrapper(3996);
  if ( v2 )
    *this = CarPhysicsStateInitializer(v2);
  else
    *this = 0;
  return this;
}

