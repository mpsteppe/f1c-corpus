int __thiscall sub_4E9860(int *this)
{
  int v2; // ecx
  _DWORD v4[2]; // [esp+4h] [ebp-28h] BYREF
  _DWORD v5[2]; // [esp+Ch] [ebp-20h] BYREF
  _DWORD v6[2]; // [esp+14h] [ebp-18h] BYREF
  int v7[2]; // [esp+1Ch] [ebp-10h] BYREF
  char v8; // [esp+24h] [ebp-8h] BYREF

  v2 = *(_DWORD *)(dword_91E084 + 14820);
  v7[0] = 0;
  if ( v2 )
  {
    sub_4E6210((int)"WX", this[147], this[148] + 156, *this, this[3], v7[0]);
    sub_4E6210((int)"=", this[147] + 168, this[148] + 156, *this, this[3], 0);
    sub_4E6210((int)"---", this[147] + 168, this[148] + 190, this[2], this[3], 1);
    sub_4E6210((int)"<", this[147] + 264, this[148] + 156, *this, this[3], 0);
    sub_4E6210((int)"---", this[147] + 264, this[148] + 190, this[2], this[3], 1);
    sub_4E6210((int)"?", this[147] + 360, this[148] + 156, *this, this[3], 0);
    sub_4E6210((int)"---", this[147] + 360, this[148] + 190, this[2], this[3], 1);
    sub_4E6210((int)">", this[147] + 456, this[148] + 156, *this, this[3], 0);
    return sub_4E6210((int)"---", this[147] + 456, this[148] + 190, this[2], this[3], 1);
  }
  else
  {
    sub_4E6210((int)"WX", this[147], this[148] + 156, *this, this[3], v7[0]);
    v7[0] = (int)&v8;
    *(float *)&v6[1] = dbl_B666D0 - 273.16;
    sub_4E8B20();
    sub_4E6210((int)"=", this[147] + 168, this[148] + 156, *this, this[3], 0);
    sub_4E6210((int)v7, this[147] + 168, this[148] + 190, this[2], this[3], 1);
    v6[0] = v7;
    *(float *)&v5[1] = dbl_B66BD0 - 273.16;
    sub_4E8B20();
    sub_4E6210((int)"<", this[147] + 264, this[148] + 156, *this, this[3], 0);
    sub_4E6210((int)v6, this[147] + 264, this[148] + 190, this[2], this[3], 1);
    v5[0] = v6;
    *(float *)&v4[1] = dbl_B670D0 - 273.16;
    sub_4E8B20();
    sub_4E6210((int)"?", this[147] + 360, this[148] + 156, *this, this[3], 0);
    sub_4E6210((int)v5, this[147] + 360, this[148] + 190, this[2], this[3], 1);
    v4[0] = v5;
    sub_4E8B20();
    sub_4E6210((int)">", this[147] + 456, this[148] + 156, *this, this[3], 0);
    return sub_4E6210((int)v4, this[147] + 456, this[148] + 190, this[2], this[3], 1);
  }
}
