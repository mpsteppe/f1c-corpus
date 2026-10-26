char __thiscall sub_4C1BA0(_DWORD *this)
{
  float v2; // eax
  float v3; // ecx
  double v4; // st7
  float v6; // [esp+0h] [ebp-Ch]
  float v7; // [esp+8h] [ebp-4h]

  v2 = *(float *)this;
  if ( !*(_DWORD *)(*this + 25300) )
  {
    LOBYTE(v2) = *((_BYTE *)this + 824);
    if ( LOBYTE(v2) )
    {
      sub_4C1790((float *)this, 0);
      v3 = *(float *)this;
      *((_BYTE *)this + 824) = 0;
      *((float *)this + 235) = dbl_7DA9D0;
      sub_41B400(SLODWORD(v3));
      if ( (unsigned int)dword_7D7540 >= 2 && dword_7D7540 != 7 && !*(_DWORD *)(*this + 20892) )
      {
        v4 = sub_51C900(*this + 84);
        v7 = v4;
        sub_4BBF50(&unk_766220);
        if ( v4 < v7 && *(_BYTE *)(*this + 21034) )
          *(_DWORD *)(*this + 21116) = -1;
        else
          *(_DWORD *)(*this + 21116) = 0;
        v6 = dbl_7DA9D0;
        sub_4F7F20(*this, v6);
      }
      LOBYTE(v2) = sub_4EED40(*this);
      if ( LOBYTE(v2) )
      {
        sub_51F3D0(1, 4);
        sub_51F3D0(0, 2);
        sub_4C0A80(this, -1);
        sub_4BEC30(dword_766238);
        LOBYTE(v2) = sub_4C1970(this, 0);
      }
    }
  }
  return LOBYTE(v2);
}
