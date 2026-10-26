int __thiscall sub_463CD0(int *this)
{
  _DWORD *v2; // ecx
  int result; // eax
  float v4; // [esp+0h] [ebp-8h]

  v2 = (_DWORD *)*this;
  result = v2[4081];
  if ( result )
  {
    InputCommandDispatchToEntities(v2);
    v4 = dbl_8AFE98;
    SessionSynchronizer(*this, v4);
    result = *this;
  }
  *(_BYTE *)(*this + 884) = 0;
  return result;
}

