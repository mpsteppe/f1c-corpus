char sub_410EA0()
{
  _DWORD *v0; // eax
  int v1; // esi
  int v2; // edi
  int v3; // ebp
  int v4; // ebx
  int v5; // eax
  char *v6; // esi
  int v7; // ecx
  int v8; // ecx
  int v9; // ecx

  sub_5E5B30(32, 0);
  sub_5E5B30(&byte_800000, 1);
  sub_5E6B50(dword_FB1D04);
  v0 = (_DWORD *)sub_5E5670(aRearview_0, 0);
  if ( v0 && byte_B722FC )
  {
    v1 = v0[30] - 1;
    v2 = v0[29] - 1;
    v3 = v0[26] + v0[29];
    v4 = v0[25] + v0[30];
    sub_4DDDB0(v1, v2, v1, v3, 0, dword_FB2790);
    sub_4DDDB0(v1, v3, v4, v3, 0, dword_FB2790);
    sub_4DDDB0(v4, v3, v4, v2, 0, dword_FB2790);
    sub_4DDDB0(v4, v2, v1, v2, 0, dword_FB2790);
    ++v3;
    --v1;
    sub_4DDDB0(v1, --v2, v1, v3, 0, dword_FB2790);
    sub_4DDDB0(v1, v3, ++v4, v3, 0, dword_FB2790);
    sub_4DDDB0(v4, v3, v4, v2, 0, dword_FB2790);
    sub_4DDDB0(v4, v2, v1, v2, 0, dword_FB2790);
  }
  LOBYTE(v5) = (_BYTE)dword_91E07C;
  if ( dword_91E07C )
  {
    v6 = dword_91E07C + 2704;
    v5 = *((_DWORD *)dword_91E07C + 1436);
    if ( v5 != 1 )
    {
      if ( v5 && v5 != 2 )
        return v5;
      v8 = *((_DWORD *)dword_91E07C + 678);
      if ( (byte_B70FC0 & 2) != 0 )
      {
        if ( v8 )
          sub_5DB320(1, 1, 0);
        if ( *((_DWORD *)v6 + 611) )
          sub_5DB320(1, 1, 0);
      }
      else
      {
        if ( v8 )
          sub_5DB320(1, 0, 0);
        if ( *((_DWORD *)v6 + 611) )
          sub_5DB320(1, 0, 0);
      }
      LOBYTE(v5) = byte_B70FC0;
      goto LABEL_28;
    }
    v7 = *((_DWORD *)dword_91E07C + 678);
    if ( (byte_B70FE4 & 2) != 0 )
    {
      if ( v7 )
        sub_5DB320(1, 1, 0);
      if ( *((_DWORD *)v6 + 611) )
      {
        sub_5DB320(1, 1, 0);
        LOBYTE(v5) = byte_B70FE4;
        goto LABEL_28;
      }
    }
    else
    {
      if ( v7 )
        sub_5DB320(1, 0, 0);
      if ( *((_DWORD *)v6 + 611) )
        sub_5DB320(1, 0, 0);
    }
    LOBYTE(v5) = byte_B70FE4;
LABEL_28:
    v9 = *((_DWORD *)v6 + 610);
    if ( (v5 & 4) != 0 )
    {
      if ( v9 )
        LOBYTE(v5) = sub_5DB320(1, 1, 0);
    }
    else if ( v9 )
    {
      LOBYTE(v5) = sub_5DB320(1, 0, 0);
    }
  }
  return v5;
}
