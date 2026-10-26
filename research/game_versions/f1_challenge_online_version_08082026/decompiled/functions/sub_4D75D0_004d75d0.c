int __thiscall sub_4D75D0(_DWORD *this, int a2)
{
  int v3; // ebx
  int v4; // edi
  char *v5; // eax

  v3 = 0;
  if ( (int)this[2] <= 0 )
  {
LABEL_7:
    if ( (unsigned __int8)sub_4D7A50(1, aDDevF119992002_4, 995) )
      sub_4D7AA0(&unk_8AD25C, aTireBrandDoesn_0);
    return 0;
  }
  else
  {
    v4 = 0;
    while ( 1 )
    {
      v5 = *(char **)(v4 + this[3]);
      if ( !v5 )
        v5 = byte_5EA438;
      if ( !sub_588410(a2, v5) )
        return this[3] + 24 * v3;
      ++v3;
      v4 += 24;
      if ( v3 >= this[2] )
        goto LABEL_7;
    }
  }
}
