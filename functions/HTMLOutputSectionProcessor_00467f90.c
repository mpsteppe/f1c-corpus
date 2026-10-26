LPVOID **__thiscall sub_467F90(_DWORD *this)
{
  LPVOID **result; // eax
  char **v3; // ebx
  int i; // esi
  LPVOID **v5; // ecx
  char *v6; // eax
  int v7; // eax
  char ***v8; // eax
  char **v9; // eax
  char *v10; // eax
  char *v11; // eax
  char *v12; // ebx
  int v13; // eax

  result = (LPVOID **)this[62];
  this[64] = result;
  if ( result )
    v3 = (char **)*result;
  else
    v3 = 0;
  for ( i = this[17]; i; result = DestructorWithDoubleFreePattern(v5, 1) )
  {
    v5 = (LPVOID **)i;
    i = *(_DWORD *)(i + 4);
  }
  this[17] = 0;
  this[18] = 0;
  this[19] = 0;
  this[20] = 0;
  if ( v3 )
  {
    do
    {
      v6 = *v3;
      if ( !*v3 )
        v6 = byte_5EA438;
      if ( sub_588410(v6, aHeader_0) )
      {
        v11 = *v3;
        if ( !*v3 )
          v11 = byte_5EA438;
        if ( !sub_588410(v11, aHeader2) )
        {
          v12 = *v3;
          if ( !v12 )
            v12 = byte_5EA438;
          LinkedListInsertWithNodeAllocation(v12, -1);
        }
      }
      else
      {
        v7 = this[64];
        if ( v7 )
          this[64] = *(_DWORD *)(v7 + 4);
        v8 = (char ***)this[64];
        if ( v8 )
        {
          v9 = *v8;
          if ( v9 )
          {
            v10 = *v9;
            if ( !v10 )
              v10 = byte_5EA438;
            LinkedListInsertWithNodeAllocation(v10, -1);
          }
        }
      }
      v13 = this[64];
      if ( v13 )
        this[64] = *(_DWORD *)(v13 + 4);
      result = (LPVOID **)this[64];
      if ( !result )
        break;
      v3 = (char **)*result;
    }
    while ( *result );
  }
  return result;
}
