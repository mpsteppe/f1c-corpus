void __thiscall sub_461A10(int this)
{
  double v2; // st7
  int v3; // esi
  bool v4; // al
  _BYTE v5[32]; // [esp+4h] [ebp-5Ch] BYREF
  _BYTE v6[60]; // [esp+24h] [ebp-3Ch] BYREF

  if ( *(_DWORD *)(this + 6720) == 3 )
  {
    v2 = *(float *)(this + 20) - dbl_7DA9C8;
    *(float *)(this + 20) = v2;
    if ( v2 < 0.0 )
    {
      sub_462C80(v5);
      if ( (unsigned __int8)sub_464BD0(v5) )
      {
        v3 = dword_7D6B58 + 400 * dword_7D6B54;
        v4 = v3 != sub_4E8DA0(v6);
        if ( *(_BYTE *)(this + 24) )
        {
          sub_4E6000(&unk_76BB28);
          sub_462FE0(v5);
          sub_4E8A30(&byte_7D6A30);
          sub_4BA680(&unk_76612C);
          if ( !byte_76617C )
            sub_4B9130(1);
          sub_4AD720(a2003MultiClien, 1);
          *(_BYTE *)(this + 24) = 0;
        }
        else if ( v4 )
        {
          *(_BYTE *)(this + 24) = 1;
        }
        *(_DWORD *)(this + 20) = 1095237632;
      }
      nullsub_6(v5);
    }
  }
}
