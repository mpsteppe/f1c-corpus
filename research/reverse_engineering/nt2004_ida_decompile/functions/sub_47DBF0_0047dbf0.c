int __thiscall sub_47DBF0(void *this)
{
  int result; // eax
  int v2; // ebx
  int i; // esi
  CHAR *v4; // eax

  sub_49FEC0(this);
  sub_49F730(aGeneral_1, 0, 0, 0, 0);
  result = sub_40C4C0(dword_75E8E8);
  v2 = result;
  for ( i = 0; i < v2; ++i )
  {
    v4 = sub_4355B0(dword_75E8E8, i);
    result = sub_49F730(v4, 0, 0, 0, 0);
  }
  return result;
}
