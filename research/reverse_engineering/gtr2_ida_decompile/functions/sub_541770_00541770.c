int __thiscall sub_541770(_DWORD *this, int a2, int a3)
{
  int result; // eax
  int *v4; // ecx
  int v5; // edx
  _DWORD v6[3]; // [esp+0h] [ebp-Ch] BYREF

  result = (int)this;
  this[7] = a2;
  if ( a2 )
  {
    if ( a2 == 1 )
    {
      v4 = (int *)this[9];
    }
    else
    {
      if ( a2 != 2 )
        return result;
      v4 = (int *)this[10];
    }
  }
  else
  {
    v4 = (int *)this[8];
  }
  if ( v4 )
  {
    v5 = *v4;
    memset(v6, 0, sizeof(v6));
    return (*(int (__thiscall **)(int *, int, int, _DWORD *, int, int, int))(v5 + 4))(
             v4,
             2,
             result + 8,
             v6,
             a3,
             1065353216,
             1);
  }
  return result;
}
