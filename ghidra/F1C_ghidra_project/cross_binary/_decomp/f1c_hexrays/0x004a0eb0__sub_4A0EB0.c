// f1c  0x004a0eb0  size=253
int sub_4A0EB0()
{
  int v1; // ecx
  int v2; // esi
  float v3; // [esp+0h] [ebp-8h]

  if ( (unsigned __int8)sub_4D7A50(2, aDDevF119992002_17, 1169) )
    sub_4D7AA0(&unk_8AD25C, aEnteredOptions);
  if ( byte_7CE260 )
  {
    byte_7C5690 = 1;
    return 0;
  }
  else if ( dword_7CE264 )
  {
    if ( byte_5CCFE4 )
    {
      byte_5CCFE4 = 0;
      return 0;
    }
    else
    {
      return 1;
    }
  }
  else
  {
    sub_404B50(&dword_5EA43C);
    while ( 1 )
    {
      sub_4F9F00(&unk_8AFE18);
      v3 = dbl_8AFE90;
      sub_4537B0((int)&ppvOut, v3);
      v1 = dword_7CE250++;
      v2 = sub_485B90(v1, byte_7CE25F);
      sub_4186F0((int)flt_5EA618);
      sub_4F9AD0(&unk_8AFE18);
      sub_404B60((void **)&dword_5EA43C);
      if ( byte_7CE25C )
        break;
      if ( v2 == -1 )
        return 1;
      if ( v2 == 1 )
        return 0;
      sub_4F9F30(&unk_8AFE18);
      sub_4A1830(&unk_7CE2A4);
    }
    byte_7CE25C = 0;
    return 0;
  }
}
