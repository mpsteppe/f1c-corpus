// f1c  0x00566810  size=149
_BYTE *__fastcall sub_566810(_BYTE *a1, char *a2)
{
  _BYTE *result; // eax
  char *v3; // esi
  int v4; // ebp
  _BYTE *v5; // edi
  char v6; // bl
  char v7; // al
  char v8; // al
  _BYTE *v9; // [esp+10h] [ebp-8h]

  result = 0;
  if ( a1 )
  {
    if ( a2 )
    {
      v3 = a2;
      v4 = 0;
      v5 = a1;
      v9 = 0;
      if ( *a1 )
      {
        while ( 1 )
        {
          v6 = sub_589A35(*v3);
          v7 = sub_58B465(*v3);
          if ( *v5 == v6 || *v5 == v7 )
          {
            if ( !v4 )
              v9 = v5;
            v8 = *++v3;
            ++v4;
            if ( !v8 )
              return v9;
            ++v5;
          }
          else
          {
            v4 = 0;
            v3 = a2;
            if ( v9 )
              v5 = v9 + 1;
            else
              ++v5;
            v9 = 0;
          }
          if ( !*v5 )
            return 0;
        }
      }
    }
  }
  return result;
}
