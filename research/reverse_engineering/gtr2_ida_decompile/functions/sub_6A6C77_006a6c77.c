int __thiscall sub_6A6C77(_DWORD *this, _DWORD *a2, int a3)
{
  int v4; // edi

  v4 = 0;
  if ( sub_6A2293(*a2 & 0xFFF00000) )
  {
    if ( !a2[5] )
      return 1;
    if ( a3 )
    {
      sub_686791((int)this, a2[15], 4500, "dependent texture read chain cannot exceed 1 in ps_1_4");
      return 0;
    }
    a3 = 1;
  }
  if ( a2[5] )
  {
    while ( sub_6A6C77(*(_DWORD *)(this[6] + 4 * *(_DWORD *)(a2[6] + 4 * v4)), a3) )
    {
      if ( (unsigned int)++v4 >= a2[5] )
        return 1;
    }
    return 0;
  }
  return 1;
}
