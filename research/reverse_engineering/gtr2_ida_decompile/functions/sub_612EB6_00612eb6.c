// positive sp value has been detected, the output may be wrong!
int __thiscall sub_612EB6(const char *this)
{
  char *v1; // ebp
  signed int v2; // edi
  signed int v3; // esi
  int v4; // ecx
  char v5; // al
  char v6; // bl
  int v7; // esi
  signed int i; // esi
  int result; // eax
  char v10; // al
  bool v11; // zf
  int v12; // [esp-21Ch] [ebp-22Ch]
  char v13; // [esp-207h] [ebp-217h]
  bool v14; // [esp-206h] [ebp-216h]
  char v15; // [esp-205h] [ebp-215h]
  int v16; // [esp-204h] [ebp-214h]
  int v17; // [esp-200h] [ebp-210h]
  int v19; // [esp-1F8h] [ebp-208h]
  signed int v20; // [esp-1F4h] [ebp-204h]
  char v21[512]; // [esp-1F0h] [ebp-200h] BYREF

  v1 = (char *)(this + 536);
  v2 = 0;
  v19 = 0;
  v3 = strlen(this + 536);
  v12 = this[536];
  v20 = v3;
  v17 = 0;
  v14 = 0;
  v13 = 0;
  v15 = 0;
  v16 = 0;
  if ( isspace(v12) )
  {
    do
    {
      if ( !v1[v2] )
        break;
      v4 = v1[++v2];
    }
    while ( isspace(v4) );
  }
  if ( v2 < v3 )
  {
    do
    {
      if ( v15 )
        break;
      v5 = v1[v2];
      v6 = 1;
      if ( v5 == 34 )
        v14 = !v14;
      if ( !v14 )
      {
        if ( v5 != 47 )
          v13 = 0;
        v7 = v5;
        switch ( v5 )
        {
          case 10:
          case 13:
            goto LABEL_22;
          case 40:
            ++v17;
            break;
          case 41:
            --v17;
            break;
          case 47:
            if ( v13 )
            {
              --v16;
              v15 = 1;
              v19 = 3;
              goto LABEL_22;
            }
            v13 = 1;
            break;
          default:
            if ( v17 && isspace(v5) )
              v6 = 0;
            v5 = sub_633CD6(v7);
            if ( v6 )
              break;
            goto LABEL_22;
        }
      }
      v21[v16++] = v5;
LABEL_22:
      ++v2;
    }
    while ( v2 < v20 );
  }
  v21[v16] = 0;
  strcpy(v1, v21);
  for ( i = strlen(v1) - 1; i > 0; --i )
  {
    if ( !isspace(v1[i]) )
      break;
  }
  this[i + 537] = 0;
  if ( v19 == 3 )
  {
    if ( strlen(v1) )
      return 0;
    return v19;
  }
  if ( !strlen(v1) )
    return 1;
  v10 = this[i + 536];
  if ( v10 == 32 )
    return 1;
  if ( v10 == 125 )
    return 2;
  v11 = sscanf(v1, "%s", v21) == -1;
  result = 4;
  if ( !v11 )
    return v19;
  return result;
}
