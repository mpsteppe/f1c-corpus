void __thiscall sub_421B50(int this)
{
  int v2; // esi
  int v3; // ecx
  double v4; // st7
  double v5; // st7
  int v6; // eax
  int v7; // eax
  int v8; // edi
  _WORD *v9; // edi
  char v10; // al
  char *v11; // esi
  unsigned int v12; // eax
  char *v13; // edi
  const char *v15; // esi
  char *v16; // eax
  int v17; // [esp+4h] [ebp-A4h] BYREF
  char v18; // [esp+8h] [ebp-A0h] BYREF
  int v19; // [esp+9h] [ebp-9Fh]
  int v20; // [esp+Dh] [ebp-9Bh]
  int v21; // [esp+11h] [ebp-97h]
  int v22; // [esp+15h] [ebp-93h]
  int v23; // [esp+19h] [ebp-8Fh]
  int v24; // [esp+1Dh] [ebp-8Bh]
  int v25; // [esp+21h] [ebp-87h]
  __int16 v26; // [esp+25h] [ebp-83h]
  char v27; // [esp+27h] [ebp-81h]
  char Buffer[125]; // [esp+28h] [ebp-80h] BYREF
  __int16 v29; // [esp+A5h] [ebp-3h]
  char v30; // [esp+A7h] [ebp-1h]

  if ( *(_DWORD *)(*(_DWORD *)this + 14820) == 1 )
  {
    v2 = 6;
    if ( *(_DWORD *)dword_B640C8 != 6 )
    {
      v3 = *(_DWORD *)(this + 19284);
      v17 = 10;
      if ( v3 <= 10 )
        v17 = v3;
      v4 = *(float *)(this + 20704) + *(float *)(this + 20676);
      if ( v4 >= (double)v17 * 0.003 + *(float *)(this + 20832) )
      {
        v17 = 10;
        if ( v3 <= 10 )
          v17 = v3;
        v4 = (double)v17 * 0.003 + *(float *)(this + 20832);
      }
      *(float *)(this + 20832) = v4;
    }
    v5 = 1.0 - sub_592970(&dword_FB1EF8) * *(float *)(this + 20660) >= 0.5
       ? 1.0 - sub_592970(&dword_FB1EF8) * *(float *)(this + 20660)
       : 0.5;
    v6 = *(_DWORD *)(this + 20848);
    *(float *)(this + 20896) = v5;
    if ( v6 != 1 )
    {
      if ( *(_DWORD *)(16 * *(_DWORD *)(this + 21496) + this + 20920) <= *(_DWORD *)(*(_DWORD *)this + 19284) )
        sub_421A90((_DWORD *)this);
      v7 = sub_578530(this + 16);
      v8 = sub_4FB6D0(v7);
      if ( sub_592970(&dword_FB1EF8) >= 0.0099999998 )
      {
        if ( sub_592970(&dword_FB1EF8) >= 0.33000001 )
        {
          if ( sub_592970(&dword_FB1EF8) >= 0.66000003 )
          {
            v2 = 7;
            if ( v8 == 6 )
            {
              v17 = SLODWORD(flt_BE08A4[(unsigned __int8)dword_BE08A0++]);
              if ( *(float *)&v17 * 0.050000001 + 0.85000002 <= sub_592970(&dword_FB1EF8) )
                goto LABEL_21;
              goto LABEL_57;
            }
          }
          else
          {
            if ( v8 == 5 )
            {
              v17 = SLODWORD(flt_BE08A4[(unsigned __int8)dword_BE08A0++]);
              if ( *(float *)&v17 * 0.050000001 + 0.40000001 <= sub_592970(&dword_FB1EF8) )
                goto LABEL_21;
              goto LABEL_57;
            }
            if ( v8 == 7 )
            {
              v17 = SLODWORD(flt_BE08A4[(unsigned __int8)dword_BE08A0++]);
              if ( *(float *)&v17 * 0.050000001 + 0.60000002 >= sub_592970(&dword_FB1EF8) )
                goto LABEL_21;
              goto LABEL_57;
            }
          }
        }
        else
        {
          v2 = 5;
          if ( v8 == 6 )
          {
            v17 = SLODWORD(flt_BE08A4[(unsigned __int8)dword_BE08A0++]);
            if ( *(float *)&v17 * 0.050000001 + 0.2 < sub_592970(&dword_FB1EF8) )
              goto LABEL_57;
          }
          if ( v8 == *(_DWORD *)(this + 20916) )
          {
            v17 = SLODWORD(flt_BE08A4[(unsigned __int8)dword_BE08A0++]);
            if ( *(float *)&v17 * 0.050000001 + 0.2 > sub_592970(&dword_FB1EF8) )
              v2 = *(_DWORD *)(this + 20916);
          }
        }
      }
      else
      {
        v2 = *(_DWORD *)(this + 20916);
        if ( v2 > 4 )
          v2 = 3;
      }
      if ( v8 != v2 && v2 )
      {
LABEL_21:
        if ( *(_DWORD *)(*(_DWORD *)this + 22468) == *(_DWORD *)(dword_91E084 + 22468)
          && *(_DWORD *)(*(_DWORD *)this + 21788) == 1
          && byte_B6F790 )
        {
          if ( v2 < 2 || v2 > 4 || v8 < 2 || v8 > 4 )
          {
            v19 = 0;
            v20 = 0;
            v21 = 0;
            v22 = 0;
            v23 = 0;
            v24 = 0;
            v25 = 0;
            v26 = 0;
            v18 = 0;
            v27 = 0;
            switch ( v2 )
            {
              case 2:
                sub_41D840(&byte_91CC38, "Hard Compound");
                off_16C95E8();
                return;
              case 3:
                strcpy(&v18, sub_41D840(&byte_91CC38, "Medium Compound"));
                goto LABEL_51;
              case 4:
                strcpy(&v18, sub_41D840(&byte_91CC38, "Soft Compound"));
                goto LABEL_51;
              case 5:
                strcpy(&v18, sub_41D840(&byte_91CC38, "Intermediate Compound"));
                goto LABEL_51;
              case 6:
                strcpy(&v18, sub_41D840(&byte_91CC38, "Wet Compound"));
                goto LABEL_51;
              case 7:
                strcpy(&v18, sub_41D840(&byte_91CC38, "Monsoon Compound"));
                goto LABEL_51;
              default:
LABEL_51:
                v9 = (_WORD *)((char *)&v17 + 3);
                do
                {
                  v10 = *((_BYTE *)v9 + 1);
                  v9 = (_WORD *)((char *)v9 + 1);
                }
                while ( v10 );
                *v9 = 32;
                v11 = sub_41D840(&byte_91CC38, "tires");
                v12 = strlen(v11) + 1;
                v13 = (char *)&v17 + 3;
                while ( *++v13 )
                  ;
                qmemcpy(v13, v11, v12);
                memset(Buffer, 0, sizeof(Buffer));
                v29 = 0;
                v30 = 0;
                v15 = (const char *)(108 * *(_DWORD *)(*(_DWORD *)this + 21788) + *(_DWORD *)this + 21656);
                v16 = sub_41D840(&byte_91CC38, "Requesting Pit for");
                sprintf(Buffer, "%s: %s %s", v15, v16, &v18);
                sub_4730C0(Buffer, 3, &byte_1020304, 1084227584);
                break;
            }
          }
        }
        else
        {
          sub_421A90((_DWORD *)this);
        }
      }
LABEL_57:
      if ( (*(float *)(this + 17096) + *(float *)(this + 16844) + *(float *)(this + 16592) + *(float *)(this + 16340))
         * 0.25 < 0.89999998 )
        sub_421A90((_DWORD *)this);
    }
  }
}
