int __thiscall sub_4F03B0(_DWORD *this, int a2)
{
  int v2; // eax
  int v3; // edx
  int v4; // ecx

  v2 = a2;
  if ( a2 < 0 || a2 >= this[3] )
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
        v3 = this[2];
        if ( !v3 )
          break;
        --v2;
        this[2] = *(_DWORD *)(v3 + 4);
      }
      while ( v2 > 0 );
    }
  }
  v4 = this[2];
  if ( v4 )
    return *(_DWORD *)v4;
  else
    return 0;
}
