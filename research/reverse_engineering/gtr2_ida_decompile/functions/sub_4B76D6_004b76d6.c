int __usercall sub_4B76D6@<eax>(int a1@<ecx>, int a2@<edi>)
{
  const CHAR *v2; // eax
  int v4; // ebx
  _DWORD *v5; // eax
  _DWORD *v6; // esi
  int v7; // ebp
  int v8; // eax
  int v9; // eax
  int v11; // [esp-8h] [ebp-28h]

  v2 = dword_B7235C;
  if ( !dword_B7235C )
    v2 = WindowName;
  sub_615860(v2);
  sub_4D5D40(a1 + 284);
  v4 = 0;
  if ( sub_5387C0(&unk_BE1CFC) - 1 >= 0 )
  {
    do
    {
      v5 = operator new(0x58u);
      v6 = v5;
      if ( v5 )
      {
        v11 = a1;
        sub_4D2EF0(v5);
        *v6 = &off_6FD198;
        v6[18] = 0;
        v6[19] = -1;
        v6[20] = 0;
        v6[21] = -1;
        *((_BYTE *)v6 + 65) = 0;
        v6[17] = 0;
      }
      else
      {
        v6 = 0;
      }
      v7 = sub_5387F0(&unk_BE1CFC, v4, v11);
      *((_BYTE *)v6 + 64) = sub_53A120();
      sub_615860(v7);
      v8 = sub_4CD450(6);
      if ( v8 )
      {
        v9 = *(_DWORD *)(v8 + 28);
        if ( v9 )
          sub_4D2F20(v9);
        sub_4D50A0(v6, 1);
      }
      ++v4;
    }
    while ( v4 <= a2 );
  }
  return sub_4D7D70(a1);
}
