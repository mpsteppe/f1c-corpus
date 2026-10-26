// f1c  0x00493c80  size=416
int __thiscall sub_493C80(_DWORD *this, int a2, const char *a3)
{
  int v3; // esi
  int v5; // ecx
  __int16 v6; // bp
  int v7; // eax
  int v8; // eax
  const char *v10; // [esp-Ch] [ebp-128h]
  _DWORD v11[4]; // [esp+Ch] [ebp-110h]
  CHAR Text[253]; // [esp+1Ch] [ebp-100h] BYREF
  __int16 v13; // [esp+119h] [ebp-3h]
  char v14; // [esp+11Bh] [ebp-1h]

  v3 = a2;
  if ( a2 <= 1 )
    return 0;
  Text[0] = byte_5EA438[0];
  memset(&Text[1], 0, 0xFCu);
  v5 = this[99];
  v13 = 0;
  v11[0] = aUndefinedError;
  v11[1] = aWarning_0;
  v11[2] = aError;
  v11[3] = aCriticalError;
  v10 = (const char *)v11[a2];
  v14 = 0;
  sub_58815F(Text, "OSC %s on line %d : ", v10, v5);
  if ( a3 )
  {
    v6 = *(_WORD *)asc_5C64D4;
    *(_WORD *)&Text[strlen(Text)] = *(_WORD *)asc_5C64D4;
    strcat(Text, a3);
    v3 = a2;
    *(_WORD *)&Text[strlen(Text)] = v6;
    *(_WORD *)&Text[strlen(Text)] = word_5C30B4;
  }
  if ( !this[2] )
  {
    v7 = sub_587DB0(this + 67, aWt);
    this[2] = v7;
    if ( v7 )
      sub_587F64(v7, 0, 0);
  }
  v8 = this[2];
  if ( v8 )
  {
    sub_5887B1(v8, aS_4);
    sub_5887B1(this[2], &word_5C30B4);
  }
  if ( v3 != 3 && v3 != 2 )
    return 0;
  if ( this[105] )
  {
    sub_4986D0(Text);
    return 0;
  }
  MessageBoxA(0, Text, Caption, 0);
  sub_589CA4(1u);
  return sub_493E20(a2);
}
