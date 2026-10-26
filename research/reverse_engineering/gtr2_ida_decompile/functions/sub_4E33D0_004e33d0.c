int __thiscall sub_4E33D0(_DWORD *this, int a2)
{
  const char *v3; // ecx
  bool v4; // zf
  char *v5; // eax
  char *v6; // edi
  _DWORD *v8; // esi
  int v9; // edx
  int result; // eax
  int v11; // [esp+8h] [ebp-10Ch] BYREF
  int v12; // [esp+Ch] [ebp-108h] BYREF
  int v13; // [esp+10h] [ebp-104h] BYREF
  char ArgList[256]; // [esp+14h] [ebp-100h] BYREF

  sub_615860(a2);
  v3 = (const char *)*this;
  v4 = *this == 0;
  v12 = 0;
  v11 = 0;
  if ( v4 )
    v3 = WindowName;
  strcpy(ArgList, v3);
  v5 = &ArgList[strlen(ArgList)];
  if ( v5 > ArgList )
  {
    while ( *v5 != 46 )
    {
      if ( --v5 <= ArgList )
        goto LABEL_8;
    }
    *v5 = 0;
  }
LABEL_8:
  v6 = (char *)&v13 + 3;
  while ( *++v6 )
    ;
  strcpy(v6, ".DDS");
  v8 = this + 8;
  if ( sub_5E7000(dword_FB1CE0, (char)ArgList, (int)&v12, (int)&v11, (int)(this + 8), (int)&v13) )
  {
    sub_5E7000(dword_FB1CE0, a2, (int)&v12, (int)&v11, (int)(this + 8), (int)&v13);
    *v8 = 8;
  }
  else
  {
    sub_615860(ArgList);
  }
  v9 = v12;
  result = v11;
  *v8 = 8;
  this[5] = v9;
  this[6] = result;
  return result;
}
