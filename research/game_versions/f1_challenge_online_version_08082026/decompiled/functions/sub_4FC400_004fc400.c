int __stdcall sub_4FC400(const char *a1, const char *a2)
{
  const char *v2; // eax
  int v3; // eax
  char v4; // cl
  int v5; // ecx
  char *v6; // eax
  int v7; // esi
  int v8; // ebx
  int result; // eax
  char v11[32]; // [esp+10h] [ebp-C0h] BYREF
  char v12[32]; // [esp+30h] [ebp-A0h] BYREF
  char v13[32]; // [esp+50h] [ebp-80h] BYREF
  char v14[32]; // [esp+70h] [ebp-60h] BYREF
  char v15[32]; // [esp+90h] [ebp-40h] BYREF
  char v16[32]; // [esp+B0h] [ebp-20h] BYREF

  strcpy(v11, a2);
  v2 = (const char *)sub_589DB0(v11, 46);
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
      v4 = byte_5D6F48[v3];
      v12[v3++] = v4;
    }
    while ( v4 );
  }
  v5 = strlen(v11);
  if ( v5 > 0 )
  {
    v6 = &v11[v5 - 1];
    if ( v11[v5 - 1] >= 65 && *v6 <= 68 )
      *v6 = 0;
  }
  v7 = 65;
  v8 = 4;
  do
  {
    sub_58815F(v14, "%s%c%s", v11, v7, v12);
    sub_58815F(v15, "%s%s", v11, v12);
    strcpy(v16, a2);
    sub_58815F(v13, "%s%c", a1, v7);
    result = sub_4DC770(v13, 1, v14, v15, v16, 0, 0);
    ++v7;
    --v8;
  }
  while ( v8 );
  return result;
}
