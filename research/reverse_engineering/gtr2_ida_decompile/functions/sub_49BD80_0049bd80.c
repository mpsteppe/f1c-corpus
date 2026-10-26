int __thiscall sub_49BD80(_DWORD **this)
{
  int v1; // eax
  const char *v2; // eax
  const char *v3; // eax
  FILE *v4; // eax
  char v6[128]; // [esp+Ch] [ebp-280h] BYREF
  char Buffer[512]; // [esp+8Ch] [ebp-200h] BYREF

  v1 = (*(int (__thiscall **)(_DWORD *, int))(*this[12] + 28))(this[12], 41);
  if ( !v1 )
    return -1;
  v2 = (const char *)sub_4CE170(v1);
  if ( !v2 || !strlen(v2) )
    return -1;
  sub_617930(128);
  v3 = Path;
  if ( !Path )
    v3 = WindowName;
  sprintf(Buffer, "%s%s%s", v3, v6, (const char *)&dword_6F1D80);
  v4 = fopen(Buffer, "rb");
  if ( !v4 )
    return -1;
  fclose(v4);
  sub_617680(Buffer);
  sub_48F4A0();
  return 0;
}
