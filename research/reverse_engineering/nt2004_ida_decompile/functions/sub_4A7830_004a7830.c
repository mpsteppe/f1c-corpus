int __thiscall sub_4A7830(_DWORD *this, int a2, int a3, int a4, int a5)
{
  int i; // esi
  int v7; // ecx
  int *v8; // eax
  int v9; // eax

  if ( this[67] )
  {
    for ( i = 0; i < this[71]; ++i )
    {
      v7 = i;
      if ( i >= 0 && i < this[71] )
      {
        v8 = (int *)this[68];
        if ( i <= 0 )
        {
LABEL_8:
          if ( v8 )
          {
            v9 = *v8;
            goto LABEL_11;
          }
        }
        else
        {
          while ( v8 )
          {
            v8 = (int *)v8[1];
            if ( --v7 <= 0 )
              goto LABEL_8;
          }
        }
      }
      v9 = 0;
LABEL_11:
      sub_4A73B0((int)this, v9);
    }
  }
  return 0;
}
