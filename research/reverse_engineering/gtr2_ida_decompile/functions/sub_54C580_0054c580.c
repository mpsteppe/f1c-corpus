int __thiscall sub_54C580(_DWORD *this)
{
  int v2; // eax
  char v3; // cl
  int v4; // kr00_4
  char *i; // eax
  const CHAR *v6; // eax
  int v7; // esi
  char *v8; // eax
  char *v9; // eax
  char *v10; // eax
  char v12; // [esp+28h] [ebp-390h]
  _DWORD v13[2]; // [esp+30h] [ebp-388h]
  char v14[253]; // [esp+38h] [ebp-380h] BYREF
  __int16 v15; // [esp+135h] [ebp-283h]
  _BYTE v16[4]; // [esp+140h] [ebp-278h] BYREF
  _BYTE v17[4]; // [esp+144h] [ebp-274h] BYREF
  _BYTE v18[88]; // [esp+148h] [ebp-270h] BYREF
  char v19[261]; // [esp+1A0h] [ebp-218h] BYREF
  __int16 v20; // [esp+2A5h] [ebp-113h]
  char FileName[260]; // [esp+2A8h] [ebp-110h] BYREF
  int v22; // [esp+3ACh] [ebp-Ch]
  int v23; // [esp+3B4h] [ebp-4h]

  if ( dword_B640C0 != 5
    && (unsigned __int8)sub_5612D0((int)byte_FAE910, 1, "\\Dev\\Src\\Copperhead\\App\\Source\\StateMan.cpp", 313) )
  {
    sub_561210((int)byte_FAE910, "StateMan::SaveState()", v12);
  }
  memset(v14, 0, sizeof(v14));
  v15 = 0;
  memset(&v19[8], 0, 253);
  v20 = 0;
  sub_54BE60(this);
  sub_54B870();
  sub_613B30(v16);
  v22 = 0;
  v2 = 0;
  do
  {
    v3 = *((_BYTE *)v13 + v2);
    v19[v2++] = v3;
  }
  while ( v3 );
  v4 = strlen(v19);
  if ( v4 > 0 )
  {
    for ( i = &v18[v4 + 87]; i > v19; --i )
    {
      if ( *i == 92 )
        break;
    }
    *i = 0;
  }
  sub_41B2B0();
  v13[0] = (char *)&this[994654 * this[994657] + 33] + 1;
  sub_436750();
  v6 = (const CHAR *)dword_B66008;
  if ( !dword_B66008 )
    v6 = WindowName;
  v7 = (int)&this[994654 * this[994657] + 1] + 1;
  sub_630FE0(v7, v6, 127);
  *(_BYTE *)(v7 + 127) = 0;
  sub_6146B0(v14, 0, 0, 1, 1, v17, 15);
  sub_613C90(&this[994654 * this[994657]], 3978616);
  sub_613C30(v18);
  if ( byte_B6F118 )
    sub_436510();
  v8 = &v14[strlen(v14)];
  if ( v8 > v14 )
  {
    while ( *v8 != 46 )
    {
      if ( --v8 <= v14 )
        goto LABEL_20;
    }
    *v8 = 0;
  }
LABEL_20:
  sub_632041(v14, 255, "%s%s", v14, "Gar.sve");
  v9 = dword_B66000;
  if ( !dword_B66000 )
    v9 = (char *)WindowName;
  sub_617D00(v9, v14);
  if ( *(_DWORD *)dword_B72314 == 4 )
  {
    sub_50FC90();
    sub_501B50();
    sub_54B870();
    v10 = &v14[strlen(v14)];
    if ( v10 > v14 )
    {
      while ( *v10 != 46 )
      {
        if ( --v10 <= v14 )
          goto LABEL_28;
      }
      *v10 = 0;
    }
LABEL_28:
    sub_632041(v14, 255, "%s%s", v14, "Chp.sve");
    sub_617D00(FileName, v14);
  }
  v23 = -1;
  return sub_614140(v18);
}
