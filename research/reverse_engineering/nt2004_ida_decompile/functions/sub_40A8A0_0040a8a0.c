char __thiscall sub_40A8A0(_DWORD *this, char *Source)
{
  char v3; // bl
  void *v4; // eax
  void *v5; // esi
  char v7[28]; // [esp+8h] [ebp-434h] BYREF
  char v8[253]; // [esp+24h] [ebp-418h] BYREF
  __int16 v9; // [esp+121h] [ebp-31Bh]
  char v10; // [esp+123h] [ebp-319h]
  char String[384]; // [esp+124h] [ebp-318h] BYREF
  int v12; // [esp+2A4h] [ebp-198h]
  char v13; // [esp+2A8h] [ebp-194h]
  int v14; // [esp+2B0h] [ebp-18Ch]
  int v15; // [esp+2B4h] [ebp-188h]
  int v16; // [esp+2B8h] [ebp-184h]
  char Buffer[384]; // [esp+2BCh] [ebp-180h] BYREF

  v3 = 0;
  sub_57A080(v7);
  if ( Source && (unsigned __int8)sub_57A2F0(Source, 1) )
  {
    memset(Buffer, 0, sizeof(Buffer));
    v8[0] = byte_629120;
    memset(&v8[1], 0, 0xFCu);
    v9 = 0;
    v12 = 0;
    v16 = 0;
    v14 = 0;
    v15 = 0;
    v13 = 1;
    v10 = 0;
    while ( sub_57A490(Buffer, 383) )
    {
      if ( !sub_577B60(String) && sub_577ED0(String, aIsicam, v8, 0) )
      {
        v4 = operator new(4u);
        if ( v4 )
          v5 = (void *)sub_459A60(v4);
        else
          v5 = 0;
        if ( (unsigned __int8)sub_459B20(v7, v8) )
        {
          sub_40A6C0(this, (int)v5);
        }
        else if ( v5 )
        {
          sub_459AC0(v5);
          sub_5BE8AE(v5);
        }
      }
    }
    v3 = 1;
    sub_57A360(v7);
  }
  sub_57A0A0(v7);
  return v3;
}
