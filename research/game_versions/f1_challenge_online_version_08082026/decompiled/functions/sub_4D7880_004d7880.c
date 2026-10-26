int __thiscall sub_4D7880(int *this, int a2)
{
  int v3; // ebx
  int v4; // edi
  char *v5; // eax

  v3 = 0;
  if ( *this <= 0 )
  {
LABEL_7:
    if ( dword_7C569C != 5 )
    {
      if ( (unsigned __int8)sub_4D7A50(1, aDDevF119992002_4, 1080) )
        sub_4D7AA0(&unk_8AD25C, aNonExistentTir);
    }
    return 0;
  }
  else
  {
    v4 = 0;
    while ( 1 )
    {
      v5 = *(char **)(v4 + this[1]);
      if ( !v5 )
        v5 = byte_5EA438;
      if ( !sub_588410(a2, v5) )
        return this[1] + 36 * v3;
      ++v3;
      v4 += 36;
      if ( v3 >= *this )
        goto LABEL_7;
    }
  }
}
