// f1c  0x004c8b70  size=296
void sub_4C8B70()
{
  char v0; // al
  int v1; // ecx
  char v2; // bl
  int v3; // edi
  int v4; // esi
  char v5; // [esp+7h] [ebp-19h]
  _BYTE v6[4]; // [esp+8h] [ebp-18h] BYREF
  float v7; // [esp+Ch] [ebp-14h]
  _BYTE v8[12]; // [esp+14h] [ebp-Ch] BYREF

  if ( dword_8AB6E4 != 2 || sub_4B9E30(&unk_8AB6EC) == 5 )
  {
    v5 = 0;
    v0 = 0;
  }
  else
  {
    v0 = 1;
    v5 = 1;
  }
  v1 = dword_8AC4C4;
  v2 = 1;
  if ( byte_7CE254 && (v2 = byte_7CF2B4, dword_8AC4C4) )
  {
    if ( !v0 )
    {
      sub_4D1140(dword_7C54E8, v8, v6);
      v7 = 3.1415927 - v7;
      (*(void (__thiscall **)(int, _BYTE *, _BYTE *))(*(_DWORD *)dword_8AC4C4 + 28))(dword_8AC4C4, v8, v6);
      v1 = dword_8AC4C4;
LABEL_10:
      if ( byte_7C56AC || !v2 )
        goto LABEL_18;
    }
  }
  else if ( !v0 )
  {
    goto LABEL_10;
  }
  v3 = dword_5C329C;
  v4 = 0;
  if ( dword_5C329C > 0 )
  {
    do
      sub_4F8440(dword_7C54F0[v4++] + 20);
    while ( v4 < v3 );
    v1 = dword_8AC4C4;
  }
  if ( v1 )
    (*(void (__thiscall **)(int))(*(_DWORD *)v1 + 8))(v1);
  sub_54A200(32, 1);
  sub_4C7DE0((int)&flt_8AC4B0);
LABEL_18:
  sub_4186F0((int)flt_5EA618);
  if ( v5 || !byte_7CE254 )
    sub_4C8A10();
  else
    sub_4C8920();
}
