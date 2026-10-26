void sub_409E80()
{
  int v0; // eax
  signed int i; // esi
  int v2; // esi
  int v3; // eax
  int v4; // edx
  int v5; // ecx
  bool v6; // sf
  float v7; // [esp+8h] [ebp-20h] BYREF
  float v8; // [esp+Ch] [ebp-1Ch] BYREF
  float v9; // [esp+10h] [ebp-18h] BYREF
  float v10; // [esp+14h] [ebp-14h] BYREF
  float v11; // [esp+18h] [ebp-10h] BYREF
  float v12; // [esp+1Ch] [ebp-Ch] BYREF
  float v13; // [esp+20h] [ebp-8h] BYREF
  int v14; // [esp+24h] [ebp-4h] BYREF

  sub_595470(32, 0);
  sub_597DD0(dword_7DA9B8);
  v0 = sub_40C4C0(&dword_6291CC);
  if ( v0 && sub_593D90(v0) )
  {
    for ( i = 0; i < (int)NumOfElements; ++i )
      sub_59EE70(32, 0);
    if ( !byte_767B2C )
    {
      if ( dword_75AAC4 )
        sub_59EE70(32, 1);
      sub_593EA0(&v9, &v10, &v11, &v12);
      v7 = flt_768360;
      v8 = flt_76833C;
      v13 = flt_768384;
      if ( flt_768318 <= v9 + 0.1
        && flt_768318 >= v9 - 0.1
        && v10 + 0.1 >= v8
        && v10 - 0.1 <= v8
        && v11 + 0.1 >= v7
        && v11 - 0.1 <= v7
        && v12 + 0.1 >= v13
        && v12 - 0.1 <= v13 )
      {
        sub_593E60(&v7, &v8, &v13, &v14);
        v2 = LODWORD(v7) + LODWORD(v13) + 2;
        v3 = LODWORD(v7) - 2;
        v4 = LODWORD(v8) + v14 + 2;
        v5 = LODWORD(v8) - 2;
        v6 = LODWORD(v7) - 2 < 0;
        LODWORD(v7) -= 2;
        LODWORD(v8) -= 2;
        if ( v6 )
        {
          v3 = 0;
        }
        else
        {
          if ( v3 <= dword_6152E8 )
            goto LABEL_21;
          v3 = dword_6152E8;
        }
        v7 = *(float *)&v3;
LABEL_21:
        if ( v5 >= 0 )
        {
          if ( v5 <= dword_6152EC )
          {
LABEL_26:
            if ( v2 >= 0 )
            {
              if ( v2 > dword_6152E8 )
                v2 = dword_6152E8;
            }
            else
            {
              v2 = 0;
            }
            if ( v4 >= 0 )
            {
              if ( v4 > dword_6152EC )
                v4 = dword_6152EC;
            }
            else
            {
              v4 = 0;
            }
            sub_59FFB0(v3, v5, v2 - v3, v4 - v5, 0);
            return;
          }
          v5 = dword_6152EC;
        }
        else
        {
          v5 = 0;
        }
        v8 = *(float *)&v5;
        goto LABEL_26;
      }
    }
  }
}
