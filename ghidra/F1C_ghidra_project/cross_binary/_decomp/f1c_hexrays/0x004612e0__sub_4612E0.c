// f1c  0x004612e0  size=249
void __thiscall sub_4612E0(int this)
{
  int v2; // eax
  double v3; // st7
  int v4; // [esp+Ch] [ebp-Ch]
  float v5; // [esp+14h] [ebp-4h]

  v2 = *(_DWORD *)(this + 16324);
  if ( v2 != 2 && v2 != 1 && *(float *)(this + 44) >= 0.0 )
  {
    if ( *(float *)(this + 44) == 5.0 )
    {
      *(float *)&v4 = dbl_8AFEA0;
      sub_45E570(this, v4);
    }
    v5 = dbl_8AFE90;
    if ( dword_7C569C != 5 && (unsigned __int8)sub_4D7A50(2, aDDevF119992002_1, 4958) )
      sub_4D7AA0(&unk_8AD25C, aApplyingFrameT);
    if ( v5 >= 0.0099999998 )
    {
      if ( v5 > 0.5 )
        v5 = 0.5;
    }
    else
    {
      v5 = 0.0099999998;
    }
    v3 = *(float *)(this + 44) - v5;
    *(float *)(this + 44) = v3;
    if ( v3 <= 0.0 )
    {
      *(_BYTE *)(this + 41) = 1;
      *(_DWORD *)(this + 44) = -1082130432;
    }
  }
}
