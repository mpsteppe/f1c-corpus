int __thiscall sub_4E9C70(int *this)
{
  _DWORD v3[2]; // [esp+4h] [ebp-28h] BYREF
  _DWORD v4[2]; // [esp+Ch] [ebp-20h] BYREF
  _DWORD v5[2]; // [esp+14h] [ebp-18h] BYREF
  _DWORD v6[2]; // [esp+1Ch] [ebp-10h] BYREF
  char v7; // [esp+24h] [ebp-8h] BYREF

  if ( *(_DWORD *)(dword_91E084 + 14820) )
  {
    sub_4E6210((int)"YZ", this[147], this[148] + 156, *this, this[3], 1);
    sub_4E6210((int)"=", this[147] + 168, this[148] + 156, *this, this[3], 1);
    sub_4E6210((int)"---", this[147] + 168, this[148] + 190, this[2], this[3], 1);
    sub_4E6210((int)"<", this[147] + 264, this[148] + 156, *this, this[3], 1);
    sub_4E6210((int)"---", this[147] + 264, this[148] + 190, this[2], this[3], 1);
    sub_4E6210((int)"?", this[147] + 360, this[148] + 156, *this, this[3], 1);
    sub_4E6210((int)"---", this[147] + 360, this[148] + 190, this[2], this[3], 1);
    sub_4E6210((int)">", this[147] + 456, this[148] + 156, *this, this[3], 1);
    return sub_4E6210((int)"---", this[147] + 456, this[148] + 190, this[2], this[3], 1);
  }
  else
  {
    sub_4E6210((int)"YZ", this[147], this[148] + 156, *this, this[3], 0);
    v6[0] = &v7;
    *(float *)&v5[1] = dbl_B66798 - 273.16;
    sub_4E8B20();
    sub_4E6210((int)"=", this[147] + 168, this[148] + 156, *this, this[3], 0);
    sub_4E6210((int)v6, this[147] + 168, this[148] + 190, this[2], this[3], 1);
    v5[0] = v6;
    *(float *)&v4[1] = dbl_B66C98 - 273.16;
    sub_4E8B20();
    sub_4E6210((int)"<", this[147] + 264, this[148] + 156, *this, this[3], 0);
    sub_4E6210((int)v5, this[147] + 264, this[148] + 190, this[2], this[3], 1);
    v4[0] = v5;
    *(float *)&v3[1] = dbl_B67198 - 273.16;
    sub_4E8B20();
    sub_4E6210((int)"?", this[147] + 360, this[148] + 156, *this, this[3], 0);
    sub_4E6210((int)v4, this[147] + 360, this[148] + 190, this[2], this[3], 1);
    v3[0] = v4;
    sub_4E8B20();
    sub_4E6210((int)">", this[147] + 456, this[148] + 156, *this, this[3], 0);
    return sub_4E6210((int)v3, this[147] + 456, this[148] + 190, this[2], this[3], 1);
  }
}
