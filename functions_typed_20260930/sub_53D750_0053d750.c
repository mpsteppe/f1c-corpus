int __thiscall sub_53D750(_DWORD *this)
{
  int v2; // eax
  int v3; // eax
  int v5; // eax

  if ( this[1087] )
  {
    v2 = this[1088];
    if ( v2 )
    {
      *this = (*(int (__stdcall **)(int))(*(_DWORD *)v2 + 8))(v2);
      this[1088] = 0;
      memset(this + 1089, 0, 0x34u);
    }
    *this = (*(int (__stdcall **)(_DWORD))(*(_DWORD *)this[1087] + 8))(this[1087]);
    this[1087] = 0;
  }
  this[2] = 0;
  this[1] = 0;
  this[1102] = 0;
  v3 = Direct3DCreate8(220);
  this[1087] = v3;
  if ( v3 )
  {
    v5 = this[1272];
    if ( v5 )
    {
      if ( (unsigned int)(v5 - 1) <= 1 )
        this[1271] = 1;
    }
    else
    {
      this[1271] = 0;
    }
    sub_540760(this);
    this[1340] = 0;
    this[1274] = 0;
    this[1275] = 0;
    this[1276] = 0;
    this[1277] = 0;
    this[1278] = 0;
    this[1279] = 0;
    this[1280] = 0;
    this[1281] = 0;
    this[1350] = 0;
    this[1376] = 0;
    return 0;
  }
  else
  {
    sub_53C590(-1, aErrorCreatingD);
    return -1;
  }
}

