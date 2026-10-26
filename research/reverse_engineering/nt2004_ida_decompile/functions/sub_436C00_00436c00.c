int __thiscall sub_436C00(char **this, int ArgList, char a3)
{
  int v4; // ebp
  int v5; // esi
  CHAR *v6; // eax
  char **v7; // esi
  char *v8; // eax
  char *v9; // ecx

  v4 = 1;
  if ( sub_42DBA0() )
  {
    v5 = dword_7D6A5C + 1232 * *(_DWORD *)(dword_75AACC + 25252);
    if ( v5 )
    {
      dword_75CBCC = dword_7689F0;
      sub_431A70((int)&byte_75CBC8);
      v6 = *(CHAR **)(v5 + 8);
      if ( !v6 )
        v6 = &byte_629120;
      if ( !sub_521740((char)v6, (int)&byte_75CBC8, 0) )
      {
        sub_431920(&byte_75CBC8);
        if ( !sub_521740(ArgList, (int)&byte_75CBC8, 1) )
        {
          v4 = 0;
          byte_75CBC8 = 0;
          if ( a3 )
          {
            v7 = this + 2;
            sub_578600(ArgList);
            v8 = *this;
            if ( !*this )
              v8 = &byte_629120;
            v9 = *v7;
            if ( !*v7 )
              v9 = &byte_629120;
            sub_57B530(v9, v8);
            sub_4368C0(this, ArgList, 0);
          }
        }
        sub_433C40(&byte_75CBC8);
      }
    }
  }
  return v4;
}
