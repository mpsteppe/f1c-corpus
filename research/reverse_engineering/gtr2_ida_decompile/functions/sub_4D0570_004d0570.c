int __thiscall sub_4D0570(_BYTE *this)
{
  int v2; // ebx
  int v3; // edi
  int v4; // eax
  int v6; // [esp+4h] [ebp-8h] BYREF
  int v7; // [esp+8h] [ebp-4h] BYREF

  if ( this[280] )
  {
    sub_4DE540(&v7, &v6);
    v2 = (*(int (__thiscall **)(_BYTE *))(*(_DWORD *)this + 4))(this);
    v3 = (*(int (__thiscall **)(_BYTE *))(*(_DWORD *)this + 8))(this);
    v4 = (*(int (__thiscall **)(_BYTE *))(*(_DWORD *)this + 16))(this);
    if ( v6 >= v3 && v6 <= v4 && v7 > v2 )
      this[282] = 1;
    sub_4D0510(this);
    if ( !(*(int (__thiscall **)(_BYTE *))(*(_DWORD *)this + 144))(this) )
      sub_4CD570();
  }
  return 0;
}
