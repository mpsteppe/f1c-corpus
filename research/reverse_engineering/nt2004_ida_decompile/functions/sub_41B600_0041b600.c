void __thiscall sub_41B600(float *this, int a2, int a3, float a4)
{
  int v5; // eax
  int v6; // ebp
  float v7; // ecx
  int v8; // ebp
  float v9; // [esp+1Ch] [ebp+Ch]

  if ( dword_7688A0 )
  {
    if ( flt_7678BC != 0.0 )
    {
      if ( byte_6292D8 )
      {
        if ( sub_4633A0(&unk_764D70) != 1 )
        {
          if ( (unsigned __int8)sub_42DBA0(&unk_62BF64) )
          {
            if ( dword_75AACC )
            {
              if ( !*(_DWORD *)(dword_75AACC + 20892) )
              {
                v5 = *(_DWORD *)(dword_75AACC + 20896);
                if ( (!v5 || v5 == 4)
                  && dword_7D5DA4 != 2
                  && dbl_7DA9D0 - flt_7D74BC > 15.0
                  && flt_7D74BC > 0.0
                  && a4 >= 1800.0 )
                {
                  v6 = *(_DWORD *)(a2 + 25248);
                  if ( (double)SLODWORD(this[v6 + 532]) < a4
                    && (double)SLODWORD(this[*(_DWORD *)(a3 + 25248) + 532]) < a4 )
                  {
                    if ( this[v6 + 340] <= 0.0 )
                      this[v6 + 484] = sub_5196B0(a2 + 84);
                    this[*(_DWORD *)(a2 + 25248) + 340] = dbl_7DA9D0;
                    this[*(_DWORD *)(a2 + 25248) + 388] = dbl_7DA9D0;
                    LODWORD(v7) = (__int64)a4;
                    this[*(_DWORD *)(a2 + 25248) + 532] = v7;
                    LODWORD(this[*(_DWORD *)(a2 + 25248) + 580]) = a3;
                    v8 = *(_DWORD *)(a3 + 25248);
                    v9 = v7;
                    if ( this[v8 + 340] <= 0.0 )
                    {
                      this[v8 + 484] = sub_5196B0(a3 + 84);
                      v7 = v9;
                    }
                    this[*(_DWORD *)(a3 + 25248) + 340] = dbl_7DA9D0;
                    this[*(_DWORD *)(a3 + 25248) + 388] = dbl_7DA9D0;
                    this[*(_DWORD *)(a3 + 25248) + 532] = v7;
                    LODWORD(this[*(_DWORD *)(a3 + 25248) + 580]) = a2;
                  }
                }
              }
            }
          }
        }
      }
    }
  }
}
