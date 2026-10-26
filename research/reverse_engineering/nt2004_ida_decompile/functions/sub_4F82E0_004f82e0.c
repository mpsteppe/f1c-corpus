int __thiscall sub_4F82E0(_DWORD *this, int a2)
{
  int result; // eax
  int v4; // esi

  result = -2;
  if ( a2 )
  {
    v4 = *(_DWORD *)(a2 + 25248);
    result = sub_4F7D60(this + 98, v4);
    if ( result < 0 )
      return sub_4F7D60(this + 1, v4);
  }
  return result;
}
