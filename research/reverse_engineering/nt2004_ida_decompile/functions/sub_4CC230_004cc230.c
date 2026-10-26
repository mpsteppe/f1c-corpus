int __thiscall sub_4CC230(_DWORD *this)
{
  int result; // eax
  int v3; // eax
  int v4; // edx
  int v5; // ecx
  int v6; // eax
  int v7; // edx
  int v8; // ecx
  int v9; // eax
  int v10; // edx
  int v11; // ecx
  int v12; // eax
  int v13; // edx
  int v14; // ecx
  int v15; // eax
  int v16; // edx
  int v17; // ecx
  int v18; // ecx
  int v19; // edx
  int v20; // [esp-4h] [ebp-8h]
  int v21; // [esp-4h] [ebp-8h]

  if ( this[2085] == 1 )
  {
    v12 = this[1427];
    v13 = this[1428];
    this[1425] = 0;
    v14 = this[1425];
    if ( v14 >= v12 )
    {
      if ( v14 > v13 )
        this[1425] = v13;
    }
    else
    {
      this[1425] = v12;
    }
    v15 = this[2354];
    v16 = this[2355];
    this[2352] = 1;
    v17 = this[2352];
    if ( v17 >= v15 )
    {
      if ( v17 > v16 )
        this[2352] = v16;
    }
    else
    {
      this[2352] = v15;
    }
    this[1272] = 8;
  }
  else
  {
    if ( this[2085] != 2 )
    {
      result = this[2085] - 3;
      if ( this[2085] == 3 )
      {
        v3 = this[1427];
        v4 = this[1428];
        this[1425] = 2;
        v5 = this[1425];
        if ( v5 >= v3 )
        {
          if ( v5 > v4 )
            this[1425] = v4;
        }
        else
        {
          this[1425] = v3;
        }
        v20 = this[2355];
        this[2352] = 3;
        sub_4CF410(v20);
        v21 = this[1275];
        this[1272] = 16;
        return sub_4CF410(v21);
      }
      return result;
    }
    v6 = this[1427];
    v7 = this[1428];
    this[1425] = 1;
    v8 = this[1425];
    if ( v8 >= v6 )
    {
      if ( v8 > v7 )
        this[1425] = v7;
    }
    else
    {
      this[1425] = v6;
    }
    v9 = this[2354];
    v10 = this[2355];
    this[2352] = 2;
    v11 = this[2352];
    if ( v11 >= v9 )
    {
      if ( v11 > v10 )
        this[2352] = v10;
      this[1272] = 12;
    }
    else
    {
      this[2352] = v9;
      this[1272] = 12;
    }
  }
  v18 = this[1272];
  result = this[1274];
  v19 = this[1275];
  if ( v18 >= result )
  {
    if ( v18 > v19 )
      this[1272] = v19;
  }
  else
  {
    this[1272] = result;
  }
  return result;
}
