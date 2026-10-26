int __thiscall sub_48F1A0(int *this)
{
  _DWORD *v2; // ecx
  int v3; // eax
  int v4; // ecx
  int v5; // eax
  int v6; // edx
  int v8; // [esp+4h] [ebp-8h] BYREF
  int v9; // [esp+8h] [ebp-4h] BYREF

  if ( !ByteFieldGetterAt100(this) )
  {
    v2 = (_DWORD *)this[16];
    *((_BYTE *)this + 381) = 1;
    DualFieldRead(v2, &v9, &v8);
    v3 = v9;
    v4 = v8;
    if ( v9 > this[74] && v9 < this[75] && v8 > this[82] && v8 < this[83] )
      *((_BYTE *)this + 382) = 1;
    if ( this[65] != 4 )
    {
      if ( v3 > this[68] && v3 < this[69] && v4 > this[76] && v4 < this[77] )
      {
        this[65] = 2;
        DecrementCounterWithClamp(this, -1);
        v4 = v8;
        v3 = v9;
        this[67] = 0;
      }
      if ( v3 > this[70] && v3 < this[71] && v4 > this[78] && v4 < this[79] )
      {
        this[65] = 3;
        sub_48FB30(this, -1);
        this[67] = 0;
      }
      UITileGrid(this);
      v4 = v8;
      v3 = v9;
    }
    if ( v3 > this[72] && v3 < this[73] && v4 > this[80] && v4 < this[81] )
    {
      v5 = this[92];
      if ( v5 >= 0 )
      {
        v6 = *this;
        this[93] = v5;
        (*(void (__thiscall **)(int *, int))(v6 + 44))(this, 1);
      }
    }
    (*(void (__thiscall **)(int *, int))(*this + 64))(this, this[65]);
    (*(void (__thiscall **)(int *))(*this + 152))(this);
  }
  return 0;
}

