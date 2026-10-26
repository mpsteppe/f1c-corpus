char __thiscall sub_5C5600(_BYTE *this, int a2, int a3, int a4, int a5)
{
  char v7[128]; // [esp+14h] [ebp-188h] BYREF
  char v8[256]; // [esp+94h] [ebp-108h] BYREF
  float v9; // [esp+194h] [ebp-8h]
  int v10; // [esp+198h] [ebp-4h]

  v10 = dword_912B08;
  if ( a4 )
  {
    (*(void (__thiscall **)(int, char *, int))(*(_DWORD *)a2 + 4))(a2, v7, 388);
    if ( this[12] )
    {
      sub_643E40("- Motion Event");
      if ( this[12] )
      {
        sub_643E40("   + Time = %f", v9);
        if ( this[12] )
        {
          sub_643E40("   + Type = '%s'", v7);
          if ( this[12] )
            sub_643E40("   + Parameters = '%s'", v8);
        }
      }
    }
    return 1;
  }
  else
  {
    if ( this[12] )
      sub_643E40("Passed motion seems to be not valid!");
    return 0;
  }
}
