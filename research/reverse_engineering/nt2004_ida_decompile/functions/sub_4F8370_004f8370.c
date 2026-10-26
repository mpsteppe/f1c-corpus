int __thiscall sub_4F8370(_DWORD *this, int a2)
{
  int result; // eax
  int v4; // esi

  result = -1;
  if ( a2 )
  {
    v4 = *(_DWORD *)(a2 + 25248);
    result = sub_4F7D30(this + 98, v4);
    if ( result < 0 )
      return sub_4F7D30(this + 1, v4);
  }
  return result;
}
