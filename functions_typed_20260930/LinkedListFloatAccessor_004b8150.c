double __thiscall sub_4B8150(_DWORD *this, int a2)
{
  int v2; // edx
  int *v3; // eax
  int v4; // eax

  v2 = a2;
  if ( a2 >= 0 && a2 < this[435] )
  {
    v3 = (int *)this[432];
    if ( a2 <= 0 )
    {
LABEL_6:
      if ( v3 )
      {
        v4 = *v3;
        if ( v4 )
          return *(float *)v4;
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
  return -1.0;
}

