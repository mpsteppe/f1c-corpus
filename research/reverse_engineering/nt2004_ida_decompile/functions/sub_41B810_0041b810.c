void __thiscall sub_41B810(float *this)
{
  int v2; // ecx
  double v3; // st7
  double v4; // st7
  double v5; // st7
  float v6; // [esp+4h] [ebp-10h]
  float v7; // [esp+8h] [ebp-Ch]
  int v8; // [esp+Ch] [ebp-8h]

  if ( dword_7688A0
    && flt_7678BC != 0.0
    && byte_6292D8
    && sub_4633A0(&unk_764D70) != 1
    && dword_75CBB0 != 5
    && ((unsigned __int8)sub_42DBA0(&unk_62BF64) && (v2 = dword_75AACC) != 0 || (v2 = dword_75AAC4) != 0) )
  {
    v3 = *(float *)(v2 + 17408);
    if ( v3 > 0.0 )
    {
      v7 = *(float *)(v2 + 18792);
      v8 = dword_7D74B8 - *(_DWORD *)(v2 + 20848);
      v6 = v7 * v3;
      v4 = v3 * this[644];
      if ( v6 >= 1.75 )
      {
        if ( v6 >= 3.5 )
        {
          v5 = 1.0 / *(float *)(v2 + 18796);
          if ( v7 * v5 < 0.5 && v5 * this[644] >= 0.5 )
          {
            sub_419400(16);
            this[644] = v7;
            return;
          }
        }
        else if ( v4 >= 3.5 && (dword_75CBB0 != 7 || (double)v8 + 1.0 >= v6) )
        {
          sub_419400(32);
          this[644] = v7;
          return;
        }
      }
      else if ( v4 >= 1.75 && (dword_75CBB0 != 7 || (double)v8 + 0.5 >= v6) )
      {
        sub_419400(64);
        this[644] = v7;
        return;
      }
      this[644] = v7;
    }
  }
}
