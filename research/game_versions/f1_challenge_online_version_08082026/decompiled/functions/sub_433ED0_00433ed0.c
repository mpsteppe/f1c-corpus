int __thiscall sub_433ED0(char **this, int a2, char a3)
{
  int v4; // ebp
  int v5; // esi
  char *v6; // eax
  char **v7; // esi
  char *v8; // eax
  char *v9; // ecx

  v4 = 1;
  if ( sub_42BC10() )
  {
    v5 = dword_8AC394 + 1060 * *(_DWORD *)(dword_7C54E8 + 18584);
    if ( v5 )
    {
      dword_7C56C4 = dword_7D0450;
      sub_42ED70((int)&byte_7C56C0);
      v6 = *(char **)(v5 + 8);
      if ( !v6 )
        v6 = &byte_5EA438;
      if ( !sub_4F4270(v6, &byte_7C56C0, 0) )
      {
        sub_42EBC0(&byte_7C56C0);
        if ( !sub_4F4270(a2, &byte_7C56C0, 1) )
        {
          v4 = 0;
          byte_7C56C0 = 0;
          if ( a3 )
          {
            v7 = this + 2;
            sub_566650(a2);
            v8 = *this;
            if ( !*this )
              v8 = &byte_5EA438;
            v9 = *v7;
            if ( !*v7 )
              v9 = &byte_5EA438;
            sub_568B00(v9, v8);
          }
        }
        sub_430F00(&byte_7C56C0);
      }
    }
  }
  return v4;
}
