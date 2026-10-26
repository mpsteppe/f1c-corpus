int __thiscall sub_4BC7A0(__int16 *this, const char *a2, int ArgList, int a4, char a5, char a6)
{
  _DWORD *v7; // edi
  int i; // esi
  _BYTE v10[256]; // [esp+14h] [ebp-100h] BYREF

  if ( dword_767C7C < *this )
    return 0;
  v7 = this + 50;
  if ( *((_DWORD *)this + 25) )
    return 0;
  if ( !sub_597350(this + 50, a2, ArgList, 16) )
  {
    if ( a5 || dword_767C7C >= 2 )
    {
      for ( i = sub_59EFF0(0); i; i = *(_DWORD *)(i + 16) )
        sub_59F020(i, 0);
    }
    if ( a4 )
      sub_59E690(*v7, 0);
    else
      sub_5974A0(*v7);
    strcpy((char *)this + 4, a2);
    return 0;
  }
  if ( a6 )
  {
    sub_591C90(0, v10);
    if ( (unsigned __int8)sub_500F90((int)&unk_7D7920, 1, (int)aDDevNascar2004_12, 174) )
      sub_500FE0((int)&unk_7D7920, aCubeErrorLoadi, ArgList);
  }
  return -1;
}
