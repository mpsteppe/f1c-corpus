void __thiscall sub_4DCA90(_DWORD *this, int a2)
{
  int v3; // ecx
  unsigned __int8 v5; // c0
  unsigned __int8 v6; // c2
  int v7; // ecx
  int v8; // [esp-8h] [ebp-3Ch]
  int v9; // [esp-8h] [ebp-3Ch]
  float v10; // [esp+4h] [ebp-30h] BYREF
  float v11; // [esp+10h] [ebp-24h] BYREF
  _BYTE v12[12]; // [esp+1Ch] [ebp-18h] BYREF
  _BYTE v13[12]; // [esp+28h] [ebp-Ch] BYREF

  if ( (*(_BYTE *)(a2 + 2) & 0x3F) == 0x1A )
  {
    if ( !this[14] )
    {
      v3 = this[15];
      this[14] = 2;
      if ( !v3 )
        this[15] = *(char *)(a2 + 8);
      if ( *(_BYTE *)(*this + 4769) )
      {
        v8 = *(_DWORD *)(*this + 4760);
        *(_BYTE *)(*this + 4769) = 0;
        sub_50B4E0(v8, 1);
      }
      sub_428150((_DWORD *)*this);
      sub_4F8F50(*this, &v10, v12);
      sub_4EEC20(0);
      if ( !(unsigned __int8)sub_4EED40(*this) )
        sub_4EEC50(0);
      sub_4EECE0(0);
      sub_4C1940(*this + 16588);
      sub_51C1E0(&v11, v13);
      if ( v5 | v6 )
        sub_50E010(0.5);
    }
    if ( (dword_75CBAC & 1) != 0 )
      sub_4F81A0(*this);
  }
  else
  {
    if ( this[14] == 2 )
      this[14] = 0;
    v7 = *this + 1892;
    if ( *(_BYTE *)(*this + 4769) != 1 )
    {
      v9 = *(_DWORD *)(*this + 4760);
      *(_BYTE *)(v7 + 2877) = 1;
      sub_50B4E0(v9, 1);
    }
  }
}
