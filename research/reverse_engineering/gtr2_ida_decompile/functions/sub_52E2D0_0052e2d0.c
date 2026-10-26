void __thiscall sub_52E2D0(int this, _DWORD *a2)
{
  _DWORD *v3; // ebp
  bool v4; // zf
  int v5; // edx
  int v6; // eax
  char *v7; // eax
  double v8; // st7
  char *v9; // eax
  char *v10; // eax
  float v11; // edi
  float v12; // [esp+Ch] [ebp-78h]
  float v13; // [esp+1Ch] [ebp-68h]
  float v14; // [esp+1Ch] [ebp-68h]
  int v15; // [esp+20h] [ebp-64h]
  char v16; // [esp+24h] [ebp-60h] BYREF
  int v17; // [esp+25h] [ebp-5Fh]
  int v18; // [esp+29h] [ebp-5Bh]
  int v19; // [esp+2Dh] [ebp-57h]
  int v20; // [esp+31h] [ebp-53h]
  int v21; // [esp+35h] [ebp-4Fh]
  int v22; // [esp+39h] [ebp-4Bh]
  int v23; // [esp+3Dh] [ebp-47h]
  __int16 v24; // [esp+41h] [ebp-43h]
  char v25; // [esp+43h] [ebp-41h]
  char v26[61]; // [esp+44h] [ebp-40h] BYREF
  __int16 v27; // [esp+81h] [ebp-3h]
  char v28; // [esp+83h] [ebp-1h]

  if ( *(float *)(this + 244) > 100.0 )
    return;
  v3 = a2;
  sub_5DA960(&a2, 2048);
  if ( !a2 )
  {
    if ( *(_DWORD *)dword_B640C8 == 6 && dword_B64134 > 4 )
    {
      v12 = dbl_FB1D18;
      v5 = sub_552BC0(*(_DWORD *)this, v12);
      if ( byte_B722E4 )
      {
        if ( v5 > -1 )
        {
          memset(v26, 0, sizeof(v26));
          v27 = 0;
          v28 = 0;
          v6 = *(_DWORD *)this;
          if ( *(_DWORD *)this == ((_BYTE)dword_757C1C != 0 ? dword_91E084 : 0) )
          {
            v17 = 0;
            v18 = 0;
            v19 = 0;
            v20 = 0;
            v21 = 0;
            v22 = 0;
            v23 = 0;
            v24 = 0;
            v25 = 0;
            v16 = 0;
            v8 = sub_5306C0(v6 + 22000, v5, *(_DWORD *)(v6 + 19332));
            v13 = v8;
            if ( v8 <= 1.0 )
              sub_41D840(&byte_91CC38, "point");
            else
              sub_41D840(&byte_91CC38, "points");
            sub_4152E0();
            if ( v13 > 0.0 )
            {
              v9 = sub_41D840(&byte_91CC38, "You have been awarded");
              sub_632041(v26, 63, "%s %.1f %s", v9, v13, &v16);
            }
            v10 = sub_41D840(&byte_91CC38, "Points will be awarded this lap!");
            sub_472920((const char **)&dword_B6CB98, v10, 0);
          }
          else if ( *(_DWORD *)(v6 + 19324) == 1 && sub_530630(v5, *(_DWORD *)(v6 + 19332)) > 0.0 )
          {
            v7 = sub_41D840(&byte_91CC38, "Points will be awarded this lap!");
            sub_4730C0((int **)&dword_B6CB98, v7, 3, (int)&byte_1020304, 1084227584);
          }
          sub_4730C0((int **)&dword_B6CB98, v26, 3, (int)&byte_1020304, 1084227584);
        }
      }
    }
    v4 = *(_DWORD *)(this + 16) == 2;
LABEL_23:
    if ( !v4 )
      return;
    goto LABEL_24;
  }
  if ( a2 == (_DWORD *)1 )
  {
    v4 = *(_DWORD *)(this + 16) == 0;
    goto LABEL_23;
  }
  if ( a2 == (_DWORD *)2 )
  {
    v4 = *(_DWORD *)(this + 16) == 1;
    goto LABEL_23;
  }
LABEL_24:
  if ( (unsigned __int8)sub_52C3E0() )
  {
    *(float *)&v15 = sub_577800(v3);
    if ( *(_DWORD *)(this + 156) == 2 )
      v14 = *(float *)&v15 - *(float *)(this + 160);
    else
      v14 = -1.0;
    if ( !*(_DWORD *)(*(_DWORD *)this + 14820) && dword_903A10 )
      sub_5573C0(&dword_903A10, a2, v15);
    if ( dword_82F4A0 >= 1023 )
    {
      v11 = *(float *)&off_9034A4;
    }
    else
    {
      ++dword_82F4A0;
      v11 = *(float *)&off_9034A4;
      off_9034A4 += 848;
    }
    sub_51B2A0((_DWORD *)LODWORD(v11), 4, 8, 8, *(_DWORD *)(this + 4), v15, a2 != 0 ? 0 : 3);
    *(float *)(LODWORD(v11) + 8) = v14;
    *(_WORD *)(LODWORD(v11) + 12) = (_WORD)a2;
    *(_WORD *)(LODWORD(v11) + 14) = *(_WORD *)(this + 12);
    sub_52D970((_DWORD **)this, v11, v14, v15, a2, *(_DWORD *)(this + 12));
  }
}
