// f1_2002_full  0x0042e540  size=362
int __thiscall sub_42E540(_BYTE *this)
{
  int result; // eax
  const char *v3; // ecx
  const char *v4; // eax
  _DWORD *v5; // edi
  const char *v6; // ecx
  const char *v7; // eax
  _DWORD *v8; // esi
  const char *v9; // ecx
  const char *v10; // eax
  char Buffer[512]; // [esp+10h] [ebp-400h] BYREF
  char v12[512]; // [esp+210h] [ebp-200h] BYREF

  if ( this[176] )
    return 0;
  v3 = (const char *)dword_5CB470;
  if ( !dword_5CB470 )
    v3 = &byte_5C97DC;
  v4 = dword_5CB3E0;
  if ( !dword_5CB3E0 )
    v4 = &byte_5C97DC;
  sprintf(Buffer, "%s%s%s", v4, v3, aDrivingschoolM);
  v5 = this + 180;
  sub_5254E0(this + 180, Buffer);
  v6 = (const char *)dword_5CB470;
  if ( !dword_5CB470 )
    v6 = &byte_5C97DC;
  v7 = dword_5CB3E0;
  if ( !dword_5CB3E0 )
    v7 = &byte_5C97DC;
  sprintf(Buffer, "%s%s%s", v7, v6, aDrivingschoolm);
  v8 = this + 184;
  sub_5254E0(this + 184, Buffer);
  if ( *v5 )
  {
    if ( *v8 )
    {
      v9 = (const char *)dword_5CB470;
      if ( !dword_5CB470 )
        v9 = &byte_5C97DC;
      v10 = dword_5CB3E0;
      if ( !dword_5CB3E0 )
        v10 = &byte_5C97DC;
      sprintf(v12, "%s%s", v10, v9);
      sub_525120(v12);
      this[176] = 1;
      return 0;
    }
    if ( *v5 )
    {
      sub_525760(*v5);
      *v5 = 0;
    }
  }
  if ( *v8 )
  {
    sub_525760(*v8);
    *v8 = 0;
  }
  result = 1;
  this[176] = 0;
  return result;
}
