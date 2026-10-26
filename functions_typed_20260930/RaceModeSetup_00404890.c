void __thiscall sub_404890(int this)
{
  PathStringUtility((_DWORD *)this);
  if ( *(_DWORD *)(this + 32) == 1 )
  {
    *(_DWORD *)(this + 80) = dword_7D2E44;
    dword_7D2E44 = 1;
    *(_DWORD *)(this + 84) = dword_7D0410;
    dword_7D0410 = 2;
    if ( dword_7D0418 <= 2 )
    {
      if ( dword_7D041C < 2 )
        dword_7D0410 = dword_7D041C;
    }
    else
    {
      dword_7D0410 = dword_7D0418;
    }
    SetGlobalFlag(&unk_7CE24D);
    ShortComputation_d360(1, 15);
    flt_7D0798 = 0.050000001;
    if ( flt_7D07A0 > 0.050000001 )
    {
      flt_7D0798 = flt_7D07A0;
LABEL_8:
      *(_WORD *)(this + 20) = 1;
      return;
    }
    if ( *(float *)&dword_7D07A4 >= 0.050000001 )
      goto LABEL_8;
    LODWORD(flt_7D0798) = dword_7D07A4;
    *(_WORD *)(this + 20) = 1;
  }
  else
  {
    *(_BYTE *)(this + 20) = 1;
    *(_BYTE *)(this + 21) = 0;
  }
}

