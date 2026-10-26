void __thiscall sub_4B2660(void *this)
{
  int v1; // ebp
  unsigned __int8 v2; // bl
  int v3; // esi
  __int16 *v4; // edi
  char v5; // al
  int v6; // edi
  char *v7; // esi
  float v8; // [esp+0h] [ebp-10h]
  unsigned int v9; // [esp+Ch] [ebp-4h] BYREF

  v9 = (unsigned int)this;
  if ( dword_75CBB0 == 7 && dword_75CBB4 >= 3 && dword_7D5DA4 != 2 )
  {
    if ( (v1 = dword_761FF8 & 1, (dword_761FF8 & 1) != 0) && (byte_762119 & 2) != 0
      || (dword_761FF8 & 1) != 0 && (byte_762199 & 2) != 0 )
    {
      v2 = byte_7697D8;
    }
    else
    {
      v2 = byte_7697D8;
      v3 = 0;
      v4 = word_762A08;
      while ( v3 < (v1 != 0 ? dword_762A04 : 0) )
      {
        if ( *v4 == 67 )
        {
          v5 = byte_7697DA;
          v2 = v2 == 0;
          if ( v2 < (unsigned __int8)byte_7697DA || (v5 = byte_7697DB, v2 > (unsigned __int8)byte_7697DB) )
            v2 = v5;
          if ( v2 == 1 )
            sub_4B2620();
        }
        ++v3;
        ++v4;
      }
      byte_7697D8 = v2;
    }
    if ( v2 )
    {
      v9 = (__int64)((double)dword_6152EC * 0.3334);
      v6 = 0;
      v7 = (char *)&unk_765D30;
      do
      {
        if ( sub_4B1CF0(v7, v6) )
        {
          sub_4B1F30((int)v7, &v9);
          v8 = dbl_7DA9C0;
          sub_4B1F80(v7, v8);
          sub_4B20D0((float *)v7, v6);
        }
        v7 += 48;
        ++v6;
      }
      while ( (int)v7 < (int)&dword_765E50 );
    }
  }
}
