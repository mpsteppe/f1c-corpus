int __thiscall sub_54F1F0(_DWORD *this, int a2)
{
  int result; // eax
  int v4; // esi

  result = -2;
  if ( a2 )
  {
    v4 = *(_DWORD *)(a2 + 22468);
    result = sub_54EE80(this + 210, v4);
    if ( result < 0 )
      return sub_54EE80(this + 1, v4);
  }
  return result;
}
