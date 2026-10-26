void __thiscall sub_4D2D80(char *this)
{
  int v2; // edi
  float *v3; // esi
  char v4; // cl
  float v5; // [esp+10h] [ebp-4h]

  v5 = sub_4D9E20(&unk_7D5DAC);
  v2 = 0;
  v3 = (float *)(this + 256);
  do
  {
    if ( !sub_4D2C80(v2) )
      goto LABEL_11;
    v4 = byte_7620FC[v2] & 1;
    if ( *(_DWORD *)v3 == -1082130432 )
    {
      if ( v4 == 1 )
      {
        *v3 = v5;
        *((_BYTE *)v3 + 4) = 1;
      }
    }
    else
    {
      if ( v5 == *v3 )
        goto LABEL_11;
      if ( v5 >= (double)*v3 )
      {
        if ( v4 == 1 )
          goto LABEL_11;
        sub_4D2F50(v2, *v3, v5);
      }
      *v3 = -1.0;
    }
LABEL_11:
    ++v2;
    v3 += 2;
  }
  while ( v2 < 256 );
}
