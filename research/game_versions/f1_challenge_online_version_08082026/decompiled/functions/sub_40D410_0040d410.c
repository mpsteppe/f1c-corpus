void __thiscall sub_40D410(int this)
{
  int v2; // eax
  _DWORD *v3; // ecx

  v2 = sub_40CD60((_DWORD *)this);
  if ( v2 >= 7 && v2 <= 10 )
    sub_40CDE0(v3, *(_DWORD *)(this + 16), 0);
  sub_408450((int)&flt_5EA4E8, 0.5);
  *(_BYTE *)(this + 36) = 0;
}
