char __thiscall sub_436F70(const CHAR ***this)
{
  const CHAR *v1; // eax
  char *v2; // esi
  int v3; // edi
  const char *v4; // ebp
  int v5; // eax
  char *v6; // eax
  const char *v7; // eax
  int i; // edi
  const char *v9; // eax
  const CHAR *v10; // eax
  int v11; // eax
  int v12; // eax
  _BYTE *v13; // eax
  const char *v14; // eax
  int v15; // eax
  const CHAR *v16; // ecx
  char *v17; // eax
  const CHAR *v18; // eax
  bool v19; // zf
  char *v21; // ecx
  char *v22; // [esp-Ch] [ebp-35Ch]
  const char *v23; // [esp-8h] [ebp-358h]
  const char *v24; // [esp-4h] [ebp-354h]
  int v25; // [esp-4h] [ebp-354h]
  char v26; // [esp+5h] [ebp-34Bh]
  char v27; // [esp+6h] [ebp-34Ah]
  void *Block; // [esp+8h] [ebp-348h]
  CHAR *v29; // [esp+10h] [ebp-340h]
  const char *v30; // [esp+14h] [ebp-33Ch]
  int v31; // [esp+18h] [ebp-338h]
  char *v32; // [esp+28h] [ebp-328h]
  int v33; // [esp+2Ch] [ebp-324h]
  int v34; // [esp+30h] [ebp-320h]
  char v35[4]; // [esp+34h] [ebp-31Ch] BYREF
  int v36; // [esp+38h] [ebp-318h]
  unsigned int v37; // [esp+3Ch] [ebp-314h]
  char v38[256]; // [esp+40h] [ebp-310h] BYREF
  char v39[256]; // [esp+140h] [ebp-210h] BYREF
  char v40[248]; // [esp+240h] [ebp-110h] BYREF
  char v41; // [esp+340h] [ebp-10h]
  int v42; // [esp+34Ch] [ebp-4h]

  v1 = **this;
  BYTE1(v29) = 0;
  if ( !v1 )
    v1 = WindowName;
  sub_615860(v1);
  v42 = 0;
  v37 = strlen(WindowName);
  BYTE2(v29) = _mkdir(WindowName) == 0;
  if ( dword_BE1CD0 > 0 )
  {
    v36 = dword_BE1CD0;
    do
    {
      v2 = (char *)(dword_BE1CD8 + 260);
      v3 = sub_53A250((char *)(dword_BE1CD8 + 260));
      if ( sub_53A250(v2) )
      {
        v5 = sub_616630(off_757C68);
        if ( v5 )
          v4 = (const char *)sub_48D380(v5);
        else
          v4 = v2;
      }
      else
      {
        v4 = v2;
      }
      strcpy(v39, v4);
      sub_4359C0(v39);
      v6 = sub_41D840(&byte_91CC38, v39);
      sub_615A50(v6);
      sub_617930(255);
      _mkdir(v40);
      LOBYTE(v29) = 0;
      if ( byte_B722B4 )
      {
        v7 = dword_B6F6A8;
        if ( !dword_B6F6A8 )
          v7 = WindowName;
        if ( !_stricmp(v2, v7) )
          LOBYTE(v29) = 1;
      }
      if ( BYTE2(v29) || (_BYTE)v29 )
      {
        BYTE1(v29) = 1;
        if ( v3 )
        {
          HIBYTE(v29) = 1;
          for ( i = sub_616610(0); i; i = sub_5C3D80(i, v22, v23, v25) )
          {
            v24 = off_757C6C;
            v9 = (const char *)sub_6165E0(i);
            if ( !_stricmp(v9, v24) )
            {
              v32 = (char *)operator new(0x80u);
              *v32 = 0;
              v33 = 128;
              v10 = dword_91CB00;
              LOBYTE(v42) = 1;
              if ( !dword_91CB00 )
                v10 = WindowName;
              sub_615A50(v10);
              v11 = sub_48D380(i);
              sub_615A50(v11);
              v34 = 0;
              *(_DWORD *)v35 = -1;
              LOBYTE(v42) = 2;
              v12 = sub_48D380(i);
              sub_615860(v12);
              v13 = (_BYTE *)sub_616480(WindowName, ".svm");
              if ( v13 )
                *v13 = 0;
              v30 = (const char *)operator new(0x80u);
              *v30 = 0;
              v31 = 128;
              LOBYTE(v42) = 3;
              sub_615A50(WindowName);
              v14 = v30;
              if ( !v30 )
                v14 = WindowName;
              v15 = strlen(v14);
              if ( v15 > 0 )
              {
                v16 = v30;
                if ( !v30 )
                  v16 = WindowName;
                if ( v16[v15 - 1] != 92 )
                  sub_615A50(word_6F1F78);
              }
              v17 = sub_41D840(&byte_91CC38, WindowName);
              sub_615A50(v17);
              sub_615A50(".svm");
              sub_617930(255);
              if ( (_BYTE)v29 )
              {
                v25 = 0;
                v23 = v4;
                v22 = v38;
                if ( !sub_436D50() )
                  sub_617D00((char *)WindowName, v35);
                if ( !v27 )
                {
                  if ( Block )
                    j_j__free(Block);
                  v41 = 0;
                  break;
                }
              }
              else
              {
                v21 = v32;
                if ( !v32 )
                  v21 = (char *)WindowName;
                sub_617D00(v21, v38);
              }
              if ( Block )
                j_j__free(Block);
              v41 = 0;
            }
          }
        }
      }
      v18 = v29;
      if ( !v29 )
        v18 = WindowName;
      v18[v34] = 0;
      v19 = v33 == 1;
      v31 += 396;
      --v33;
    }
    while ( !v19 );
  }
  if ( v29 )
    j_j__free(v29);
  return v26;
}
