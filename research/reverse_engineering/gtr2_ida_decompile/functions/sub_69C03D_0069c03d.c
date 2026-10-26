int __thiscall sub_69C03D(void *this, int a2, int a3)
{
  _DWORD *v4; // eax
  _DWORD *v5; // esi
  int result; // eax

  v4 = (_DWORD *)sub_65B229(20);
  if ( v4 )
    v5 = sub_67ED1B(v4, a3, 0, (int)&off_741D70);
  else
    v5 = 0;
  if ( !v5 )
    return 0;
  result = sub_69BE8D(this, a2, (int)v5);
  v5[2] = 0;
  return result;
}
