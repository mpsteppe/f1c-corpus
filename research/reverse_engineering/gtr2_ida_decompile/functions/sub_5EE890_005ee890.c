int __thiscall sub_5EE890(int this)
{
  int *v2; // eax
  int **v3; // esi
  int result; // eax
  int *v5; // eax
  bool v6; // zf
  char *v7; // eax
  char *v8; // esi

  if ( *(_DWORD *)(this + 16) )
  {
    fclose(*(FILE **)(this + 16));
    *(_DWORD *)(this + 16) = 0;
  }
  if ( *(_DWORD *)(this + 292) )
  {
    v2 = *(int **)(this + 296);
    v3 = (int **)(this + 296);
    *(_DWORD *)(this + 304) = v2;
    if ( v2 && *v2 )
    {
      *(_DWORD *)(this + 304) = v2;
      result = *v2;
      if ( result )
      {
        while ( 1 )
        {
          sub_59F730((int *)(this + 296), result, 1);
          v5 = *v3;
          v6 = *v3 == 0;
          *(_DWORD *)(this + 304) = *(_DWORD *)(this + 296);
          if ( v6 )
            break;
          result = *v5;
          if ( !result )
            return result;
        }
      }
    }
    else
    {
      v7 = *(char **)(this + 292);
      if ( v7 )
      {
        v8 = v7 - 4;
        `eh vector destructor iterator'(v7, 0x100u, *((_DWORD *)v7 - 1), nullsub_7);
        j__free(v8);
      }
      *(_DWORD *)(this + 292) = 0;
    }
  }
  return 0;
}
