int sub_566C10()
{
  char *v0; // eax
  char *v2; // eax
  int v3; // eax
  char *v4; // eax
  char *v5; // eax
  char *v6; // eax
  char *v7; // eax
  char *v8; // eax
  char *v9; // eax
  int v10; // eax
  double v11; // st7
  unsigned __int64 v12; // rax
  double v13; // [esp+4h] [ebp-54h]
  int v14; // [esp+Ch] [ebp-4Ch] BYREF
  int v15[2]; // [esp+10h] [ebp-48h] BYREF
  char Buffer[64]; // [esp+18h] [ebp-40h] BYREF

  if ( *(_DWORD *)dword_B72314 == 8 && byte_91E048 && dword_91DC50 && !sub_521050(&dword_BE120C) )
  {
    if ( byte_91DE28 )
    {
      if ( !byte_91DE29 )
      {
        if ( flt_91DE20 + 1.0 > dbl_FB1D18 )
        {
          v4 = sub_41D840(&byte_91CC38, "GO!");
          sprintf(Buffer, v4);
          sub_562B70((int)Buffer, 600, 500, 1627324416, 0, 2, 1.0, 1.0);
        }
        if ( dword_91DE18 == 1 )
        {
          v5 = sub_41D840(&byte_91CC38, "SUGGESTED");
          sprintf(Buffer, v5);
          sub_562B70((int)Buffer, 280, 180, 1627389951, 0, 2, 1.0, 1.0);
          v6 = sub_41D840(&byte_91CC38, "  GEAR");
          sprintf(Buffer, v6);
          sub_562B70((int)Buffer, 280, 220, 1627389951, 0, 2, 1.0, 1.0);
          v7 = sub_41D840(&byte_91CC38, "  SPEED");
          sprintf(Buffer, v7);
          sub_562B70((int)Buffer, 280, 260, 1627389951, 0, 2, 1.0, 1.0);
        }
        v8 = sub_41D840(&byte_91CC38, "TIME LEFT");
        sprintf(Buffer, v8);
        sub_562B70((int)Buffer, 280, 340, 1627389951, 0, 2, 1.0, 1.0);
        if ( sub_42A730(byte_91DC48) )
        {
          v10 = sub_42A730(byte_91DC48);
          sprintf(Buffer, "%d", v10);
        }
        else
        {
          v9 = sub_41D840(&byte_91CC38, "N");
          sprintf(Buffer, v9);
        }
        if ( dword_91DE18 == 1 )
          sub_562B70((int)Buffer, 530, 220, 1627389951, 1, 2, 1.0, 1.0);
        if ( byte_B72478 )
          v11 = 3.6;
        else
          v11 = 2.236936292054402;
        *(double *)v15 = v11;
        *(float *)v15 = v11;
        v12 = (unsigned __int64)(sub_42A740(byte_91DC48) * v11);
        sprintf(Buffer, "%d", (_DWORD)v12);
        if ( dword_91DE18 == 1 )
          sub_562B70((int)Buffer, 530, 260, 1627389951, 1, 2, 1.0, 1.0);
        if ( flt_91DE30 > 0.0 )
        {
          v15[0] = 0;
          *(float *)&v14 = 0.0;
          sub_4E42B0(flt_91DE30, v15, (float *)&v14);
          sprintf(Buffer, "%.2d:%06.3f", v15[0], *(float *)&v14);
          sub_562B70((int)Buffer, 280, 380, 1627389951, 0, 2, 1.0, 1.0);
        }
        else
        {
          LODWORD(v13) = 0;
          sprintf(Buffer, "%.2d:%06.3f", 0, v13);
          sub_562B70((int)Buffer, 280, 380, 1627324416, 0, 2, 1.0, 1.0);
        }
      }
    }
    else if ( !byte_91DE29 )
    {
      if ( byte_91DE38 )
      {
        v3 = (unsigned __int64)(flt_91DE3C + 4.0 - dbl_FB1D18) + 1;
        if ( v3 <= 3 )
        {
          sprintf(Buffer, "%d", v3);
          sub_562B70((int)Buffer, 600, 500, 1627389951, 2, 2, 1.0, 1.0);
          return 0;
        }
      }
      else
      {
        if ( *(float *)(dword_91DC50 + 52) < 3.0 )
        {
          v0 = sub_41D840(&byte_91CC38, "Get Ready for Manual Control");
          sprintf(Buffer, v0);
          sub_562B70((int)Buffer, 600, 500, 1627389951, 2, 2, 1.0, 1.0);
          return 0;
        }
        v2 = sub_41D840(&byte_91CC38, "Hold down Accelerator");
        sprintf(Buffer, v2);
        sub_562B70((int)Buffer, 600, 500, 1627389951, 2, 2, 1.0, 1.0);
        if ( byte_91E060 == 1 )
        {
          sub_42AA60();
          byte_91E060 = 0;
          return 0;
        }
      }
    }
  }
  return 0;
}
