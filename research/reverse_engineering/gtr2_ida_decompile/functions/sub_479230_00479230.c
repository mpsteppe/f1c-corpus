void __thiscall sub_479230(int this)
{
  double v2; // st7
  int v3; // esi
  bool v4; // al
  _DWORD *v5; // [esp-4h] [ebp-C8h]
  int v6; // [esp+0h] [ebp-C4h] BYREF
  int v7; // [esp+4h] [ebp-C0h] BYREF
  _DWORD v8[7]; // [esp+8h] [ebp-BCh] BYREF
  _BYTE v9[128]; // [esp+24h] [ebp-A0h] BYREF
  unsigned __int8 v10; // [esp+A4h] [ebp-20h]

  if ( *(_DWORD *)(this + 113328) == 3 )
  {
    v2 = *(float *)(this + 20) - dbl_FB1D10;
    *(float *)(this + 20) = v2;
    if ( v2 < 0.0 )
    {
      sub_473460(v8);
      v5 = v8;
      if ( (unsigned __int8)sub_473900() )
      {
        v6 = v10;
        if ( dword_B72338 != v10 )
        {
          sub_4762A0(dword_B72324, &v6);
          sub_50A440(&byte_B6F530, v8, v6);
        }
        v3 = dword_BE1CD8 + 396 * dword_BE1CD4;
        v4 = v3 != sub_53A220(v9);
        if ( *(_BYTE *)(this + 24) )
        {
          sub_4781A0((int)&v7, v3);
          sub_476630((float *)(this + 292692));
          sub_53A160(0);
          sub_4EB8E0(&unk_B6F134, v5, v6, v7, v8[0], v8[1], v8[2]);
          if ( !byte_B6F118 )
            sub_4EA9D0(&unk_B6F135);
          sub_4E1810("MONITOR_MPCLIENT", 0);
          *(_BYTE *)(this + 24) = 0;
          *(_DWORD *)(this + 20) = 1095237632;
        }
        else
        {
          if ( v4 )
            *(_BYTE *)(this + 24) = 1;
          *(_DWORD *)(this + 20) = 1095237632;
        }
      }
    }
  }
}
