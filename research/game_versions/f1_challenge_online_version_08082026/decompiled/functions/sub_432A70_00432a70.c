int __thiscall sub_432A70(_DWORD *this, _DWORD *a2)
{
  int result; // eax
  int v4; // eax
  CHAR v5[256]; // [esp+Ch] [ebp-418h] BYREF
  _BYTE v6[384]; // [esp+10Ch] [ebp-318h] BYREF
  int v7; // [esp+28Ch] [ebp-198h]
  char v8; // [esp+290h] [ebp-194h]
  int v9; // [esp+298h] [ebp-18Ch]
  int v10; // [esp+29Ch] [ebp-188h]
  int v11; // [esp+2A0h] [ebp-184h]
  _BYTE v12[384]; // [esp+2A4h] [ebp-180h] BYREF

  result = 1;
  if ( a2 && *a2 )
  {
    memset(v12, 0, sizeof(v12));
    v7 = 0;
    v11 = 0;
    v9 = 0;
    v10 = 0;
    v8 = 1;
    if ( sub_566CC0(v12, 384) )
    {
      while ( 1 )
      {
        v4 = sub_5651B0(v6);
        if ( v4 )
        {
          if ( v4 == 1 )
            return 0;
          goto LABEL_13;
        }
        if ( sub_5654A0(off_5C3F8C[0], v5) || sub_5654A0(off_5C3F90[0], v5) )
          break;
        if ( sub_565520(off_5C3F94[0], v5, 0) )
        {
          this[4] = sub_587F59(v5);
        }
        else if ( sub_5654A0(off_5C3F98[0], v5) )
        {
          break;
        }
LABEL_13:
        if ( !sub_566CC0(v12, 384) )
          return 0;
      }
      sub_566650(v5);
      goto LABEL_13;
    }
    return 0;
  }
  return result;
}
