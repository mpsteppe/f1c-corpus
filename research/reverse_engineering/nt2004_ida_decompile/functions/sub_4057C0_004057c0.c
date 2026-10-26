void __thiscall sub_4057C0(void **this)
{
  const char *v2; // eax
  float *v3; // ecx
  bool v4; // zf
  double v5; // st7
  _DWORD v6[5]; // [esp+8h] [ebp-14h] BYREF

  if ( *((_DWORD *)*this + 9) )
  {
    if ( dword_7655CC && ((v2 = (const char *)sub_4AD7F0()) == 0 || _strcmpi(v2, aMainMenu)) )
    {
      *((_DWORD *)*this + 8) = 0;
    }
    else if ( dword_75CBA8 == 2 )
    {
      v3 = (float *)*this;
      v4 = dword_762A48 == *(_DWORD *)*this;
      v6[0] = dword_762A48;
      v6[1] = dword_762A4C;
      v6[2] = dword_762AE8;
      v6[3] = dword_762AEC;
      v6[4] = dword_762AF0;
      if ( v4
        && dword_762A4C == *((_DWORD *)v3 + 1)
        && dword_762AE8 == *((_DWORD *)v3 + 2)
        && dword_762AEC == *((_DWORD *)v3 + 3)
        && dword_762AF0 == *((_DWORD *)v3 + 4) )
      {
        v5 = dbl_7DA9C0;
        if ( dbl_7DA9C0 >= 0.0 )
        {
          if ( dbl_7DA9C0 > 0.5 )
            v5 = 0.5;
          v3[8] = v5 + v3[8];
        }
        else
        {
          v3[8] = v3[8] + 0.0;
        }
      }
      else
      {
        v3[8] = 0.0;
      }
      qmemcpy(*this, v6, 0x14u);
      if ( *((float *)*this + 8) >= (double)*((float *)*this + 7) )
      {
        sub_4051B0((int)*this);
        *((_DWORD *)*this + 8) = 0;
        *((_DWORD *)*this + 6) = 0;
      }
    }
    else if ( dword_75CBA8 == 5 && *((_BYTE *)*this + 20) )
    {
      sub_4EFA90(-1.0);
      if ( !*((_BYTE *)*this + 21) )
      {
        sub_4054B0(*this);
        *((_BYTE *)*this + 21) = 1;
      }
      if ( *((_DWORD *)*this + 9) == 2 && sub_4D9EC0(&unk_7D5DAC) > *((_DWORD *)*this + 6) )
      {
        sub_4D20D0(2, 0, 1056964608, 1);
        sub_4D20D0(0, 2, 1056964608, 0);
        dword_75CBA8 = 6;
        sub_4AD720(aMainMenu, 0);
      }
    }
  }
}
