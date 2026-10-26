char __thiscall sub_4CF2C0(int *this, int a2)
{
  CHAR *v3; // eax
  const char *v4; // eax
  char v6; // [esp+0h] [ebp-10Ch]
  char v7[256]; // [esp+Ch] [ebp-100h] BYREF

  v7[0] = 0;
  sub_4BC200(v7, this + 5);
  v3 = (CHAR *)this[1];
  if ( !v3 )
    v3 = &byte_629120;
  sub_57A400(a2, aSS, (char)v3);
  v4 = (const char *)this[3];
  if ( !v4 )
    v4 = &byte_629120;
  if ( strlen(v4) )
    sub_57A400(a2, aS_8, this[3]);
  sub_57A400(a2, asc_5FB9D8, v6);
  return 0;
}
