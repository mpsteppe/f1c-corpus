int __thiscall sub_4E88A0(int *this)
{
  int *v1; // esi
  int v2; // ebp
  bool v3; // bl
  int v4; // edi
  int v5; // eax
  int v6; // esi
  int v7; // ecx
  int v8; // eax
  char *v9; // eax
  char *v10; // eax
  char *v11; // eax
  int v13; // [esp-4h] [ebp-174h]
  char *v14; // [esp-4h] [ebp-174h]
  char *v15; // [esp-4h] [ebp-174h]
  float v16; // [esp+0h] [ebp-170h]
  int v17; // [esp+0h] [ebp-170h]
  int v18; // [esp+0h] [ebp-170h]
  char v20[24]; // [esp+18h] [ebp-158h] BYREF
  char v21[24]; // [esp+30h] [ebp-140h] BYREF
  char Buffer[96]; // [esp+48h] [ebp-128h] BYREF
  _BYTE v23[144]; // [esp+A8h] [ebp-C8h] BYREF
  int v24; // [esp+138h] [ebp-38h]
  int v25; // [esp+16Ch] [ebp-4h]

  v1 = this;
  if ( *(_DWORD *)dword_B640C8 == 6 )
  {
    v2 = 0;
    v3 = 0;
    if ( !byte_B722E4 )
    {
      if ( (unsigned __int8)sub_4735A0() )
      {
        sub_4744E0(v23);
        v25 = 0;
        if ( sub_4747D0(&dword_B6CBA8, (int)v23, 0) )
        {
          v2 = v24;
          v3 = v24 != 0;
        }
        v25 = -1;
        nullsub_7(v23);
      }
      else if ( byte_B729E8 )
      {
        v2 = dword_B7261C;
        v3 = 1;
      }
    }
    v4 = *((_DWORD *)dword_91E07C + 4821) + 1;
    if ( dword_B64134 == 5 )
    {
      v16 = flt_FADE20 - dbl_FB1D18 + 0.5;
      v5 = sub_4015C0(v16);
      if ( v5 < 0 )
      {
        v14 = sub_41D840(&byte_91CC38, "L");
        sprintf(Buffer, "%s %02d/   -:--:--", v14, v4);
      }
      else
      {
        v6 = v5 / 3600;
        v7 = v5 % 3600;
        v8 = v5 % 3600 / 60;
        if ( v3 )
        {
          v9 = sub_41D840(&byte_91CC38, "L");
          sprintf(Buffer, "%s %02d/%02d", v9, v4, v2);
        }
        else
        {
          v17 = v7 % 60;
          v13 = v8;
          v10 = sub_41D840(&byte_91CC38, "L");
          sprintf(Buffer, "%s %02d/   %d:%02d:%02d", v10, v4, v6, v13, v17);
        }
        v1 = this;
      }
    }
    else if ( v3 )
    {
      v11 = sub_41D840(&byte_91CC38, "L");
      sprintf(Buffer, "%s %02d/%02d", v11, v4, v2);
    }
    else
    {
      v18 = *((_DWORD *)dword_91E07C + 4821) + 1;
      v15 = sub_41D840(&byte_91CC38, "L");
      sprintf(Buffer, "%s %02d/   -:--:--", v15, v18);
    }
  }
  else
  {
    sub_4E5370(v20, 24);
    sub_4E5570(v21, 24);
    sprintf(Buffer, "%s   %s", v20, v21);
  }
  return sub_4E6210((int)Buffer, v1[147] + 96, v1[148] + 190, v1[2], v1[3], 0);
}
