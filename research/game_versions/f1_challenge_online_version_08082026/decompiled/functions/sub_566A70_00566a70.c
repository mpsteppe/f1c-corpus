bool __thiscall sub_566A70(_DWORD *this, const CHAR *a2, int a3, int a4, char a5)
{
  bool result; // al
  int v7; // eax
  bool v8; // bl
  char v9[1024]; // [esp+8h] [ebp-400h] BYREF

  if ( !a5 || (result = sub_5668F0(a2)) )
  {
    this[3] = a4;
    this[4] = a3;
    sub_568620(1024);
    if ( this[3] )
      v7 = sub_587DB0(v9, &unk_5E517C);
    else
      v7 = sub_587DB0(v9, &unk_5E5180);
    *this = v7;
    v8 = v7 != 0;
    *((_BYTE *)this + 24) = 0;
    if ( v7 )
      sub_566650((int)(this + 1), v9);
    return v8;
  }
  return result;
}
