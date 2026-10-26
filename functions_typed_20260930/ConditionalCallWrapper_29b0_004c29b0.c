_DWORD *__thiscall sub_4C29B0(_DWORD *this, int a2)
{
  _DWORD *v2; // eax
  int v3; // edx

  v2 = (_DWORD *)LinkedListDereference(this);
  if ( v2 )
    return SessionConfigReader(v2, a2);
  else
    return (_DWORD *)v3;
}

