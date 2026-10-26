void __thiscall sub_5556A0(float *this)
{
  unsigned int v1; // kr00_4
  double v3; // st7
  char *v4; // eax
  int v5; // edi
  double v6; // st7
  double v7; // st7
  double v8; // st7
  char *v9; // eax
  char *v10; // eax
  int i; // eax
  int v12; // eax
  char *v13; // eax
  char *v14; // eax
  int v15; // edi
  int k; // edi
  int j; // edi
  int v18; // eax
  int v19; // edi
  char *v20; // eax
  int m; // ebp
  int v22; // edi
  int v23; // ebx
  int v24; // ebp
  float *v25; // edi
  int v26; // ecx
  int v27; // ecx
  int v28; // [esp+0h] [ebp-1A4h]
  int v29; // [esp+0h] [ebp-1A4h]
  char *v30; // [esp+0h] [ebp-1A4h]
  int v31; // [esp+0h] [ebp-1A4h]
  int v32; // [esp+4h] [ebp-1A0h]
  char *v33; // [esp+4h] [ebp-1A0h]
  float v34; // [esp+4h] [ebp-1A0h]
  int v35; // [esp+4h] [ebp-1A0h]
  int v36; // [esp+4h] [ebp-1A0h]
  int v37; // [esp+8h] [ebp-19Ch]
  float v38; // [esp+18h] [ebp-18Ch]
  float v39; // [esp+1Ch] [ebp-188h] BYREF
  char v40[4]; // [esp+20h] [ebp-184h] BYREF
  char v41[4]; // [esp+9Ch] [ebp-108h] BYREF
  char Buffer[260]; // [esp+A0h] [ebp-104h] BYREF

  if ( *(int *)dword_B640C8 > 0 )
  {
    if ( *(int *)dword_B640C8 <= 5 )
    {
      sub_551380();
      if ( dword_B64134 )
      {
        if ( dword_B64134 == 5 )
        {
          if ( dbl_FB1D18 >= this[56] )
          {
            sub_430250(&dword_B640C0, 8u);
            sub_54EE10();
          }
        }
        else if ( dword_B64134 == 7 )
        {
          v6 = dbl_FB1D10 + this[56];
LABEL_114:
          this[56] = v6;
        }
      }
      else if ( dbl_FB1D18 >= this[55] )
      {
        sub_430250(&dword_B640C0, 5u);
        sub_54EE10();
      }
    }
    else if ( *(_DWORD *)dword_B640C8 == 6 )
    {
      switch ( dword_B64134 )
      {
        case 0:
          if ( dbl_FB1D18 < this[55] )
          {
            if ( (unsigned __int8)sub_4735A0() )
            {
              if ( !dword_B70030 )
              {
                if ( sub_42FE50(&dword_B640C0) )
                {
                  v3 = this[55] - dbl_FB1D18;
                  *(float *)v40 = v3;
                  if ( v3 >= 0.0 )
                  {
                    if ( dword_757C10 == *((_DWORD *)this + 62) )
                    {
                      v37 = 1084227584;
                      v32 = (int)&byte_1020304;
                      v28 = 3;
                      v4 = sub_41D840(&byte_91CC38, "Grid full. Prepare to race.");
                      goto LABEL_16;
                    }
                    sub_41D840(&byte_91CC38, "Waiting for");
                    sub_4152E0();
                    v5 = dword_757C10;
                    if ( dword_757C10 - *((_DWORD *)this + 62) == 1 )
                      v33 = sub_41D840(&byte_91CC38, "player to join the grid");
                    else
                      v33 = sub_41D840(&byte_91CC38, "players to join the grid");
                    sprintf(Buffer, "%s %d %s: ", v40, v5 - *((_DWORD *)this + 62), v33);
                    sub_54ECC0();
                  }
                }
              }
            }
          }
          else if ( dword_B70030 )
          {
            sub_430250(&dword_B640C0, 1u);
            sub_54EE10();
          }
          else
          {
            sub_430250(&dword_B640C0, 3u);
            this[55] = dbl_FB1D18;
            this[56] = 3.4028235e38;
            if ( (unsigned __int8)sub_4735A0() )
              sub_472920((const char **)&dword_B6CB98, "00:01", 0);
          }
          break;
        case 1:
          if ( dbl_FB1D18 < this[56] )
          {
            v39 = this[56] - dbl_FB1D18;
            sub_551380();
            if ( v38 < 15.0 && !dword_B70174 )
              sub_555670(this);
            v7 = (double)dword_B6FFAC + this[55] - dbl_FB1D18;
            v39 = v7;
            if ( v7 >= 0.0 )
            {
              if ( byte_B6FFF4 )
              {
                sub_41D840(&byte_91CC38, "Time until pit closes: ");
                sub_54ECC0();
              }
            }
            else
            {
              sub_54EE10();
              if ( v38 > -0.5 )
                sub_4731E0(&dword_B6CB98);
              if ( byte_B6FFF4 )
                sub_54ECC0();
            }
          }
          else
          {
            sub_4731E0(&dword_B6CB98);
            if ( dword_B70174 )
            {
              sub_430250(&dword_B640C0, 2u);
              v6 = this[56] + 300.0;
              goto LABEL_114;
            }
LABEL_38:
            if ( sub_42FE50(&dword_B640C0) )
            {
              sub_430250(&dword_B640C0, 3u);
              this[55] = dbl_FB1D18;
              this[56] = 3.4028235e38;
            }
            else
            {
              this[71] = 3.4028235e38;
              this[55] = 3.4028235e38;
              *((_BYTE *)this + 253) = 0;
              sub_430250(&dword_B640C0, 4u);
            }
          }
          break;
        case 2:
          if ( *(_DWORD *)this == 2 )
            sub_415BF0((_DWORD **)this);
          sub_415CD0(this);
          if ( dbl_FB1D18 < this[56] )
            break;
          *((_BYTE *)this + 253) = 0;
          goto LABEL_38;
        case 3:
          sub_551380();
          if ( sub_42FE50(&dword_B640C0) )
          {
            if ( dbl_FB1D18 > this[56] )
            {
              sub_551380();
              v8 = this[56];
              this[55] = this[56];
              this[56] = v8 + this[57];
              v9 = sub_41D840(&byte_91CC38, "Press SPACE To Skip Formation Lap");
              sub_472920((const char **)&dword_B6CB98, v9, 0);
              v10 = sub_41D840(&byte_91CC38, "Green Flag!");
              sub_4730C0((int **)&dword_B6CB98, v10, 3, (int)&byte_1020304, 1084227584);
              sub_4EE320(62, 0);
              for ( i = 0; i < dword_757C10; ++i )
                *(_DWORD *)(*(&dword_91E088 + i) + 19280) = 9;
              sub_430250(&dword_B640C0, 5u);
            }
            if ( (_BYTE)dword_757C1C )
            {
              *(float *)&v29 = dbl_FB1D10;
              sub_52E2A0((int *)(dword_91E084 + 19272), v29);
            }
          }
          else if ( this[55] + 15.0 < dbl_FB1D18 && (_BYTE)dword_757C1C && dword_91E084 )
          {
            sub_52C430((int *)(dword_91E084 + 19272), 0, 1);
          }
          v12 = *((_DWORD *)this + 60);
          if ( v12 != 2139095039 && v12 != -8388609 )
          {
            if ( dbl_FB1D18 <= this[60] )
            {
              if ( !(unsigned __int8)sub_4735A0() || !byte_B73540 )
              {
                v14 = sub_41D840(&byte_91CC38, "Skipping Formation Lap ...");
                sub_4730C0((int **)&dword_B6CB98, v14, 3, (int)&byte_1020304, 1084227584);
              }
            }
            else
            {
              v13 = sub_41D840(&byte_91CC38, "Skipping Formation Lap ...");
              sub_472920((const char **)&dword_B6CB98, v13, 0);
              this[60] = -3.4028235e38;
              if ( sub_42FE50(&dword_B640C0) )
              {
                sub_550650(this);
              }
              else
              {
                this[71] = 3.4028235e38;
                this[55] = 3.4028235e38;
                *((_BYTE *)this + 253) = 0;
                sub_430250(&dword_B640C0, 4u);
              }
            }
          }
          sub_415F50((int)this);
          break;
        case 4:
          if ( !*((_BYTE *)this + 253) )
          {
            sub_415F50((int)this);
            if ( dword_91BF28 != dword_91BF40 )
              sub_413790(&dword_91BF20, this);
            off_16C9458();
            return;
          }
          if ( dbl_FB1D18 < this[55] )
          {
            if ( (unsigned __int8)sub_4735A0() )
              sub_472920((const char **)&dword_B6CB98, "00:01", 0);
            v39 = dbl_FB1D18;
            if ( this[71] + 4.0 > v39
              && this[71] + 3.0 > v39
              && this[71] + 2.0 > v39
              && this[71] + 1.0 > v39
              && v39 < (double)this[71] )
            {
              v37 = 0;
              sub_551380();
              if ( (unsigned __int8)sub_4735A0() )
              {
                v39 = 122.5 - dbl_FB1D18;
                if ( 122.5 - dbl_FB1D18 >= 0.0 )
                {
                  if ( dword_757C10 == *((_DWORD *)this + 62) )
                  {
                    v32 = 1084227584;
                    v28 = (int)&byte_1020304;
                    v4 = sub_41D840(&byte_91CC38, (const char *)3);
LABEL_16:
                    sub_4730C0((int **)&dword_B6CB98, v4, v28, v32, v37);
                  }
                  else
                  {
                    sub_41D840(&byte_91CC38, "Waiting for");
                    sub_4152E0();
                    v15 = dword_757C10;
                    if ( dword_757C10 - *((_DWORD *)this + 62) == 1 )
                      v30 = sub_41D840(&byte_91CC38, "player to join the grid");
                    else
                      v30 = sub_41D840(&byte_91CC38, "players to join the grid");
                    sprintf(v41, "%s %d %s: ", &v39, v15 - *((_DWORD *)this + 62), v30);
                    sub_54ECC0();
                  }
                }
              }
            }
            else
            {
              sub_551380();
            }
          }
          else
          {
            sub_551AD0();
            sub_551380();
            sub_430250(&dword_B640C0, 5u);
          }
          break;
        case 5:
          if ( *((_DWORD *)this + 78) == 2 )
          {
            for ( j = 0; j < dword_757C10; ++j )
            {
              if ( *(_DWORD *)(*(&dword_91E088 + j) + 19288) == 1 )
                sub_54EE10();
            }
          }
          if ( dword_B6FF34 > 0 )
          {
            v34 = this[56] - dbl_FB1D18 + 0.5;
            v18 = sub_4015C0(v34);
            if ( v18 >= 0 && !(v18 % dword_B6FF34) )
            {
              v19 = v18 / 3600;
              v35 = v18 % 3600 % 60;
              v31 = v18 % 3600 / 60;
              v20 = sub_41D840(&byte_91CC38, "Time Remaining:");
              sprintf(v40, "%s %d:%02d:%02d", v20, v19, v31, v35);
              sub_4730C0((int **)&dword_B6CB98, v40, 3, (int)&byte_1020304, 1084227584);
            }
          }
          if ( (_BYTE)dword_757C1C && !*(_DWORD *)(dword_91E084 + 19284) && *(_DWORD *)(dword_91E084 + 19280) == 9 )
          {
            *(float *)&v36 = dbl_FB1D10;
            sub_52E2A0((int *)(dword_91E084 + 19272), v36);
          }
          break;
        case 6:
          if ( *((_DWORD *)this + 78) == 2 )
          {
            for ( k = 0; k < dword_757C10; ++k )
            {
              if ( *(_DWORD *)(*(&dword_91E088 + k) + 19288) == 1 )
                sub_54EE10();
            }
          }
          break;
        default:
          break;
      }
    }
  }
  v1 = __readeflags();
  __writeeflags(v1);
  if ( (*(_DWORD *)(dword_16C6EE0 + 1823602725) & 1) == 0 )
  {
    for ( m = 0; m < dword_757C10; ++m )
    {
      v22 = *(&dword_91E088 + m);
      if ( *(_DWORD *)(v22 + 14820) != -1 )
        *(float *)(v22 + 19292) = sub_577BC0(v22 + 16);
    }
  }
  v23 = 0;
  if ( dword_757C14 > 0 )
  {
    v24 = 0;
    do
    {
      if ( *(_DWORD *)((char *)off_757C18 + v24 + 14820) != -1 )
      {
        v25 = (float *)((char *)off_757C18 + v24);
        v25[4823] = sub_577BC0(v25 + 4);
      }
      ++v23;
      v24 += 22616;
    }
    while ( v23 < dword_757C14 );
  }
  if ( *((_DWORD *)this + 78) != 2 )
  {
    if ( *((_BYTE *)this + 328) && (v39 = dbl_FB1D18, fmod(dbl_FB1D18, 1.0) > 0.5) )
    {
      v26 = *((_DWORD *)this + 79);
      *((_DWORD *)this + 78) = 4;
      if ( v26 )
        sub_5E37F0(4, 0, 0);
      if ( *((_DWORD *)this + 80) )
        sub_5E37F0(4, 0, 0);
    }
    else
    {
      v27 = *((_DWORD *)this + 79);
      *((_DWORD *)this + 78) = 1;
      if ( v27 )
        sub_5E37F0(1, 0, 0);
      if ( *((_DWORD *)this + 80) )
        sub_5E37F0(1, 0, 0);
    }
  }
}
