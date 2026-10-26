void __thiscall sub_4A1270(_DWORD *this, const char **a2)
{
  int v2; // ebx
  int v4; // esi
  _DWORD *v5; // eax
  char **v6; // eax
  int v7; // esi
  LPVOID **v8; // edi
  char v9; // al
  char *v10; // eax
  const char *v11; // esi
  char *v12; // eax
  _DWORD *v13; // eax
  _DWORD *v14; // eax
  int v15; // edi
  int v16; // esi
  _DWORD *v17; // eax
  _DWORD *v18; // eax
  int v19; // edi
  _DWORD *v20; // eax
  int v21; // esi
  int v22; // esi
  _DWORD *v23; // [esp+10h] [ebp-24h]
  const char *v24; // [esp+14h] [ebp-20h]
  char **v25; // [esp+18h] [ebp-1Ch]
  int v26; // [esp+1Ch] [ebp-18h]
  int v27; // [esp+20h] [ebp-14h] BYREF
  int v28; // [esp+24h] [ebp-10h] BYREF
  int v29; // [esp+28h] [ebp-Ch]
  char v30; // [esp+2Ch] [ebp-8h] BYREF
  int v31; // [esp+2Dh] [ebp-7h]
  __int16 v32; // [esp+31h] [ebp-3h]
  char v33; // [esp+33h] [ebp-1h]
  bool v34; // [esp+38h] [ebp+4h]

  v2 = 0;
  if ( a2 )
  {
    v28 = 0;
    v27 = 0;
    v26 = 0;
    v4 = sub_49D770(this, 1);
    v29 = v4 - sub_49D770(this, 0);
    sub_49D7F0(this, 1);
    sub_49D7F0(this, 0);
    v24 = *a2;
    if ( !*a2 )
      v24 = &byte_629120;
    v5 = operator new(8u);
    if ( v5 )
    {
      *v5 = 0;
      v5[1] = -1;
      v23 = v5;
    }
    else
    {
      v23 = 0;
    }
    v6 = (char **)operator new(8u);
    if ( v6 )
    {
      *v6 = 0;
      v6[1] = (char *)-1;
      v25 = v6;
    }
    else
    {
      v25 = 0;
    }
    v7 = this[69];
    while ( v7 )
    {
      v8 = (LPVOID **)v7;
      v9 = *(_BYTE *)(v7 + 8);
      v7 = *(_DWORD *)(v7 + 4);
      if ( v9 && *v8 )
        sub_4115A0(*v8, 1);
      sub_5BE8AE(v8);
    }
    this[69] = 0;
    this[70] = 0;
    this[71] = 0;
    this[72] = 0;
    v10 = *(char **)(this[61] + 64);
    if ( !v10 )
      v10 = &byte_629120;
    sub_4AE350(v10);
    v11 = v24;
    if ( (int)strlen(v24) > 0 )
    {
      while ( 1 )
      {
        v31 = 0;
        v32 = 0;
        v33 = 0;
        v28 = 0;
        v27 = 0;
        v30 = v11[v2];
        sub_578560(&v30);
        v34 = v30 == 10;
        if ( v30 == 32 || v30 == 10 )
          break;
LABEL_55:
        if ( v2 == strlen(v11) - 1 )
        {
          v19 = v26;
          if ( v26 <= v2 )
          {
            do
            {
              v30 = v11[v19];
              sub_578560(&v30);
              ++v19;
            }
            while ( v19 <= v2 );
            v26 = v19;
          }
          if ( v23 )
          {
            v20 = operator new(0xCu);
            if ( v20 )
            {
              *v20 = v23;
              v20[1] = 0;
              *((_BYTE *)v20 + 8) = 1;
            }
            else
            {
              v20 = 0;
            }
            if ( this[69] )
            {
              *(_DWORD *)(this[70] + 4) = v20;
            }
            else
            {
              this[69] = v20;
              this[71] = v20;
            }
            this[70] = v20;
            ++this[72];
          }
        }
        if ( ++v2 >= (int)strlen(v11) )
          goto LABEL_68;
      }
      v12 = *v25;
      if ( !*v25 )
        v12 = &byte_629120;
      sub_4AE230(v12, (int)&v28, (int)&v27);
      if ( v28 <= v29 )
      {
        v15 = v26;
      }
      else
      {
        if ( v23 )
        {
          v13 = operator new(0xCu);
          if ( v13 )
          {
            *v13 = v23;
            v13[1] = 0;
            *((_BYTE *)v13 + 8) = 1;
          }
          else
          {
            v13 = 0;
          }
          if ( this[69] )
          {
            *(_DWORD *)(this[70] + 4) = v13;
          }
          else
          {
            this[69] = v13;
            this[71] = v13;
          }
          this[70] = v13;
          ++this[72];
        }
        v14 = operator new(8u);
        if ( v14 )
        {
          *v14 = 0;
          v14[1] = -1;
          v23 = v14;
        }
        else
        {
          v23 = 0;
        }
        sub_578600(&byte_629120);
        v15 = v26;
        v16 = v26;
        if ( v26 > v2 )
        {
          v11 = v24;
LABEL_42:
          if ( v34 )
          {
            if ( v23 )
            {
              v17 = operator new(0xCu);
              if ( v17 )
              {
                *v17 = v23;
                v17[1] = 0;
                *((_BYTE *)v17 + 8) = 1;
              }
              else
              {
                v17 = 0;
              }
              if ( this[69] )
              {
                *(_DWORD *)(this[70] + 4) = v17;
              }
              else
              {
                this[69] = v17;
                this[71] = v17;
              }
              this[70] = v17;
              ++this[72];
            }
            v18 = operator new(8u);
            if ( v18 )
            {
              *v18 = 0;
              v18[1] = -1;
              v23 = v18;
            }
            else
            {
              v23 = 0;
            }
            sub_578600(&byte_629120);
          }
          goto LABEL_55;
        }
        do
        {
          v30 = v24[v16];
          sub_578560(&v30);
          ++v16;
        }
        while ( v16 <= v2 );
        v11 = v24;
      }
      if ( v15 <= v2 )
      {
        do
        {
          v30 = v11[v15];
          sub_578560(&v30);
          ++v15;
        }
        while ( v15 <= v2 );
        v26 = v15;
      }
      goto LABEL_42;
    }
LABEL_68:
    if ( v27 )
    {
      v21 = sub_49D7F0(this, 1);
      v22 = v21 - sub_49D7F0(this, 0);
      this[76] = v22 / v27;
    }
  }
}
