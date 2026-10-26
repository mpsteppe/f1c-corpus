int __thiscall sub_44A530(_DWORD *this, int a2, int a3)
{
  int result; // eax
  int v5; // eax
  int v6; // eax
  int v7; // ecx
  int v8; // edx
  int v9; // ecx
  int v10; // ecx

  result = a2;
  if ( a2 != this[2152] )
  {
    if ( a2 == -1 )
    {
      this[2153] = 1;
    }
    else if ( a2 )
    {
      this[2153] = 2 * (a2 > this[2151]) - 1;
    }
    else
    {
      this[2153] = 0;
    }
    this[2152] = a2;
    v5 = this[2153];
    this[2151] = 0;
    if ( v5 <= 0 )
    {
      v8 = this[2127];
      this[2120] = this[2126];
      v9 = this[2155] + 92;
      this[2121] = v8;
      sub_5262A0(v9);
      if ( a3 )
      {
        if ( a3 == 4 )
          this[13] = 5;
      }
      else
      {
        this[13] = 2;
      }
    }
    else
    {
      v6 = this[2123];
      v7 = this[2155] + 92;
      this[2120] = this[2122];
      this[2121] = v6;
      sub_5261A0(v7);
      if ( a3 )
      {
        if ( a3 == 4 )
          this[13] = 6;
      }
      else
      {
        this[13] = 3;
      }
    }
    result = this[32];
    v10 = this[33];
    this[14] = result;
    this[15] = v10;
  }
  return result;
}
