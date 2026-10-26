int __thiscall sub_502090(_DWORD *this)
{
  int v2; // esi
  int v3; // edx
  _DWORD *v4; // eax
  char *v5; // eax
  int v6; // edi
  int v7; // esi
  const char **v8; // eax
  const char *v9; // ecx
  const char *v10; // eax
  int v11; // esi
  _DWORD *v12; // eax
  char *v13; // eax
  _BYTE v15[4]; // [esp+1Ch] [ebp-730h] BYREF
  _BYTE v16[28]; // [esp+20h] [ebp-72Ch] BYREF
  char Buffer[253]; // [esp+3Ch] [ebp-710h] BYREF
  __int16 v18; // [esp+139h] [ebp-613h]
  char v19; // [esp+13Bh] [ebp-611h]
  char v20[1036]; // [esp+13Ch] [ebp-610h] BYREF
  int v21; // [esp+744h] [ebp-8h]
  int v22; // [esp+748h] [ebp-4h]

  sub_53C160(v16);
  v22 = 0;
  sub_53B0D0(&unk_BE1CFC, v20, 1023);
  v2 = sub_53A250(0);
  sub_501CC0(&byte_B6F530, *(int *)dword_B72314);
  v3 = sub_616840("IgnoreTrackFilter");
  memset(Buffer, 0, sizeof(Buffer));
  v18 = 0;
  v19 = 0;
  if ( v2 )
  {
    if ( !v3 )
    {
      v4 = (_DWORD *)sub_616630("AI Vehicle Filter");
      if ( v4 )
      {
        v5 = sub_48D380(v4);
        sprintf(Buffer, " AND: %s", v5);
      }
    }
  }
  sprintf(v20, "%s NOT: NotAI %s", v20, Buffer);
  sub_53BDE0(v16, v20);
  v6 = sub_5A6E90(v15);
  v7 = 0;
  if ( v6 > 0 )
  {
    while ( 1 )
    {
      v8 = (const char **)((int (__thiscall *)(_BYTE *, int))byte_53A070)(v15, v7);
      v9 = (const char *)this[118];
      if ( !v9 )
        v9 = WindowName;
      v10 = *v8;
      if ( !v10 )
        v10 = WindowName;
      if ( !_stricmp(v10, v9) )
        break;
      if ( ++v7 >= v6 )
        goto LABEL_14;
    }
    --v6;
  }
LABEL_14:
  v11 = 103;
  v12 = (_DWORD *)sub_53A250("Max Vehicles");
  if ( v12 )
  {
    v13 = sub_48D380(v12);
    v11 = (unsigned __int64)((double)atol(v13) - 1.0);
  }
  if ( v6 >= 0 )
  {
    if ( v6 > v11 )
      v6 = v11;
  }
  else
  {
    v6 = 0;
  }
  v21 = -1;
  sub_53C1D0(v15);
  return v6;
}
