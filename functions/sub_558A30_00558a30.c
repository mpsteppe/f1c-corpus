char __thiscall sub_558A30(int this, int a2)
{
  int v3; // eax
  int v4; // ecx
  int *v5; // ebx
  int v6; // ecx
  int v7; // edi
  int v8; // edx
  _DWORD *v9; // ecx
  _DWORD *v10; // eax
  int v11; // edi
  int i; // ecx
  int v13; // ecx

  v3 = *(_DWORD *)(this + 44);
  if ( *(_DWORD *)(this + 48) < v3 && a2 < v3 )
  {
    v4 = *(_DWORD *)(this + 52);
    LOBYTE(v3) = *(_BYTE *)((a2 << 7) + v4);
    v5 = (int *)(v4 + (a2 << 7));
    if ( (v3 & 0x40) == 0 )
    {
      if ( *(char *)(this + 32) >= 0 )
      {
        v3 = *(_DWORD *)(this + 56);
        if ( v3 )
        {
          for ( i = *(_DWORD *)(v3 + 124); i; i = *(_DWORD *)(i + 124) )
            v3 = i;
          *(_DWORD *)(v3 + 124) = v5;
        }
        else
        {
          *(_DWORD *)(this + 56) = v5;
        }
        v13 = *v5 | 0x40;
        v5[30] = v3;
        v5[31] = 0;
        *v5 = v13;
        ++*(_DWORD *)(this + 48);
      }
      else
      {
        TextureAllocationWithFormatSizeFlags(0);
        v6 = *(_DWORD *)(this + 80);
        v7 = *(_DWORD *)(v6 + 32);
        if ( v7 )
        {
          v8 = *(_DWORD *)(this + 36);
          v9 = (_DWORD *)(*(_DWORD *)(v6 + 12) + 36 * a2 * v8);
          v10 = (_DWORD *)(v7 + ((v8 * *(_DWORD *)(this + 48)) << 6));
          v11 = 0;
          if ( v8 > 0 )
          {
            do
            {
              *v10 = *v9;
              v10[1] = v9[1];
              v10[2] = v9[2];
              v10[6] = v9[6];
              v10 += 16;
              v9 += 9;
              ++v11;
            }
            while ( v11 < *(_DWORD *)(this + 36) );
          }
        }
        v5[1] = *(_DWORD *)(this + 48);
        *(_DWORD *)(*(_DWORD *)(this + 60) + 4 * *(_DWORD *)(this + 48)) = v5;
        *v5 |= 0x40u;
        v3 = *(_DWORD *)(this + 48) + 1;
        *(_DWORD *)(this + 48) = v3;
      }
    }
  }
  return v3;
}
