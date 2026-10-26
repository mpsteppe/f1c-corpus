int __thiscall sub_69C1B4(_DWORD *this, int a2, _DWORD *a3)
{
  _DWORD *v4; // eax
  _DWORD *v5; // eax
  int *v7; // ecx
  int v8; // edx

  if ( sub_69BE34(this, a3, &a3) < 0 )
  {
    sub_694B97((int)this, 0, 3058, "array dimensions must be literal scalar expressions");
    return 0;
  }
  v4 = (_DWORD *)sub_65B229(24);
  if ( v4 )
    v5 = sub_67F254(v4, 0, (int)a3);
  else
    v5 = 0;
  if ( !v5 )
    return 0;
  v7 = &a2;
  if ( a2 )
  {
    do
    {
      v8 = *v7;
      if ( *(_DWORD *)(*v7 + 4) != 8 )
        break;
      v7 = (int *)(v8 + 16);
    }
    while ( *(_DWORD *)(v8 + 16) );
  }
  v5[4] = *v7;
  *v7 = (int)v5;
  return a2;
}
