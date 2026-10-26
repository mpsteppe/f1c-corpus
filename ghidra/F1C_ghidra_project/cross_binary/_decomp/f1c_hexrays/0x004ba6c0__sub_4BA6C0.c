// f1c  0x004ba6c0  size=119
char __thiscall sub_4BA6C0(_DWORD *this)
{
  float *v2; // eax
  float v4; // [esp+0h] [ebp-Ch]
  float v5; // [esp+4h] [ebp-8h]

  v2 = (float *)*this;
  if ( *this == 1 )
  {
    if ( !byte_7C56AC )
    {
      v5 = dbl_8AFEA0;
      sub_4B9870(this + 2, &dword_83EE60, (int)&unk_5EC6D8, v5);
    }
    LOBYTE(v2) = sub_461DB0(dword_7CD25C);
    if ( !(_BYTE)v2 )
    {
      LOBYTE(v2) = dword_7CC4C8;
      if ( dword_7CC4C8 )
      {
        v4 = (float)dword_7D0080;
        LOBYTE(v2) = sub_4B9890((float **)this + 2, v4, this);
      }
    }
  }
  else if ( v2 == (float *)2 )
  {
    LOBYTE(v2) = sub_4B9A00(this + 2);
    if ( !(_BYTE)v2 )
      LOBYTE(v2) = sub_4CFCC0(&unk_8ACEA0);
  }
  return (char)v2;
}
