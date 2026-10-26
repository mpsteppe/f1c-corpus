void __thiscall sub_4BBBD0(_BYTE *this)
{
  int v2; // eax
  float *v3; // esi
  double v4; // st7
  float *v5; // eax
  int v6; // eax
  char *v7; // eax
  double v8; // st7
  float v9; // [esp+0h] [ebp-1Ch]
  float v10; // [esp+10h] [ebp-Ch]
  float v11; // [esp+14h] [ebp-8h]
  float v12; // [esp+18h] [ebp-4h]

  if ( !*this )
    goto LABEL_15;
  if ( this[1] )
  {
    v2 = sub_4F83E0(0);
    if ( v2 > -1 )
    {
      v3 = (float *)((char *)&unk_62BF68 + 25304 * v2);
      v10 = *((float *)off_5FD348 + 4401) - v3[4401];
      v11 = *((float *)off_5FD348 + 4402) - v3[4402];
      v12 = *((float *)off_5FD348 + 4403) - v3[4403];
      v4 = sub_424BC0(v3, (int)off_5FD348);
      if ( v4 >= -50.0 )
      {
        if ( v4 < 50.0 && v4 > -50.0 )
        {
          v5 = (float *)sub_427FF0((int)v3);
          v4 = v12 * v5[55] + v11 * v5[54] + v10 * v5[53];
        }
        if ( v4 < 30.0 )
          sub_4BBE30(this);
      }
    }
  }
  if ( !*this )
  {
LABEL_15:
    v6 = dword_7D7540;
LABEL_16:
    if ( v6 )
    {
      if ( v6 != 6 && v6 != 7 )
      {
        v7 = (char *)&unk_62BF68 + 25304 * sub_4FA870(0);
        if ( *((_DWORD *)v7 + 4146) != -1 )
        {
          v8 = sub_51C7A0(v7 + 84);
          if ( v8 > flt_628F60 * flt_6290D0 && v8 < flt_628F64 * flt_6290D0 )
          {
            sub_4BBE60(1);
            if ( dword_7D7540 > 1 )
            {
              if ( dword_79FC40 < 1023 )
              {
                ++dword_79FC40;
                dword_7D3C44 += 208;
              }
              v9 = dbl_7DA9D0;
              sub_4D0D00(4, 40, 0, 63, LODWORD(v9), 3);
            }
          }
        }
      }
    }
    return;
  }
  v6 = dword_7D7540;
  if ( !dword_7D7540 )
  {
    sub_4BBF10(this);
    v6 = dword_7D7540;
  }
  if ( !*this )
    goto LABEL_16;
}
