char __thiscall sub_50B240(_DWORD *this, char *String2)
{
  int v2; // ebp
  bool v3; // zf
  char *v4; // ebp
  int v5; // esi
  char *v6; // edx
  int v9; // [esp+14h] [ebp-104h]
  char String1[256]; // [esp+18h] [ebp-100h] BYREF

  v2 = 1232 * *(_DWORD *)(*this + 25252);
  v3 = dword_7D6A5C + v2 == 0;
  v4 = (char *)(dword_7D6A5C + v2);
  if ( v3 )
    return 0;
  v5 = 0;
  v9 = sub_4E6CD0(v4);
  if ( v9 <= 0 )
    return 0;
  while ( 1 )
  {
    String1[0] = 0;
    if ( sub_4E7140((const char **)v4, v5, String1, 256) )
    {
      v6 = &String1[strlen(String1)];
      if ( v6 > String1 )
      {
        while ( *v6 != 92 )
        {
          if ( --v6 <= String1 )
            goto LABEL_9;
        }
        ++v6;
      }
LABEL_9:
      if ( !_strnicmp(v6, String2, strlen(String2)) )
        break;
    }
    if ( ++v5 >= v9 )
      return 0;
  }
  this[37] = v5;
  return 1;
}
