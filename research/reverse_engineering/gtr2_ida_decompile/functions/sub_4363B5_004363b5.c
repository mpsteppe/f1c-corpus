char __thiscall sub_4363B5(_DWORD *this, float a2, _DWORD *a3)
{
  char result; // al
  char v5; // bl
  int v6; // edi
  int v7; // ebp
  double v8; // st7
  float v9; // [esp+4h] [ebp-18h]
  float v10; // [esp+8h] [ebp-14h]
  int retaddr; // [esp+1Ch] [ebp+0h] BYREF

  result = byte_B6F118;
  if ( !byte_B6F118 )
  {
    sub_4304C0();
    v5 = byte_91BF50;
    byte_91BF50 = 0;
    v6 = sub_410B50(&dword_91BF20);
    v7 = *(_DWORD *)(*(&dword_91E088 + dword_91E078) + 22468);
    *a3 = 2;
    *(float *)(*this + 2892964) = a2;
    if ( (unsigned __int8)sub_529080(*this) )
    {
      v8 = a2;
      if ( a2 >= 10.0 )
      {
        if ( v8 > 180.0 )
          v8 = 180.0;
      }
      else
      {
        v8 = 10.0;
      }
      v10 = dbl_FB1D18 - v8;
      sub_522980(*this, LODWORD(v10));
      *(_DWORD *)(*this + 2892968) = *(_DWORD *)(*this + 2892852);
      sub_412EB0(&dword_91BF20, 5, 0);
      do
      {
        retaddr = sub_522B60(*this);
        sub_540850(-1.0);
      }
      while ( (unsigned __int8)sub_5283B0(&retaddr) );
      v9 = dbl_FB1D18;
      sub_522980(*this, LODWORD(v9));
      sub_42C8A0(v7);
      sub_412EB0(&dword_91BF20, v6, 0);
      byte_91BF50 = v5;
      sub_5291F0(*this);
    }
    *a3 = 1;
    return sub_540130(&unk_BE1D30);
  }
  return result;
}
