char __thiscall sub_41C8B0(_DWORD *this, int a2, int a3)
{
  _DWORD *v3; // ecx
  char result; // al

  v3 = (_DWORD *)*this;
  if ( !v3 )
    return 0;
  result = 0;
  if ( *v3 && v3[2] && v3[3] && v3[4] )
  {
    if ( a2 )
    {
      sub_41C110(v3, a2, a3, 0.0, 0.0, 1.0, 1.0, 1.0, 1.0, 0.0);
      return 1;
    }
  }
  return result;
}
