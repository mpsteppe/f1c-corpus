char __thiscall sub_4CF1B0(int this, int a2)
{
  CHAR *v3; // eax
  const char *v4; // eax
  char v6; // [esp+0h] [ebp-10Ch]
  char v7[256]; // [esp+Ch] [ebp-100h] BYREF

  v7[0] = 0;
  sub_4BC150(v7, (unsigned __int16 *)(this + 20));
  v3 = *(CHAR **)(this + 4);
  if ( !v3 )
    v3 = &byte_629120;
  sub_57A400(a2, aSS, (char)v3);
  v4 = *(const char **)(this + 12);
  if ( !v4 )
    v4 = &byte_629120;
  if ( strlen(v4) )
    sub_57A400(a2, aS_8, *(_DWORD *)(this + 12));
  sub_57A400(a2, asc_5FB9D8, v6);
  return 0;
}
