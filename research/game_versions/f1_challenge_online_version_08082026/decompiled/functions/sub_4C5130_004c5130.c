int __thiscall sub_4C5130(_DWORD *this)
{
  int v1; // edx
  int *v2; // eax
  int v3; // eax
  int *v5; // eax
  int v6; // eax

  v1 = this[6];
  if ( v1 >= 0 && v1 < this[5] )
  {
    v2 = (int *)this[2];
    if ( v1 <= 0 )
    {
LABEL_6:
      if ( v2 )
      {
        v3 = *v2;
        if ( v3 )
          return *(_DWORD *)v3;
      }
    }
    else
    {
      while ( v2 )
      {
        v2 = (int *)v2[1];
        if ( --v1 <= 0 )
          goto LABEL_6;
      }
    }
  }
  v5 = (int *)this[2];
  this[4] = v5;
  if ( v5 && (v6 = *v5) != 0 )
    return *(_DWORD *)v6;
  else
    return 0;
}
