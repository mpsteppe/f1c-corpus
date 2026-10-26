int sub_494F50()
{
  const CHAR *v1; // eax
  int v2; // eax
  const char *v3; // esi
  _BYTE v4[36]; // [esp+Ch] [ebp-6Ch] BYREF
  int v5; // [esp+30h] [ebp-48h]
  _BYTE v6[56]; // [esp+34h] [ebp-44h] BYREF
  int v7; // [esp+74h] [ebp-4h]

  if ( !(unsigned __int8)sub_54B750(&unk_BE27B0) )
    return sub_4CE020(WindowName);
  sub_617030(v6);
  v7 = 1;
  v1 = *(const CHAR **)dword_91CA70;
  if ( !*(_DWORD *)dword_91CA70 )
    v1 = WindowName;
  sub_615860(v1);
  v2 = sub_54B350(&unk_BE27B0);
  sub_615A50(v2);
  sub_616F90(WindowName, 0);
  v3 = (const char *)sub_616930("Game Name");
  sub_630FE0(v4, v3, 39);
  HIBYTE(v5) = 0;
  if ( strlen(v3) > 0x27 )
    v5 = 3026478;
  sub_4CE020(v4);
  v7 = -1;
  return sub_617060(v6);
}
