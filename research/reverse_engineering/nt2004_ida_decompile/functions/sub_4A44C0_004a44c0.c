char __thiscall sub_4A44C0(_DWORD *this)
{
  const char *v1; // eax
  char *v3; // eax
  CHAR *v4; // eax
  CHAR *v6; // eax
  _BYTE v7[256]; // [esp+4h] [ebp-100h] BYREF

  v1 = dword_7656D8;
  if ( !dword_7656D8 )
    v1 = &byte_629120;
  if ( !_strcmpi(v1, &byte_629120) )
    return 0;
  sub_4AD000(this[12]);
  v3 = dword_7656D8;
  if ( !dword_7656D8 )
    v3 = &byte_629120;
  if ( !sub_598240(&dword_7656E0, v3, 0) )
  {
    if ( dword_7656E0 )
    {
      this[67] = sub_597290(dword_7656E0);
      v6 = dword_7656D8;
      if ( !dword_7656D8 )
        v6 = &byte_629120;
      sub_578600(v6);
    }
    if ( this[67] )
    {
      sub_5934A0(0, 0, 0.0, 0.0, 0.0, 0.0);
      sub_593430(0);
    }
    (*(void (__thiscall **)(_DWORD *))(*this + 168))(this);
    return 0;
  }
  sub_591C90(0, v7);
  if ( (unsigned __int8)sub_500F90((int)&unk_7D7920, 1, (int)aDDevNascar2004_29, 8000) )
  {
    LOBYTE(v4) = (_BYTE)dword_7656D8;
    if ( !dword_7656D8 )
      v4 = &byte_629120;
    sub_500FE0((int)&unk_7D7920, aCubeErrorLoadi_1, (char)v4);
  }
  return 1;
}
