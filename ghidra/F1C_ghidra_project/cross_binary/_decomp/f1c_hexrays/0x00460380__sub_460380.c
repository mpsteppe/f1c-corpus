// f1c  0x00460380  size=232
void __thiscall sub_460380(int this)
{
  double v2; // st7
  int v3; // edi
  _BYTE v4[32]; // [esp+4h] [ebp-80h] BYREF
  _BYTE v5[96]; // [esp+24h] [ebp-60h] BYREF

  if ( *(_DWORD *)(this + 16324) == 3 )
  {
    v2 = *(float *)(this + 28) - dbl_8AFE98;
    *(float *)(this + 28) = v2;
    if ( v2 < 0.0 )
    {
      sub_461550(v4);
      if ( (unsigned __int8)sub_4630D0(v4) )
      {
        v3 = dword_8AC48C;
        sub_4C5690(v5);
        if ( *(_BYTE *)(this + 32) )
        {
          sub_461900(v4);
          sub_4C54F0(0);
          sub_4A0DC0(&unk_7CE24D);
          if ( !byte_7CE254 )
            sub_4A0030(&unk_7CE24C);
          sub_497940(aMpclientgrid, -1);
          *(_BYTE *)(this + 32) = 0;
        }
        else if ( v3 != dword_8AC48C )
        {
          *(_BYTE *)(this + 32) = 1;
        }
        *(_DWORD *)(this + 28) = 1089470464;
      }
      nullsub_3(v4);
    }
  }
}
