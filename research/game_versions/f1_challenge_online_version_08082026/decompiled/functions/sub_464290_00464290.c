char __thiscall sub_464290(_DWORD **this)
{
  int v2; // ecx
  int v3; // eax
  int i; // edi
  int v5; // eax
  int v6; // ecx

  v2 = (int)*this;
  v3 = *(_DWORD *)(v2 + 16324);
  if ( v3 )
  {
    if ( *(_BYTE *)(v2 + 40) )
    {
      sub_460C60((_DWORD *)v2);
      sub_460CB0(*this, 1);
      if ( (*this)[4081] == 3 )
      {
        if ( dword_7C569C != 5 && (unsigned __int8)sub_4D7A50(1, aDDevF119992002_1, 7877) )
          sub_4D7AA0(&unk_8AD25C, aEnteringSynchr);
        sub_45F390(*this);
      }
    }
    else
    {
      *(_BYTE *)(v2 + 40) = 1;
      for ( i = 0; i < 22672; i += 218 )
        sub_4FFFA0(&(*this)[i + 4192]);
    }
    v5 = (int)*this;
    v6 = (*this)[4081];
    if ( v6 == 2 || v6 == 1 )
    {
      if ( dword_7C56A4 == 7 || byte_7D105C && dword_7C56A4 == 5 )
        sub_57A570(0);
      else
        sub_57A570(1);
    }
    else
    {
      *(_BYTE *)(v5 + 20) = 1;
      *(float *)(v5 + 16) = 5.0;
      (*this)[228] = 1008981770;
    }
    (*this)[226] = 0;
    (*this)[224] = 0;
    LOBYTE(v3) = sub_45C8B0(*this + 26864, 1);
    if ( *((_BYTE *)*this + 112528) )
    {
      LOBYTE(v3) = *((_BYTE *)*this + 112529);
      if ( (_BYTE)v3 )
        LOBYTE(v3) = sub_562AC0(off_5E4DFC, 1);
    }
  }
  return v3;
}
