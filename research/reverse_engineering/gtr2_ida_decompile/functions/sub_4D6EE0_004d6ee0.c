int __thiscall sub_4D6EE0(int *this, int a2, int a3, int a4, int a5)
{
  int v6; // ebx
  int v7; // edi
  int v8; // eax
  int v9; // ecx
  const char *v10; // eax
  int v11; // edx
  int v12; // ebx
  const char *v13; // eax
  int v14; // ebp
  const char *v15; // eax
  const char *v16; // eax
  char *v17; // eax
  char *v18; // eax
  int v19; // eax
  int v20; // edi
  int v21; // ebp
  int v22; // eax
  int v24; // [esp+0h] [ebp-698h]
  int v25; // [esp+8h] [ebp-690h]
  void *Block; // [esp+Ch] [ebp-68Ch]
  int v27; // [esp+38h] [ebp-660h]
  int v28; // [esp+3Ch] [ebp-65Ch]
  int v29; // [esp+40h] [ebp-658h]
  int v30; // [esp+40h] [ebp-658h]
  int v31; // [esp+54h] [ebp-644h]
  char *v32; // [esp+58h] [ebp-640h]
  char *v33; // [esp+58h] [ebp-640h]
  int v34; // [esp+5Ch] [ebp-63Ch]
  char *v35; // [esp+60h] [ebp-638h]
  int v36; // [esp+64h] [ebp-634h]
  int v37[3]; // [esp+68h] [ebp-630h] BYREF
  char *v38; // [esp+74h] [ebp-624h]
  _DWORD v39[129]; // [esp+78h] [ebp-620h] BYREF
  char v40; // [esp+27Ch] [ebp-41Ch]
  int v41; // [esp+284h] [ebp-414h]
  int v42; // [esp+288h] [ebp-410h]
  int v43; // [esp+28Ch] [ebp-40Ch]
  _BYTE v44[512]; // [esp+290h] [ebp-408h] BYREF
  char ArgList; // [esp+490h] [ebp-208h] BYREF
  _BYTE v46[509]; // [esp+498h] [ebp-200h] BYREF
  __int16 v47; // [esp+695h] [ebp-3h]
  char v48; // [esp+697h] [ebp-1h]

  if ( this[142] >= 1 && this[147] >= 1 )
  {
    v6 = this[36];
    v7 = 0;
    v36 = v6;
    v37[1] = 0;
    v8 = sub_4CFD30(this, 2);
    v9 = this[3];
    v38 = (char *)(this[133] + v8);
    v39[0] = v9 + this[136];
    if ( v6 )
    {
      do
      {
        if ( v7 > this[139] )
          break;
        v10 = *(const char **)(v36 + 160);
        if ( !v10 )
          v10 = WindowName;
        if ( strstr(v10, "<LOGO") )
        {
          v11 = *this;
          v12 = (this[142] + this[135]) * (this[139] - v7 - 1);
          memset(v46, 0, sizeof(v46));
          v47 = 0;
          v48 = 0;
          v37[2] = 0;
          (*(void (__thiscall **)(int *, _BYTE *, int))(v11 + 180))(this, v46, 512);
          sub_5EE940((int)v37, (char)&ArgList, 0);
          v13 = *(const char **)(v34 + 160);
          v14 = 0;
          if ( !v13 )
            v13 = WindowName;
          v32 = strstr(v13, "<LOGO>");
          v15 = *(const char **)(v34 + 160);
          if ( !v15 )
            v15 = WindowName;
          v35 = strstr(v15, "<LOGO_RIGHT>");
          v16 = *(const char **)(v34 + 160);
          if ( !v16 )
            v16 = WindowName;
          v17 = strstr(v16, "<LOGO_CENTER>");
          v38 = v17;
          if ( v35 )
          {
            v33 = v35 + 12;
          }
          else
          {
            if ( v17 )
              v18 = v17 + 13;
            else
              v18 = v32 + 6;
            v33 = v18;
          }
          memset(v44, 0, sizeof(v44));
          v39[128] = 0;
          v43 = 0;
          v41 = 0;
          v42 = 0;
          v40 = 1;
          if ( v33 )
          {
            sub_630FE0(v44, v33, 511);
            v44[511] = 0;
            sub_612EB0(v39);
            v19 = sub_4E0080(this[12], v44, 1, 1, 1, 0, 0, 0, 0);
            this[132] = v19;
            if ( v19 )
            {
              v20 = *(_DWORD *)(v19 + 20);
              v27 = *(_DWORD *)(v19 + 24);
              if ( v27 > v12 )
              {
                if ( v29 )
                {
                  v30 = this[3];
                  v14 = sub_4CFCC0(this, 3) - v30 - v20;
                }
                else if ( v31 )
                {
                  v21 = this[3];
                  v14 = (sub_4CFCC0(this, 3) - v21) / 2 - v20 / 2;
                }
                Block = 0;
                v25 = 0;
                this[132] = sub_4E0240(this[12]);
                v22 = sub_4DDFE0(&unk_B6E2A0, v27);
                sub_4D5E10(this, this[132], 0, 0, v22, v28 + v14, v27, v20);
              }
            }
          }
          if ( Block )
            sub_5EEA30(dword_FB1CE0, Block, 0);
        }
        v7 = ++v25;
        v24 = *(_DWORD *)(v24 + 140);
      }
      while ( v24 );
    }
  }
  return 0;
}
