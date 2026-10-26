int __thiscall sub_48BE30(_DWORD *this, int a2)
{
  int result; // eax
  int v4; // eax
  int v5; // eax
  int v6; // ecx
  int v7; // [esp-8h] [ebp-Ch]
  int v8; // [esp-4h] [ebp-8h]

  result = this[211];
  if ( result )
  {
    v4 = *(_DWORD *)(result + 20);
    if ( a2 == 1 )
      v5 = v4 + 1;
    else
      v5 = v4 - 1;
    v6 = this[214];
    if ( v6 == 4 )
    {
      sub_432AE0(&byte_B64150, this[212], v5);
      return (*(int (__thiscall **)(_DWORD *, int, int))(*this + 164))(this, v7, v8);
    }
    else
    {
      sub_432A10((int)&byte_B64150, v6, this[213], v5);
      return (*(int (__thiscall **)(_DWORD *))(*this + 164))(this);
    }
  }
  return result;
}
