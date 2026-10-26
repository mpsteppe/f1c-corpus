int __thiscall sub_4C3D80(void *this)
{
  const char *v2; // ecx
  const char *v3; // eax
  void *v4; // ebx
  char *v5; // esi
  int v6; // edi
  int v7; // esi
  int *v8; // eax
  int v9; // ebx
  _DWORD *v10; // edi
  const char *i; // eax
  const char *v12; // edx
  const char *v13; // ecx
  CHAR SrcStr[512]; // [esp+8h] [ebp-200h] BYREF

  sub_565EB0(&unk_8AD3B0);
  v2 = (const char *)dword_5EC428;
  if ( !dword_5EC428 )
    v2 = byte_5EA438;
  v3 = (const char *)dword_5EC3D8;
  if ( !dword_5EC3D8 )
    v3 = byte_5EA438;
  sub_58815F(SrcStr, "%s%s", v3, v2);
  sub_565F80(aVeh, 1, (int)SrcStr, 1);
  if ( dword_8AC394 )
  {
    v4 = (void *)(dword_8AC394 - 4);
    v5 = (char *)(dword_8AC394 + 1060 * *(_DWORD *)(dword_8AC394 - 4));
    if ( *(_DWORD *)(dword_8AC394 - 4) - 1 >= 0 )
    {
      v6 = *(_DWORD *)(dword_8AC394 - 4);
      do
      {
        v5 -= 1060;
        sub_4C3130(v5);
        --v6;
      }
      while ( v6 );
    }
    sub_587BCF(v4);
  }
  v7 = sub_565F70(&unk_8AD3B0);
  v8 = (int *)sub_587C03(1060 * v7 + 4);
  if ( v8 )
  {
    v9 = (int)(v8 + 1);
    *v8 = v7;
    v10 = v8 + 1;
    if ( v7 - 1 >= 0 )
    {
      do
      {
        sub_4C3050(v10);
        v10 += 265;
        --v7;
      }
      while ( v7 );
    }
    dword_8AC394 = v9;
  }
  else
  {
    dword_8AC394 = 0;
  }
  sub_565F50(&unk_8AD3B0);
  for ( i = (const char *)sub_5662D0(&unk_8AD3B0); i; i = (const char *)sub_5662D0(&unk_8AD3B0) )
  {
    v12 = (const char *)dword_5EC428;
    if ( !dword_5EC428 )
      v12 = byte_5EA438;
    v13 = (const char *)dword_5EC3D8;
    if ( !dword_5EC3D8 )
      v13 = byte_5EA438;
    sub_58815F(SrcStr, "%s%s%s", v13, v12, i);
    sub_589901(SrcStr);
    sub_566650(SrcStr);
    if ( sub_4C3200((char *)(dword_8AC394 + 1060 * dword_8AC390)) )
    {
      if ( (unsigned __int8)sub_4D7A50(1, aDDevF119992002_8, 516) )
        sub_4D7AA0(&unk_8AD25C, aFailedReadingD);
    }
    else
    {
      ++dword_8AC390;
    }
    if ( !(unsigned __int8)sub_565F20(&unk_8AD3B0) )
      break;
  }
  sub_565EB0(&unk_8AD3B0);
  sub_4C4240(this);
  return dword_8AC390;
}
