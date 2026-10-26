int __thiscall sub_416DD0(int *this, float a2)
{
  int result; // eax
  char *v4; // esi
  int i; // edi
  int v6; // edi
  bool v7; // cc
  int j; // edi
  int v9; // ecx

  if ( dword_BE1204 == 2 )
  {
    for ( result = sub_42DA10(&unk_920488); dword_920480 < 105; result = sub_42DA60(&unk_920488) )
    {
      v4 = (char *)&unk_9204B0 + 22616 * result;
      sub_583360(a2);
      sub_57D8A0(v4);
    }
  }
  else
  {
    for ( i = 0; i < *this; ++i )
      sub_416370(*(_DWORD **)(this[2] + 4 * i), a2);
    if ( dword_BE1204 == 1 && *((float *)this + 31) + 0.30000001 < a2 )
    {
      result = *this;
      v6 = 0;
      v7 = *this <= 0;
      *((float *)this + 31) = a2;
      if ( !v7 )
      {
        do
        {
          if ( *(_DWORD *)(*(_DWORD *)(this[2] + 4 * v6) + 32) != 7 )
            sub_416B10();
          result = *this;
          ++v6;
        }
        while ( v6 < *this );
      }
    }
    else
    {
      result = *this;
      for ( j = 0; j < *this; ++j )
      {
        v9 = *(_DWORD *)(this[2] + 4 * j);
        if ( *(_DWORD *)(v9 + 32) != 7 && *(_DWORD *)(v9 + 12) != 1 )
          sub_416B10();
        result = *this;
      }
    }
  }
  return result;
}
