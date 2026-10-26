int __thiscall sub_4CA940(_DWORD *this, char a2)
{
  int v3; // eax
  int v4; // edx
  int v5; // ecx
  int v6; // eax
  int v7; // eax
  int v8; // edx
  int v9; // eax
  int v10; // ecx
  int v11; // edx
  int v12; // eax
  int v13; // ecx

  if ( a2 )
  {
    if ( (byte_762F00 & 1) != 0 )
    {
      sub_4CB410(2);
    }
    else if ( (byte_7632FC & 1) != 0 )
    {
      sub_4CB410(3);
    }
    else
    {
      sub_4CB410(1);
    }
  }
  else
  {
    v3 = this[2069];
    v4 = this[2070];
    this[2067] = 1;
    v5 = this[2067];
    if ( v5 >= v3 )
    {
      if ( v5 > v4 )
        this[2067] = v4;
    }
    else
    {
      this[2067] = v3;
    }
  }
  if ( (int)this[2076] > 0 )
  {
    v6 = dword_62A158;
    if ( dword_62A158 >= 0 )
    {
      if ( dword_62A158 > 3 )
        v6 = 3;
    }
    else
    {
      v6 = 0;
    }
    v7 = v6 + 1;
    if ( v7 > 4 )
      v7 = 4;
    v8 = this[2079];
    this[2076] = v7;
    v9 = this[2078];
    v10 = this[2076];
    if ( v10 >= v9 )
    {
      if ( v10 > v8 )
        this[2076] = v8;
    }
    else
    {
      this[2076] = v9;
    }
  }
  if ( (int)this[2085] > 0 )
  {
    v11 = this[2088];
    this[2085] = dword_62A148 + 1;
    v12 = this[2087];
    v13 = this[2085];
    if ( v13 >= v12 )
    {
      if ( v13 > v11 )
        this[2085] = v11;
    }
    else
    {
      this[2085] = v12;
    }
  }
  sub_4CC3D0(this);
  nullsub_6(this);
  sub_4CAA80(this);
  sub_4CB220(this);
  sub_4CB810(this);
  return sub_4CC230(this);
}
