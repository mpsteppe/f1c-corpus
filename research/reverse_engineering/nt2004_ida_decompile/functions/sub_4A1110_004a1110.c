int __thiscall sub_4A1110(_DWORD *this, LPVOID **a2)
{
  const char *v3; // eax
  const char *v4; // ecx
  int v5; // esi
  unsigned int v6; // edi
  LPVOID *v7; // esi
  _BYTE *v8; // eax
  LPVOID *v9; // edi
  char v11[8]; // [esp+8h] [ebp-228h] BYREF
  char v12[28]; // [esp+10h] [ebp-220h] BYREF
  char v13[4]; // [esp+2Ch] [ebp-204h] BYREF
  char Buffer[509]; // [esp+30h] [ebp-200h] BYREF
  __int16 v15; // [esp+22Dh] [ebp-3h]
  char v16; // [esp+22Fh] [ebp-1h]

  Buffer[0] = byte_629120;
  memset(&Buffer[1], 0, 0x1FCu);
  v15 = 0;
  v16 = 0;
  sub_57A080(v12);
  v3 = (const char *)this[40];
  if ( !v3 )
    v3 = &byte_629120;
  v4 = (const char *)dword_62A098;
  if ( !dword_62A098 )
    v4 = &byte_629120;
  sprintf(Buffer, "%s%s", v4, v3);
  if ( (unsigned __int8)sub_57A2F0(Buffer, 1) )
  {
    sub_57A5B0(2);
    v5 = sub_57A620(v12);
    sub_57A5B0(0);
    v6 = v5 - sub_57A620(v12);
    v7 = (LPVOID *)operator new(8u);
    if ( v7 )
    {
      v8 = operator new(v6);
      *v7 = v8;
      *v8 = 0;
      v7[1] = (LPVOID)v6;
    }
    else
    {
      v7 = 0;
    }
    sub_57A490(v13, 1);
    while ( sub_57A490(v11, 2) )
      sub_578560(v11);
    v9 = *a2;
    if ( *a2 )
    {
      if ( *v9 )
        sub_5BE8AE(*v9);
      sub_5BE8AE(v9);
      *a2 = 0;
    }
    *a2 = v7;
  }
  return sub_57A0A0(v12);
}
