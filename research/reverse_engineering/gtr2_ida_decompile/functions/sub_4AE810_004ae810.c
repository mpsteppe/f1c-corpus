void __thiscall sub_4AE810(int this, int a2)
{
  int v3; // eax
  int v4; // ebx
  int i; // esi
  const char *v6; // edi
  int v7; // eax
  int v8; // edx
  int v9; // edi
  char *v10; // ebx
  int v11; // esi
  char *v12; // ebx
  _DWORD *v13; // eax
  char *v14; // ecx
  int v15; // ecx
  int v16; // [esp+8h] [ebp-68h]
  _BYTE Buffer[13]; // [esp+18h] [ebp-58h] BYREF
  __int16 v18; // [esp+25h] [ebp-4Bh]
  char v19; // [esp+27h] [ebp-49h]
  char v20[4]; // [esp+28h] [ebp-48h] BYREF
  char String1[65]; // [esp+2Ch] [ebp-44h] BYREF
  __int16 v22; // [esp+6Dh] [ebp-3h]
  char v23; // [esp+6Fh] [ebp-1h]
  int retaddr; // [esp+70h] [ebp+0h]
  int v25; // [esp+74h] [ebp+4h]

  memset(&String1[4], 0, 61);
  v22 = 0;
  v23 = 0;
  if ( a2 )
  {
LABEL_19:
    sub_4D0AC0(v16);
    v8 = dword_B6E084;
    v9 = 0;
    v10 = 0;
    retaddr = 0;
    do
    {
      v11 = 0;
      if ( dword_757C10 > 0 )
      {
        v12 = v10 + 1;
        while ( 1 )
        {
          v13 = (_DWORD *)*(&dword_91E088 + v11);
          v14 = (char *)(v8 <= 0 ? v13[4831] : v13[4832]);
          if ( v14 == v12 && (v13[5451] == v8 || !v8) )
            break;
          if ( ++v11 >= dword_757C10 )
            goto LABEL_37;
        }
        if ( *(_DWORD *)(*(&dword_91E088 + v11) + 14820) != -1 )
        {
          if ( !(unsigned __int8)sub_523BD0(&unk_BE1210, v11)
            && (!*(_BYTE *)(this + 608)
             || *(_DWORD *)dword_B640C8 != 6
             || *(float *)(*(&dword_91E088 + v11) + 19436) > 0.0) )
          {
            sub_4AE1E0((_DWORD *)this, v11, byte_B6DB18, v20);
            v15 = *(&dword_91E088 + v11);
            v18 = 0;
            v19 = 0;
            memset(Buffer, 0, sizeof(Buffer));
            sprintf(Buffer, "%d", *(_DWORD *)(v15 + 22468));
            sub_4D93B0(byte_B6DB18, 0, 0, Buffer, 0, 0, -1, -1, -1, -1);
            sub_4CE460(this);
            ++v9;
          }
          v8 = dword_B6E084;
        }
      }
LABEL_37:
      v10 = (char *)++retaddr;
    }
    while ( retaddr < 104 );
  }
  else
  {
    v3 = dword_757C10;
    v25 = dword_757C10;
    v4 = 0;
    while ( 1 )
    {
      for ( i = 0; i < v3; ++i )
      {
        if ( *(_DWORD *)(*(&dword_91E088 + i) + 19324) - 1 == v4 )
          break;
      }
      if ( i >= v25
        || *(_DWORD *)(*(&dword_91E088 + i) + 14820) == -1
        || (unsigned __int8)sub_523BD0(&unk_BE1210, i)
        || dword_B6E084 && *(_DWORD *)(*(&dword_91E088 + i) + 21804) != dword_B6E084 )
      {
        v7 = sub_4CE2D0(v4);
      }
      else
      {
        sub_4AE1E0((_DWORD *)this, i, byte_B6DB18, String1);
        v6 = (const char *)sub_4CE2D0(v4);
        *(_DWORD *)Buffer = sub_4CE4B0(v4);
        if ( !v6 || strcmp(v6, byte_B6DB18) )
          goto LABEL_19;
        v7 = _stricmp(String1, *(const char **)Buffer);
      }
      if ( v7 )
        goto LABEL_19;
      if ( ++v4 >= 104 )
        break;
      v3 = dword_757C10;
    }
  }
}
