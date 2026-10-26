// f1c  0x0047c770  size=74
int __thiscall sub_47C770(_DWORD *this)
{
  int v1; // eax
  _BYTE v3[32]; // [esp+4h] [ebp-20h] BYREF

  v1 = dword_7CF230;
  if ( dword_7CF230 <= 16 )
    this[196] = 0;
  else
    this[196] = 2;
  sub_58815F(v3, "%d", v1);
  return sub_48B810(v3);
}
