int __thiscall sub_4AF250(_DWORD **this)
{
  int v1; // eax
  const char *v2; // eax
  const char *v3; // eax
  FILE *v4; // eax
  int v6; // [esp+4h] [ebp-304h] BYREF
  char v7[256]; // [esp+8h] [ebp-300h] BYREF
  char Buffer[512]; // [esp+108h] [ebp-200h] BYREF

  v1 = (*(int (__thiscall **)(_DWORD *, int))(*this[12] + 28))(this[12], 41);
  if ( !v1 )
    return 0;
  v2 = (const char *)sub_4CE170(v1);
  if ( !v2 )
    return 0;
  if ( strlen(v2) )
  {
    sub_617930(256);
    v3 = Path;
    if ( !Path )
      v3 = WindowName;
    sprintf(Buffer, "%s%s%s", v3, v7, (const char *)&dword_6F1D80);
    v4 = fopen(Buffer, "rb");
    if ( v4 )
    {
      fclose(v4);
      sub_5210E0(Buffer);
      dword_BE1204 = 2;
      byte_91E234 = 1;
      v6 = 6;
      sub_4762A0(dword_B72300, &v6);
      dword_75B17C = 1;
    }
  }
  return 0;
}
