int __thiscall sub_501F60(_DWORD *this, int a2, char a3)
{
  char v5; // al
  int v6; // ebp
  int v7; // ebx
  bool v8; // bl
  bool v9; // al
  int result; // eax
  bool v11; // [esp+13h] [ebp-1h]
  char v12; // [esp+18h] [ebp+4h]

  v11 = this[a2 + 9] != 0;
  if ( dword_767A54 || (v5 = sub_502970(a2), v12 = 0, v5) )
    v12 = 1;
  v6 = this[4];
  v8 = 1;
  if ( v6 != -1 )
  {
    v7 = sub_502930(a2);
    if ( sub_502930(v6) >= v7 && this[4] != a2 )
      v8 = 0;
  }
  v9 = sub_405BF0(&dword_629124);
  if ( v11 && v12 && v8 && !v9 )
  {
    if ( a3 == 1 )
      this[24] = 0;
    else
      this[24] = 1056964608;
    this[4] = a2;
    sub_501600((int *)this[a2 + 9]);
    return 0;
  }
  else
  {
    result = 1;
    if ( a2 == -1 )
      this[4] = -1;
  }
  return result;
}
