// f1c  0x00404b60  size=347
void __thiscall sub_404B60(void **this)
{
  int v2; // eax
  float *v3; // ecx
  bool v4; // zf
  double v5; // st7
  _DWORD v6[5]; // [esp+4h] [ebp-14h] BYREF

  if ( !*((_DWORD *)*this + 8) )
    return;
  if ( dword_7CD8C0 )
  {
    v2 = sub_497980();
    if ( !v2 || sub_588410(v2, aMainMenu) )
    {
LABEL_23:
      *((_DWORD *)*this + 7) = 0;
      return;
    }
  }
  if ( dword_7C569C != 2 )
  {
    if ( dword_7C569C == 5 && *((_BYTE *)*this + 20) )
    {
      sub_4C8650(-1.0);
      if ( !*((_BYTE *)*this + 21) )
      {
        sub_404970(*this);
        *((_BYTE *)*this + 21) = 1;
      }
    }
    return;
  }
  v3 = (float *)*this;
  v4 = dword_7CB25C == *(_DWORD *)*this;
  v6[0] = dword_7CB25C;
  v6[1] = dword_7CB260;
  v6[2] = dword_7CB2FC;
  v6[3] = dword_7CB300;
  v6[4] = dword_7CB304;
  if ( v4
    && dword_7CB260 == *((_DWORD *)v3 + 1)
    && dword_7CB2FC == *((_DWORD *)v3 + 2)
    && dword_7CB300 == *((_DWORD *)v3 + 3)
    && dword_7CB304 == *((_DWORD *)v3 + 4) )
  {
    v5 = dbl_8AFE90;
    if ( dbl_8AFE90 >= 0.0 )
    {
      if ( dbl_8AFE90 > 0.5 )
        v5 = 0.5;
      v3[7] = v5 + v3[7];
    }
    else
    {
      v3[7] = v3[7] + 0.0;
    }
  }
  else
  {
    v3[7] = 0.0;
  }
  qmemcpy(*this, v6, 0x14u);
  if ( *((float *)*this + 7) >= (double)*((float *)*this + 6) )
  {
    sub_404890((int)*this);
    goto LABEL_23;
  }
}
