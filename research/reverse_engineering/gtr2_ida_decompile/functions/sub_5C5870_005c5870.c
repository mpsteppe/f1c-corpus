char __thiscall sub_5C5870(_BYTE *this, int a2, _DWORD *a3, int a4, int a5)
{
  char v6; // al
  _BYTE v8[4]; // [esp+8h] [ebp-44h] BYREF
  int v9; // [esp+Ch] [ebp-40h]
  _BYTE v10[4]; // [esp+10h] [ebp-3Ch] BYREF
  const char *v11; // [esp+14h] [ebp-38h]
  _BYTE v12[4]; // [esp+20h] [ebp-2Ch] BYREF
  const char *v13; // [esp+24h] [ebp-28h]
  _BYTE v14[4]; // [esp+30h] [ebp-1Ch] BYREF
  const char *v15; // [esp+34h] [ebp-18h]
  int v16; // [esp+48h] [ebp-4h]

  (*(void (__thiscall **)(int, _BYTE *, int))(*(_DWORD *)a2 + 4))(a2, v8, 8);
  sub_5BE610((int)v14, a2);
  v16 = 0;
  sub_5BE610((int)v12, a2);
  LOBYTE(v16) = 1;
  sub_5BE610((int)v10, a2);
  v6 = this[12];
  LOBYTE(v16) = 2;
  if ( v6 )
  {
    sub_643E40("- File Information");
    if ( this[12] )
    {
      sub_643E40("   + Source application = '%s'", v15);
      if ( this[12] )
        sub_643E40("   + Original filename  = '%s'", v13);
    }
  }
  if ( a3 )
  {
    if ( v9 )
    {
      if ( v9 == 1 )
      {
        sub_5BC090(a3, 1);
        if ( !this[12] )
          goto LABEL_14;
        sub_643E40("   + Multiplication Order  = Rotation * Scale * Translation");
      }
    }
    else
    {
      sub_5BC090(a3, 0);
      if ( !this[12] )
        goto LABEL_14;
      sub_643E40("   + Multiplication Order  = Scale * Rotation * Translation");
    }
  }
  if ( this[12] )
    sub_643E40("   + Exporter version = %i.%i", v8[0], v8[1]);
LABEL_14:
  if ( this[12] )
    sub_643E40("   + Exporter compilation date = '%s'", v11);
  LOBYTE(v16) = 1;
  sub_5A8840();
  LOBYTE(v16) = 0;
  sub_5A8840();
  v16 = -1;
  sub_5A8840();
  return 1;
}
