char __thiscall sub_41C5A0(int *this, char *Buffer, _DWORD *a3, char a4)
{
  int v5; // ecx
  int v6; // edi
  int v7; // eax
  int v8; // eax
  int v9; // esi
  _DWORD *v10; // ebx
  int v11; // eax
  int v12; // eax
  bool v13; // cc
  int v14; // eax
  unsigned int *v15; // esi
  int v16; // ebx
  char v18; // [esp+8h] [ebp-4Ch] BYREF
  char v19; // [esp+9h] [ebp-4Bh] BYREF
  char v20; // [esp+Ah] [ebp-4Ah] BYREF
  char v21; // [esp+Bh] [ebp-49h] BYREF
  int v22; // [esp+Ch] [ebp-48h]
  unsigned int v23; // [esp+10h] [ebp-44h] BYREF
  int v24; // [esp+14h] [ebp-40h]
  int v25; // [esp+18h] [ebp-3Ch]
  int v26; // [esp+1Ch] [ebp-38h]
  int v27; // [esp+20h] [ebp-34h] BYREF
  int v28; // [esp+24h] [ebp-30h] BYREF
  int v29; // [esp+28h] [ebp-2Ch] BYREF
  int v30; // [esp+2Ch] [ebp-28h] BYREF
  _BYTE v31[8]; // [esp+30h] [ebp-24h] BYREF
  _BYTE v32[28]; // [esp+38h] [ebp-1Ch] BYREF

  v5 = *this;
  v6 = 0;
  if ( v5 )
  {
    v7 = this[1];
    if ( v7 )
    {
      sub_59FDC0(0, 0, v7, 0, 0, *(_DWORD *)(*(_DWORD *)(v5 + 16) + 28), *(_DWORD *)(*(_DWORD *)(v5 + 16) + 32), -2, 0);
      sub_57A080(v32);
      if ( (unsigned __int8)sub_57A110(Buffer, 0, 0, 1) )
      {
        v8 = *this;
        LOBYTE(Buffer) = 0;
        v18 = 0;
        v19 = 2;
        v31[0] = 0;
        v31[1] = 0;
        v31[2] = 0;
        v31[3] = 0;
        v31[4] = 0;
        v27 = 0;
        v28 = 0;
        v29 = *(unsigned __int16 *)(*(_DWORD *)(v8 + 16) + 28);
        v30 = *(unsigned __int16 *)(*(_DWORD *)(v8 + 16) + 32);
        v20 = *(_BYTE *)(*(_DWORD *)(v8 + 16) + 36);
        v21 = 40;
        sub_57A3A0(&Buffer, 1u);
        sub_57A3A0(&v18, 1u);
        sub_57A3A0(&v19, 1u);
        sub_57A3A0(v31, 5u);
        sub_57A3A0(&v27, 2u);
        sub_57A3A0(&v28, 2u);
        sub_57A3A0(&v29, 2u);
        sub_57A3A0(&v30, 2u);
        sub_57A3A0(&v20, 1u);
        sub_57A3A0(&v21, 1u);
        v24 = 0;
        v9 = sub_59FD80(1, 0);
        v25 = v9;
        v10 = a3;
        v22 = 0;
        if ( a3 )
        {
          if ( a3[12] == 8 )
          {
            v11 = this[1];
            if ( a3[7] >= *(_DWORD *)(v11 + 28) && a3[8] >= *(_DWORD *)(v11 + 32) )
              v22 = sub_59FD80(0, 0);
          }
        }
        if ( v9 )
        {
          v12 = this[1];
          v13 = *(_DWORD *)(v12 + 28) <= 0;
          v26 = 0;
          if ( !v13 )
          {
            v14 = *(_DWORD *)(v12 + 32);
            do
            {
              if ( v14 > 0 )
              {
                v15 = (unsigned int *)(v9 + 4 * v24);
                v16 = v22 - v25;
                do
                {
                  if ( v22 )
                  {
                    v23 = *(unsigned int *)((char *)v15 + v16)
                        ^ (*(unsigned int *)((char *)v15 + v16)
                         ^ *v15)
                        & 0xFFFFFF;
                  }
                  else if ( a4 )
                  {
                    v23 = *v15 | 0xFF000000;
                  }
                  else
                  {
                    v23 = *v15;
                  }
                  sub_57A3A0(&v23, 4u);
                  v14 = *(_DWORD *)(this[1] + 32);
                  ++v15;
                  ++v6;
                  ++v24;
                }
                while ( v6 < v14 );
                v10 = a3;
                v9 = v25;
                v6 = 0;
              }
              v13 = ++v26 < *(_DWORD *)(this[1] + 28);
            }
            while ( v13 );
          }
        }
        sub_57A360(v32);
      }
      else
      {
        v10 = a3;
      }
      if ( v10 )
        sub_59FDA0(0, 0);
      sub_59FDA0(1, 0);
      sub_57A0A0(v32);
    }
  }
  return 0;
}
