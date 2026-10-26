char __thiscall sub_48ED71(_DWORD *this)
{
  char result; // al
  int v3; // eax
  int v4; // edi
  float v5; // [esp+0h] [ebp-380h]
  _BYTE v6[4]; // [esp+18h] [ebp-368h] BYREF
  _BYTE v7[8]; // [esp+1Ch] [ebp-364h] BYREF
  _BYTE v8[4]; // [esp+24h] [ebp-35Ch] BYREF
  _BYTE v9[8]; // [esp+28h] [ebp-358h] BYREF
  _BYTE v10[8]; // [esp+30h] [ebp-350h] BYREF
  char v11; // [esp+38h] [ebp-348h]

  result = 0;
  if ( *(_DWORD *)dword_B640C8 == 6 && dword_B6FD6C )
  {
    v3 = this[4915];
    if ( v3 != 5 || this[4914] )
    {
      if ( v3 == 4 && !this[4914] )
        sub_552F80(*this);
      return 0;
    }
    else
    {
      sub_422830();
      sub_573540(this + 4);
      v4 = rand() % 4;
      v5 = dbl_FB1D18;
      sub_51B2A0(4, 24, 1, *(_DWORD *)(*this + 22468), LODWORD(v5), 0);
      if ( v4 )
        v11 = v4 != 1 ? 8 : 3;
      else
        v11 = 7;
      sub_52BE90(v10);
      sub_54FDF0(&unk_FADD40, *this, v6, v8);
      sub_57DCC0(v7, v9);
      sub_4FF690(0);
      return 1;
    }
  }
  return result;
}
