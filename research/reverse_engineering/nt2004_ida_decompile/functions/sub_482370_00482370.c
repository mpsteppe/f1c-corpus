int __thiscall sub_482370(_DWORD *this)
{
  int v2; // ecx
  int *v3; // eax
  int v4; // eax
  int v5; // eax

  sub_4CDC80(0);
  v2 = this[216];
  if ( v2 >= 0 && v2 < this[220] )
  {
    v3 = (int *)this[217];
    if ( v2 <= 0 )
    {
LABEL_6:
      if ( v3 )
      {
        v4 = *v3;
        if ( v4 )
        {
          v5 = (*(int (__thiscall **)(int))(*(_DWORD *)v4 + 28))(v4);
          if ( v5 || strlen(0) )
            sub_4CD9C0(v5, 0);
        }
      }
    }
    else
    {
      while ( v3 )
      {
        v3 = (int *)v3[1];
        if ( --v2 <= 0 )
          goto LABEL_6;
      }
    }
  }
  return sub_482200();
}
