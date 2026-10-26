int __thiscall sub_4A5A60(_DWORD *this, char *String2)
{
  int v3; // eax
  char *v4; // edi
  int result; // eax
  CHAR *v6; // eax
  int v7; // edx
  int v8; // [esp+8h] [ebp-4h] BYREF

  v3 = (*(int (__thiscall **)(_DWORD *))(*this + 4))(this);
  v4 = String2;
  if ( !v3 || (result = (*(int (__thiscall **)(_DWORD *))(*this + 8))(this)) == 0 )
  {
    v6 = (CHAR *)this[16];
    String2 = 0;
    v8 = 0;
    if ( !v6 )
      v6 = &byte_629120;
    result = sub_4AE370(v4, (int)v6, (int)&String2, (int)&v8);
    v7 = v8;
    this[1] = String2;
    this[2] = v7;
  }
  if ( v4 )
    return sub_578600(v4);
  return result;
}
