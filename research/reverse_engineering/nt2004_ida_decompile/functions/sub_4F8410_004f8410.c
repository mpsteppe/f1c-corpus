bool __thiscall sub_4F8410(_DWORD *this, int a2)
{
  int v3; // esi
  bool result; // al

  result = 0;
  if ( a2 )
  {
    v3 = *(_DWORD *)(a2 + 25248);
    if ( sub_4F7D30(this + 1, v3) != -2 || sub_4F7D30(this + 98, v3) != -2 )
      return 1;
  }
  return result;
}
