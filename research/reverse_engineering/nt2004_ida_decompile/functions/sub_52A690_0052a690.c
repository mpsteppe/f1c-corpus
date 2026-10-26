int __stdcall sub_52A690(const char *a1, const char *a2)
{
  char *v2; // eax
  int v3; // eax
  char v4; // cl
  int v5; // ecx
  char *v6; // eax
  int v7; // esi
  int v8; // ebx
  int result; // eax
  char Str[32]; // [esp+10h] [ebp-C0h] BYREF
  char v12[32]; // [esp+30h] [ebp-A0h] BYREF
  char v13[32]; // [esp+50h] [ebp-80h] BYREF
  char Buffer[32]; // [esp+70h] [ebp-60h] BYREF
  char v15[32]; // [esp+90h] [ebp-40h] BYREF
  char v16[32]; // [esp+B0h] [ebp-20h] BYREF

  strcpy(Str, a2);
  v2 = strchr(Str, 46);
  if ( v2 )
  {
    strcpy(v12, v2);
    *v2 = 0;
  }
  else
  {
    v3 = 0;
    do
    {
      v4 = aTga[v3];
      v12[v3++] = v4;
    }
    while ( v4 );
  }
  v5 = strlen(Str);
  if ( v5 > 0 )
  {
    v6 = &Str[v5 - 1];
    if ( Str[v5 - 1] >= 65 && *v6 <= 68 )
      *v6 = 0;
  }
  v7 = 65;
  v8 = 4;
  do
  {
    sprintf(Buffer, "%s%c%s", Str, v7, v12);
    sprintf(v15, "%s%s", Str, v12);
    strcpy(v16, a2);
    sprintf(v13, "%s%c", a1, v7);
    result = sub_505E80(v13, 1, Buffer, v15, v16, 0);
    ++v7;
    --v8;
  }
  while ( v8 );
  return result;
}
