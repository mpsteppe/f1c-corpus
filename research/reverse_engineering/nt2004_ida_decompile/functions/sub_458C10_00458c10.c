char __thiscall sub_458C10(_DWORD *this, int a2, int a3, int a4, int a5, int a6)
{
  char result; // al
  int v7; // ebx

  result = 0;
  if ( a2 && a3 && *(float *)&a4 != 0.0 )
  {
    v7 = this[2];
    if ( v7 == 1 )
    {
      return sub_458E00(a2, a3, a4, a5, a6);
    }
    else if ( v7 )
    {
      if ( v7 == 2 )
        return sub_459440(a2, a3, *(float *)&a4, a5, *(float *)&a6);
    }
    else
    {
      return sub_4590A0(a2, a3, a4, *(float *)&a5, a6);
    }
  }
  return result;
}
