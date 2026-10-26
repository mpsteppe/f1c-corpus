int __thiscall sub_4F8320(_DWORD *this, int a2)
{
  int result; // eax
  int v4; // edi
  _DWORD *v5; // ecx

  result = -2;
  if ( a2 )
  {
    v4 = *(_DWORD *)(a2 + 25248);
    result = sub_4F7D30(this + 98, v4);
    v5 = this + 1;
    if ( result < 0 )
    {
      result = sub_4F7D30(v5, v4);
      if ( result < 0 )
        return result;
      v5 = this + 98;
    }
    return sub_4F7CF0(v5, result);
  }
  return result;
}
