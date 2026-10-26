void __thiscall sub_5E4AA0(int this, char a2)
{
  int v3; // edx
  int v4; // ebx
  _DWORD *v5; // eax
  int v7; // ebp
  const char *v8; // esi
  unsigned int v9; // eax
  int v10; // esi
  char *v11; // eax
  char *v12; // esi
  _BYTE v13[64]; // [esp+8h] [ebp-40h] BYREF

  v3 = *(_DWORD *)(this + 220);
  v4 = 0;
  if ( v3 )
  {
    v5 = dword_FB2D78;
    if ( dword_FB2D78 )
    {
      while ( !*v5 || *v5 != v3 )
      {
        v5 = (_DWORD *)v5[1];
        if ( !v5 )
          goto LABEL_18;
      }
      if ( *v5 )
      {
        if ( (*(_DWORD *)(v3 + 108))-- == 1 )
        {
          if ( *(int *)(*(_DWORD *)(this + 220) + 212) > 0 )
          {
            v7 = 0;
            do
            {
              v8 = (const char *)(*(_DWORD *)(this + 220) + v7 + 140);
              sub_630FE0(v13);
              if ( (int)strlen(v8) <= 63 )
                v9 = strlen(v8);
              else
                v9 = 63;
              v10 = v7 + *(_DWORD *)(this + 220);
              v13[v9] = 0;
              sub_5E6DD0(v10);
              *(_BYTE *)(v10 + 140) = 0;
              ++v4;
              v7 += 216;
            }
            while ( v4 < *(_DWORD *)(*(_DWORD *)(this + 220) + 212) );
          }
          sub_5D9A40((int *)&dword_FB2D78, *(_DWORD *)(this + 220), 1);
          v11 = *(char **)(this + 220);
          if ( v11 )
          {
            v12 = v11 - 4;
            `eh vector destructor iterator'(v11, 0xD8u, *((_DWORD *)v11 - 1), j_j_nullsub_7);
            j__free(v12);
          }
        }
        *(_DWORD *)(this + 220) = 0;
      }
    }
  }
LABEL_18:
  if ( !a2 )
  {
    if ( *(_DWORD *)(this + 76) )
    {
      j__free(*(void **)(this + 76));
      *(_DWORD *)(this + 76) = 0;
      *(_DWORD *)(this + 80) = 0;
    }
  }
}
