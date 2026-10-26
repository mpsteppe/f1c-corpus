int __thiscall sub_4C52C0(void *this)
{
  const char *v1; // ecx
  const char *v2; // eax
  int v3; // ebp
  const char *i; // eax
  int v5; // esi
  char v8[256]; // [esp+Ch] [ebp-200h] BYREF
  char v9[256]; // [esp+10Ch] [ebp-100h] BYREF

  v1 = (const char *)dword_5EC420;
  byte_8AC398 = 0;
  byte_8AC3E8 = 0;
  byte_8AC438 = 0;
  dword_8AC488 = 0;
  dword_8AC48C = 0;
  dword_8AC490 = 0;
  if ( !dword_5EC420 )
    v1 = byte_5EA438;
  v2 = (const char *)dword_5EC3D8;
  if ( !dword_5EC3D8 )
    v2 = byte_5EA438;
  sub_58815F(v8, "%s%s", v2, v1);
  sub_565F80(aScn, 1, (int)v8, 1);
  if ( dword_8AC490 )
    sub_587BCF((LPVOID)dword_8AC490);
  v3 = sub_565F70(&unk_8AD3B0);
  dword_8AC490 = sub_587C03(396 * v3);
  memset((void *)dword_8AC490, 0, 4 * ((unsigned int)(396 * v3) >> 2));
  if ( !v3 )
  {
    if ( (unsigned __int8)sub_4D7A50(1, aDDevF119992002_8, 1282) )
      sub_4D7AA0(&unk_8AD25C, aCouldNotFindAn);
    if ( (unsigned __int8)sub_4D7A50(1, aDDevF119992002_8, 1283) )
      sub_4D7AA0(&unk_8AD25C, a1IncorrectSeas);
    if ( (unsigned __int8)sub_4D7A50(1, aDDevF119992002_8, 1284) )
      sub_4D7AA0(&unk_8AD25C, a2WeDoNotHaveRe);
    if ( (unsigned __int8)sub_4D7A50(1, aDDevF119992002_8, 1285) )
      sub_4D7AA0(&unk_8AD25C, a3ThereAreNoSce);
  }
  sub_565F50(&unk_8AD3B0);
  for ( i = (const char *)sub_5662D0(&unk_8AD3B0); i; i = (const char *)sub_5662D0(&unk_8AD3B0) )
  {
    sub_58815F(v9, "%s%s", v8, i);
    v5 = sub_587DB0(v9, aR);
    if ( v5 )
    {
      sub_4C51A0(v5, 0, v9, dword_8AC490);
      sub_587D02(v5);
    }
    if ( !(unsigned __int8)sub_565F20(&unk_8AD3B0) )
      break;
  }
  sub_565EB0(&unk_8AD3B0);
  sub_4C5940(this);
  return dword_8AC488;
}
