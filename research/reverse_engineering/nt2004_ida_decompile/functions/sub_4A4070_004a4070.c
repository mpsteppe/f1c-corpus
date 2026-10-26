int __thiscall sub_4A4070(_DWORD *this)
{
  CHAR *v2; // eax
  CHAR *v3; // eax
  char *v4; // edx
  CHAR v5; // cl
  const char *v6; // edi
  char v8[128]; // [esp+10h] [ebp-80h] BYREF

  v2 = (CHAR *)this[40];
  if ( !v2 )
    v2 = &byte_629120;
  sub_578600(v2);
  v3 = (CHAR *)dword_62A080;
  if ( !dword_62A080 )
    v3 = &byte_629120;
  v4 = (char *)(v8 - v3);
  do
  {
    v5 = *v3;
    v3[(_DWORD)v4] = *v3;
    ++v3;
  }
  while ( v5 );
  v6 = (const char *)this[40];
  if ( !v6 )
    v6 = &byte_629120;
  strcat(v8, v6);
  this[68] = sub_5A9070(this + 67, v8, 0, 0);
  return 0;
}
