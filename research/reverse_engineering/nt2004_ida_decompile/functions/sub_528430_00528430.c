void __thiscall sub_528430(void *this)
{
  int v2; // esi
  char v3; // dl
  signed int v4; // esi

  if ( (dword_761FF8 & 1) != 0 && (byte_762119 & 2) != 0 && (byte_76211D & 2) != 0 )
  {
    if ( dword_7DA7CC )
      sub_526830(&dword_7DA7C8, 0);
    else
      sub_526830(&dword_7DA7C8, 2);
  }
  sub_526870((char *)&dword_7DA7C8, dword_7E8CDC);
  if ( sub_463490(dword_764D70) || dword_7D5DA4 == 2 )
  {
LABEL_21:
    sub_527950(0);
    goto LABEL_22;
  }
  if ( dword_768948 )
  {
    v2 = dword_761FF8 & 1;
    v3 = byte_762119;
    if ( (dword_761FF8 & 1) != 0 && (byte_762119 & 2) != 0 && (byte_76211E & 2) != 0 )
    {
      if ( dbl_6152F8 == 1.0 )
        sub_527950(2);
      else
        sub_527950(0);
    }
    if ( v2 && (v3 & 2) != 0 && (byte_762110 & 2) != 0 )
    {
      if ( dbl_6152F8 == 1.0 )
      {
        sub_527950(1);
        goto LABEL_22;
      }
      goto LABEL_21;
    }
  }
LABEL_22:
  if ( byte_7DA994 )
    goto LABEL_43;
  byte_7DA994 = 1;
  sub_526670(&dword_7DA7C8, 4, dword_6152EC - 48);
  if ( dword_76618C == 1 )
    sub_526830(&dword_7DA7C8, 2);
  else
    sub_526830(&dword_7DA7C8, 0);
  if ( dword_76809C )
  {
    if ( dword_76809C == 1 )
    {
      sub_597F30(0, 6144);
    }
    else if ( dword_76809C == 2 )
    {
      sub_597F30(0, 4096);
    }
  }
  else
  {
    sub_597F30(4, 6147);
  }
  if ( !dword_767C58 )
  {
    sub_597F30(0, 256);
    goto LABEL_40;
  }
  if ( dword_767C58 != 1 )
    goto LABEL_40;
  v4 = 0;
  if ( (int)NumOfElements > 0 )
  {
    do
    {
      if ( *(_DWORD *)(LODWORD(dword_75AAD0[v4]) + 16584) )
        sub_59EF70(0, 1, 0);
      ++v4;
    }
    while ( v4 < (int)NumOfElements );
LABEL_40:
    if ( dword_767C58 <= 0 )
      goto LABEL_43;
  }
  if ( (unsigned int)dword_767FAC <= 1 )
    sub_597F30(0, 256);
LABEL_43:
  if ( !byte_76617C )
    sub_527360(0);
  if ( dword_763B84 && !sub_463490(dword_764D70) && dword_7D5DA4 != 2 && (dword_75CBB0 != 7 || !byte_76617C) )
  {
    sub_42FA50(&dword_75CBA8, byte_75CBB8 == 0);
    if ( byte_75CBB8 )
      sub_4F0190();
    else
      sub_4F01B0();
  }
  if ( byte_75CBB8 )
  {
    if ( sub_41F230(dword_62A170, aPaused, Destination) )
    {
      strncpy(Destination, aPaused, 0x1FFu);
      byte_62A37B = 0;
    }
    sub_45D100(&byte_764D68, (int)Destination, 3, 16909060, 0);
  }
  ++dword_7DA9AC;
  sub_590140(2, 0);
  dbl_7DA9C0 = sub_5ACA90(0);
  dbl_7DA9D8 = sub_5ACAC0(0);
  if ( byte_75CBB8 )
  {
    dbl_7DA9C8 = 0.0;
  }
  else if ( dbl_6152F8 == 1.0 )
  {
    dbl_7DA9C8 = sub_463E70(dword_764D70, dbl_7DA9C0);
    dbl_7DA9D0 = dbl_7DA9D0 + dbl_7DA9C8;
    sub_57B690(this);
    if ( dbl_7DA9C8 > 0.5 )
      dbl_7DA9C8 = 0.5;
  }
  else
  {
    dbl_7DA9C8 = dbl_6152F8 * dbl_7DA9C0;
    if ( dbl_6152F8 * dbl_7DA9C0 > 0.5 )
      dbl_7DA9C8 = 0.5;
    dbl_7DA9D0 = dbl_7DA9D0 + dbl_7DA9C8;
  }
  sub_590140(1, 0);
  if ( byte_7DA996 )
  {
    byte_7DA996 = 0;
    sub_4F6B60(&dword_7D73D0);
    sub_402940((int)&flt_628F60, 1, 0);
  }
  sub_527A00();
}
