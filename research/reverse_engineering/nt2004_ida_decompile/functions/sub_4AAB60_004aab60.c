int __thiscall sub_4AAB60(char *this, int a2, char a3, char a4, int a5)
{
  int v5; // esi
  int v6; // ebp
  int result; // eax
  const char *v8; // eax
  char *v9; // eax
  int v10; // esi
  _DWORD *v11; // edi
  const char *v12; // ebp
  _DWORD *v13; // eax
  _DWORD *v14; // esi
  const char *v15; // eax
  _DWORD *v16; // eax
  int v17; // edx
  int v18; // ecx
  LPVOID **v19; // edi
  CHAR ***v20; // eax
  CHAR **v21; // eax
  CHAR *v22; // eax
  LPVOID **v23; // esi
  bool v24; // zf
  LPVOID *v25; // ebp
  int v26; // esi
  double v27; // st7
  float v29; // [esp+Ch] [ebp-264h]
  LPVOID **v30; // [esp+10h] [ebp-260h]
  int v31; // [esp+1Ch] [ebp-254h]
  char v32[76]; // [esp+24h] [ebp-24Ch] BYREF
  char Buffer[256]; // [esp+70h] [ebp-200h] BYREF
  char v34[256]; // [esp+170h] [ebp-100h] BYREF

  v5 = a2;
  v6 = (int)this;
  if ( !a2 )
    return -1;
  strcpy(this + 84, (const char *)(*(int (__thiscall **)(int))(*(_DWORD *)a2 + 12))(a2));
  *(_BYTE *)(v6 + 480) = a3;
  *(_DWORD *)(v6 + 492) = a2;
  *(_BYTE *)(v6 + 481) = a4;
  *(_BYTE *)(v6 + 482) = 0;
  result = sub_4A8410((_BYTE *)v6);
  if ( result != -1 )
  {
    sub_4A85A0((_DWORD *)v6);
    if ( byte_6088CC )
    {
      v8 = (const char *)dword_62A0A8;
      if ( !dword_62A0A8 )
        v8 = &byte_629120;
      sprintf(Buffer, "%s%s", v8, aEasBik);
      sub_527460(Buffer, 0);
      v9 = dword_62A0E0;
      v10 = 0;
      v11 = 0;
      v30 = 0;
      v31 = 0;
      if ( !dword_62A0E0 )
        v9 = &byte_629120;
      sub_578A30(aBik, 1, v9, 1);
      sub_578E30(2);
      v12 = (const char *)sub_578D80(&unk_7D7A0C);
      if ( v12 )
      {
        do
        {
          v13 = operator new(8u);
          if ( v13 )
          {
            *v13 = 0;
            v13[1] = -1;
            v14 = v13;
          }
          else
          {
            v14 = 0;
          }
          v15 = dword_62A0E0;
          if ( !dword_62A0E0 )
            v15 = &byte_629120;
          sprintf(v34, "%s%s", v15, v12);
          sub_578600(v34);
          if ( v14 )
          {
            v16 = operator new(0xCu);
            if ( v16 )
            {
              *v16 = v14;
              v16[1] = 0;
              *((_BYTE *)v16 + 8) = 1;
            }
            else
            {
              v16 = 0;
            }
            if ( v30 )
              v11[1] = v16;
            else
              v30 = (LPVOID **)v16;
            v11 = v16;
            ++v31;
          }
          sub_5789D0(&unk_7D7A0C);
          v12 = (const char *)sub_578D80(&unk_7D7A0C);
        }
        while ( v12 );
        v10 = v31;
      }
      sub_578960(&unk_7D7A0C);
      if ( v10 <= 0 )
        goto LABEL_38;
      v17 = rand() % v10;
      if ( v17 >= v10 )
        v17 = 0;
      v18 = v17;
      if ( v17 < 0 || v17 >= v10 )
      {
LABEL_38:
        v19 = v30;
      }
      else
      {
        v19 = v30;
        v20 = (CHAR ***)v30;
        if ( v17 <= 0 )
        {
LABEL_33:
          if ( v20 )
          {
            v21 = *v20;
            if ( v21 )
            {
              v22 = *v21;
              if ( !v22 )
                v22 = &byte_629120;
              sub_527460(v22, 1);
            }
          }
        }
        else
        {
          while ( v20 )
          {
            v20 = (CHAR ***)v20[1];
            if ( --v18 <= 0 )
              goto LABEL_33;
          }
        }
      }
      while ( v19 )
      {
        v23 = v19;
        v24 = *((_BYTE *)v19 + 8) == 0;
        v19 = (LPVOID **)v19[1];
        if ( !v24 )
        {
          v25 = *v23;
          if ( *v23 )
          {
            sub_40D5B0(*v23);
            sub_5BE8AE(v25);
          }
        }
        sub_5BE8AE(v23);
      }
      v5 = a2;
      v6 = (int)this;
    }
    sub_4AC660(v5);
    sub_57B5D0(v32);
    sub_57B610(1);
    sub_57B690(v32);
    v26 = sub_4A8640(v6);
    sub_4A8480((char *)v6);
    v27 = 4.0 - sub_57B720(v32);
    if ( v27 > 0.0 )
    {
      v29 = v27 * 1000.0;
      Sleep((int)v29);
    }
    if ( byte_6088CC )
    {
      byte_6088CC = 0;
      nullsub_6(&unk_629328);
    }
    nullsub_6(v32);
    return v26;
  }
  return result;
}
