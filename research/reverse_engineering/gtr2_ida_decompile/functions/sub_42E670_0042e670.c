char __thiscall sub_42E670(float *this)
{
  char *v1; // eax
  int v3; // edi
  __int16 v4; // si
  int v5; // eax
  char *v6; // eax
  int v7; // eax
  char *v8; // eax
  int v9; // eax
  char *v10; // eax
  int v11; // eax
  char *v12; // eax
  int v13; // eax
  int v14; // edi
  const char *v15; // eax
  char v16; // zf
  char v17; // sf
  char v18; // of
  const char *v19; // esi
  char *v20; // eax
  const char *v21; // eax
  char *v22; // eax
  unsigned int v23; // kr00_4
  float v25; // [esp+18h] [ebp-1ACh]
  float v26; // [esp+2Ch] [ebp-198h] BYREF
  char v27; // [esp+33h] [ebp-191h] BYREF
  float v28; // [esp+34h] [ebp-190h]
  char v29; // [esp+3Ah] [ebp-18Ah] BYREF
  char v30; // [esp+3Bh] [ebp-189h] BYREF
  char v31; // [esp+3Ch] [ebp-188h] BYREF
  char v32; // [esp+3Dh] [ebp-187h] BYREF
  char v33; // [esp+3Eh] [ebp-186h] BYREF
  char v34; // [esp+3Fh] [ebp-185h] BYREF
  float v35; // [esp+40h] [ebp-184h]
  char v36[128]; // [esp+44h] [ebp-180h] BYREF
  char v37[128]; // [esp+C4h] [ebp-100h] BYREF
  char Buffer[128]; // [esp+144h] [ebp-80h] BYREF

  v35 = *(float *)&dword_757C20;
  LOBYTE(v1) = dword_757C1C;
  dword_757C20 = 2139095039;
  if ( (_BYTE)dword_757C1C )
  {
    LOBYTE(v1) = byte_B6F118;
    if ( !byte_B6F118 )
    {
      v3 = 0;
      while ( v3 < ((dword_B698E8 & 1) != 0 ? dword_B6A2F4 : 0) )
      {
        v4 = word_B6A2F8[v3];
        v30 = 1;
        v29 = 1;
        v33 = 2;
        v27 = 2;
        v34 = 1;
        v32 = 1;
        v31 = 1;
        sub_5019D0(7, &v30, 1);
        sub_5019D0(8, &v29, 1);
        sub_5019D0(0, &v33, 1);
        sub_5019D0(1, &v27, 1);
        sub_5019D0(5, &v34, 1);
        sub_5019D0(2, &v32, 1);
        sub_5019D0(9, &v31, 1);
        switch ( v4 )
        {
          case ';':
          case '<':
          case '=':
          case '>':
          case '?':
          case '@':
          case 'A':
          case 'B':
            sub_42C9B0();
            ++v3;
            break;
          case 'C':
            sub_42C9B0();
            goto LABEL_8;
          default:
LABEL_8:
            ++v3;
            break;
        }
      }
      v5 = dword_B6B778;
      if ( dword_B6B778 && byte_B6820A && byte_B68208 )
      {
        LOBYTE(v5) = byte_B68209 == 0;
        sub_44A3C0(&dbl_B66040, v5, 0);
      }
      if ( dword_B6B938 == 2 )
      {
        sub_44A4E0(&dbl_B66040);
      }
      else
      {
        if ( dword_B6B95C )
          sub_44A400(-1);
        if ( dword_B6B988 )
          sub_44A400(1);
      }
      if ( dword_B6BA0C && !(unsigned __int8)sub_4735A0(&dword_B6CBA8) && !*(_DWORD *)(dword_91E084 + 14820) )
        sub_57F350(dword_91E084 + 16);
      if ( dword_B6BD50 )
        byte_B6820A = byte_B6820A == 0;
      if ( dword_B6BD7C && (unsigned __int8)sub_449750(&dbl_B66040) )
        sub_4497C0(0);
      if ( (dword_B698E8 & 1) != 0 && (byte_B69A24 & 2) != 0 )
      {
        v27 = (byte_B69A0D & 2) != 0;
        if ( (byte_B69A0D & 2) != 0 )
        {
          if ( dword_B74F94 )
            sub_463CE0(&unk_B6B000);
        }
      }
      if ( dword_91E07C && *((_DWORD *)dword_91E07C + 1436) == 1 )
      {
        if ( dword_B6BEB0 )
        {
          v6 = dword_B6F708;
          if ( !dword_B6F708 )
            v6 = (char *)WindowName;
          v7 = sub_539670(v6);
          v28 = *(float *)(v7 + 136);
          v26 = flt_B70ED0 - 0.0099999998;
          if ( v26 >= (double)*(float *)(v7 + 132) )
          {
            if ( v26 > (double)v28 )
              v26 = v28;
          }
          else
          {
            v26 = *(float *)(v7 + 132);
          }
          sub_409B80(flt_B70EBC, &v26);
        }
        if ( dword_B6BEDC )
        {
          v8 = dword_B6F708;
          if ( !dword_B6F708 )
            v8 = (char *)WindowName;
          v9 = sub_539670(v8);
          v28 = *(float *)(v9 + 136);
          v26 = flt_B70ED0 + 0.0099999998;
          if ( v26 >= (double)*(float *)(v9 + 132) )
          {
            if ( v26 > (double)v28 )
              v26 = v28;
          }
          else
          {
            v26 = *(float *)(v9 + 132);
          }
          sub_409B80(flt_B70EBC, &v26);
        }
        if ( dword_B6BF08 )
        {
          v10 = dword_B6F708;
          if ( !dword_B6F708 )
            v10 = (char *)WindowName;
          v11 = sub_539670(v10);
          v28 = *(float *)(v11 + 140);
          v26 = flt_B70EF4 + 0.0099999998;
          if ( v26 >= (double)*(float *)(v11 + 144) )
          {
            if ( v26 > (double)v28 )
              v26 = v28;
          }
          else
          {
            v26 = *(float *)(v11 + 144);
          }
          sub_409B80(flt_B70EE0, &v26);
        }
        if ( dword_B6BF34 )
        {
          v12 = dword_B6F708;
          if ( !dword_B6F708 )
            v12 = (char *)WindowName;
          v13 = sub_539670(v12);
          v28 = *(float *)(v13 + 140);
          v26 = flt_B70EF4 - 0.0099999998;
          if ( v26 >= (double)*(float *)(v13 + 144) )
          {
            if ( v26 > (double)v28 )
              v26 = v28;
          }
          else
          {
            v26 = *(float *)(v13 + 144);
          }
          sub_409B80(flt_B70EE0, &v26);
        }
      }
      if ( byte_B71140 == 1
        && ((dword_B698E8 & 1) != 0 && (byte_B69A09 & 2) != 0 || (dword_B698E8 & 1) != 0 && (byte_B69A16 & 2) != 0)
        && !byte_91BF6D )
      {
        sub_42E040((int)this);
      }
      if ( byte_B70F18 == 1 && !byte_91BF6D )
        sub_42E110(this);
      LOBYTE(v1) = dword_757C1C;
      if ( (_BYTE)dword_757C1C )
      {
        LOBYTE(v1) = dword_91E084;
        if ( dword_91E084 )
        {
          if ( v35 == 3.4028235e38 )
          {
            LOBYTE(v1) = dword_B6B9B4;
            if ( dword_B6B9B4 || dword_B6E4DC == 5 )
            {
              v1 = *(char **)dword_B72314;
              if ( *(_DWORD *)dword_B72314 != 5 || byte_B73570 )
              {
                if ( *(_DWORD *)dword_B640C8 == 6 )
                {
                  if ( !(unsigned __int8)sub_42FE50(&dword_B640C0) )
                  {
                    LOBYTE(v1) = dword_B64134;
                    if ( !dword_B64134 || dword_B64134 == 4 )
                      return (char)v1;
                  }
                  if ( *(_DWORD *)dword_B640C8 == 6 )
                  {
                    if ( (unsigned __int8)sub_42FE50(&dword_B640C0) )
                    {
                      LOBYTE(v1) = dword_B64134;
                      if ( !dword_B64134 )
                        return (char)v1;
                    }
                  }
                  v1 = *(char **)dword_B72314;
                }
                if ( v1 != (char *)7 && v1 != (char *)8 )
                {
                  if ( v1 != (char *)4 )
                    goto LABEL_108;
                  v21 = Str;
                  if ( !Str )
                    v21 = WindowName;
                  v1 = strstr(v21, "Custom");
                  if ( !v1 )
                  {
LABEL_108:
                    if ( *(_DWORD *)((_BYTE)dword_757C1C != 0 ? dword_91E084 + 0x39E4 : 14820)
                      || *(_DWORD *)((_BYTE)dword_757C1C != 0 ? dword_91E084 + 0x3CD8 : 15576) > 1u )
                    {
                      v1 = (_BYTE)dword_757C1C != 0 ? (char *)dword_91E084 : 0;
                      if ( *((_DWORD *)v1 + 3705) == 1 )
                      {
                        v1 = (_BYTE)dword_757C1C != 0 ? (char *)dword_91E084 : 0;
                        if ( *((_DWORD *)v1 + 4607) != 2 )
                        {
                          v1 = *(char **)(dword_91E084 + 21788);
                          if ( !v1 || (LOBYTE(v1) = byte_B6F790) == 0 )
                            *(float *)&dword_757C20 = dbl_FB1D18 + 3.0;
                        }
                      }
                    }
                    else
                    {
                      *(float *)&dword_757C20 = dbl_FB1D18;
                      v22 = sub_41D840(&byte_91CC38, "Control switched to AI");
                      LOBYTE(v1) = sub_4730C0(v22, 3, &byte_1020304, 1084227584);
                    }
                    dword_B6E4DC = 7;
                  }
                }
              }
            }
          }
          else
          {
            strcpy(v37, sub_41D840(&byte_91CC38, "AI Control:"));
            strcpy(v36, sub_41D840(&byte_91CC38, "Player Control:"));
            sub_472920(v37, 1);
            sub_472920(v36, 1);
            v28 = dbl_FB1D18;
            if ( dbl_FB1D18 <= v35 )
            {
              if ( !*(_DWORD *)((_BYTE)dword_757C1C != 0 ? dword_91E084 + 0x39E4 : 14820)
                || (v1 = (_BYTE)dword_757C1C != 0 ? (char *)dword_91E084 : 0, *((_DWORD *)v1 + 3705) == 1) )
              {
                v25 = v35 + 0.5 - v28;
                v14 = sub_4015C0(v25);
                v23 = __readeflags();
                *(float *)(dword_16EF792 + dword_16C6F38) = v35;
                __writeeflags(v23);
                v15 = "seconds";
                if ( v17 ^ v18 | v16 )
                  v15 = "second";
                v19 = v37;
                if ( *(_DWORD *)((_BYTE)dword_757C1C != 0 ? dword_91E084 + 0x39E4 : 14820) )
                  v19 = v36;
                v20 = sub_41D840(&byte_91CC38, v15);
                sprintf(Buffer, "%s %d %s", v19, v14, v20);
                LOBYTE(v1) = sub_4730C0(Buffer, 3, &byte_1020304, 1084227584);
              }
            }
            else
            {
              LOBYTE(v1) = sub_53E3E0((_BYTE)dword_757C1C != 0 ? dword_91E084 : 0);
            }
          }
        }
      }
    }
  }
  return (char)v1;
}
