void __thiscall sub_4197A0(void *this, char a2)
{
  int v4; // eax
  float v5; // [esp+Ch] [ebp+4h]

  if ( !a2 )
  {
    if ( dword_629D48 < 20 )
    {
      ++dword_629D48;
      return;
    }
    dword_629D48 = 0;
  }
  v5 = dbl_7DA9D0;
  if ( dword_7688A0 )
  {
    if ( flt_7678BC != 0.0 )
    {
      if ( byte_6292D8 )
      {
        if ( sub_4633A0(&unk_764D70) != 1 )
        {
          if ( dword_75AAC4 )
          {
            if ( !*(_DWORD *)(dword_75AAC4 + 20892) )
            {
              v4 = *(_DWORD *)(dword_75AAC4 + 20896);
              if ( (!v4 || v4 == 4) && dword_7D5DA4 != 2 && v5 - flt_7D74BC > 15.0 && v5 > 0.0 && flt_7D74BC > 0.0 )
              {
                sub_4198A0(a2);
                sub_419CC0(this);
                sub_41B810(this);
              }
            }
          }
        }
      }
    }
  }
}
