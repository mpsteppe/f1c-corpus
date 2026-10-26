int __thiscall sub_4E2960(_DWORD *this, int a2)
{
  int v2; // esi
  int result; // eax
  int v4; // edx
  int *v5; // ecx
  int v6; // ecx

  v2 = a2;
  result = 0;
  if ( a2 < this[3] )
  {
    if ( a2 < 0 )
    {
      this[2] = 0;
    }
    else
    {
      this[2] = *this;
      if ( a2 > 0 )
      {
        do
        {
          v4 = this[2];
          if ( !v4 )
            break;
          --v2;
          this[2] = *(_DWORD *)(v4 + 4);
        }
        while ( v2 > 0 );
      }
    }
    v5 = (int *)this[2];
    if ( v5 )
    {
      v6 = *v5;
      if ( v6 )
        return *(_DWORD *)v6;
    }
  }
  return result;
}
