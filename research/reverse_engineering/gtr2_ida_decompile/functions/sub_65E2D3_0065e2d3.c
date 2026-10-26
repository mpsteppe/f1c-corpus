int __thiscall sub_65E2D3(int this, char *a2, unsigned int *a3)
{
  char *v3; // ebx
  unsigned int v5; // esi
  unsigned int v6; // eax
  int v8; // [esp+8h] [ebp-4h]

  v3 = a2;
  if ( (unsigned int)a2 >= *(_DWORD *)(this + 4) || !isdigit(*a2) )
    return 0;
  v5 = 0;
  v8 = 0;
  if ( (unsigned int)a2 < *(_DWORD *)(this + 4) )
  {
    do
    {
      if ( !isdigit(*v3) )
        break;
      if ( v5 > 0x19999999 )
        v8 = 1;
      v6 = 10 * v5;
      v5 = *v3 + 10 * v5 - 48;
      if ( v5 < v6 )
        v8 = 1;
      ++v3;
    }
    while ( (unsigned int)v3 < *(_DWORD *)(this + 4) );
  }
  if ( a3 )
    *a3 = v5;
  if ( v8 )
    sub_65DD1F(*(_DWORD **)(this + 48), this + 8, 1004, "decimal value truncated to 32bits");
  return v3 - a2;
}
