void __thiscall sub_4DD1C0(int this, int Buffer)
{
  int v3; // edi
  bool v4; // zf
  int v5; // eax
  int v6; // edi
  float v7; // [esp+Ch] [ebp-8h]
  int v8; // [esp+10h] [ebp-4h]

  if ( *(float *)(this + 200) > 10.0 )
    return;
  v3 = Buffer;
  sub_59EF10(&Buffer, 2048);
  switch ( Buffer )
  {
    case 0:
      v5 = *(_DWORD *)(this + 16);
      *(_DWORD *)(this + 212) = 0;
      v4 = v5 == 2;
LABEL_8:
      if ( !v4 )
        return;
      break;
    case 1:
      v4 = *(_DWORD *)(this + 16) == 0;
      goto LABEL_8;
    case 2:
      v4 = *(_DWORD *)(this + 16) == 1;
      goto LABEL_8;
  }
  *(float *)&v8 = sub_51C290(v3);
  if ( *(_DWORD *)(this + 116) == 2 )
    v7 = *(float *)&v8 - *(float *)(this + 120);
  else
    v7 = -1.0;
  if ( !sub_4DD160((_DWORD *)this, 0) || *(_BYTE *)(this + 36) )
  {
    sub_4DD350(LODWORD(v7), v8, Buffer, *(_DWORD *)(this + 12));
  }
  else
  {
    flt_628F80 = flt_628F80 + 1.0;
    if ( !*(_DWORD *)(*(_DWORD *)this + 16584) && dword_7D78FC )
      sub_4FE730(Buffer, v8);
    v6 = dword_7D3C44;
    if ( dword_79FC40 < 1023 )
    {
      ++dword_79FC40;
      dword_7D3C44 += 208;
    }
    sub_4D0D00((_DWORD *)v6, 4, 8, 8, *(_DWORD *)(this + 4), v8, 3);
    *(float *)(v6 + 8) = v7;
    *(_WORD *)(v6 + 12) = Buffer;
    *(_WORD *)(v6 + 14) = *(_WORD *)(this + 12);
    sub_4DD490(v7, *(float *)&v8, Buffer, *(_DWORD *)(this + 12));
  }
}
