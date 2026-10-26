char __thiscall sub_5C5720(_BYTE *this, int a2, int a3, float a4, int a5)
{
  char v7; // al
  _BYTE v8[4]; // [esp+14h] [ebp-2Ch] BYREF
  const char *v9; // [esp+18h] [ebp-28h]
  _BYTE v10[4]; // [esp+24h] [ebp-1Ch] BYREF
  const char *v11; // [esp+28h] [ebp-18h]
  int v12; // [esp+3Ch] [ebp-4h]

  if ( a4 == 0.0 )
  {
    if ( this[12] )
      sub_643E40("Passed motion seems to be not valid!");
    return 0;
  }
  else
  {
    (*(void (__thiscall **)(int, float *, int))(*(_DWORD *)a2 + 4))(a2, &a4, 4);
    sub_5BE610((int)v10, a2);
    v12 = 0;
    sub_5BE610((int)v8, a2);
    v7 = this[12];
    LOBYTE(v12) = 1;
    if ( v7 )
      sub_643E40("- Motion Event");
    if ( this[12] )
    {
      sub_643E40("   + Time = %f", a4);
      if ( this[12] )
      {
        sub_643E40("   + Type = '%s'", v11);
        if ( this[12] )
          sub_643E40("   + Parameters = '%s'", v9);
      }
    }
    LOBYTE(v12) = 0;
    sub_5A8840();
    v12 = -1;
    sub_5A8840();
    return 1;
  }
}
