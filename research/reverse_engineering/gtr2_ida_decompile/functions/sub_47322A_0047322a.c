int __thiscall sub_47322A(char *this, int a2, int a3)
{
  int result; // eax
  _DWORD *v4; // eax
  _DWORD *v5; // esi
  void *retaddr; // [esp+10h] [ebp+0h]

  if ( a3 <= 0 )
  {
    v4 = operator new(8u);
    v5 = v4;
    if ( v4 )
    {
      *v4 = 0;
      v4[1] = -1;
      sub_615860(a2);
    }
    else
    {
      v5 = 0;
    }
    return sub_5FDFB0(v5, 1);
  }
  else
  {
    result = sub_47F6E0(this + 52, a3);
    if ( result )
      return sub_615860(retaddr);
  }
  return result;
}
