int __thiscall sub_4357F0(_DWORD *this, _DWORD *a2)
{
  int result; // eax
  int v4; // eax
  char String[256]; // [esp+Ch] [ebp-418h] BYREF
  char v6[384]; // [esp+10Ch] [ebp-318h] BYREF
  int v7; // [esp+28Ch] [ebp-198h]
  char v8; // [esp+290h] [ebp-194h]
  int v9; // [esp+298h] [ebp-18Ch]
  int v10; // [esp+29Ch] [ebp-188h]
  int v11; // [esp+2A0h] [ebp-184h]
  char Buffer[384]; // [esp+2A4h] [ebp-180h] BYREF

  result = 1;
  if ( a2 && *a2 )
  {
    memset(Buffer, 0, sizeof(Buffer));
    v7 = 0;
    v11 = 0;
    v9 = 0;
    v10 = 0;
    v8 = 1;
    if ( sub_57A490(Buffer, 384) )
    {
      while ( 1 )
      {
        v4 = sub_577B60(v6);
        if ( v4 )
        {
          if ( v4 == 1 )
            return 0;
          goto LABEL_13;
        }
        if ( sub_577E50(v6, off_5FE064, (int)String) || sub_577E50(v6, off_5FE068, (int)String) )
          break;
        if ( sub_577ED0(v6, off_5FE06C, String, 0) )
        {
          this[4] = atoi(String);
        }
        else if ( sub_577E50(v6, off_5FE070, (int)String) )
        {
          break;
        }
LABEL_13:
        if ( !sub_57A490(Buffer, 384) )
          return 0;
      }
      sub_578600(String);
      goto LABEL_13;
    }
    return 0;
  }
  return result;
}
