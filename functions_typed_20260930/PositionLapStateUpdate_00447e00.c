int __thiscall sub_447E00(_DWORD *this, int a2, int a3)
{
  int result; // eax
  int v5; // eax
  int v6; // eax
  int v7; // ecx
  int v8; // ecx
  int v9; // ecx
  int v10; // edx
  int v11; // ecx
  int v12; // ecx
  int v13; // ecx

  result = a2;
  if ( a2 != this[1981] )
  {
    if ( a2 == -1 )
    {
      this[1982] = 1;
    }
    else if ( a2 )
    {
      this[1982] = 2 * (a2 > this[1980]) - 1;
    }
    else
    {
      this[1982] = 0;
    }
    this[1981] = a2;
    v5 = this[1982];
    this[1980] = 0;
    if ( v5 <= 0 )
    {
      v10 = this[1958];
      this[1951] = this[1957];
      v11 = this[1984] + 20;
      this[1952] = v10;
      SoundEffectTrigger_89a0(v11);
      if ( !a3 )
      {
        result = this[24];
        v12 = this[25];
        this[13] = 2;
        this[14] = result;
        this[15] = v12;
        return result;
      }
      if ( a3 == 4 )
        this[13] = 5;
    }
    else
    {
      v6 = this[1954];
      v7 = this[1984] + 20;
      this[1951] = this[1953];
      this[1952] = v6;
      SoundEffectTrigger(v7);
      if ( !a3 )
      {
        result = this[24];
        v8 = this[25];
        this[13] = 3;
        this[14] = result;
        this[15] = v8;
        return result;
      }
      if ( a3 == 4 )
      {
        result = this[24];
        v9 = this[25];
        this[13] = 6;
        this[14] = result;
        this[15] = v9;
        return result;
      }
    }
    result = this[24];
    v13 = this[25];
    this[14] = result;
    this[15] = v13;
  }
  return result;
}

