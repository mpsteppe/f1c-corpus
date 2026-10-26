int __thiscall sub_4D8760(_DWORD *this, int a2, char a3)
{
  char v5; // al
  int v6; // ebx
  bool v7; // bl
  bool v8; // al
  int result; // eax
  bool v10; // [esp+Fh] [ebp-1h]
  char v11; // [esp+14h] [ebp+4h]

  v10 = this[a2 + 4] != 0;
  if ( dword_7CF638 || (v5 = sub_4D9280(a2), v11 = 0, v5) )
    v11 = 1;
  v7 = 1;
  if ( *this != -1 )
  {
    v6 = sub_4D91E0(*this);
    if ( v6 >= sub_4D91E0(a2) && *this != a2 )
      v7 = 0;
  }
  v8 = sub_404F10(&dword_5EA43C);
  if ( v10 && v11 && v7 && !v8 )
  {
    if ( a3 == 1 )
      this[55] = 0;
    else
      this[55] = 1056964608;
    *this = a2;
    sub_4D7E30((int *)this[a2 + 4]);
    return 0;
  }
  else
  {
    result = 1;
    if ( a2 == -1 )
      *this = -1;
  }
  return result;
}
