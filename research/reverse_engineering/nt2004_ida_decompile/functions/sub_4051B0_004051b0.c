int __thiscall sub_4051B0(int this)
{
  int result; // eax
  char *v3; // eax
  int v4; // eax
  int i; // edi
  CHAR *v6; // eax
  CHAR *v7; // edi
  char Buffer[253]; // [esp+Ch] [ebp-100h] BYREF
  __int16 v9; // [esp+109h] [ebp-3h]
  char v10; // [esp+10Bh] [ebp-1h]

  sub_405170((_DWORD *)this);
  sub_451B70(&unk_762A38);
  if ( *(_DWORD *)(this + 36) == 1 )
  {
    *(_DWORD *)(this + 84) = *(_DWORD *)dword_76BB84;
    *(_DWORD *)dword_76BB84 = 1;
    *(_DWORD *)(this + 88) = *(_DWORD *)dword_7689CC;
    *(_DWORD *)dword_7689CC = 2;
    if ( dword_7689D4 <= 2 )
    {
      if ( dword_7689D8 < 2 )
        *(_DWORD *)dword_7689CC = dword_7689D8;
    }
    else
    {
      *(_DWORD *)dword_7689CC = dword_7689D4;
    }
    sub_4BA650(&unk_76612C);
    flt_768DF8 = 0.050000001;
    if ( flt_768E00 <= 0.050000001 )
    {
      if ( *(float *)&dword_768E04 < 0.050000001 )
        LODWORD(flt_768DF8) = dword_768E04;
    }
    else
    {
      flt_768DF8 = flt_768E00;
    }
    *(_DWORD *)(this + 92) = dword_761FF8;
    dword_761FF8 = 2;
    result = sub_4B9130(1);
    *(_BYTE *)(this + 20) = 1;
    *(_BYTE *)(this + 21) = 0;
  }
  else
  {
    result = *(_DWORD *)(this + 36) - 2;
    if ( *(_DWORD *)(this + 36) == 2 )
    {
      sub_578960(&unk_7D7A0C);
      v3 = ArgList;
      if ( !ArgList )
        v3 = &byte_629120;
      sub_578A30(aVcr_0, 0, v3, 1);
      v4 = sub_578A20(&unk_7D7A0C);
      if ( v4 <= 0 )
        return sub_451B50(&unk_762A38);
      if ( *(_DWORD *)(this + 96) >= v4 )
        *(_DWORD *)(this + 96) = 0;
      sub_578A00(&unk_7D7A0C);
      for ( i = 0; i < *(_DWORD *)(this + 96); ++i )
        sub_5789D0(&unk_7D7A0C);
      if ( sub_578D80(&unk_7D7A0C) )
      {
        *(_DWORD *)(this + 84) = 0;
        *(_DWORD *)(this + 88) = *(_DWORD *)dword_7689CC;
        *(_DWORD *)dword_7689CC = 7;
        if ( dword_7689D4 <= 7 )
        {
          if ( dword_7689D8 < 7 )
            *(_DWORD *)dword_7689CC = dword_7689D8;
        }
        else
        {
          *(_DWORD *)dword_7689CC = dword_7689D4;
        }
        sub_4BA650(&unk_76612C);
        flt_768DF8 = 0.050000001;
        if ( flt_768E00 <= 0.050000001 )
        {
          if ( *(float *)&dword_768E04 < 0.050000001 )
            LODWORD(flt_768DF8) = dword_768E04;
        }
        else
        {
          flt_768DF8 = flt_768E00;
        }
        *(_DWORD *)(this + 92) = dword_761FF8;
        dword_761FF8 = 2;
        *(_BYTE *)(this + 20) = 1;
        *(_BYTE *)(this + 21) = 0;
        v6 = dword_766578;
        if ( !dword_766578 )
          v6 = &byte_629120;
        sub_578600(v6);
        Buffer[0] = byte_629120;
        memset(&Buffer[1], 0, 0xFCu);
        v9 = 0;
        v10 = 0;
        LOBYTE(v7) = (_BYTE)ArgList;
        if ( !ArgList )
          v7 = &byte_629120;
        sub_578D80(&unk_7D7A0C);
        sub_405480(Buffer, 0xFFu, Format, (char)v7);
        sub_4DA290(Buffer);
        dword_7D5DA4 = 2;
        sub_4B9130(0);
        result = *(_DWORD *)(this + 96) + 1;
        *(_DWORD *)(this + 96) = result;
      }
      else
      {
        return sub_451B50(&unk_762A38);
      }
    }
  }
  return result;
}
