int __stdcall sub_536CC0(const char *a1)
{
  int v1; // ebx
  const CHAR *v2; // eax
  int *v3; // esi
  int v4; // edi
  int v5; // ebp
  char *v6; // esi
  int *v7; // eax
  char *v8; // eax
  _BYTE v10[4]; // [esp+0h] [ebp-124h] BYREF
  int v11[2]; // [esp+4h] [ebp-120h] BYREF
  int v12; // [esp+Ch] [ebp-118h]
  int v13; // [esp+10h] [ebp-114h]
  char *v14; // [esp+14h] [ebp-110h]
  _BYTE v15[264]; // [esp+18h] [ebp-10Ch] BYREF
  int v16; // [esp+120h] [ebp-4h]

  v1 = 0;
  if ( dword_757C10 <= 0 )
    goto LABEL_26;
  v11[0] = 0;
  v11[1] = 0;
  v12 = 0;
  v13 = 0;
  v16 = 0;
  if ( (_BYTE)dword_757C1C )
  {
    v2 = dword_B6F708;
    if ( !dword_B6F708 )
      v2 = WindowName;
    sub_630FE0(v15, v2, 255);
    v15[255] = 0;
  }
  else
  {
    v15[0] = 0;
  }
  if ( *(_DWORD *)dword_B72314 == 7 || *(_DWORD *)dword_B72314 == 8 )
  {
    dword_757C10 = 1;
    goto LABEL_24;
  }
  if ( *(_DWORD *)dword_B72314 != 1 )
    goto LABEL_13;
  if ( !dword_B71F00 )
  {
    dword_757C10 = sub_51C780() % 3u + 3;
    sub_42CC30(&unk_920488);
LABEL_13:
    v3 = (int *)dword_757C10;
    if ( (_BYTE)dword_757C1C )
      v3 = (int *)(dword_757C10 - 1);
    if ( sub_5365F0(v11, (int)v3, (int)v15, a1) == v3 )
    {
      v4 = (_BYTE)dword_757C1C != 0;
      v14 = (char *)v3 + v4;
      if ( v4 < (int)v3 + v4 )
      {
        v5 = 0;
        v6 = (char *)&unk_9204A0 + 22616 * v4;
        do
        {
          sub_53E6A0(v6, 1);
          if ( v5 < v12 )
          {
            v7 = (int *)sub_47F6E0(v10, v5);
            if ( v7 )
              v1 = *v7;
          }
          sub_53FE50(v6, v1);
          sub_53E350(v4++);
          ++v5;
          v6 += 22616;
          v1 = 0;
        }
        while ( v4 < v11[0] );
      }
      goto LABEL_25;
    }
  }
  dword_757C10 = 1;
LABEL_24:
  sub_42CC30(&unk_920488);
LABEL_25:
  v16 = -1;
  sub_525140(v11);
  sub_525140(v11);
LABEL_26:
  if ( (_BYTE)dword_757C1C )
    sub_53E6A0(&unk_9204A0, 0);
  else
    sub_53E6A0(&unk_9204A0, 1);
  v8 = dword_B6F708;
  if ( !dword_B6F708 )
    v8 = (char *)WindowName;
  sub_539600(v8);
  sub_53FE50(&unk_9204A0, dword_BE1BD0);
  sub_53E350(0);
  return 0;
}
